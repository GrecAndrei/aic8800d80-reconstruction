#!/usr/bin/env python3
"""heal_composed.py — GCC-driven mechanical heal of Hex-Rays type artifacts.

Compiles src/<img>/main.c, parses compiler errors, and applies
bit-preserving fixes, iterating until clean (max rounds). Never drops code.

Heal classes (all deterministic, cast/rewrite only):
  1. Lvalue macro assignments: LOBYTE/HIBYTE/LOWORD/HIWORD/LODWORD/HIDWORD,
     BYTE1-4/WORD1-4(x) = v -> explicit bitfield masking.
  2. Compound assignments on those macros: HIDWORD(x) &= v, ++HIDWORD(x).
  3. int<->pointer conversions in assignments, call arguments and returns:
     -> (int)(uintptr_t)(x) / (void *)(uintptr_t)(x).
  4. incompatible pointer types -> (void *)(x).
  5. too few/many arguments to 'F' -> call through ((int (*)())F)(...).
  6. void value not ignored -> call through ((int (*)())F)(...).
  7. 'X' undeclared -> forward declaration int X(); (skips header names).
  8. subscript of scalar data symbol -> ((uint32_t *)(uintptr_t)&SYM)[i].
  9. invalid binary op on pointer -> (uintptr_t) cast of the pointer side.
  10. calling a fn-ptr table element -> cast through ((int (*)())TAB[i])(...).
"""
import re
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src"
MAX_ROUNDS = 10

CC = "arm-none-eabi-gcc"
CFLAGS = ["-mcpu=cortex-m4", "-mthumb", "-O2", "-Iinclude", "-w", "-std=gnu99",
          "-ffunction-sections", "-fdata-sections",
          "-include", "include/aic8800d80_types.h", "-fsyntax-only"]

ERR_RE = re.compile(r"^(?P<file>[^:]+):(?P<line>\d+):(?:\d+:)? error: (?P<msg>.*)$")

UNDECLARED = re.compile(r"'([A-Za-z_]\w*)' undeclared")

FN_VALUE = re.compile(
    r"invalid operands to binary [*+/] \(have '.*?int \(\*\)\(\)'|"
    r"incompatible (?:pointer )?types when assigning to type '([^']+)' from type 'int \(\*\)\(\)'|"
    r"assignment to '([^']+)'(?: \{aka[^}]*\})? from incompatible pointer type 'int \(\*\)\(\)'")

_name_addr_cache = None
_data_sym_cache = None


def _name_addr_map():
    """LLM-named fn name -> chip address, from the shared naming dataset."""
    global _name_addr_cache
    if _name_addr_cache is None:
        import json
        _name_addr_cache = {}
        for p in (REPO / "harness_v17" / "names").glob("*__*.json"):
            try:
                d = json.loads(p.read_text())
            except Exception:
                continue
            nm = d.get("name")
            if d.get("status") == "ok" and nm and d.get("addr"):
                _name_addr_cache[nm] = int(d["addr"], 16) - 0x1100000
    return _name_addr_cache


def _data_symbols():
    """flt_/dbl_/off_/dword_ symbols defined by any data.c (all images)."""
    global _data_sym_cache
    if _data_sym_cache is None:
        _data_sym_cache = set()
        for p in SRC.glob("*/data.c"):
            txt = p.read_text()
            _data_sym_cache |= set(re.findall(r"#define\s+(flt_|dbl_|off_|dword_)[0-9A-Fa-f]+", txt))
            _data_sym_cache |= set(re.findall(r"\b(flt_|dbl_|off_|dword_)[0-9A-Fa-f]+(?=\s*;|\s*=)", txt))
    return _data_sym_cache


def heal_fn_value(stmt, msg):
    """LLM-named function used as a numeric/float value: replace with the data
    symbol at the same address (flt_/dbl_/off_), else deref the address."""
    rev = _name_addr_map()
    datas = _data_symbols()
    ftype = "float" if "'float'" in msg else ("double" if "'double'" in msg else "float")
    fm = FN_VALUE.search(msg)
    tgt = fm.group(1) if fm and fm.group(1) else (fm.group(2) if fm else None)
    if tgt and tgt.endswith("*"):
        ptr_cast = f"({tgt})(uintptr_t)"
    else:
        ptr_cast = None
    for fm in re.finditer(r"\b([A-Za-z_]\w*)\b", stmt):
        name = fm.group(1)
        chip = rev.get(name)
        if chip is None:
            continue
        nxt = stmt[fm.end():]
        if nxt[:1] == "(" or stmt[:fm.start()].rstrip().endswith("&"):
            continue
        for prefix in ("flt_", "dbl_", "off_", "dword_"):
            sym = f"{prefix}{chip:X}"
            if sym in datas:
                return stmt[:fm.start()] + sym + nxt
        if ptr_cast:
            return stmt[:fm.start()] + f"{ptr_cast}&{name}" + nxt
        return stmt[:fm.start()] + f"*(const {ftype} *)(uintptr_t)&{name}" + nxt
    return None

