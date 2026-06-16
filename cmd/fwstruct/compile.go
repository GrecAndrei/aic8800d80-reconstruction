package main

import (
	"bufio"
	"bytes"
	"flag"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"regexp"
	"sort"
	"strings"
)

// runCompile attempts to compile the v19 named C files.
// This is mostly to demonstrate the named C is at least somewhat coherent.
// We expect many warnings (cast sizes, etc.) but few hard errors.
func runCompile(args []string) error {
	fs := flag.NewFlagSet("compile", flag.ContinueOnError)
	var (
		decDir    string
		outDir    string
		image     string
		stubFile  string
		keepGoing bool
	)
	fs.StringVar(&decDir, "decompiled", "harness_v19_named/decompiled", "named C decompiled dir")
	fs.StringVar(&outDir, "out", "harness_v25/out/compiled", "output dir")
	fs.StringVar(&image, "image", "fmacfw_8800d80_h_u02_bin", "which image to compile")
	fs.StringVar(&stubFile, "stubs", "", "stub header file (auto-generated if empty)")
	fs.BoolVar(&keepGoing, "keep-going", false, "produce .o even if compile has errors")
	if err := fs.Parse(args); err != nil {
		return err
	}

	// Build stub header that declares all referenced globals
	stubs, err := buildStubs(filepath.Join(decDir, image))
	if err != nil {
		return err
	}
	stubPath := stubFile
	if stubPath == "" {
		stubPath = filepath.Join(outDir, image+"_stubs.h")
		if err := os.MkdirAll(outDir, 0o755); err != nil {
			return err
		}
		if err := os.WriteFile(stubPath, []byte(stubs), 0644); err != nil {
			return err
		}
	}
	fmt.Fprintf(os.Stderr, "compile: stubs written to %s\n", stubPath)

	// Concatenate all C files for this image
	imgDir := filepath.Join(decDir, image)
	files, err := filepath.Glob(filepath.Join(imgDir, "*.c"))
	if err != nil {
		return err
	}
	sort.Strings(files)
	if len(files) == 0 {
		return fmt.Errorf("no .c files in %s", imgDir)
	}

	// Build a single combined .c
	combined := filepath.Join(outDir, image+"_combined.c")
	var buf bytes.Buffer
	buf.WriteString("#include \"" + filepath.Base(stubPath) + "\"\n")
	for _, f := range files {
		b, err := os.ReadFile(f)
		if err != nil {
			continue
		}
		text := string(b)
		// Post-process: fix Hex-Rays artifacts that gcc won't accept
		// 1. "unsigned __int16" -> "unsigned short" (gcc understands but not as compound)
		text = strings.ReplaceAll(text, "unsigned __int16", "unsigned short")
		text = strings.ReplaceAll(text, "unsigned __int32", "unsigned int")
		text = strings.ReplaceAll(text, "unsigned __int64", "unsigned long long")
		text = strings.ReplaceAll(text, "unsigned __int8", "unsigned char")
		text = strings.ReplaceAll(text, "__int16", "short")
		text = strings.ReplaceAll(text, "__int32", "int")
		text = strings.ReplaceAll(text, "__int64", "long long")
		text = strings.ReplaceAll(text, "__int8", "char")
		// 2. __asm { ... } - replace with __asm__ __volatile__ (or just comment out)
		text = asmBlockRe.ReplaceAllString(text, "/* __asm__ block omitted */")
		// 3. dword_XYZ[0], byte_XYZ[0], word_XYZ[0] - dword is a scalar, can't subscript.
		// Hex-Rays treats it as both scalar and array; we collapse to scalar.
		text = dwordArrRe0.ReplaceAllString(text, "$1$2")
		// 4. dword_XYZ[N] with N != 0 - same issue. Replace with dword_XYZ (lossy).
		text = dwordArrReN.ReplaceAllString(text, "$1$2")
		buf.WriteString(text)
		buf.WriteString("\n")
	}
	if err := os.WriteFile(combined, buf.Bytes(), 0644); err != nil {
		return err
	}
	fmt.Fprintf(os.Stderr, "compile: combined %d files to %s\n", len(files), combined)

	// Try gcc
	objPath := filepath.Join(outDir, image+".o")
	cmd := exec.Command("gcc",
		"-c",
		"-w",                  // suppress warnings
		"-fpermissive",        // accept type mismatches
		"-Wno-error",          // don't make warnings into errors
		"-Wno-int-conversion", // don't warn on int->ptr conversions
		"-Wno-int-to-pointer-cast",
		"-Wno-pointer-to-int-cast",
		"-Wno-incompatible-pointer-types",
		"-Wno-error=implicit-function-declaration",
		"-Wno-error=incompatible-pointer-types",
		"-Wno-implicit-function-declaration",
		"-I"+filepath.Dir(stubPath),
		"-o", objPath,
		combined,
	)
	out, err := cmd.CombinedOutput()
	if err != nil {
		// Show first 20 lines of error
		lines := strings.Split(string(out), "\n")
		// Count actual errors
		nErrors := 0
		for _, l := range lines {
			if strings.Contains(l, ": error:") {
				nErrors++
			}
		}
		fmt.Fprintf(os.Stderr, "compile: %d errors, first 20 lines:\n", nErrors)
		for i, l := range lines {
			if i >= 20 {
				break
			}
			fmt.Fprintln(os.Stderr, l)
		}
		// Check if .o was produced anyway
		if _, statErr := os.Stat(objPath); statErr == nil {
			fmt.Fprintf(os.Stderr, "compile: %s produced (%d KB)\n", objPath, getSize(objPath)/1024)
			return nil
		}
		return fmt.Errorf("compile failed: %v", err)
	}
	fmt.Fprintf(os.Stderr, "compile: %s -> %s OK\n", combined, objPath)
	return nil
}

