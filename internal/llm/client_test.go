package llm

import (
	"context"
	"encoding/json"
	"io"
	"net/http"
	"net/http/httptest"
	"os"
	"path/filepath"
	"strings"
	"testing"
)

func TestParseIntHex(t *testing.T) {
	tests := []struct {
		in   string
		want int
	}{
		{"0x18", 24},
		{"0xFF", 255},
		{"0", 0},
		{"42", 42},
		{"-4", -4},
		{"", 0},
		{"junk", 0},
	}
	for _, tc := range tests {
		got := ParseIntHex(tc.in)
		if got != tc.want {
			t.Errorf("ParseIntHex(%q) = %d, want %d", tc.in, got, tc.want)
		}
	}
}

func TestDefaultConfigAndPromptCacheRequest(t *testing.T) {
	cfg := DefaultConfig()
	if cfg.Model != "qwen4-max-preview" {
		t.Fatalf("Model = %q, want qwen4-max-preview", cfg.Model)
	}
	if cfg.ReasoningEffort != "max" {
		t.Fatalf("ReasoningEffort = %q, want max", cfg.ReasoningEffort)
	}
	if cfg.Timeout != 0 {
		t.Fatalf("Timeout = %v, want 0 (no limit)", cfg.Timeout)
	}
	if cfg.MaxTokens != 0 {
		t.Fatalf("MaxTokens = %d, want 0 (no limit)", cfg.MaxTokens)
	}
	if !cfg.PromptCache {
		t.Fatalf("PromptCache = false, want true")
	}

	var gotUA, gotSession, gotAuth string
	var gotBody map[string]any
	srv := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		gotUA = r.Header.Get("User-Agent")
		gotSession = r.Header.Get("x-opencode-session")
		gotAuth = r.Header.Get("Authorization")
		b, _ := io.ReadAll(r.Body)
		_ = json.Unmarshal(b, &gotBody)
		w.Header().Set("Content-Type", "application/json")
		_, _ = w.Write([]byte(`{"choices":[{"message":{"role":"assistant","content":"ok"},"finish_reason":"stop"}],"usage":{"prompt_tokens":1500,"prompt_tokens_details":{"cached_tokens":1024}}}`))
	}))
	defer srv.Close()

	cfg.Endpoint = srv.URL
	cfg.Keys = []string{"sk-sp-test"}
	c := New(cfg)
	out, err := c.Call(context.Background(), "sys", "usr", true)
	if err != nil {
		t.Fatalf("Call failed: %v", err)
	}
	if out != "ok" {
		t.Fatalf("Call = %q, want ok", out)
	}
	if gotUA != UserAgent {
		t.Fatalf("User-Agent = %q, want %q", gotUA, UserAgent)
	}
	if gotSession != "" {
		t.Fatalf("x-opencode-session = %q, want empty for non-opencode endpoint", gotSession)
	}
	if gotAuth != "Bearer sk-sp-test" {
		t.Fatalf("Authorization = %q", gotAuth)
	}
	if gotBody["model"] != "qwen4-max-preview" || gotBody["reasoning_effort"] != "max" {
		t.Fatalf("unexpected body model/reasoning_effort: %v", gotBody)
	}
	if _, hasMax := gotBody["max_tokens"]; hasMax {
		t.Fatalf("max_tokens should be omitted when unlimited, got: %v", gotBody["max_tokens"])
	}
	msgs, _ := gotBody["messages"].([]any)
	sysMsg, _ := msgs[0].(map[string]any)
	blocks, ok := sysMsg["content"].([]any)
	if !ok || len(blocks) != 1 {
		t.Fatalf("system content should be cached ContentBlock slice, got: %T %v", sysMsg["content"], sysMsg["content"])
	}
	blk, _ := blocks[0].(map[string]any)
	cc, _ := blk["cache_control"].(map[string]any)
	if cc["type"] != "ephemeral" {
		t.Fatalf("cache_control = %v, want ephemeral", cc)
	}
	calls, ptok, ctok := c.CacheStats()
	if calls != 1 || ptok != 1500 || ctok != 1024 {
		t.Fatalf("CacheStats = (%d,%d,%d), want (1,1500,1024)", calls, ptok, ctok)
	}
}