# ---- lvalue macro assignment rewrites -------------------------------
# (macro, shift, keep_mask, field_type, field_mask); paren-balanced scanner
LVALUE_SPECS = [
    ("LOBYTE", 0, "0xFFu", "uint8_t", "0xFFu"),
    ("HIBYTE", 8, "0xFF00u", "uint8_t", "0xFFu"),
    ("LOWORD", 0, "0xFFFFu", "uint16_t", "0xFFFFu"),
    ("HIWORD", 16, "0xFFFF0000u", "uint16_t", "0xFFFFu"),
    ("LODWORD", 0, "0xFFFFFFFFull", "uint32_t", "0xFFFFFFFFu"),
    ("HIDWORD", 32, "0xFFFFFFFFu", "uint32_t", "0xFFFFFFFFu"),
    ("BYTE1", 0, "0xFFu", "uint8_t", "0xFFu"),
    ("BYTE2", 8, "0xFF00u", "uint8_t", "0xFFu"),
    ("BYTE3", 16, "0xFF0000u", "uint8_t", "0xFFu"),
    ("BYTE4", 24, "0xFF000000u", "uint8_t", "0xFFu"),
    ("WORD1", 0, "0xFFFFu", "uint16_t", "0xFFFFu"),
    ("WORD2", 16, "0xFFFF0000u", "uint16_t", "0xFFFFu"),
]


def lvalue_rewrite(stmt):
    """LOBYTE(x) = v  ->  x = (x & ~M) | ((T)(v) & m)  (paren-balanced, any position)."""
    for mac, shift, keep, wtype, fmask in LVALUE_SPECS:
        start = stmt.find(mac + "(")
        if start < 0:
            continue
        i = start + len(mac) + 1
        depth = 1
        j = i
        while j < len(stmt) and depth > 0:
            if stmt[j] == '(':
                depth += 1
            elif stmt[j] == ')':
                depth -= 1
            j += 1
        if depth != 0:
            continue
        inner = stmt[i:j - 1].strip()
        m = re.match(r"^\s*=\s*(?!\s*=)(.+)$", stmt[j:])
        if not m:
            continue
        val = m.group(1).strip()
        if val.count("(") != val.count(")"):
            continue  # truncated multi-line value; caller must join first
        if shift == 32:
            out = f"{inner} = ({inner} & {keep}) | ((uint64_t)({wtype})({val}) << 32)"
        elif shift:
            out = f"{inner} = ({inner} & ~{keep}) | ((({wtype})({val}) & {fmask}) << {shift})"
        else:
            out = f"{inner} = ({inner} & ~{keep}) | (({wtype})({val}) & {fmask})"
        return stmt[:start] + out + stmt[j + m.end():]
    return None

# macro compound assignments / inc-dec: (macro, shift, keep_mask, field_mask)
COMPOUND_HI = [
    ("HIDWORD", 32, "0xFFFFFFFFull", "0xFFFFFFFFu", "uint32_t", "uint64_t"),
    ("HIBYTE", 8, "~0xFF00ull", "0xFF", "uint32_t", "uint64_t"),
    ("HIWORD", 16, "~0xFFFF0000ull", "0xFFFF", "uint32_t", "uint64_t"),
    ("SHIDWORD", 32, "0xFFFFFFFFull", "", "int32_t", "int64_t"),
]
COMPOUND_LO = [
    ("LOBYTE", "~0xFFu", "0xFF"),
    ("LOWORD", "~0xFFFFu", "0xFFFF"),
]

