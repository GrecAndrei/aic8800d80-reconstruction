#!/usr/bin/env python3
"""Zero-shot function classifier using BGE-code-v1 GGUF model.

Provides:
- embed(text) -> embedding vector
- classify_function(name, pseudocode, image) -> behavioral class tags
- semantic_similarity(emb1, emb2) -> cosine score

Caches embeddings per (name, image, address) identity to avoid recomputation.
"""

from __future__ import annotations

import json
import math
import os
import sys
from pathlib import Path
from typing import Optional


# Behavioral category descriptors for zero-shot classification.
# Each category has a key, a label, a description embedding text, and a synthesis role hint.
BEHAVIOR_CATEGORIES: dict[str, dict] = {
    "dma_io": {
        "label": "dma_io",
        "desc": "DMA transfer, SDIO read/write, USB endpoint, buffer descriptor management, hardware FIFO, scatter-gather I/O",
        "synth_role": "io_driver",
        "priority_boost": 1.3,
        "min_probe_budget": 2,
    },
    "radio_control": {
        "label": "radio_control",
        "desc": "RF register write, PHY calibration, TX power control, antenna config, frequency tuning, radio state machine",
        "synth_role": "radio_reg_write",
        "priority_boost": 1.3,
        "min_probe_budget": 2,
    },
    "timer_callback": {
        "label": "timer_callback",
        "desc": "timer interrupt, periodic callback, hw timer handler, timeout, delay scheduling, tick processing",
        "synth_role": "interrupt_handler",
        "priority_boost": 1.2,
        "min_probe_budget": 1,
    },
    "message_handler": {
        "label": "message_handler",
        "desc": "IPC message dispatch, event routing, ke_msg, task message handler, mailbox processing, doorbell handler, host-wifi message forwarding",
        "synth_role": "dispatcher",
        "priority_boost": 1.25,
        "min_probe_budget": 2,
    },
    "state_machine": {
        "label": "state_machine",
        "desc": "protocol state machine, connection state transitions, mode enter/exit, link control, power save state management, scan state handler",
        "synth_role": "state_machine",
        "priority_boost": 1.2,
        "min_probe_budget": 2,
    },
    "memory_pool": {
        "label": "memory_pool",
        "desc": "memory allocator, free, pool init, buffer queue, linked list push/pop, heap management, refill, reclaim",
        "synth_role": "memory_pool",
        "priority_boost": 1.05,
        "min_probe_budget": 1,
    },
    "crypto_security": {
        "label": "crypto_security",
        "desc": "AES encrypt, key schedule, HMAC, SHA, crypto engine init, certificate, authentication, secure boot, ECC, RSA, key load, crypto hardware power-up",
        "synth_role": "crypto_core",
        "priority_boost": 1.3,
        "min_probe_budget": 2,
    },
    "system_init": {
        "label": "system_init",
        "desc": "firmware boot, hardware init, clock configuration, PLL setup, peripheral reset, chip feature detection, startup sequence, main initialization",
        "synth_role": "init_sequence",
        "priority_boost": 1.25,
        "min_probe_budget": 2,
    },
    "log_debug": {
        "label": "log_debug",
        "desc": "printf wrapper, log write, debug output, UART putc, trace message, diagnostic dump, assert handler, hex dump",
        "synth_role": "leaf_wrapper",
        "priority_boost": 0.8,
        "min_probe_budget": 1,
    },
    "patch_routine": {
        "label": "patch_routine",
        "desc": "binary patch apply, fixup table entry, relocation, version check patch, address remap, hotfix inject",
        "synth_role": "patch_apply",
        "priority_boost": 1.1,
        "min_probe_budget": 1,
    },
    "error_handler": {
        "label": "error_handler",
        "desc": "fault handler, watchdog reset, panic loop, assert fail, exception handler, hardfault, NMI, bus error",
        "synth_role": "error_handler",
        "priority_boost": 1.15,
        "min_probe_budget": 1,
    },
    "math_helper": {
        "label": "math_helper",
        "desc": "fixed-point multiply, divide, bit operations, rounding, integer math, fast math approximations, bitmask operations, shift, count leading zeros",
        "synth_role": "leaf_wrapper",
        "priority_boost": 0.9,
        "min_probe_budget": 1,
    },
    "leaf_wrapper": {
        "label": "leaf_wrapper",
        "desc": "simple passthrough function, trivial return, unconditional branch wrapper, empty body, single instruction, jump only, nop equivalent",
        "synth_role": "leaf_wrapper",
        "priority_boost": 0.7,
        "min_probe_budget": 1,
    },
}


