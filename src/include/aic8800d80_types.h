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

/* Hex-Rays Byte/Word Extract & Insert Macros */
#define LOBYTE(x)   ((uint8_t)((uintptr_t)(x) & 0xFF))
#define HIBYTE(x)   ((uint8_t)(((uintptr_t)(x) >> 8) & 0xFF))
#define LOWORD(x)   ((uint16_t)((uintptr_t)(x) & 0xFFFF))
#define HIWORD(x)   ((uint16_t)(((uintptr_t)(x) >> 16) & 0xFFFF))
#define LODWORD(x)  ((uint32_t)(uintptr_t)(x))
#define HIDWORD(x)  ((uint32_t)(((uint64_t)(uintptr_t)(x) >> 32)))
/* Hex-Rays BYTE1-4 / WORD1-2 byte-select macros (1-based, LSB = BYTE1) */
#define BYTE1(x)    ((uint8_t)((uintptr_t)(x) & 0xFF))
#define BYTE2(x)    ((uint8_t)(((uintptr_t)(x) >> 8) & 0xFF))
#define BYTE3(x)    ((uint8_t)(((uintptr_t)(x) >> 16) & 0xFF))
#define BYTE4(x)    ((uint8_t)(((uintptr_t)(x) >> 24) & 0xFF))
#define WORD1(x)    ((uint16_t)((uintptr_t)(x) & 0xFFFF))
#define WORD2(x)    ((uint16_t)(((uintptr_t)(x) >> 16) & 0xFFFF))
#define SHIBYTE(x)  ((int8_t)(((uintptr_t)(x) >> 8) & 0xFF))
#define SLOBYTE(x)  ((int8_t)((uintptr_t)(x) & 0xFF))
#define SHIWORD(x)  ((int16_t)(((uintptr_t)(x) >> 16) & 0xFFFF))
#define SLOWORD(x)  ((int16_t)((uintptr_t)(x) & 0xFFFF))
#define SHIDWORD(x) ((int32_t)(((uint64_t)(uintptr_t)(x) >> 32)))

/* Hex-Rays Pair & Shift Intrinsics */
#define __PAIR64__(high, low) (((uint64_t)(uint32_t)(high) << 32) | (uint32_t)(low))
#define __CFSHL__(x, y)       ((uint8_t)((((uint32_t)(uintptr_t)(x)) >> (32 - (y))) & 1))
#define __clz(x)              ((x) ? __builtin_clz(x) : 32)

static inline uint8_t __OFADD__(uint32_t a, uint32_t b) { return ((a + b) < a); }
static inline uint8_t __OFSUB__(uint32_t a, uint32_t b) { return (a < b); }

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
#define __und(...)     __asm__ volatile(".word 0xe7f000f0")
static inline uint32_t __rev16(uint32_t v) { return ((v & 0xFF00FF00u) >> 8) | ((v & 0x00FF00FFu) << 8); }
static inline uint32_t __rev(uint32_t v)   { return __builtin_bswap32(v); }
static inline uint32_t __usat(uint32_t v, int sat, int shift) { (void)sat; (void)shift; return v; }
static inline uint32_t bswap32(uint32_t v) { return __builtin_bswap32(v); }
static inline uint32_t abs16(int32_t v)    { return (uint32_t)(v < 0 ? -v : v); }
static inline uint32_t abs32(int32_t v)    { return (uint32_t)(v < 0 ? -v : v); }
static inline uint16_t _byteswap_ushort(uint16_t v) { return (uint16_t)((v >> 8) | (v << 8)); }
static inline uint32_t __ROR4__(uint32_t v, int n)  { return (v >> (n & 31)) | (v << ((32 - n) & 31)); }
static inline float COERCE_FLOAT(uint32_t v) { float f; __builtin_memcpy(&f, &v, sizeof(f)); return f; }
static inline uint32_t COERCE_UINT32(float f) { uint32_t v; __builtin_memcpy(&v, &f, sizeof(v)); return v; }
static inline float vcvts_n_s32_f32(int32_t v, int n) { return (float)v * (float)(1u << n); }
static inline float vcvts_n_f32_u32(uint32_t v, int n) { return (float)v * (float)(1u << n); }
static inline uint8_t __CFADD__(uint32_t a, uint32_t b) { return ((a + b) < a); }
static inline uint32_t MEMD(unsigned idx) { return (uint32_t)(uintptr_t)(0x100000u + idx * 4u); }
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

#endif /* AIC8800D80_TYPES_H */
