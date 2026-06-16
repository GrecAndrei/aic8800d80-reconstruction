// Package llm is a client for the MiniMax-M3 (tokenrouter) LLM API.
//
// The package supports:
//   - Per-call timeout (default 120s)
//   - System + user message format
//   - JSON mode (response_format=json_object)
//   - 6-key round-robin for rate-limit distribution
//
// All requests go through POST https://api.tokenrouter.com/v1/chat/completions
// with model "MiniMax-M3" and 1M context.
package llm

import (
	"bytes"
	"context"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"os"
	"path/filepath"
	"strconv"
	"strings"
	"sync"
	"time"
)

const (
	Endpoint = "https://api.tokenrouter.com/v1/chat/completions"
	Model    = "MiniMax-M3"
)

// Config holds the LLM client configuration.
type Config struct {
	Keys        []string
	Endpoint    string
	Model       string
	Timeout     time.Duration
	MaxTokens   int
	Temperature float64
}

// DefaultConfig returns a Config with 6 default keys (placeholders) and
// reasonable defaults. Keys should be overridden via env or flags.
func DefaultConfig() Config {
	return Config{
		Endpoint:    Endpoint,
		Model:       Model,
		Timeout:     120 * time.Second,
		MaxTokens:   8000,
		Temperature: 0.2,
	}
}

// LoadKeysFromEnv reads API keys from AIC8800D80_LLM_KEY_<N> env vars.
// Returns the keys in numeric order.
func LoadKeysFromEnv() []string {
	var keys []string
	for i := 1; i <= 16; i++ {
		k := os.Getenv(fmt.Sprintf("AIC8800D80_LLM_KEY_%d", i))
		if k != "" {
			keys = append(keys, k)
		}
	}
	return keys
}

// LoadKeysFromJSONConfig reads API keys from a JSON file with this shape:
//   {"providers": [{"name":"key_1","api_key":"sk-..."}, ...]}
// Returns just the api_key values in file order.
func LoadKeysFromJSONConfig(path string) ([]string, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	var cfg struct {
		Providers []struct {
			APIKey string `json:"api_key"`
		} `json:"providers"`
	}
	if err := json.Unmarshal(b, &cfg); err != nil {
		return nil, err
	}
	var keys []string
	for _, p := range cfg.Providers {
		if p.APIKey != "" {
			keys = append(keys, p.APIKey)
		}
	}
	return keys, nil
}

// LoadKeysFromDir reads API keys from a directory of *.key files.
func LoadKeysFromDir(dir string) ([]string, error) {
	entries, err := os.ReadDir(dir)
	if err != nil {
		return nil, err
	}
	var keys []string
	for _, e := range entries {
		if e.IsDir() {
			continue
		}
		path := filepath.Join(dir, e.Name())
		b, err := os.ReadFile(path)
		if err != nil {
			continue
		}
		k := strings.TrimSpace(string(b))
		if k != "" {
			keys = append(keys, k)
		}
	}
	return keys, nil
}

// Client is a thread-safe LLM client with key round-robin.
// Bad keys (401/403/auth errors) are remembered and skipped.
type Client struct {
	cfg     Config
	keys    []string
	rrIdx   int
	rrMu    sync.Mutex
	http    *http.Client

	// badKeys tracks keys that have failed authentication.
	// We never pick them again for the lifetime of this client.
	badKeys   map[string]bool
	badKeysMu sync.RWMutex
}

// NewClient creates a new LLM client with the given config.
func NewClient(cfg *Config) *Client {
	return &Client{
		cfg:     *cfg,
		keys:    cfg.Keys,
		http:    &http.Client{Timeout: cfg.Timeout},
		badKeys: make(map[string]bool),
	}
}

// New creates a new Client. If cfg.Keys is empty and LoadKeysFromEnv returns
// none, the Client will fail every call.
func New(cfg Config) *Client {
	if len(cfg.Keys) == 0 {
		cfg.Keys = LoadKeysFromEnv()
	}
	return &Client{
		cfg:  cfg,
		keys: cfg.Keys,
		http: &http.Client{Timeout: cfg.Timeout},
	}
}

// Message represents one chat message.
type Message struct {
	Role    string `json:"role"`
	Content string `json:"content"`
}

// Request is the chat completions request body.
type Request struct {
	Model          string    `json:"model"`
	Messages       []Message `json:"messages"`
	MaxTokens      int       `json:"max_tokens,omitempty"`
	Temperature    float64   `json:"temperature,omitempty"`
	ResponseFormat *struct {
		Type string `json:"type"`
	} `json:"response_format,omitempty"`
}

