package llm

import (
	"context"
	"encoding/json"
	"fmt"
	"strings"
	"time"
)

// StructProposalInput is the input to NameStruct.
type StructProposalInput struct {
	ClusterID    int
	Image        string
	PrimaryArg   string
	Fields       []FieldInput   // ordered by offset
	FieldStats   map[string]int // field_name -> total read_count
	SampleFuncs  []string       // sample function names touching the struct
	SampleCode   string         // 1-2 representative code snippets
}

// FieldInput is one field of a struct.
type FieldInput struct {
	Name      string // "field_0_0x0"
	Offset    int
	Size      int
	ReaderHint string  // optional: top caller names
	WriterHint string
}

// NameStruct asks the LLM to propose a name + field names for a struct.
//
// Uses a 2-turn strategy: Turn 1 asks for a one-line name, Turn 2 asks for
// the full JSON. The 2-turn approach avoids the model getting stuck in
// thinking before producing the answer.
func NameStruct(ctx context.Context, c *Client, in StructProposalInput) (*StructProposal, error) {
	// Turn 1: brief
	t1System := "You are a senior firmware reverse engineer. You will be given a struct's field layout and asked to name it concisely. Answer in 1 short line. Do not include a prefix like 'struct'."
	t1User := buildBriefPrompt(in)
	brief, err := c.Call(ctx, t1System, t1User, false)
	if err != nil {
		return nil, fmt.Errorf("turn1: %w", err)
	}
	brief = cleanBrief(brief)
	// Turn 2: full JSON
	t2System := "You are a senior firmware reverse engineer. Output JSON only, with no commentary. The JSON schema is {\"struct_name\":\"<snake_case>\",\"fields\":[{\"name\":\"<snake_case>\",\"comment\":\"<one-line semantic>\"}]}. Do not include offsets in field names; use semantic names from firmware context."
	t2User := buildJSONPrompt(in, brief)
	resp, err := c.Call(ctx, t2System, t2User, true)
	if err != nil {
		return nil, fmt.Errorf("turn2: %w", err)
	}
	// Parse JSON, tolerate junk
	return parseProposal(resp, in)
}

// StructProposal is the LLM's output.
type StructProposal struct {
	StructName string             `json:"struct_name"`
	Brief      string             `json:"brief"`
	Fields     []StructFieldName  `json:"fields"`
}

type StructFieldName struct {
	Name    string `json:"name"`
	Comment string `json:"comment"`
}

func buildBriefPrompt(in StructProposalInput) string {
	var b strings.Builder
	b.WriteString(fmt.Sprintf("Image: %s, cluster %d, primary arg: %s\n", in.Image, in.ClusterID, in.PrimaryArg))
	b.WriteString(fmt.Sprintf("Fields (%d):\n", len(in.Fields)))
	for _, f := range in.Fields {
		b.WriteString(fmt.Sprintf("  %s @ offset 0x%x size=%d\n", f.Name, f.Offset, f.Size))
	}
	b.WriteString("\nSample caller funcs (top 5):\n")
	for i, fn := range in.SampleFuncs {
		if i >= 5 {
			break
		}
		b.WriteString("  " + fn + "\n")
	}
	if in.SampleCode != "" {
		b.WriteString("\nCode sample (truncated):\n")
		if len(in.SampleCode) > 1500 {
			b.WriteString(in.SampleCode[:1500] + "...\n")
		} else {
			b.WriteString(in.SampleCode + "\n")
		}
	}
	b.WriteString("\nIn one short line, what is this struct likely to be? (e.g. 'WiFi vif state', 'mmio register poll context', 'tx packet buffer').")
	return b.String()
}

func buildJSONPrompt(in StructProposalInput, brief string) string {
	var b strings.Builder
	b.WriteString("Brief: " + brief + "\n\n")
	b.WriteString(fmt.Sprintf("Image: %s, cluster %d, primary arg: %s\n", in.Image, in.ClusterID, in.PrimaryArg))
	b.WriteString(fmt.Sprintf("Fields (%d), in offset order:\n", len(in.Fields)))
	for _, f := range in.Fields {
		hint := ""
		if f.ReaderHint != "" {
			hint += " [readers: " + f.ReaderHint + "]"
		}
		if f.WriterHint != "" {
			hint += " [writers: " + f.WriterHint + "]"
		}
		b.WriteString(fmt.Sprintf("  offset=0x%x size=%d%s\n", f.Offset, f.Size, hint))
	}
	b.WriteString("\nOutput JSON with struct_name and fields. Field names should be semantic (e.g. 'mac_addr', 'bssid_lo', 'op', 'state'). 6-8 chars max per name. No prefixes.")
	return b.String()
}