class EmbedderCache:
    """Persistent embedding cache keyed by (name, image, address) identity."""

    def __init__(self, path: Path):
        self.path = path
        self.data: dict[str, dict] = {}
        if path.is_file():
            try:
                raw = json.loads(path.read_text(encoding="utf-8"))
                if isinstance(raw, dict):
                    self.data = raw
            except (json.JSONDecodeError, OSError):
                self.data = {}

    def _identity_key(self, name: str, image: str = "", address: str = "") -> str:
        n = (name or "").strip().lower()
        img = (image or "").strip().lower()
        addr = (address or "").strip().lower()
        if img or addr:
            return f"{img}|{addr}|{n}"
        return f"|{n}"

    def get_embedding(self, name: str, image: str = "", address: str = "") -> Optional[list[float]]:
        key = self._identity_key(name, image, address)
        entry = self.data.get(key)
        if entry and isinstance(entry.get("emb"), list):
            return entry["emb"]
        return None

    def get_classification(self, name: str, image: str = "", address: str = "") -> Optional[dict]:
        key = self._identity_key(name, image, address)
        entry = self.data.get(key)
        if entry and isinstance(entry.get("classification"), dict):
            return entry["classification"]
        return None

    def set_embedding(self, name: str, image: str, address: str, emb: list[float]) -> None:
        key = self._identity_key(name, image, address)
        self.data.setdefault(key, {})["emb"] = emb

    def set_classification(self, name: str, image: str, address: str, classification: dict) -> None:
        key = self._identity_key(name, image, address)
        self.data.setdefault(key, {})["classification"] = classification

    def has(self, name: str, image: str = "", address: str = "") -> bool:
        key = self._identity_key(name, image, address)
        entry = self.data.get(key)
        return entry is not None and isinstance(entry.get("emb"), list)

    def save(self) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        with open(self.path, "w", encoding="utf-8") as f:
            json.dump(self.data, f, indent=2)

    def stats(self) -> dict:
        total = len(self.data)
        with_emb = sum(1 for v in self.data.values() if isinstance(v.get("emb"), list))
        with_class = sum(1 for v in self.data.values() if isinstance(v.get("classification"), dict))
        return {"total_entries": total, "with_embeddings": with_emb, "with_classifications": with_class}


