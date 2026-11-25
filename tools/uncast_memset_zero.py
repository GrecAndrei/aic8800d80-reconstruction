"""Unwrap the spurious casted-strchr zero-fill calls.

Machine truth: 0x100200 is a byte-identical splat-fill memset in all four
images (see tools/libc_names.py), and the raw Hex-Rays units originally
emitted `memset(buf, 0, len)` for these zero-init-before-use idioms. The
pipeline broke them: heal_composed ran while the `memset` symbol was still
owned by the strchr body (the LLM one-slot shift), so the three-argument
call mismatched the two-argument prototype and was wrapped in a cast;
libc_names later swapped the names back, leaving `((int (*)())strchr)(buf,
0, len)` — a call that never writes memory.

strchr takes exactly two arguments; a three-argument call through the cast
can never be a genuine strchr. Combined with the zero middle argument these
sites are memset fills with certainty. The rewrite restores the plain call.
"""
import re, sys, os

CAST = "((int (*)())strchr)("

def args_of(text, start):
    """Return top-level-split args of the parenthesized list starting at
    text[start] == '(', plus the index just past the closing paren."""
    depth, cur, args, i = 0, [], [], start
    while i < len(text):
        ch = text[i]
        if ch == "(":
            depth += 1
            if depth > 1:
                cur.append(ch)
        elif ch == ")":
            depth -= 1
            if depth == 0:
                args.append("".join(cur).strip())
                return args, i + 1
            cur.append(ch)
        elif ch == "," and depth == 1:
            args.append("".join(cur).strip())
            cur = []
        else:
            cur.append(ch)
        i += 1
    return None, start

def process(path, check):
    text = open(path).read()
    out = []
    pos = 0
    total = 0
    while True:
        idx = text.find(CAST, pos)
        if idx < 0:
            out.append(text[pos:])
            break
        argstart = idx + len(CAST) - 1
        args, end = args_of(text, argstart)
        if args is not None and len(args) == 3 and args[1] == "0":
            total += 1
            out.append(text[pos:idx])
            out.append("memset" if not check else CAST)
            out.append(text[argstart:end])
            pos = end
        else:
            out.append(text[pos:argstart])
            pos = argstart
    if total and not check:
        open(path, "w").write("".join(out))
    return total

def main():
    check = "--check" in sys.argv
    total = 0
    for img in ("fmacfw_h_u02", "fmacfw_u02", "fmacfwbt_u02", "lmacfw_rf_u02"):
        path = f"src/{img}/main.c"
        if os.path.exists(path):
            n = process(path, check)
            if n:
                print(f"[uncast_memset_zero] {img}: {n} zero-fill call(s) {'pending' if check else 'restored'}")
            total += n
    return 1 if check and total else 0

if __name__ == "__main__":
    sys.exit(main())