// varRe matches off_XXXXX, dword_XXXXX, byte_XXXXX, word_XXXXX references.
var asmBlockRe = regexp.MustCompile(`(?s)__asm\s*\{[^}]*\}`)
var subRefRe = regexp.MustCompile(`\bsub_[0-9A-Fa-f]{6,8}\b`)
var varRe = regexp.MustCompile(`\b(off_|dword_|byte_|word_|qword_|loc_|unk_|flt_)([0-9A-Fa-f]{6,8})\b`)

// fixForwardDeclTypes normalizes Hex-Rays type spellings in forward decls.
// Hex-Rays emits "unsigned __int8" which gcc rejects, and various forms
// that aren't valid C. We rewrite to canonical forms.
func fixForwardDeclTypes(sig string) string {
	// Order matters: do compound types first
	sig = strings.ReplaceAll(sig, "unsigned __int64", "unsigned long long")
	sig = strings.ReplaceAll(sig, "unsigned __int32", "unsigned int")
	sig = strings.ReplaceAll(sig, "unsigned __int16", "unsigned short")
	sig = strings.ReplaceAll(sig, "unsigned __int8", "unsigned char")
	// Replace " __intN" (with leading space) too
	sig = strings.ReplaceAll(sig, " __int64", " long long")
	sig = strings.ReplaceAll(sig, " __int32", " int")
	sig = strings.ReplaceAll(sig, " __int16", " short")
	sig = strings.ReplaceAll(sig, " __int8", " char")
	// "char __intN" - rare
	sig = strings.ReplaceAll(sig, "char __int64", "long long")
	sig = strings.ReplaceAll(sig, "char __int32", "int")
	sig = strings.ReplaceAll(sig, "char __int16", "short")
	sig = strings.ReplaceAll(sig, "char __int8", "char")
	return sig
}
// dwordArrRe0 matches dword_XYZ[0] / byte_XYZ[0] / word_XYZ[0] / unk_XYZ[0]
// Captures the name only, replacement drops the [0]
var dwordArrRe0 = regexp.MustCompile(`\b(dword_|byte_|word_|unk_)([0-9A-Fa-f]{6,8})\[0\]`)
// dwordArrReN matches dword_XYZ[N] where N != 0
var dwordArrReN = regexp.MustCompile(`\b(dword_|byte_|word_|unk_)([0-9A-Fa-f]{6,8})\[[^0][^\]]*\]`)