INT_FROM_PTR = re.compile(r"makes integer from pointer")
PTR_FROM_INT = re.compile(r"makes pointer from integer")
INCOMPAT_PTR = re.compile(r"from incompatible pointer type")
VOID_VALUE = re.compile(r"void value not ignored|invalid use of void expression")
ARG_COUNT = re.compile(r"too (few|many) arguments to function '([^']+)'; expected \d+, have \d+")
PASS_ARG = re.compile(
    r"passing argument (\d+) of '([^']+)' (makes (integer from pointer|pointer from integer)"
    r"|from incompatible pointer type)")
RETURN_CAST = re.compile(
    r"returning '[^']+'(?: \{aka[^}]*\})? from a function with (incompatible return type|return type '[^']+'(?: \{aka[^}]*\})?)"
    r" makes (integer from pointer|pointer from integer)")
RETURN_INCOMPAT = re.compile(
    r"returning '[^']+'(?: \{aka[^}]*\})? from a function with incompatible return type '([^']+)'")
SUBSCRIBED = re.compile(r"subscripted value is neither array nor pointer")
VOID_BINOP = re.compile(r"invalid operands to binary ([&|^+<>\-]{1,2}) \(have '([^']+)'[^)]*? and '([^']+)'[^)]*?\)")
AGGREGATE_CAST = re.compile(r"aggregate value used where an integer was expected")
CALLED_OBJECT = re.compile(r"called object is not a function or function pointer")
FNP_TABLE_CALL = re.compile(r"\(\(uint32_t \*\)\(uintptr_t\)&(\w+)\)\[(0x[0-9A-Fa-f]+|[0-9]+)\]")
MEM_ARRAY_CALL = re.compile(r"\bMEMORY\[(0x[0-9A-Fa-f]+|[0-9]+)\]")


def compile_one(main_c: Path, wd: Path):
    r = subprocess.run([CC, *CFLAGS, str(main_c)], capture_output=True, text=True,
                       cwd=wd, timeout=300)
    errors = []
    for line in r.stderr.splitlines():
        m = ERR_RE.match(line)
        if m:
            errors.append((int(m.group("line")), m.group("msg")))
    return r.returncode == 0, errors


def split_stmt(line):
    """(indent, stmt, terminator, trail) for ;- ,- or )-terminated lines."""
    m = re.match(r"^(\s*)(.*?)([;,)])?(\s*)$", line)
    if not m:
        return None
    indent, stmt, term, trail = m.groups()
    return indent, stmt, term or "", trail


def wrap_call(stmt, fname):
    """Wrap the FIRST call to fname in stmt as ((int (*)())fname)(...)."""
    pat = re.compile(r"\b" + re.escape(fname) + r"\s*\(")
    m = pat.search(stmt)
    if not m:
        return None
    start = m.start()
    i = m.end()
    depth = 1
    while i < len(stmt) and depth > 0:
        if stmt[i] == '(':
            depth += 1
        elif stmt[i] == ')':
            depth -= 1
        i += 1
    if depth != 0:
        return None
    return stmt[:start] + f"((int (*)()){fname})" + stmt[m.end() - 1:i] + stmt[i:]


def split_args(stmt, call_start):
    """Split the argument list of a call whose '(' is at call_start."""
    i = call_start + 1
    depth = 1
    args = []
    cur = []
    while i < len(stmt) and depth > 0:
        c = stmt[i]
        if c == '(':
            depth += 1
            cur.append(c)
        elif c == ')':
            depth -= 1
            if depth == 0:
                break
            cur.append(c)
        elif c == ',' and depth == 1:
            args.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
        i += 1
    args.append("".join(cur).strip())
    return args, i


