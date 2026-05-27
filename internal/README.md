# Internal Packages

This directory contains shared Go packages used by the commands in `cmd/`.

## Packages

- `extract/`: extraction and frontier logic
- `fileio/`: JSON, JSONL, bytes, and file-lock helpers
- `pipeline/`: shared pipeline coordination helpers
- `reconstruct/`: reconstruction descriptors, motif memory, transfer logic, and rebuild helpers
- `stats/`: aggregate statistics helpers

`internal/reconstruct/` is the current center of the descriptor-driven rebuild path.