func cleanBrief(s string) string {
	s = strings.TrimSpace(s)
	// Strip code fences
	for _, prefix := range []string{"```", "Brief:", "Answer:", "Output:"} {
		s = strings.TrimPrefix(s, prefix)
	}
	// First line
	if i := strings.Index(s, "\n"); i >= 0 {
		s = s[:i]
	}
	return strings.TrimSpace(s)
}

// parseProposal uses a stack-based tolerant JSON parser since the LLM
// often emits non-strict JSON (hex literals, negative numbers, etc).
func parseProposal(s string, in StructProposalInput) (*StructProposal, error) {
	// Find the first '{' and last '}'
	start := strings.Index(s, "{")
	end := strings.LastIndex(s, "}")
	if start < 0 || end < 0 || end <= start {
		return nil, fmt.Errorf("no JSON object in response: %q", s[:min(100, len(s))])
	}
	body := s[start : end+1]
	// Try strict parse first
	var p StructProposal
	if err := json.Unmarshal([]byte(body), &p); err == nil && p.StructName != "" {
		return &p, nil
	}
	// Tolerant parse: extract struct_name and fields
	return tolerantParse(body, in)
}

func tolerantParse(s string, in StructProposalInput) (*StructProposal, error) {
	p := &StructProposal{}
	// Extract struct_name: "struct_name"\s*:\s*"<name>"
	if m := extractQuoted(s, "struct_name"); m != "" {
		p.StructName = sanitizeName(m)
	}
	// Extract fields array
	if arrStart := strings.Index(s, "\"fields\""); arrStart >= 0 {
		if lb := strings.Index(s[arrStart:], "["); lb >= 0 {
			arrStart += lb
			rb := findMatching(s, arrStart, '[', ']')
			if rb > arrStart {
				arr := s[arrStart+1 : rb]
				p.Fields = parseFieldArray(arr)
			}
		}
	}
	if p.StructName == "" {
		return nil, fmt.Errorf("could not extract struct_name from: %q", s[:min(200, len(s))])
	}
	return p, nil
}

func parseFieldArray(s string) []StructFieldName {
	var out []StructFieldName
	// Split on top-level objects
	depth := 0
	start := -1
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case '{':
			if depth == 0 {
				start = i
			}
			depth++
		case '}':
			depth--
			if depth == 0 && start >= 0 {
				obj := s[start : i+1]
				f := StructFieldName{}
				if n := extractQuoted(obj, "name"); n != "" {
					f.Name = sanitizeName(n)
				}
				if c := extractQuoted(obj, "comment"); c != "" {
					f.Comment = c
				}
				if f.Name != "" {
					out = append(out, f)
				}
				start = -1
			}
		}
	}
	return out
}

func extractQuoted(s, key string) string {
	kp := "\"" + key + "\""
	idx := strings.Index(s, kp)
	if idx < 0 {
		return ""
	}
	rest := s[idx+len(kp):]
	// Find colon
	ci := strings.Index(rest, ":")
	if ci < 0 {
		return ""
	}
	rest = rest[ci+1:]
	// Skip whitespace
	rest = strings.TrimLeft(rest, " \t\n")
	if len(rest) == 0 || rest[0] != '"' {
		return ""
	}
	// Find matching close quote
	for i := 1; i < len(rest); i++ {
		if rest[i] == '\\' && i+1 < len(rest) {
			i++
			continue
		}
		if rest[i] == '"' {
			return rest[1:i]
		}
	}
	return ""
}

func sanitizeName(s string) string {
	s = strings.TrimSpace(s)
	var b strings.Builder
	for i, r := range s {
		if i == 0 && (r >= '0' && r <= '9') {
			b.WriteRune('_')
			continue
		}
		switch {
		case r >= 'a' && r <= 'z':
			b.WriteRune(r)
		case r >= 'A' && r <= 'Z':
			b.WriteRune(r)
		case r >= '0' && r <= '9':
			b.WriteRune(r)
		case r == '_':
			b.WriteRune(r)
		default:
			b.WriteRune('_')
		}
	}
	out := b.String()
	if out == "" {
		return "unnamed"
	}
	return out
}

func findMatching(s string, start int, open, close byte) int {
	depth := 0
	for i := start; i < len(s); i++ {
		if s[i] == open {
			depth++
		} else if s[i] == close {
			depth--
			if depth == 0 {
				return i
			}
		}
	}
	return -1
}

// Wait a bit between calls to be polite to the API.
var DefaultDelay = 200 * time.Millisecond