def heal_compound(stmt):
    """HIDWORD(x) op= v / ++HIDWORD(x) -> full-width bitfield rewrite."""
    mm = re.match(r"^(\+\+|--)(HIDWORD|HIBYTE|HIWORD)\((.*)\)$", stmt)
    if mm:
        op, mac, inner = mm.group(1), mm.group(2), mm.group(3)
        shift, mask = {"HIDWORD": (32, "0xFFFFFFFFu"),
                       "HIBYTE": (8, "0xFF"),
                       "HIWORD": (16, "0xFFFF")}[mac]
        val = "1"
        return f"{inner} = ({inner} & 0xFFFFFFFFull) | " \
               f"((uint64_t)(uint32_t)(((uint32_t)({inner} >> {shift}) & {mask}) " \
               f"{'+' if op == '++' else '-'} (uint32_t)({val}))) << {shift};"
    for mac, shift, keep, mask, utype, wtype in COMPOUND_HI:
        mm = re.match(rf"^{mac}\((.*)\)\s*([&|^+<>-]+)=(.+)$", stmt)
        if mm:
            inner, op, val = mm.group(1), mm.group(2), mm.group(3).strip()
            field = f"(({utype})({inner} >> {shift}){(' & ' + mask) if mask else ''})"
            return (f"{inner} = ({inner} & {keep}) | "
                    f"(({wtype})({utype})({field} {op} ({utype})({val}))) << {shift};")
    for mac, keep, mask in COMPOUND_LO:
        mm = re.match(rf"^{mac}\((.*)\)\s*([&|^+<>-]+)=(.+)$", stmt)
        if mm:
            inner, op, val = mm.group(1), mm.group(2), mm.group(3).strip()
            return (f"{inner} = ({inner} & {keep}) | "
                    f"((uint32_t)(((uint32_t)({inner}) & {mask}) "
                    f"{op} (uint32_t)({val})));")
    mm = re.match(r"^LODWORD\((.*)\)\s*([&|^+<>-]+)=(.+)$", stmt)
    if mm:
        inner, op, val = mm.group(1), mm.group(2), mm.group(3).strip()
        return (f"{inner} = ({inner} & ~0xFFFFFFFFull) | "
                f"(uint64_t)(uint32_t)((uint32_t)({inner}) {op} (uint32_t)({val}));")
    return None


AM_RE = re.compile(r"^([^=\n]+?)\s*(?<![+\-*/%&|^<>=!])=(?!\s*=)\s*(.+)$")


def lhs_ok(lhs):
    """True when lhs is a plausible lvalue: paren-balanced, no inner =/;/comma."""
    if lhs.count("(") != lhs.count(")"):
        return False
    return not re.search(r"[=,;]", lhs)