// Response is the chat completions response.
type Response struct {
	Choices []struct {
		Message struct {
			Role    string `json:"role"`
			Content string `json:"content"`
		} `json:"message"`
		FinishReason string `json:"finish_reason"`
	} `json:"choices"`
	Usage struct {
		PromptTokens     int `json:"prompt_tokens"`
		CompletionTokens int `json:"completion_tokens"`
		TotalTokens      int `json:"total_tokens"`
	} `json:"usage"`
	Error *struct {
		Message string `json:"message"`
		Type    string `json:"type"`
	} `json:"error,omitempty"`
}

// Call sends a chat completion request.
//
// The system prompt is sent as a "system" role message; userPrompt as
// "user". If jsonMode is true, response_format={"type":"json_object"}.
func (c *Client) Call(ctx context.Context, systemPrompt, userPrompt string, jsonMode bool) (string, error) {
	if len(c.keys) == 0 {
		return "", fmt.Errorf("no LLM API keys configured")
	}
	// Try up to len(keys) times to find a good key.
	var lastErr error
	for attempt := 0; attempt < len(c.keys); attempt++ {
		key := c.pickKey()
		if key == "" {
			return "", fmt.Errorf("all LLM keys exhausted or bad")
		}
		result, err := c.callWithKey(ctx, key, systemPrompt, userPrompt, jsonMode)
		if err == nil {
			return result, nil
		}
		lastErr = err
		// If auth failure, mark key bad
		if strings.Contains(err.Error(), "HTTP 401") || strings.Contains(err.Error(), "HTTP 403") || strings.Contains(err.Error(), "Invalid token") {
			c.markBad(key)
			continue
		}
		// Otherwise, return the error immediately
		return "", err
	}
	return "", lastErr
}

// pickKey returns the next key in round-robin order, skipping bad keys.
func (c *Client) pickKey() string {
	c.rrMu.Lock()
	defer c.rrMu.Unlock()
	c.badKeysMu.RLock()
	defer c.badKeysMu.RUnlock()
	for i := 0; i < len(c.keys); i++ {
		idx := (c.rrIdx + i) % len(c.keys)
		k := c.keys[idx]
		if !c.badKeys[k] {
			c.rrIdx = idx + 1
			return k
		}
	}
	return ""
}

// markBad remembers a key as broken.
func (c *Client) markBad(key string) {
	c.badKeysMu.Lock()
	c.badKeys[key] = true
	c.badKeysMu.Unlock()
}

// callWithKey makes one LLM call with a specific key.
func (c *Client) callWithKey(ctx context.Context, key, systemPrompt, userPrompt string, jsonMode bool) (string, error) {
	req := Request{
		Model:    c.cfg.Model,
		Messages: []Message{{Role: "system", Content: systemPrompt}, {Role: "user", Content: userPrompt}},
		MaxTokens: c.cfg.MaxTokens,
		Temperature: c.cfg.Temperature,
	}
	if jsonMode {
		req.ResponseFormat = &struct {
			Type string `json:"type"`
		}{Type: "json_object"}
	}
	body, err := json.Marshal(req)
	if err != nil {
		return "", err
	}
	httpReq, err := http.NewRequestWithContext(ctx, "POST", c.cfg.Endpoint, bytes.NewReader(body))
	if err != nil {
		return "", err
	}
	httpReq.Header.Set("Content-Type", "application/json")
	httpReq.Header.Set("Authorization", "Bearer "+key)
	resp, err := c.http.Do(httpReq)
	if err != nil {
		return "", err
	}
	defer resp.Body.Close()
	respBody, err := io.ReadAll(resp.Body)
	if err != nil {
		return "", err
	}
	if resp.StatusCode != 200 {
		return "", fmt.Errorf("LLM HTTP %d: %s", resp.StatusCode, string(respBody[:min(500, len(respBody))]))
	}
	var r Response
	if err := json.Unmarshal(respBody, &r); err != nil {
		return "", fmt.Errorf("decode response: %w (body: %s)", err, string(respBody[:min(200, len(respBody))]))
	}
	if r.Error != nil {
		return "", fmt.Errorf("LLM error: %s", r.Error.Message)
	}
	if len(r.Choices) == 0 {
		return "", fmt.Errorf("LLM no choices in response")
	}
	return r.Choices[0].Message.Content, nil
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// ParseIntHex is a tolerant integer parser. Accepts "0x18", "18", "24", "-4".
// Returns 0 if unparseable.
func ParseIntHex(s string) int {
	s = strings.TrimSpace(s)
	if s == "" {
		return 0
	}
	if strings.HasPrefix(s, "0x") || strings.HasPrefix(s, "0X") {
		if n, err := strconv.ParseInt(s[2:], 16, 64); err == nil {
			return int(n)
		}
	}
	if n, err := strconv.ParseInt(s, 10, 64); err == nil {
		return int(n)
	}
	if n, err := strconv.ParseInt(s, 16, 64); err == nil {
		return int(n)
	}
	return 0
}
