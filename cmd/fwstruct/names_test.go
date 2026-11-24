package main

import (
	"encoding/json"
	"net/http"
	"net/http/httptest"
	"os"
	"path/filepath"
	"testing"

	"aic8800d80/internal/structs"
)

func TestNamesSkipNamed(t *testing.T) {
	calls := 0
	srv := httptest.NewServer(http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		calls++
		w.Header().Set("Content-Type", "application/json")
		_, _ = w.Write([]byte(`{"choices":[{"message":{"role":"assistant","content":"{\"struct_name\":\"rf_new_ctx_t\",\"fields\":[{\"offset\":4,\"name\":\"flags\"}]}"},"finish_reason":"stop"}]}`))
	}))
	defer srv.Close()

	dir := t.TempDir()
	kpath := filepath.Join(dir, "keys.json")
	if err := os.WriteFile(kpath, []byte(`{"providers":[{"base_url":"`+srv.URL+`","api_key":"oc_sk_test","model":"glm-5.3","reasoning_effort":"max"}]}`), 0600); err != nil {
		t.Fatal(err)
	}

	outDir := filepath.Join(dir, "out")
	if err := os.MkdirAll(outDir, 0755); err != nil {
		t.Fatal(err)
	}
	img := "test_img"
	rep := clusterReport{
		Image:        img,
		TotalFuncs:   2,
		Clustered:    2,
		ClusterCount: 2,
		Clusters: []*structs.Cluster{
			{GroupID: 0, PrimaryArg: "a1", Name: "already_named_t", Fingerprint: []structs.AccessKey{{Offset: 0, Size: 4}}},
			{GroupID: 1, PrimaryArg: "a1", Name: "struct_shape_abc_t", Fingerprint: []structs.AccessKey{{Offset: 4, Size: 4}}},
		},
	}
	b, _ := json.MarshalIndent(rep, "", "  ")
	if err := os.WriteFile(filepath.Join(outDir, img+"_clusters.json"), b, 0644); err != nil {
		t.Fatal(err)
	}
	prevNamed := `[{"image":"test_img","group":0,"primary_arg":"a1","struct_name":"already_named_t","fields":[{"name":"keep_me","offset":0,"size":4}]}]`
	if err := os.WriteFile(filepath.Join(outDir, img+"_named.json"), []byte(prevNamed), 0644); err != nil {
		t.Fatal(err)
	}

	if err := runNames([]string{"--images", img, "--out", outDir, "--llm-keys", kpath, "--skip-named", "--concurrency", "1"}); err != nil {
		t.Fatalf("runNames failed: %v", err)
	}
	if calls != 2 {
		t.Fatalf("expected 2 LLM calls (turn1+turn2) for unnamed cluster only, got %d", calls)
	}

	var gotRep clusterReport
	if err := readJSON(filepath.Join(outDir, img+"_clusters.json"), &gotRep); err != nil {
		t.Fatal(err)
	}
	if gotRep.Clusters[0].Name != "already_named_t" || gotRep.Clusters[1].Name != "rf_new_ctx_t" {
		t.Fatalf("unexpected cluster names: %q, %q", gotRep.Clusters[0].Name, gotRep.Clusters[1].Name)
	}

	var gotNamed []map[string]any
	if err := readJSON(filepath.Join(outDir, img+"_named.json"), &gotNamed); err != nil {
		t.Fatal(err)
	}
	if len(gotNamed) != 2 || gotNamed[0]["struct_name"] != "already_named_t" || gotNamed[1]["struct_name"] != "rf_new_ctx_t" {
		t.Fatalf("unexpected named entries: %+v", gotNamed)
	}
}