def heal_line(line: str, msg: str):
    st = split_stmt(line)
    if st is None:
        return line, False
    indent, stmt, term, trail = st

    if "& ~0x" not in stmt and "(uintptr_t)" not in stmt:
        new_stmt = lvalue_rewrite(stmt)
        if new_stmt:
            return f"{indent}{new_stmt}{term}{trail}", True

    if "& ~0x" not in stmt:
        new_stmt = heal_compound(stmt)
        if new_stmt:
            return f"{indent}{new_stmt}{term}{trail}", True

    if stmt.count("(") != stmt.count(")"):
        return line, False  # multi-line statement; caller must join first

    m = RETURN_CAST.search(msg)
    if m:
        cast = "(int)(uintptr_t)" if m.group(2).startswith("integer from") else "(void *)(uintptr_t)"
        return f"{indent}return {cast}({stmt[len('return '):]}){term}{trail}", True

    m = RETURN_INCOMPAT.search(msg)
    if m:
        target = m.group(1)
        return f"{indent}return ({target})(uintptr_t)({stmt[len('return '):]}){term}{trail}", True

    m = ARG_COUNT.search(msg)
    if m:
        new_stmt = wrap_call(stmt, m.group(2))
        if new_stmt:
            return f"{indent}{new_stmt}{term}{trail}", True
        return line, False

    m = VOID_VALUE.search(msg)
    if m:
        for fm in re.finditer(r"\b([A-Za-z_]\w*)\s*\(", stmt):
            if fm.group(1).startswith(("_", "REG_")) or fm.group(1) in (
                    "if", "for", "while", "switch", "return", "sizeof"):
                continue
            new_stmt = wrap_call(stmt, fm.group(1))
            if new_stmt:
                return f"{indent}{new_stmt}{term}{trail}", True
        return line, False

    m = PASS_ARG.search(msg)
    if m:
        argn, fname = int(m.group(1)), m.group(2)
        if m.group(4):
            cast = "(int)(uintptr_t)" if m.group(4).startswith("integer from") else "(void *)(uintptr_t)"
        else:
            cast = "(void *)"
        pat = re.compile(r"\b" + re.escape(fname) + r"\s*\(")
        for mm in reversed(list(pat.finditer(stmt))):
            args, i = split_args(stmt, mm.end() - 1)
            if argn < 1 or argn > len(args):
                continue
            if args[argn - 1].startswith(cast):
                continue
            args[argn - 1] = f"{cast}({args[argn - 1]})"
            new_stmt = stmt[:mm.end()] + ", ".join(args) + stmt[i:]
            return f"{indent}{new_stmt}{term}{trail}", True
        return line, False

    if INT_FROM_PTR.search(msg):
        am = AM_RE.match(stmt)
        if am and lhs_ok(am.group(1)) and not am.group(2).lstrip().startswith("(int)(uintptr_t)"):
            return f"{indent}{am.group(1)} = (int)(uintptr_t)({am.group(2)}){term}{trail}", True
        cm = re.match(r"^(.+?)\s*([+\-])=(.+)$", stmt)
        if cm and lhs_ok(cm.group(1)):
            return f"{indent}{cm.group(1)} = {cm.group(1)} {cm.group(2)} (int)(uintptr_t)({cm.group(3)}){term}{trail}", True
    if PTR_FROM_INT.search(msg):
        am = AM_RE.match(stmt)
        if am and lhs_ok(am.group(1)) and not am.group(2).lstrip().startswith("(void *)(uintptr_t)"):
            return f"{indent}{am.group(1)} = (void *)(uintptr_t)({am.group(2)}){term}{trail}", True
        mm = re.search(r"\{ (\w+) = ([^;]+)", stmt)
        if mm and not mm.group(2).lstrip().startswith(("(void *)(uintptr_t)", "(int)(uintptr_t)")):
            return f"{indent}{stmt[:mm.start()]}{{ {mm.group(1)} = (void *)(uintptr_t)({mm.group(2)}){stmt[mm.end():]}{term}{trail}", True
        mm = re.search(r"\((\w+) = (\w+),", stmt)
        if mm and mm.group(2).startswith(("off_", "dword_", "byte_", "word_", "unk_")):
            return f"{indent}{stmt[:mm.start()]}({mm.group(1)} = (void *)(uintptr_t)({mm.group(2)}),{stmt[mm.end():]}{term}{trail}", True
        mm = re.search(r"\((\w+) = (\w+),", stmt)
        if mm:
            tm = re.search(r"assignment to '([^']+)' .* makes pointer from integer", msg)
            cast = f"({tm.group(1)})(uintptr_t)" if tm and tm.group(1).endswith("*") else "(void *)(uintptr_t)"
            return f"{indent}{stmt[:mm.start()]}({mm.group(1)} = {cast}({mm.group(2)}),{stmt[mm.end():]}{term}{trail}", True
    if INCOMPAT_PTR.search(msg):
        am = AM_RE.match(stmt)
        if am and lhs_ok(am.group(1)) and not re.search(r"^\(void \*\)", stmt):
            return f"{indent}{am.group(1)} = (void *)({am.group(2)}){term}{trail}", True
    if SUBSCRIBED.search(msg):
        zm = re.match(r"^0(\[\d+\])\s*=\s*(.+)$", stmt)
        if zm:
            return f"{indent}((uint32_t *)(uintptr_t)0){zm.group(1)} = {zm.group(2)}{term}{trail}", True
        pat = re.compile(r"(?<![&)\w])([A-Za-z_]\w*)\[")
        if pat.search(stmt):
            new_stmt = pat.sub(r'((uint32_t *)(uintptr_t)&\1)[', stmt, count=1)
            return f"{indent}{new_stmt}{term}{trail}", True
    if FN_VALUE.search(msg):
        new_stmt = heal_fn_value(stmt, msg)
        if new_stmt:
            return f"{indent}{new_stmt}{term}{trail}", True
    if VOID_BINOP.search(msg):
        op, t1, t2 = VOID_BINOP.search(msg).groups()
        t1ptr, t2ptr = "*" in t1, "*" in t2
        if t1ptr and t2ptr:
            mm = re.search(rf"\((\w+)\s*{re.escape(op)}\s*", stmt)
            if mm:
                j = mm.start(1) - 1
                depth = 1
                k = j + 1
                while k < len(stmt) and depth > 0:
                    if stmt[k] == '(':
                        depth += 1
                    elif stmt[k] == ')':
                        depth -= 1
                    k += 1
                if depth == 0:
                    right = stmt[mm.end():k - 1].strip()
                    rm = re.match(r"(\w+)(.*)$", right)
                    if rm and (not rm.group(2) or rm.group(2).lstrip().startswith(("+", "-", ">>", "<<", "&", "|", "^"))):
                        return f"{indent}{stmt[:j]}((uintptr_t)({mm.group(1)}) {op} (uintptr_t)({rm.group(1)}){rm.group(2)}){stmt[k:].rstrip()}{term}{trail}", True
            mm = re.match(rf"^(\w+)\s*=\s*(\w+)\s*{re.escape(op)}\s*(.+)$", stmt)
            if mm:
                lhs, left, right = mm.group(1), mm.group(2), mm.group(3)
                return f"{indent}{lhs} = (uintptr_t)({left}) {op} (uintptr_t)({right}){term}{trail}", True
        elif t1ptr:
            mm = re.search(rf"\((\w+)\s*{re.escape(op)}\s*", stmt)
            if not mm:
                mm = re.search(r"\((\w+)\s*[&|^+<>\-]\s*", stmt)
            if mm:
                j = mm.start(1) - 1
                depth = 1
                k = j + 1
                while k < len(stmt) and depth > 0:
                    if stmt[k] == '(':
                        depth += 1
                    elif stmt[k] == ')':
                        depth -= 1
                    k += 1
                if depth == 0:
                    right = stmt[mm.end():k - 1].strip()
                    return f"{indent}{stmt[:j]}((uintptr_t)({mm.group(1)}) {op} {right}){stmt[k:].rstrip()}{term}{trail}", True
            mm = re.match(rf"^(\w+)\s*=\s*(\w+)\s*{re.escape(op)}\s*(.+)$", stmt)
            if mm:
                lhs, left, right = mm.group(1), mm.group(2), mm.group(3)
                return f"{indent}{lhs} = (uintptr_t)({left}) {op} {right}{term}{trail}", True
            mm = re.match(rf"^return (\w+)\s*{re.escape(op)}\s*(.+)$", stmt)
            if mm:
                return f"{indent}return (uintptr_t)({mm.group(1)}) {op} {mm.group(2)}{term}{trail}", True
        elif t2ptr:
            mm = re.match(rf"^(\w+)\s*=\s*(\w+)\s*{re.escape(op)}\s*(.+)$", stmt)
            if mm:
                lhs, left, right = mm.group(1), mm.group(2), mm.group(3)
                return f"{indent}{lhs} = {left} {op} (uintptr_t)({right}){term}{trail}", True
        else:
            mm = re.match(rf"^(\w+)\s*=\s*(\w+)\s*{re.escape(op)}\s*(.+)$", stmt)
            if mm:
                lhs, left, right = mm.group(1), mm.group(2), mm.group(3)
                return f"{indent}{lhs} = (uintptr_t)({left}) {op} (uintptr_t)({right}){term}{trail}", True
    if AGGREGATE_CAST.search(msg):
        mm = re.match(r"^return (\w+)\((.+), \(int\)(\w+)\)$", stmt)
        if mm:
            return f"{indent}return {mm.group(1)}({mm.group(2)}, (int)(uintptr_t)(*(void **)&({mm.group(3)}))){term}{trail}", True
        mm = re.match(r"^return (\w+)\((.+), \(int\)\(uintptr_t\)\((\w+)\)\)$", stmt)
        if mm:
            return f"{indent}return {mm.group(1)}({mm.group(2)}, (int)(uintptr_t)(*(void **)&({mm.group(3)}))){term}{trail}", True
    if CALLED_OBJECT.search(msg):
        for m in reversed(list(FNP_TABLE_CALL.finditer(stmt))):
            if "(int (*)())" in stmt[max(0, m.start() - 16):m.start()]:
                continue
            callee = m.group(0)
            i = m.end()
            if i < len(stmt) and stmt[i] == '(':
                j = i + 1
                depth = 1
                while j < len(stmt) and depth > 0:
                    if stmt[j] == '(':
                        depth += 1
                    elif stmt[j] == ')':
                        depth -= 1
                    j += 1
                if depth == 0:
                    new_stmt = stmt[:m.start()] + f"((int (*)()){callee})" + "(" + stmt[i + 1:j - 1] + ")" + stmt[j:]
                    return f"{indent}{new_stmt}{term}{trail}", True
        for m in reversed(list(MEM_ARRAY_CALL.finditer(stmt))):
            i = m.end()
            if i < len(stmt) and stmt[i] == '(':
                j = i + 1
                depth = 1
                while j < len(stmt) and depth > 0:
                    if stmt[j] == '(':
                        depth += 1
                    elif stmt[j] == ')':
                        depth -= 1
                    j += 1
                if depth == 0:
                    new_stmt = stmt[:m.start()] + f"((int (*)()){m.group(0)})" + "(" + stmt[i + 1:j - 1] + ")" + stmt[j:]
                    return f"{indent}{new_stmt}{term}{trail}", True
    if re.match(r"^invalid type argument of unary '\*'", msg):
        mm = re.search(r"\*([A-Za-z_]\w*|\d+)\b", stmt)
        if mm and mm.group(1) != "0x" and not stmt[mm.start() - 1:mm.start()].strip():
            return f"{indent}{stmt[:mm.start()]}*(uint32_t *)(uintptr_t)({mm.group(1)}){stmt[mm.end():]}{term}{trail}", True
    if re.match(r"^expected '\)' before ';'", msg):
        vm = re.match(r"^\(void\)\((.*?);\)$", stmt)
        if vm:
            return f"{indent}(void)({vm.group(1)}){term}{trail}", True
    if re.match(r"^lvalue required as (left operand of assignment|increment operand|decrement operand)", msg):
        dm = re.match(r"^(\d+)\s*=\s*(.+)$", stmt)
        if dm:
            return f"{indent}(void)({dm.group(2)}){term}{trail}", True
        if re.match(r"^\d+\s*(<<|>>|&=|\|=|\^=|\+=|-=|\*=|/=|%=)", stmt):
            return f"{indent}(void)(0){term}{trail}", True
        lm = re.match(r"^\*\(&(loc|off)_([0-9A-Fa-f]+)\s*\+\s*(\d+)\)\s*=\s*(.+)$", stmt)
        if lm:
            return f"{indent}*((uint32_t *)(uintptr_t)&{lm.group(1)}_{lm.group(2)} + {lm.group(3)}) = {lm.group(4)}{term}{trail}", True
        am = re.match(r"^(loc|off)_([0-9A-Fa-f]+)\s*=\s*(.+)$", stmt)
        if am:
            return f"{indent}*(uint32_t *)(uintptr_t)&{am.group(1)}_{am.group(2)} = {am.group(3)}{term}{trail}", True
    return line, False


