// Package llm is a client for OpenAI-compatible reasoning LLMs (OpenCode Go GLM-5.3).
//
// The package supports:
//   - Unlimited HTTP call timeout by default (Timeout: 0)
//   - System + user message format
//   - Configurable reasoning_effort (default "max") and unlimited output tokens (MaxTokens: 0)
//   - JSON mode (response_format=json_object)
//   - Multi-key round-robin and stable x-opencode-session header
//
// All requests default to POST https://opencode.ai/inference/go/openai/v1/chat/completions
// with model "glm-5.3".
package llm

import (
	"bytes"
	"context"
	"crypto/rand"
	"encoding/hex"
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
	Endpoint        = "https://opencode.ai/inference/go/openai/v1/chat/completions"
	Model           = "glm-5.3"
	ReasoningEffort = "max"
	UserAgent       = "aic8800d80-pipeline/1.0"
)

// Config holds the LLM client configuration.
type Config struct {
	Keys            []string
	Endpoint        string
	Model           string
	ReasoningEffort string
	Timeout         time.Duration
	MaxTokens       int
	Temperature     float64
}

// DefaultConfig returns a Config with the default OpenCode Go GLM-5.3 endpoint,
// model, max reasoning effort, no output budget (MaxTokens: 0), and no HTTP
// timeout (Timeout: 0). Keys should be loaded from keys.json, env, or flags.
func DefaultConfig() Config {
	return Config{
		Endpoint:        Endpoint,
		Model:           Model,
		ReasoningEffort: ReasoningEffort,
		Timeout:         0,
		MaxTokens:       0,
		Temperature:     0.2,
	}
}

// ProviderEntry describes one entry in harness_v15/keys/keys.json.
type ProviderEntry struct {
	Name            string `json:"name"`
	BaseURL         string `json:"base_url"`
	APIKey          string `json:"api_key"`
	Model           string `json:"model"`
	ReasoningEffort string `json:"reasoning_effort"`
}

// KeysFile describes harness_v15/keys/keys.json.
type KeysFile struct {
	Providers []ProviderEntry `json:"providers"`
	Strategy  string          `json:"strategy"`
}

// LoadConfigFromKeysJSON loads API keys and provider settings from keys.json.
func LoadConfigFromKeysJSON(path string) (Config, error) {
	cfg := DefaultConfig()
	b, err := os.ReadFile(path)
	if err != nil {
		return cfg, err
	}
	var kf KeysFile
	if err := json.Unmarshal(b, &kf); err != nil {
		return cfg, err
	}
	for _, p := range kf.Providers {
		k := strings.TrimSpace(p.APIKey)
		if k != "" && k != "REPLACE_ME" {
			cfg.Keys = append(cfg.Keys, k)
		}
		if cfg.Endpoint == Endpoint && strings.TrimSpace(p.BaseURL) != "" {
			base := strings.TrimRight(strings.TrimSpace(p.BaseURL), "/")
			if strings.HasSuffix(base, "/chat/completions") {
				cfg.Endpoint = base
			} else {
				cfg.Endpoint = base + "/chat/completions"
			}
		}
		if cfg.Model == Model && strings.TrimSpace(p.Model) != "" {
			cfg.Model = strings.TrimSpace(p.Model)
		}
		if cfg.ReasoningEffort == ReasoningEffort && strings.TrimSpace(p.ReasoningEffort) != "" {
			cfg.ReasoningEffort = strings.TrimSpace(p.ReasoningEffort)
		}
	}
	return cfg, nil
}

// LoadKeysFromEnv reads API keys from AIC8800D80_LLM_KEY_<N> or OPENCODE_API_KEY env vars.
// Returns the keys in order.
func LoadKeysFromEnv() []string {
	var keys []string
	for i := 1; i <= 16; i++ {
		k := strings.TrimSpace(os.Getenv(fmt.Sprintf("AIC8800D80_LLM_KEY_%d", i)))
		if k != "" {
			keys = append(keys, k)
		}
	}
	if len(keys) == 0 {
		if k := strings.TrimSpace(os.Getenv("OPENCODE_API_KEY")); k != "" {
			keys = append(keys, k)
		}
	}
	return keys
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

func newSessionID() string {
	if s := strings.TrimSpace(os.Getenv("OPENCODE_SESSION_ID")); s != "" {
		return s
	}
	var buf [16]byte
	if _, err := rand.Read(buf[:]); err == nil {
		return "ses_" + hex.EncodeToString(buf[:])
	}
	return fmt.Sprintf("ses_%d", time.Now().UnixNano())
}

// Client is a thread-safe LLM client with key round-robin.
type Client struct {
	cfg       Config
	keys      []string
	sessionID string
	rrIdx     int
	rrMu      sync.Mutex
	http      *http.Client
}

// New creates a new Client. If cfg.Keys is empty and LoadKeysFromEnv returns
// none, the Client will fail every call.
func New(cfg Config) *Client {
	if len(cfg.Keys) == 0 {
		cfg.Keys = LoadKeysFromEnv()
	}
	if cfg.Endpoint == "" {
		cfg.Endpoint = Endpoint
	}
	if cfg.Model == "" {
		cfg.Model = Model
	}
	if cfg.ReasoningEffort == "" {
		cfg.ReasoningEffort = ReasoningEffort
	}
	return &Client{
		cfg:       cfg,
		keys:      cfg.Keys,
		sessionID: newSessionID(),
		http:      &http.Client{Timeout: cfg.Timeout},
	}
}

// Message represents one chat message.
type Message struct {
	Role    string `json:"role"`
	Content string `json:"content"`
}

// Request is the chat completions request body.
type Request struct {
	Model           string    `json:"model"`
	Messages        []Message `json:"messages"`
	MaxTokens       int       `json:"max_tokens,omitempty"`
	ReasoningEffort string    `json:"reasoning_effort,omitempty"`
	Temperature     float64   `json:"temperature,omitempty"`
	ResponseFormat  *struct {
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
	c.rrMu.Lock()
	key := c.keys[c.rrIdx%len(c.keys)]
	c.rrIdx++
	c.rrMu.Unlock()

	req := Request{
		Model:           c.cfg.Model,
		Messages:        []Message{{Role: "system", Content: systemPrompt}, {Role: "user", Content: userPrompt}},
		MaxTokens:       c.cfg.MaxTokens,
		ReasoningEffort: c.cfg.ReasoningEffort,
		Temperature:     c.cfg.Temperature,
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
	httpReq.Header.Set("User-Agent", UserAgent)
	httpReq.Header.Set("x-opencode-session", c.sessionID)
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
