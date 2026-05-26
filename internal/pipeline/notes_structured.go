package pipeline

import (
	"encoding/json"
	"fmt"
	"os"
	"strings"
)

type structuredNotes struct {
	SchemaVersion string               `json:"schema_version"`
	Functions     []FunctionRecord     `json:"functions"`
	Artifacts     []ArtifactRecord     `json:"artifacts"`
	StateMachines []StateMachineRecord `json:"state_machines"`
	MessageRoutes []MessageRouteRecord `json:"message_routes"`
}

func parseStructuredNotes(path string, image string) ([]FunctionRecord, []ArtifactRecord, []StateMachineRecord, []MessageRouteRecord, error) {
	if strings.TrimSpace(path) == "" {
		return nil, nil, nil, nil, nil
	}
	st, err := os.Stat(path)
	if err != nil || st.IsDir() {
		return nil, nil, nil, nil, nil
	}
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, nil, nil, nil, fmt.Errorf("read structured notes %s: %w", path, err)
	}
	var notes structuredNotes
	if err := json.Unmarshal(b, &notes); err != nil {
		return nil, nil, nil, nil, fmt.Errorf("parse structured notes %s: %w", path, err)
	}
	if strings.TrimSpace(notes.SchemaVersion) != "" && notes.SchemaVersion != schemaVersion {
		return nil, nil, nil, nil, fmt.Errorf("schema mismatch in %s: got %s, want %s", path, notes.SchemaVersion, schemaVersion)
	}
	applyImage := func(in string) string {
		if strings.TrimSpace(in) != "" {
			return in
		}
		if strings.TrimSpace(image) != "" {
			return image
		}
		return "unknown.bin"
	}
	for i := range notes.Functions {
		notes.Functions[i].SchemaVersion = schemaVersion
		notes.Functions[i].Image = applyImage(notes.Functions[i].Image)
		if notes.Functions[i].Source == "" {
			notes.Functions[i].Source = "re_notes_structured"
		}
	}
	for i := range notes.Artifacts {
		notes.Artifacts[i].SchemaVersion = schemaVersion
		notes.Artifacts[i].Image = applyImage(notes.Artifacts[i].Image)
		if notes.Artifacts[i].Source == "" {
			notes.Artifacts[i].Source = "re_notes_structured"
		}
	}
	for i := range notes.StateMachines {
		notes.StateMachines[i].SchemaVersion = schemaVersion
		notes.StateMachines[i].Image = applyImage(notes.StateMachines[i].Image)
		if notes.StateMachines[i].Source == "" {
			notes.StateMachines[i].Source = "re_notes_structured"
		}
	}
	for i := range notes.MessageRoutes {
		notes.MessageRoutes[i].SchemaVersion = schemaVersion
		notes.MessageRoutes[i].Image = applyImage(notes.MessageRoutes[i].Image)
		if notes.MessageRoutes[i].Source == "" {
			notes.MessageRoutes[i].Source = "re_notes_structured"
		}
	}
	return notes.Functions, notes.Artifacts, notes.StateMachines, notes.MessageRoutes, nil
}

func inferMessageRouteSemantic(evidence string, addr string) (action string, targetName string, sideEffect string) {
	name := "sub_" + strings.TrimPrefix(strings.ToLower(addr), "0x")
	line := strings.ToLower(strings.TrimSpace(evidence))
	switch {
	case strings.Contains(line, "enqueue") || strings.Contains(line, "queue"):
		return "enqueue", name, "queue mutation"
	case strings.Contains(line, "flag"):
		return "set_flag", name, "flag update"
	case strings.Contains(line, "fallback"):
		return "fallback", name, "fallback path"
	case strings.Contains(line, "error"):
		return "error_path", name, "blocking/error"
	case strings.Contains(line, "parse"):
		return "parse_message", name, "parser dispatch"
	case strings.Contains(line, "pool") || strings.Contains(line, "alloc"):
		return "pool_get", name, "buffer allocation"
	default:
		return "conditional_call", name, "guarded path"
	}
}
