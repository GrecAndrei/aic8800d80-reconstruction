/*
 * AIC8800D80 Firmware Reconstruction — Standard Types & Intrinsics Header
 */

#ifndef AIC8800D80_TYPES_H
#define AIC8800D80_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <inttypes.h>

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

/* Pseudo Registers & Condition Flags */
extern uint32_t _R0, _R1, _R2, _R3, _R4, _R5, _R6, _R7, _R8, _R9, _R10, _R11, _R12, _LR, _SP, _PC;
extern uint32_t _CF, _ZF, _NF, _OF, _VF;

#endif /* AIC8800D80_TYPES_H */