func TestLoadConfigFromKeysJSON(t *testing.T) {
	dir := t.TempDir()
	p := filepath.Join(dir, "keys.json")
	data := `{"providers":[{"name":"alibaba_token_plan","base_url":"https://token-plan.ap-southeast-1.maas.aliyuncs.com/compatible-mode/v1","api_key":"sk-sp-abc","model":"deepseek-v4.1-flash-1017","reasoning_effort":"max","prompt_cache":true}]}`
	if err := os.WriteFile(p, []byte(data), 0600); err != nil {
		t.Fatal(err)
	}
	cfg, err := LoadConfigFromKeysJSON(p)
	if err != nil {
		t.Fatal(err)
	}
	if len(cfg.Keys) != 1 || cfg.Keys[0] != "sk-sp-abc" {
		t.Fatalf("Keys = %v", cfg.Keys)
	}
	if cfg.Endpoint != Endpoint {
		t.Fatalf("Endpoint = %q, want %q", cfg.Endpoint, Endpoint)
	}
	if cfg.Model != "deepseek-v4.1-flash-1017" || cfg.ReasoningEffort != "max" || !cfg.PromptCache {
		t.Fatalf("Model=%q ReasoningEffort=%q PromptCache=%v", cfg.Model, cfg.ReasoningEffort, cfg.PromptCache)
	}
}

func TestLoadKeysFromDashScopeEnv(t *testing.T) {
	t.Setenv("AIC8800D80_LLM_KEY_1", "")
	t.Setenv("OPENCODE_API_KEY", "")
	t.Setenv("DASHSCOPE_API_KEY", "sk-sp-env-key")
	keys := LoadKeysFromEnv()
	if len(keys) != 1 || keys[0] != "sk-sp-env-key" {
		t.Fatalf("LoadKeysFromEnv() = %v, want [sk-sp-env-key]", keys)
	}
}

func TestRetryOn429AndEmptyContent(t *testing.T) {
	attempts := 0
	srv := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		attempts++
		if attempts == 1 {
			w.Header().Set("Retry-After", "0")
			w.WriteHeader(http.StatusTooManyRequests)
			_, _ = w.Write([]byte(`{"error":{"type":"rate_limit_error"}}`))
			return
		}
		if attempts == 2 {
			w.Header().Set("Content-Type", "application/json")
			_, _ = w.Write([]byte(`{"choices":[{"message":{"role":"assistant","content":""},"finish_reason":"stop"}]}`))
			return
		}
		w.Header().Set("Content-Type", "application/json")
		_, _ = w.Write([]byte(`{"choices":[{"message":{"role":"assistant","content":"ok-after-retry"},"finish_reason":"stop"}]}`))
	}))
	defer srv.Close()

	cfg := DefaultConfig()
	cfg.Endpoint = srv.URL
	cfg.Keys = []string{"sk-sp-test"}
	c := New(cfg)
	out, err := c.Call(context.Background(), "sys", "usr", false)
	if err != nil {
		t.Fatalf("Call after retry failed: %v", err)
	}
	if out != "ok-after-retry" || attempts != 3 {
		t.Fatalf("out=%q attempts=%d", out, attempts)
	}
}

func TestStructNamingSystemPromptAboveCacheThreshold(t *testing.T) {
	// Alibaba Token Plan / DashScope requires >=1,024 tokens for prompt caching.
	// Rough conservative check: >=4,500 bytes (~1,200+ tokens).
	if len(structNamingSystemPrompt) < 4500 {
		t.Fatalf("structNamingSystemPrompt length = %d bytes, want >= 4500 for >=1024-token cache hit", len(structNamingSystemPrompt))
	}
	if !strings.Contains(structNamingSystemPrompt, "AIC8800D80") {
		t.Fatalf("structNamingSystemPrompt missing AIC8800D80 domain context")
	}
}