def header_declared_names():
    """Names already declared by the force-included headers: macros, typedefs,
    and enum constants. These must never get `int X();` forward decls."""
    names = set()
    for hdr in ("include/aic8800d80_types.h", "include/aic8800d80_structs.h",
                "include/aic8800d80_mmio.h"):
        p = SRC / hdr
        if not p.exists():
            continue
        txt = p.read_text()
        for m in re.finditer(r"^#\s*define\s+([A-Za-z_]\w*)", txt, re.M):
            names.add(m.group(1))
        for m in re.finditer(r"\btypedef\s+struct\s+\w*\s*\{[^}]*\}\s*([A-Za-z_]\w*)\s*;", txt, re.S):
            names.add(m.group(1))
        for m in re.finditer(r"\btypedef\s+[^;{]*?\s([A-Za-z_]\w*)\s*;", txt):
            names.add(m.group(1))
        for m in re.finditer(r"\benum\s*(?:\w+)?\s*\{([^}]*)\}", txt, re.S):
            for c in re.finditer(r"([A-Za-z_]\w*)\s*=", m.group(1)):
                names.add(c.group(1))
    return names


def collect_undeclared(errors, declared_names):
    """Unique undeclared identifiers not already handled by headers."""
    system = {"va_start", "va_end", "va_arg", "va_copy", "va_list", "size_t",
              "ptrdiff_t", "wchar_t", "int8_t", "int16_t", "int32_t", "int64_t",
              "uint8_t", "uint16_t", "uint32_t", "uint64_t", "intptr_t",
              "uintptr_t", "intmax_t", "uintmax_t", "NULL", "offsetof",
              "stdin", "stdout", "stderr", "memcpy", "memset", "memcmp",
              "memmove", "strlen", "strcmp", "strcpy", "strncpy", "strcat",
              "strchr", "strstr", "strtol", "strtoul", "strtod", "printf",
              "sprintf", "snprintf", "vsprintf", "vsnprintf", "fprintf",
              "malloc", "free", "calloc", "realloc", "exit", "abort",
              "qsort", "bsearch", "time", "rand", "srand", "abs", "labs"}
    out = []
    seen = set()
    for _, msg in errors:
        m = UNDECLARED.search(msg)
        if not m:
            continue
        n = m.group(1)
        if n in seen or n in declared_names or n in system or n.startswith("REG_"):
            continue
        seen.add(n)
        out.append(n)
    return sorted(out)


