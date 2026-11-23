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

func TestDefaultConfigAndOpenCodeGoRequest(t *testing.T) {
	cfg := DefaultConfig()
	if cfg.Model != "glm-5.3" {
		t.Fatalf("Model = %q, want glm-5.3", cfg.Model)
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

	var gotUA, gotSession, gotAuth string
	var gotBody map[string]any
	srv := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		gotUA = r.Header.Get("User-Agent")
		gotSession = r.Header.Get("x-opencode-session")
		gotAuth = r.Header.Get("Authorization")
		b, _ := io.ReadAll(r.Body)
		_ = json.Unmarshal(b, &gotBody)
		w.Header().Set("Content-Type", "application/json")
		_, _ = w.Write([]byte(`{"choices":[{"message":{"role":"assistant","content":"ok"},"finish_reason":"stop"}]}`))
	}))
	defer srv.Close()

	cfg.Endpoint = srv.URL
	cfg.Keys = []string{"oc_sk_test"}
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
	if !strings.HasPrefix(gotSession, "ses_") || len(gotSession) < 8 {
		t.Fatalf("x-opencode-session = %q, want ses_<id>", gotSession)
	}
	if gotAuth != "Bearer oc_sk_test" {
		t.Fatalf("Authorization = %q", gotAuth)
	}
	if gotBody["model"] != "glm-5.3" || gotBody["reasoning_effort"] != "max" {
		t.Fatalf("unexpected body model/reasoning_effort: %v", gotBody)
	}
	if _, hasMax := gotBody["max_tokens"]; hasMax {
		t.Fatalf("max_tokens should be omitted when unlimited, got: %v", gotBody["max_tokens"])
	}
}

func TestLoadConfigFromKeysJSON(t *testing.T) {
	dir := t.TempDir()
	p := filepath.Join(dir, "keys.json")
	data := `{"providers":[{"name":"p1","base_url":"https://opencode.ai/inference/go/openai/v1","api_key":"oc_sk_abc","model":"glm-5.3","reasoning_effort":"max"}]}`
	if err := os.WriteFile(p, []byte(data), 0600); err != nil {
		t.Fatal(err)
	}
	cfg, err := LoadConfigFromKeysJSON(p)
	if err != nil {
		t.Fatal(err)
	}
	if len(cfg.Keys) != 1 || cfg.Keys[0] != "oc_sk_abc" {
		t.Fatalf("Keys = %v", cfg.Keys)
	}
	if cfg.Endpoint != Endpoint {
		t.Fatalf("Endpoint = %q, want %q", cfg.Endpoint, Endpoint)
	}
	if cfg.Model != "glm-5.3" || cfg.ReasoningEffort != "max" {
		t.Fatalf("Model=%q ReasoningEffort=%q", cfg.Model, cfg.ReasoningEffort)
	}
}
