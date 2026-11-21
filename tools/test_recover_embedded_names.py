#!/usr/bin/env python3
import hashlib
import json
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import recover_embedded_names as ren


class EvidenceTest(unittest.TestCase):
    def test_aligned_words_are_evidence_not_function_assignments(self):
        # No instructions or function starts. Identical text at distinct
        # offsets and multiple matches for one string must remain distinct.
        data = bytearray(131)
        for offset in (64, 80, 96):
            data[offset:offset + 9] = b"same_text"
        for pos, value in [(0, ren.HARDWARE_BASE + 64), (12, ren.HARDWARE_BASE + 64),
                           (120, ren.HARDWARE_BASE + 80), (20, 0x100000 + 96),
                           (25, ren.HARDWARE_BASE + 96)]:
            struct.pack_into("<I", data, pos, value)
        self.assertEqual(ren.image_evidence(data), {
            "sha256": hashlib.sha256(data).hexdigest(),
            "identifiers": [
                {"string_offset": "0x40", "text": "same_text", "word_offsets": ["0x0", "0xc"]},
                {"string_offset": "0x50", "text": "same_text", "word_offsets": ["0x78"]},
            ],
        })

    def test_only_whole_nul_terminated_identifiers(self):
        data = b"abc_def\0Not_One\0prefix: bad_id\0a_b\0not_nul\n\0no_end"
        self.assertEqual(list(ren.identifier_strings(data)), [(0, "abc_def")])

    def test_missing_firmware_preserves_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            out = Path(tmp) / "evidence.json"
            out.write_text("previous output")
            (Path(tmp) / f"{ren.IMAGES[0]}.bin").write_bytes(b"")
            proc = subprocess.run([sys.executable, ren.__file__, "--out", out,
                                   "--firmware-dir", tmp], capture_output=True, text=True)
            self.assertNotEqual(proc.returncode, 0)
            self.assertIn("missing firmware", proc.stderr)
            self.assertEqual(out.read_text(), "previous output")

    def test_tracked_evidence_matches_firmware(self):
        report = json.loads((ren.REPO / "metadata/embedded_identifiers.json").read_bytes())
        self.assertEqual(set(report["images"]), {f"{blob}_bin" for blob in ren.IMAGES})
        for blob in ren.IMAGES:
            with self.subTest(image=blob):
                path = ren.REPO / f"inputs/firmware/{blob}.bin"
                if not path.exists():
                    self.skipTest("run tools/fetch_firmware.sh for the firmware regression")
                data = path.read_bytes()
                evidence = report["images"][f"{blob}_bin"]
                self.assertEqual(ren.image_evidence(data), evidence)
                for entry in evidence["identifiers"]:
                    offset = int(entry["string_offset"], 16)
                    raw = entry["text"].encode("ascii") + b"\0"
                    self.assertEqual(data[offset:offset + len(raw)], raw)
                    for pos in map(lambda s: int(s, 16), entry["word_offsets"]):
                        self.assertEqual(pos % 4, 0)
                        word = int.from_bytes(data[pos:pos + 4], "little")
                        self.assertEqual(word, int(report["hardware_base"], 16) + offset)


if __name__ == "__main__":
    unittest.main()