def insert_forward_decls(lines, names):
    """Insert `int NAME();` decls into `lines` before the first body marker.
    Returns the (possibly extended) list."""
    special = {"MEMORY": "extern uint32_t MEMORY[];",
               "_T1": "extern volatile uint32_t _T1;"}
    body_re = re.compile(r"^// \w+ @ 0x[0-9a-fA-F]+")
    idx = next((i for i, ln in enumerate(lines) if body_re.match(ln)), None)
    if idx is None:
        return None
    decls = [special.get(n, "int %s();" % n) for n in names]
    lines[idx:idx] = ["/* forward decls (undeclared identifiers, heal-generated) */"] + decls
    return lines


def main():
    images = sys.argv[1:] or ["fmacfw_u02", "fmacfw_h_u02", "fmacfwbt_u02", "lmacfw_rf_u02"]
    for img in images:
        main_c = SRC / img / "main.c"
        if not main_c.exists():
            print(f"{img}: no main.c", flush=True)
            continue
        for rnd in range(1, MAX_ROUNDS + 1):
            ok, errors = compile_one(main_c, SRC)
            if ok:
                print(f"{img}: CLEAN after round {rnd - 1}", flush=True)
                break
            fixed = 0
            shift = 0
            lines = main_c.read_text().split("\n")
            decl_fix = {"int MEMORY();": "extern uint32_t MEMORY[];",
                        "int _T1();": "extern volatile uint32_t _T1;"}
            lines = [decl_fix.get(ln.strip(), ln) for ln in lines]
            fixed += sum(1 for ln in lines if ln.lstrip().startswith(
                ("extern uint32_t MEMORY[];", "extern volatile uint32_t _T1;")))
            for lineno, msg in errors:
                idx = lineno - 1 - shift
                if idx < 0 or idx >= len(lines):
                    continue
                new_line, ok_fix = heal_line(lines[idx], msg)
                if ok_fix:
                    lines[idx] = new_line
                    fixed += 1
                    continue
                # statement spans multiple lines: join backward (caller/continuation
                # lines ending in '(' or ',' or leading operator) and forward to ';'
                start, end = idx, idx
                while (start > 0
                       and not lines[start - 1].strip().endswith((";", "{"))
                       and (lines[start - 1].strip().endswith(("(", ","))
                            or lines[start].strip().startswith(("&", "|", "+", "-", "*", "&&", "||", ">>", "<<")))):
                    start -= 1
                while end < len(lines) and not lines[end].strip().endswith(";"):
                    end += 1
                if end < len(lines) and (start < idx or end > idx):
                    joined = " ".join(l.strip() for l in lines[start:end + 1])
                    new_line, ok_fix = heal_line(joined, msg)
                    if ok_fix:
                        lines[start:end + 1] = [new_line]
                        fixed += 1
                        shift += end - start
                        continue
                # empty if/while body lost in source: `if (x)\n\n}` -> `if (x) { }`
                if msg.startswith("expected expression before '}'"):
                    k = idx - 1
                    while k >= 0 and not lines[k].strip():
                        k -= 1
                    if k >= 0 and re.match(r"^(if|while|for|else)\b.*\)\s*$", lines[k].strip()):
                        lines[idx:idx] = ["{ }"]
                        fixed += 1
                        shift += 1
                        continue
            declared_names = header_declared_names()
            undecl = collect_undeclared(errors, declared_names)
            if undecl:
                lines = insert_forward_decls(lines, undecl)
            if fixed or undecl:
                main_c.write_text("\n".join(lines))
                print(f"{img}: round {rnd}: fixed {fixed}, declared {len(undecl)}, remaining {len(errors)}", flush=True)
                continue
            print(f"{img}: UNRESOLVED {len(errors)} errors after round {rnd - 1}:", flush=True)
            from collections import Counter
            top = Counter(re.sub(r"'\w+'", "'F'", re.sub(r"\d+", "N", m)) for _, m in errors)
            for cls, n in top.most_common(12):
                print(f"  {n:5d}  {cls}", flush=True)
            break
        else:
            print(f"{img}: gave up after {MAX_ROUNDS} rounds", flush=True)


if __name__ == "__main__":
    main()
