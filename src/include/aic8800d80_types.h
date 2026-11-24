/*
 * AIC8800D80 Firmware Reconstruction — Standard Types & Intrinsics Header
 */

#ifndef AIC8800D80_TYPES_H
#define AIC8800D80_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#if !defined(__STDC_HOSTED__) || __STDC_HOSTED__
#include <inttypes.h>
#endif

#ifndef nullptr
#define nullptr NULL
#endif

/* Hex-Rays legacy type aliases */
typedef int BOOL;

/* Hex-Rays base types (IDA decompiler output) */
typedef unsigned char _BYTE;
typedef unsigned short _WORD;
typedef unsigned int _DWORD;
typedef unsigned long long _QWORD;
typedef int _BOOL1;
typedef void _UNKNOWN;

/* Hex-Rays Byte/Word Extract Macros, with the meaning IDA's defs.h gives them:
 * BYTEn/WORDn count from 0 at the least significant end (BYTE1 is bits 8..15,
 * WORD1 bits 16..31, BYTE4 and WORD2 start at bit 32), and HIBYTE/HIWORD/
 * HIDWORD select the most significant unit of the operand's own type, so
 * HIBYTE of a 32-bit value is bits 24..31. Checked against the binary:
 * fmacfw_h is_scan_active @ 0x1016a8 computes HIBYTE(reg) as `lsrs r3, #24`
 * and BYTE2(reg) as `ubfx r2, r2, #16, #8`. A pointer operand is widened
 * through uintptr_t (GCC would sign-extend it otherwise). */
#define HX_U64(x)   ((uint64_t)__builtin_choose_expr(__builtin_classify_type(x) == 5, (uintptr_t)(x), (x)))
#define BYTEn(x, n) ((uint8_t)(HX_U64(x) >> (8 * (n))))
#define WORDn(x, n) ((uint16_t)(HX_U64(x) >> (16 * (n))))
#define LOBYTE(x)   BYTEn(x, 0)
#define HIBYTE(x)   BYTEn(x, sizeof(x) - 1)
#define LOWORD(x)   WORDn(x, 0)
#define HIWORD(x)   WORDn(x, sizeof(x) / 2 - 1)
#define LODWORD(x)  ((uint32_t)HX_U64(x))
#define HIDWORD(x)  ((uint32_t)(HX_U64(x) >> 32))
#define BYTE1(x)    BYTEn(x, 1)
#define BYTE2(x)    BYTEn(x, 2)
#define BYTE3(x)    BYTEn(x, 3)
#define BYTE4(x)    BYTEn(x, 4)
#define WORD1(x)    WORDn(x, 1)
#define WORD2(x)    WORDn(x, 2)
#define SHIBYTE(x)  ((int8_t)HIBYTE(x))
#define SLOBYTE(x)  ((int8_t)LOBYTE(x))
#define SHIWORD(x)  ((int16_t)HIWORD(x))
#define SLOWORD(x)  ((int16_t)LOWORD(x))
#define SHIDWORD(x) ((int32_t)HIDWORD(x))
#define SBYTE1(x)   ((int8_t)BYTE1(x))
#define SBYTE2(x)   ((int8_t)BYTE2(x))
#define SBYTE3(x)   ((int8_t)BYTE3(x))
#define SBYTE4(x)   ((int8_t)BYTE4(x))

/* Hex-Rays Pair & Shift Intrinsics */
#define __PAIR64__(high, low) (((uint64_t)(uint32_t)(high) << 32) | (uint32_t)(low))
#define __SPAIR64__(high, low) ((int64_t)__PAIR64__((high), (low)))
#define __CFSHL__(x, y)       ((uint8_t)((((uint32_t)(uintptr_t)(x)) >> (32 - (y))) & 1))
#define __clz(x)              ((x) ? __builtin_clz(x) : 32)

/* Signed overflow (the V flag) of a + b and a - b. */
static inline uint8_t __OFADD__(int32_t a, int32_t b) { int32_t r; return __builtin_add_overflow(a, b, &r); }
static inline uint8_t __OFSUB__(int32_t a, int32_t b) { int32_t r; return __builtin_sub_overflow(a, b, &r); }

/* ARM CPSR & IRQ Intrinsics Stub */
static inline uint32_t __get_CPSR(void) { return 0; }
static inline void __disable_irq(void) { __asm__ volatile("" ::: "memory"); }
static inline void __enable_irq(void) { __asm__ volatile("" ::: "memory"); }
static inline void __pld(const void *p) { (void)p; }

/* ARMv7-M Intrinsics (Hex-Rays output) */
#define __dsb(...)     __asm__ volatile("dsb" ::: "memory")
#define __isb(...)     __asm__ volatile("isb" ::: "memory")
#define __wfi(...)     __asm__ volatile("wfi")
#define __mcr(...)     __asm__ volatile("" ::: "memory")
#define __mrc(...)     0u
#define __cdp(...)     __asm__ volatile("" ::: "memory")
/* Hex-Rays __und(n) is the Thumb `udf #n` (0xDE00 | n; the firmware's assert
 * trap is udf #255 = 0xDEFF). The ARM-mode word used here before decoded in
 * Thumb as `lsls r0, r6, #3; b.n .-28`, a shift and a backward branch. */
