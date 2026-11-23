"""Dump IDB names at src unit addresses + resolve stub call-site names.

Env:
  IDA_UNITS   - JSON dict image -> [unit addrs] (analysis space)
  IDA_STUBS   - JSON dict image -> [names] (optional)
  IDA_OUT     - output JSON path: {"unit_names": {addr: name}, "stubs": {name: addr}}
"""
import json, os
import idaapi, ida_name, idc

idaapi.auto_wait()
units = json.loads(os.environ['IDA_UNITS'])
stubs = json.loads(os.environ.get('IDA_STUBS', '{}'))
out = {"unit_names": {}, "stubs": {}}
for a in units:
    n = ida_name.get_name(a)
    if n:
        out["unit_names"][str(a)] = n
for n in stubs:
    ea = ida_name.get_name_ea(idaapi.BADADDR, n)
    if ea == idaapi.BADADDR:
        ea = idc.get_name_ea_simple(n)
    out["stubs"][n] = ea if ea != idaapi.BADADDR else -1
json.dump(out, open(os.environ['IDA_OUT'], 'w'), indent=1)
print('unit names', len(out["unit_names"]), 'stubs resolved', sum(1 for v in out["stubs"].values() if v >= 0))
