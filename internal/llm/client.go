// Package llm is a client for OpenAI-compatible reasoning LLMs
// (default: Alibaba Token Plan deepseek-v4.1-flash-1017 with prompt caching).
//
// The package supports:
//   - Unlimited HTTP call timeout by default (Timeout: 0)
//   - Persistent HTTP keep-alive connection pooling across parallel workers
//   - Explicit prompt caching (cache_control={"type":"ephemeral"} on system block)
//   - Multi-turn append-only CallMessages for prefix cache reuse
//   - Configurable reasoning_effort (default "max") and unlimited output tokens (MaxTokens: 0)
//   - JSON mode (response_format=json_object)
//   - Multi-key round-robin and atomic prompt/cached token accounting
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
	"sync/atomic"
	"time"
)

const (
	Endpoint        = "https://token-plan.ap-southeast-1.maas.aliyuncs.com/compatible-mode/v1/chat/completions"
	Model           = "qwen4-max-preview"
	ReasoningEffort = "max"
	UserAgent       = "aic8800d80-pipeline/1.0"
)

// Config configures the LLM client.
type Config struct {
	Keys            []string
	Endpoint        string
	Model           string
	ReasoningEffort string
	Timeout         time.Duration
	MaxTokens       int
	Temperature     float64
	PromptCache     bool
}

// DefaultConfig returns sensible defaults for Alibaba Token Plan deepseek-v4.1-flash-1017:
// max reasoning effort, prompt caching enabled, no output cap, and no HTTP timeout.
func DefaultConfig() Config {
	return Config{
		Endpoint:        Endpoint,
		Model:           Model,
		ReasoningEffort: ReasoningEffort,
		Timeout:         0,
		MaxTokens:       0,
		Temperature:     0.2,
		PromptCache:     true,
	}
}

// ProviderEntry describes one entry in harness_v15/keys/keys.json.
type ProviderEntry struct {
	Name            string `json:"name"`
	BaseURL         string `json:"base_url"`
	APIKey          string `json:"api_key"`
	Model           string `json:"model"`
	ReasoningEffort string `json:"reasoning_effort"`
	PromptCache     *bool  `json:"prompt_cache,omitempty"`
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
		if p.PromptCache != nil {
			cfg.PromptCache = *p.PromptCache
		}
	}
	return cfg, nil
}

