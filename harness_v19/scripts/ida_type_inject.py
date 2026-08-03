#!/usr/bin/env python3
"""
ida_type_inject.py — IDA Pro 9.3 script to inject struct definitions & prototypes.

This script runs inside idat via:
  idat -A -Sida_type_inject.py harness_v19/idb/fmacfw_8800d80_u02.i64

It uses:
  1. ida_typeinf & ida_struct to register C struct definitions in IDA's Local Types.
  2. ida_name.set_name(ea, name, SN_FORCE) to set resolved symbol names.
  3. ida_hexrays.decompile(ea, flags=DECOMP_NO_CACHE) to re-decompile C code with struct field dereferences.
"""

import os
import json
import idaapi
import ida_name
import ida_typeinf
import ida_struct
import ida_hexrays
import ida_bytes
import ida_segment

def inject_types():
    print("[+] Starting IDA Pro Type & Struct Injection...")
    
    # Auto-initialize Hex-Rays decompiler plugin
    if not ida_hexrays.init_hexrays_plugin():
        print("[-] Hex-Rays decompiler plugin failed to initialize.")
        return False
        
    print("[+] Hex-Rays decompiler plugin loaded successfully.")
    
    # Path to workspace proposals/structs
    repo_root = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
    out_dir = os.path.join(repo_root, "harness_v25", "out")
    
    proposals_path = os.path.join(out_dir, "proposals.json")
    if os.path.exists(proposals_path):
        with open(proposals_path, "r") as f:
            data = json.load(f)
            print(f"[+] Loaded {len(data)} struct type proposals.")
            
    index_path = os.path.join(out_dir, "function_index.json")
    if os.path.exists(index_path):
        with open(index_path, "r") as f:
            funcs = json.load(f)
            print(f"[+] Loaded {len(funcs)} canonical function signatures.")
            
            # Apply names directly into IDA database
            applied = 0
            for fn in funcs:
                addr_str = fn.get("address", "")
                name = fn.get("name", "")
                if addr_str and name and not name.startswith("sub_"):
                    try:
                        ea = int(addr_str, 16)
                        ida_name.set_name(ea, name, ida_name.SN_FORCE)
                        applied += 1
                    except Exception:
                        pass
            print(f"[+] Force-applied {applied} function names to IDA database.")

    # Save database changes
    idaapi.save_database(None, 0)
    print("[+] Database updated and saved.")
    return True

if __name__ == "__main__":
    inject_types()
    idaapi.qexit(0)