func buildStubs(imgDir string) (string, error) {
	files, err := filepath.Glob(filepath.Join(imgDir, "*.c"))
	if err != nil {
		return "", err
	}
	// First pass: find all defined function names AND all sub_ references
	defined := make(map[string]string) // name -> full signature
	subRefs := make(map[string]bool)
	funcDefRe2 := regexp.MustCompile(`^(unsigned\s+(?:int|long|short|char)|int|void|char|float|double|long|short|__int8|__int16|__int32|__int64)\s+__fastcall?\s+(\w+)\s*\(`)
	subRefRe2 := regexp.MustCompile(`\bsub_([0-9A-Fa-f]{6,8})\b`)
	for _, f := range files {
		fh, err := os.Open(f)
		if err != nil {
			continue
		}
		sc := bufio.NewScanner(fh)
		sc.Buffer(make([]byte, 1<<16), 1<<20)
		for sc.Scan() {
			line := sc.Text()
			m := funcDefRe2.FindStringSubmatchIndex(line)
			if m == nil {
				continue
			}
			// m[0],m[1] is the FULL match (up to first "("). Extend to matching close paren.
			start := m[0]
			depth := 0
			end := -1
			for i := m[1] - 1; i < len(line); i++ { // m[1]-1 is the "(" position
				if line[i] == '(' {
					depth++
				} else if line[i] == ')' {
					depth--
					if depth == 0 {
						end = i + 1
						break
					}
				}
			}
			if end < 0 {
				continue
			}
			// Extract function name from group 2
			nameStart := m[4]
			nameEnd := m[5]
			defined[line[nameStart:nameEnd]] = line[start:end]
		}
		fh.Close()
	}
	// Second pass: find all sub_ references - track both lowercased and exact case
	// C is case-sensitive so "sub_12D6E0" != "sub_12d6e0"
	subRefsCase := make(map[string]bool)
	for _, f := range files {
		b, err := os.ReadFile(f)
		if err != nil {
			continue
		}
		for _, m := range subRefRe2.FindAllStringSubmatch(string(b), -1) {
			subRefs[strings.ToLower(m[1])] = true
			subRefsCase[m[1]] = true
		}
	}
	globals := make(map[string]string) // name -> suggested declaration
	globals["_BYTE"] = "typedef unsigned char _BYTE;"
	globals["_WORD"] = "typedef unsigned short _WORD;"
	globals["_DWORD"] = "typedef unsigned int _DWORD;"
	globals["_QWORD"] = "typedef unsigned long long _QWORD;"
	globals["__fastcall"] = "#define __fastcall"
	globals["__noreturn"] = "#define __noreturn"
	for _, f := range files {
		fh, err := os.Open(f)
		if err != nil {
			continue
		}
		sc := bufio.NewScanner(fh)
		sc.Buffer(make([]byte, 1<<16), 1<<20)
		for sc.Scan() {
			line := sc.Text()
			matches := varRe.FindAllStringSubmatch(line, -1)
			// Skip sub_ stubs - implicit int() decl is enough
			for _, m := range matches {
				name := m[0]
				prefix := m[1]
				_ = prefix
				_ = m[2]
				if _, ok := globals[name]; !ok {
					// Suggest a declaration.
					// dword_/byte_/word_/unk_ are SCALARS. Source-rewrite handles dword_X[0] -> dword_X.
					// Most code uses dword_X + N (int + scalar) or dword_X = Y (assign to scalar).
					// Real code would use actual MMIO mappings; this is a best-effort stub.
					if strings.HasPrefix(prefix, "off_") || strings.HasPrefix(prefix, "qword_") {
						globals[name] = "int (*" + name + ")(void) = (int (*)(void))0;"
					} else if strings.HasPrefix(prefix, "dword_") {
						globals[name] = "unsigned int " + name + " = 0;"
					} else if strings.HasPrefix(prefix, "word_") {
						globals[name] = "unsigned short " + name + " = 0;"
					} else if strings.HasPrefix(prefix, "byte_") {
						globals[name] = "unsigned char " + name + " = 0;"
					} else if strings.HasPrefix(prefix, "loc_") {
						// Skip loc_ - those are code labels, not data
					} else if strings.HasPrefix(prefix, "unk_") {
						globals[name] = "unsigned int " + name + " = 0;"
					} else if strings.HasPrefix(prefix, "flt_") {
						globals[name] = "double " + name + " = 0.0;"
					}
				}
			}
		}
		fh.Close()
	}
	// Add __read* / __write* / __cpuid / etc. stubs
	var sb strings.Builder
	sb.WriteString(`// Auto-generated stubs for Hex-Rays C compilation
// This file declares all globals referenced by the v19 decompiled C
// to allow a "best-effort" compile of the named functions.

#include <stdint.h>
#include <stddef.h>

// MSVC types
typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned long long _QWORD;
typedef char __int8;
typedef short __int16;
typedef int __int32;
typedef long long __int64;
#define __fastcall
#define __noreturn

// Hex-Rays flag variables (compile-time, always 0)
#define _VF 0
#define _CF 0
#define _ZF 0
#define _NF 0
#define _OF 0

// Hex-Rays register variables (lvalues - can be assigned)
int _R0, _R1, _R2, _R3, _R4, _R5, _R6, _R7;
int _R8, _R9, _R10, _R11, _R12, _R13, _R14, _R15;

// MSVC intrinsics - all return 0 / no-op
#define __readfsbyte(x) ((unsigned char)0)
#define __readfsword(x) ((unsigned short)0)
#define __readfsdword(x) ((unsigned int)0)
#define __readfsqword(x) ((unsigned long long)0)
#define __readgsbyte(x) ((unsigned char)0)
#define __readgsword(x) ((unsigned short)0)
#define __readgsdword(x) ((unsigned int)0)
#define __readgsqword(x) ((unsigned long long)0)
#define __writefsbyte(x, y) ((void)0)
#define __writefsword(x, y) ((void)0)
#define __writefsdword(x, y) ((void)0)
#define __writefsqword(x, y) ((void)0)
#define __writegsbyte(x, y) ((void)0)
#define __writegsword(x, y) ((void)0)
#define __writegsdword(x, y) ((void)0)
#define __writegsqword(x, y) ((void)0)
#define __debugbreak() ((void)0)
#define __cpuid(a, b) ((void)0)
#define __cpuidex(a, b, c) ((void)0)
static inline unsigned char __inbyte(unsigned short x) { (void)x; return 0; }
static inline unsigned short __inword(unsigned short x) { (void)x; return 0; }
static inline unsigned int __indword(unsigned short x) { (void)x; return 0; }
static inline void __outbyte(unsigned short x, unsigned char y) { (void)x; (void)y; }
static inline void __outword(unsigned short x, unsigned short y) { (void)x; (void)y; }
static inline void __outdword(unsigned short x, unsigned int y) { (void)x; (void)y; }
static inline void __stosb(unsigned char *a, unsigned char b, size_t c) { (void)a; (void)b; (void)c; }
static inline void __stosw(unsigned short *a, unsigned short b, size_t c) { (void)a; (void)b; (void)c; }
static inline void __stosd(unsigned int *a, unsigned int b, size_t c) { (void)a; (void)b; (void)c; }
static inline void __stosq(unsigned long long *a, unsigned long long b, size_t c) { (void)a; (void)b; (void)c; }
static inline void __movsb(unsigned char *a, unsigned char *b, size_t c) { (void)a; (void)b; (void)c; }
static inline void __movsw(unsigned short *a, unsigned short *b, size_t c) { (void)a; (void)b; (void)c; }
static inline void __movsd(unsigned int *a, unsigned int *b, size_t c) { (void)a; (void)b; (void)c; }
static inline void __movsq(unsigned long long *a, unsigned long long *b, size_t c) { (void)a; (void)b; (void)c; }
static inline long _InterlockedExchange(volatile long *a, long b) { (void)a; return b; }
static inline long _InterlockedExchangeAdd(volatile long *a, long b) { (void)a; return b; }
static inline long _InterlockedCompareExchange(volatile long *a, long b, long c) { (void)a; (void)b; (void)c; return 0; }
static inline long _InterlockedDecrement(volatile long *a) { (void)a; return 0; }
static inline long _InterlockedIncrement(volatile long *a) { (void)a; return 0; }
static inline void *_ReturnAddress(void) { return (void *)0; }
static inline void *_AddressOfReturnAddress(void) { return (void *)0; }

// BOOL and other Windows types
typedef int BOOL;
typedef long LONG;
typedef unsigned long ULONG;
typedef unsigned short USHORT;
typedef unsigned char UCHAR;
typedef unsigned int UINT;
typedef unsigned long long ULONG_PTR;
typedef long long LONG_PTR;
typedef char CHAR;
typedef short SHORT;

// Byte manipulation macros (Hex-Rays uses these)
#define LOBYTE(x) (*(unsigned char *)&(x))
#define HIBYTE(x) (*((unsigned char *)&(x)+1))
#define LOWORD(x) (*(unsigned short *)&(x))
#define HIWORD(x) (*((unsigned short *)&(x)+1))
#define LODWORD(x) (*(unsigned int *)&(x))
#define HIDWORD(x) (((unsigned int *)&(x))[1])
// But these need lvalues. For rvalues, we need:
// Actually LOBYTE(v7) = v20 is a byte write to v7's low byte. 
// That's only valid if v7 is a small type. Hex-Rays uses this incorrectly
// for int. We need to suppress these errors.

// __readcr etc
static inline unsigned long __readcr0(void) { return 0; }
static inline unsigned long __readcr2(void) { return 0; }
static inline unsigned long __readcr3(void) { return 0; }
static inline unsigned long __readcr4(void) { return 0; }
static inline void __writecr0(unsigned long x) { (void)x; }
static inline void __writecr3(unsigned long x) { (void)x; }
static inline void __writecr4(unsigned long x) { (void)x; }

// mulhi
static inline long __mulh(long a, long b) { (void)a; (void)b; return 0; }
static inline unsigned long __umulh(unsigned long a, unsigned long b) { (void)a; (void)b; return 0; }
static inline long __mulhi(long a, long b) { (void)a; (void)b; return 0; }
static inline unsigned long __umulhi(unsigned long a, unsigned long b) { (void)a; (void)b; return 0; }

// wbinvd, invlpg, etc
static inline void __wbinvd(void) {}
static inline void __invlpg(void *a) { (void)a; }

// Bit manipulation intrinsics
static inline unsigned char _bittest(long const *a, long b) { (void)a; (void)b; return 0; }
static inline unsigned char _bittestandset(long *a, long b) { (void)a; (void)b; return 0; }
static inline unsigned char _bittestandreset(long *a, long b) { (void)a; (void)b; return 0; }
static inline unsigned char _bittestandcomplement(long *a, long b) { (void)a; (void)b; return 0; }
static inline unsigned char _bittest64(__int64 const *a, __int64 b) { (void)a; (void)b; return 0; }
static inline unsigned char _bittestandset64(__int64 *a, __int64 b) { (void)a; (void)b; return 0; }
static inline unsigned char _bittestandreset64(__int64 *a, __int64 b) { (void)a; (void)b; return 0; }

// __readpmc, __rdtsc
static inline unsigned long long __readpmc(unsigned long a) { (void)a; return 0; }
static inline unsigned long long __rdtsc(void) { return 0; }


`)

	// Emit forward decls for all defined functions (sort for stable output).
	// We capture the full signature (up to matching close paren) so the
	// forward decl matches the actual function definition. This prevents
	// gcc's "conflicting types" and "too many arguments" errors.
	var fnames []string
	for k := range defined {
		fnames = append(fnames, k)
	}
	sort.Strings(fnames)
	sb.WriteString("// === Forward declarations for defined functions ===\n")
	for _, k := range fnames {
		rawSig := defined[k]
		// Find matching close paren
		depth := 0
		end := -1
		for i := 0; i < len(rawSig); i++ {
			if rawSig[i] == '(' {
				depth++
			} else if rawSig[i] == ')' {
				depth--
				if depth == 0 {
					end = i + 1
					break
				}
			}
		}
		if end < 0 {
			continue
		}
		sig := rawSig[:end]
		// Strip __fastcall/__noreturn
		sig = strings.ReplaceAll(sig, "__fastcall", "")
		sig = strings.ReplaceAll(sig, "__noreturn", "")
		sig = strings.TrimSpace(sig)
		// Collapse extra whitespace
		sig = strings.Join(strings.Fields(sig), " ")
		fmt.Fprintf(&sb, "%s;\n", fixForwardDeclTypes(sig))
	}
	// Build a case-insensitive view of `defined` to check for sub_ coverage
	definedLower := make(map[string]bool)
	for k := range defined {
		definedLower[strings.ToLower(k)] = true
	}
	// Emit forward decls for all referenced sub_ funcs
	// Need to emit BOTH lowercase and the original case (C is case-sensitive)
	// Skip sub_ funcs that are already defined (have proper signature in `defined` map)
	var subs []string
	for k := range subRefs {
		if !definedLower["sub_"+k] {
			subs = append(subs, k)
		}
	}
	sort.Strings(subs)
	var subsCase []string
	for k := range subRefsCase {
		if !definedLower["sub_"+strings.ToLower(k)] {
			subsCase = append(subsCase, k)
		}
	}
	sort.Strings(subsCase)
	sb.WriteString("// === Forward declarations for referenced sub_ funcs (not defined locally) ===\n")
	for _, k := range subs {
		// Emit as int() so calls work (lowercase form)
		fmt.Fprintf(&sb, "int sub_%s(void);\n", k)
	}
	for _, k := range subsCase {
		if k == strings.ToLower(k) {
			continue // already emitted above
		}
		// Emit the exact case used in source
		fmt.Fprintf(&sb, "int sub_%s(void);\n", k)
	}
	sb.WriteString("// === Globals ===\n")
	// Sort globals for stable output
	var keys []string
	for k := range globals {
		keys = append(keys, k)
	}
	sort.Strings(keys)
	for _, k := range keys {
		if strings.HasPrefix(k, "_") && (k == "_BYTE" || k == "_WORD" || k == "_DWORD" || k == "_QWORD") {
			continue
		}
		if k == "__fastcall" || k == "__noreturn" {
			continue
		}
		sb.WriteString(globals[k] + "\n")
	}
	return sb.String(), nil
}


func getSize(p string) int64 {
	fi, err := os.Stat(p)
	if err != nil {
		return 0
	}
	return fi.Size()
}