// LoadKeysFromEnv reads API keys from AIC8800D80_LLM_KEY_<N>, DASHSCOPE_API_KEY,
// BAILIAN_API_KEY, ALIBABA_API_KEY, or OPENCODE_API_KEY env vars.
func LoadKeysFromEnv() []string {
	var keys []string
	for i := 1; i <= 16; i++ {
		k := strings.TrimSpace(os.Getenv(fmt.Sprintf("AIC8800D80_LLM_KEY_%d", i)))
		if k != "" {
			keys = append(keys, k)
		}
	}
	if len(keys) == 0 {
		for _, envName := range []string{"DASHSCOPE_API_KEY", "BAILIAN_API_KEY", "ALIBABA_API_KEY", "OPENCODE_API_KEY"} {
			if k := strings.TrimSpace(os.Getenv(envName)); k != "" {
				keys = append(keys, k)
				break
			}
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

// Client is a thread-safe LLM client with key round-robin and keep-alive pooling.
type Client struct {
	cfg          Config
	keys         []string
	sessionID    string
	rrIdx        int
	rrMu         sync.Mutex
	http         *http.Client
	calls        atomic.Int64
	promptTokens atomic.Int64
	cachedTokens atomic.Int64
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
	tr := &http.Transport{
		MaxIdleConns:        128,
		MaxIdleConnsPerHost: 128,
		IdleConnTimeout:     120 * time.Second,
	}
	return &Client{
		cfg:       cfg,
		keys:      cfg.Keys,
		sessionID: newSessionID(),
		http:      &http.Client{Timeout: cfg.Timeout, Transport: tr},
	}
}

// CacheStats returns cumulative (calls, promptTokens, cachedTokens) observed by this client.
func (c *Client) CacheStats() (calls, promptTokens, cachedTokens int64) {
	return c.calls.Load(), c.promptTokens.Load(), c.cachedTokens.Load()
}

// CacheControl marks a content block for provider prompt caching.
type CacheControl struct {
	Type string `json:"type"`
}

// ContentBlock is a structured OpenAI-compatible message content block.
type ContentBlock struct {
	Type         string        `json:"type"`
	Text         string        `json:"text"`
	CacheControl *CacheControl `json:"cache_control,omitempty"`
}

// Message represents one chat message (Content may be string or []ContentBlock).
type Message struct {
	Role    string `json:"role"`
	Content any    `json:"content"`
}

// Request is the OpenAI-compatible chat completions request body.
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
		PromptTokens         int `json:"prompt_tokens"`
		CompletionTokens     int `json:"completion_tokens"`
		TotalTokens          int `json:"total_tokens"`
		CacheReadInputTokens int `json:"cache_read_input_tokens"`
		PromptTokensDetails  struct {
			CachedTokens int `json:"cached_tokens"`
		} `json:"prompt_tokens_details"`
	} `json:"usage"`
	Error *struct {
		Message string `json:"message"`
		Type    string `json:"type"`
	} `json:"error,omitempty"`
}

// Call sends a single-turn system + user chat completion request.
func (c *Client) Call(ctx context.Context, systemPrompt, userPrompt string, jsonMode bool) (string, error) {
	msgs := []Message{
		{Role: "system", Content: systemPrompt},
		{Role: "user", Content: userPrompt},
	}
	return c.CallMessages(ctx, msgs, jsonMode)
}

// CallMessages sends a multi-turn chat completion request.
//
// When PromptCache is enabled and the first message is a string "system" message,
// it is automatically wrapped with cache_control={"type":"ephemeral"} so providers
// such as Alibaba Token Plan / DashScope cache the leading static prefix.
func (c *Client) CallMessages(ctx context.Context, messages []Message, jsonMode bool) (string, error) {
	if len(c.keys) == 0 {
		return "", fmt.Errorf("no LLM API keys configured")
	}
	c.rrMu.Lock()
	key := c.keys[c.rrIdx%len(c.keys)]
	c.rrIdx++
	c.rrMu.Unlock()

	msgs := make([]Message, len(messages))
	copy(msgs, messages)
	if c.cfg.PromptCache && len(msgs) > 0 && msgs[0].Role == "system" {
		if s, ok := msgs[0].Content.(string); ok && s != "" {
			msgs[0].Content = []ContentBlock{{
				Type:         "text",
				Text:         s,
				CacheControl: &CacheControl{Type: "ephemeral"},
			}}
		}
	}

	req := Request{
		Model:           c.cfg.Model,
		Messages:        msgs,
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

	useOpenCodeSession := strings.Contains(c.cfg.Endpoint, "opencode.ai")
	var lastErr error
	for attempt := 0; attempt < 8; attempt++ {
		httpReq, err := http.NewRequestWithContext(ctx, "POST", c.cfg.Endpoint, bytes.NewReader(body))
		if err != nil {
			return "", err
		}
		httpReq.Header.Set("Content-Type", "application/json")
		httpReq.Header.Set("Authorization", "Bearer "+key)
		httpReq.Header.Set("User-Agent", UserAgent)
		if useOpenCodeSession {
			httpReq.Header.Set("x-opencode-session", c.sessionID)
		}
		resp, err := c.http.Do(httpReq)
		if err != nil {
			lastErr = err
			if attempt < 4 && ctx.Err() == nil {
				wait := time.Duration(1<<min(attempt, 4)) * time.Second
				select {
				case <-ctx.Done():
					return "", ctx.Err()
				case <-time.After(wait):
				}
				continue
			}
			return "", err
		}
		respBody, readErr := io.ReadAll(resp.Body)
		resp.Body.Close()
		if readErr != nil {
			return "", readErr
		}
		statusCode := resp.StatusCode
		if statusCode != 200 {
			if (statusCode == 429 || statusCode == 500 || statusCode == 502 || statusCode == 503 || statusCode == 504) && attempt < 7 {
				wait := time.Duration(1<<min(attempt, 5)) * time.Second
				if ra := resp.Header.Get("Retry-After"); ra != "" {
					if secs, perr := strconv.Atoi(ra); perr == nil && secs > 0 {
						wait = time.Duration(secs) * time.Second
					}
				}
				select {
				case <-ctx.Done():
					return "", ctx.Err()
				case <-time.After(wait):
				}
				continue
			}
			return "", fmt.Errorf("LLM HTTP %d: %s", statusCode, string(respBody[:min(500, len(respBody))]))
		}

		var r Response
		if err := json.Unmarshal(respBody, &r); err != nil {
			return "", fmt.Errorf("decode response: %w (body: %s)", err, string(respBody[:min(200, len(respBody))]))
		}
		if r.Error != nil {
			return "", fmt.Errorf("LLM error: %s", r.Error.Message)
		}
		if len(r.Choices) == 0 {
			lastErr = fmt.Errorf("LLM no choices in response")
			if attempt < 4 {
				time.Sleep(time.Duration(1<<min(attempt, 3)) * time.Second)
				continue
			}
			return "", lastErr
		}
		c.calls.Add(1)
		c.promptTokens.Add(int64(r.Usage.PromptTokens))
		cached := r.Usage.PromptTokensDetails.CachedTokens
		if cached == 0 {
			cached = r.Usage.CacheReadInputTokens
		}
		c.cachedTokens.Add(int64(cached))

		content := r.Choices[0].Message.Content
		if strings.TrimSpace(content) == "" {
			lastErr = fmt.Errorf("LLM empty content (finish_reason=%q)", r.Choices[0].FinishReason)
			if attempt < 4 {
				wait := time.Duration(1<<min(attempt, 3)) * time.Second
				select {
				case <-ctx.Done():
					return "", ctx.Err()
				case <-time.After(wait):
				}
				continue
			}
			return "", lastErr
		}
		return content, nil
	}
	if lastErr != nil {
		return "", lastErr
	}
	return "", fmt.Errorf("LLM retries exhausted")
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