class BehaviorEmbedder:
    """Zero-shot function classifier backed by a GGUF embedding model."""

    def __init__(self, model_path: str, cache_path: Optional[Path] = None, n_threads: int = 4):
        self.model_path = model_path
        self.cache = EmbedderCache(cache_path or Path(model_path).parent / "embedder_cache.json")
        self._llm = None
        self._n_threads = max(1, n_threads)
        self._category_embs: Optional[list[tuple[str, list[float]]]] = None

    @property
    def llm(self):
        if self._llm is None:
            from llama_cpp import Llama
            self._llm = Llama(
                model_path=self.model_path,
                embedding=True,
                verbose=False,
                n_ctx=512,
                n_threads=self._n_threads,
            )
        return self._llm

    def _embed(self, text: str) -> list[float]:
        text = text.strip()
        if len(text) > 800:
            text = text[:800]
        if not text:
            return [0.0] * 1536
        result = self.llm.embed(text)
        if isinstance(result, list) and len(result) > 0 and isinstance(result[0], list):
            return list(result[0])
        if isinstance(result, list) and all(isinstance(v, (int, float)) for v in result):
            return list(result)
        return [0.0] * 1536

    @staticmethod
    def cosine(a: list[float], b: list[float]) -> float:
        n1 = len(a)
        n2 = len(b)
        if n1 == 0 or n2 == 0:
            return 0.0
        dots = sum(a[i] * b[i] for i in range(min(n1, n2)))
        mag_a = math.sqrt(sum(x * x for x in a))
        mag_b = math.sqrt(sum(x * x for x in b))
        if mag_a == 0 or mag_b == 0:
            return 0.0
        return dots / (mag_a * mag_b)

    def embed_function(self, name: str, image: str = "", address: str = "", pseudocode: str = "") -> list[float]:
        """Get embedding for a function, using cache if available."""
        cached = self.cache.get_embedding(name, image, address)
        if cached is not None:
            return cached
        text = self._build_function_text(name, pseudocode)
        emb = self._embed(text)
        if any(v != 0.0 for v in emb):
            self.cache.set_embedding(name, image, address, emb)
        return emb

    def _build_function_text(self, name: str, pseudocode: str) -> str:
        text = f"function {name}"
        if pseudocode:
            text += f": {pseudocode}"
        return text

    def _get_category_embeddings(self) -> list[tuple[str, list[float]]]:
        if self._category_embs is not None:
            return self._category_embs
        raw: list[tuple[str, list[float]]] = []
        for ckey, cdef in BEHAVIOR_CATEGORIES.items():
            emb = self._embed(cdef["desc"])
            if any(v != 0.0 for v in emb):
                raw.append((ckey, emb))
        self._category_embs = raw
        return raw

    def classify_function(self, name: str, image: str = "", address: str = "", pseudocode: str = "") -> dict:
        """Zero-shot classify a function into behavioral categories.

        Returns:
            dict with keys: primary_class, primary_label, all_scores (dict class->score),
            priority_boost, min_probe_budget, synth_role, confidence
        """
        cached = self.cache.get_classification(name, image, address)
        if cached is not None:
            return cached

        emb = self.embed_function(name, image, address, pseudocode)
        cats = self._get_category_embeddings()
        scores: dict[str, float] = {}
        for ckey, cat_emb in cats:
            scores[ckey] = self.cosine(emb, cat_emb)

        if not scores:
            primary = "unknown"
        else:
            primary = max(scores, key=scores.get)

        primary_def = BEHAVIOR_CATEGORIES.get(primary, {})
        confidence = scores.get(primary, 0.0)
        result = {
            "primary_class": primary,
            "primary_label": primary_def.get("label", primary),
            "all_scores": {k: round(v, 4) for k, v in sorted(scores.items(), key=lambda kv: -kv[1])},
            "priority_boost": primary_def.get("priority_boost", 1.0),
            "min_probe_budget": primary_def.get("min_probe_budget", 1),
            "synth_role": primary_def.get("synth_role", "leaf_wrapper"),
            "confidence": round(confidence, 4),
        }
        self.cache.set_classification(name, image, address, result)
        return result

    def classify_batch(self, items: list[dict]) -> None:
        """Classify a batch of functions in-place, mutating each item dict.

        Each item dict should have: name, image (optional), address (optional), pseudocode (optional).
        Classification result is written to item['behavior_class'].
        """
        for item in items:
            name = str(item.get("name", "")).strip()
            if not name:
                continue
            image = str(item.get("image", "")).strip()
            address = str(item.get("address", "")).strip()
            pseudocode = str(item.get("pseudocode", "")).strip()
            item["behavior_class"] = self.classify_function(name, image, address, pseudocode)

    def save_cache(self) -> None:
        self.cache.save()


# Standalone CLI for debugging / pre-computation
def main() -> int:
    import argparse
    ap = argparse.ArgumentParser(description="Embedder CLI")
    ap.add_argument("--model", required=True, help="Path to GGUF model")
    ap.add_argument("--cache", default="extraction_out/reconstruction/mega7/embedder_cache.json", help="Cache path")
    ap.add_argument("--name", help="Function name to classify")
    ap.add_argument("--image", default="", help="Image name")
    ap.add_argument("--address", default="", help="Hex address")
    ap.add_argument("--pseudocode", default="", help="Decompiled pseudocode")
    ap.add_argument("--batch-file", help="JSONL file of {name, image, address, pseudocode} rows to classify")
    ap.add_argument("--batch-out", help="Output JSON path for batch results")
    ap.add_argument("--stats", action="store_true", help="Print cache stats")
    ap.add_argument("--threads", type=int, default=4, help="CPU threads")
    args = ap.parse_args()

    embedder = BehaviorEmbedder(args.model, Path(args.cache), n_threads=args.threads)

    if args.stats:
        st = embedder.cache.stats()
        print(json.dumps(st, indent=2))
        return 0

    if args.batch_file:
        rows = []
        with open(args.batch_file, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                try:
                    rows.append(json.loads(line))
                except json.JSONDecodeError:
                    continue
        embedder.classify_batch(rows)
        embedder.save_cache()
        if args.batch_out:
            with open(args.batch_out, "w", encoding="utf-8") as f:
                json.dump(rows, f, indent=2)
        else:
            print(json.dumps(rows, indent=2))
        print(f"Classified {len(rows)} functions", file=sys.stderr)
        st = embedder.cache.stats()
        print(json.dumps(st, indent=2), file=sys.stderr)
        return 0

    if args.name:
        result = embedder.classify_function(args.name, args.image, args.address, args.pseudocode)
        embedder.save_cache()
        print(json.dumps(result, indent=2))
        return 0

    ap.print_help()
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