#define __und(n)       __asm__ volatile(".inst.n 0xde00 + %c0" :: "i"(n))
static inline uint32_t __rev16(uint32_t v) { return ((v & 0xFF00FF00u) >> 8) | ((v & 0x00FF00FFu) << 8); }
static inline uint32_t __rev(uint32_t v)   { return __builtin_bswap32(v); }
/* ARM USAT as Hex-Rays prints it, __usat(bits, value): value clamped to
 * 0 .. 2^bits - 1 (gpio_mode_set stores the results in 3- and 4-bit fields). */
static inline uint32_t __usat(uint32_t bits, int32_t v) { int32_t max = (int32_t)((1u << bits) - 1u); return (uint32_t)(v < 0 ? 0 : v > max ? max : v); }
static inline uint32_t bswap32(uint32_t v) { return __builtin_bswap32(v); }
static inline uint32_t abs16(int32_t v)    { return (uint32_t)(v < 0 ? -v : v); }
static inline uint32_t abs32(int32_t v)    { return (uint32_t)(v < 0 ? -v : v); }
static inline uint16_t _byteswap_ushort(uint16_t v) { return (uint16_t)((v >> 8) | (v << 8)); }
static inline uint32_t __ROR4__(uint32_t v, int n)  { return (v >> (n & 31)) | (v << ((32 - n) & 31)); }
static inline float COERCE_FLOAT(uint32_t v) { float f; __builtin_memcpy(&f, &v, sizeof(f)); return f; }
static inline uint32_t COERCE_UINT32(float f) { uint32_t v; __builtin_memcpy(&v, &f, sizeof(v)); return v; }
static inline uint32_t COERCE_UNSIGNED_INT(float v) { uint32_t r; __builtin_memcpy(&r, &v, sizeof(r)); return r; }
static inline int32_t COERCE_INT(float v) { int32_t r; __builtin_memcpy(&r, &v, sizeof(r)); return r; }
static inline int32_t hx_slodword_f64(double v) { uint64_t u; __builtin_memcpy(&u, &v, sizeof(u)); return (int32_t)(uint32_t)u; }
#define SLODWORD(x) __builtin_choose_expr( \
    __builtin_types_compatible_p(__typeof__(x), float), \
    COERCE_INT(__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), float), (x), 0.0f)), \
    __builtin_choose_expr( \
        __builtin_types_compatible_p(__typeof__(x), double), \
        hx_slodword_f64(__builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), double), (x), 0.0)), \
        ((int32_t)LODWORD(x))))
static inline int32_t vcvts_n_s32_f32(float v, int n) {
    float s = v * (float)(1u << n);
    if (s != s) return 0;
    if (s >= 2147483648.0f) return 0x7fffffff;
    if (s <= -2147483648.0f) return (int32_t)0x80000000u;
    return (int32_t)s;
}
static inline float vcvts_n_f32_u32(uint32_t v, int n) { return (float)v / (float)(1u << n); }
static inline uint8_t __CFADD__(uint32_t a, uint32_t b) { return ((a + b) < a); }
/* Hex-Rays MEMORY[addr] / MEMD(addr) is a volatile dword access at the
 * absolute byte address addr (not a dword index and not image-relative). It
 * must remain an lvalue: assert paths write MEMORY[0], while the boot-ROM
 * callback thunks read low-memory vector slots such as 0x1b0 and 0x1fc. */
#define MEMD(idx) (*(volatile uint32_t *)(uintptr_t)(idx))
static inline uint32_t JUMPOUT(void) { return 0; }

/* Pseudo Registers & Condition Flags */
extern uint32_t _R0, _R1, _R2, _R3, _R4, _R5, _R6, _R7, _R8, _R9, _R10, _R11, _R12, _LR, _SP, _PC;
extern uint32_t _CF, _ZF, _NF, _OF, _VF;

/* Definitions (weak symbols so every image links; extern decl above matches) */
uint32_t _R0 = 0, _R1 = 0, _R2 = 0, _R3 = 0, _R4 = 0, _R5 = 0, _R6 = 0, _R7 = 0,
         _R8 = 0, _R9 = 0, _R10 = 0, _R11 = 0, _R12 = 0, _LR = 0, _SP = 0, _PC = 0;
uint32_t _CF = 0, _ZF = 0, _NF = 0, _OF = 0, _VF = 0;

/* Firmware memory image size: load base 0x100000, IDA LOAD extended to 0x200000 */
#define MEMORY_IMAGE_SIZE 0x100000

/* __zmask32 — 0xFF per byte lane that is zero (mechanical re-emission of the
   Hex-Rays UADD8/SEL word-scan asm: SEL Rd, Rn, R12 selects 0xFF into lanes
   whose UADD8 input byte was 0, i.e. Rd = Rn | __zmask32(input)). */
static inline uint32_t __zmask32(uint32_t w) {
	uint32_t m = 0;
	if (((w >> 0) & 0xFF) == 0) m |= 0xFFu;
	if (((w >> 8) & 0xFF) == 0) m |= 0xFFu << 8;
	if (((w >> 16) & 0xFF) == 0) m |= 0xFFu << 16;
	if (((w >> 24) & 0xFF) == 0) m |= 0xFFu << 24;
	return m;
}

#endif /* AIC8800D80_TYPES_H */
