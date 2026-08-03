#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_10EADC;
extern uint32_t dword_10EAE0;
extern uint32_t dword_10EAE4;
extern uint32_t off_10EAE8;
extern uint32_t off_10EB00;
extern uint32_t dword_10EAEC;
extern uint32_t off_10EAF0;
extern uint32_t off_10EAFC;
extern uint32_t off_10EAF4;
extern uint32_t dword_10EAF8;

// sub_10E9D8 @ 0x10e9d8, size 260 bytes
int  sub_10E9D8(unsigned int *a1)
{
  uint32_t *v1; // r2
  int v2; // r7
  int v3; // r3
  uint32_t *v4; // r5
  uint32_t *v5; // r10
  int v6; // r6
  unsigned int *v7; // r4
  int *v8; // r1
  int v9; // r0
  unsigned int v10; // r9
  unsigned int v11; // r8
  unsigned int v12; // r7
  unsigned int v13; // r6
  int result; // r0
  uint32_t v16[2]; // [sp+Ch] [bp-Ch] BYREF
  int16_t v17; // [sp+14h] [bp-4h]

  v1 = off_10EADC;
  v2 = dword_10EAE0;
  v3 = dword_10EAE4;
  v4 = off_10EAE8;
  v5 = off_10EB00;
  v6 = dword_10EAEC;
  v7 = (unsigned int *)off_10EAF0;
  v17 = 0;
  *((uint32_t *)off_10EAFC + 14) = 296;
  v1[3] = v1[3] & 0xE0000000 | v2;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 2u;
  *v4 &= ~1u;
  v16[0] = v6;
  v16[1] = 5610;
  sub_102970((uint16_t *)v16, 0);
  v8 = (int *)off_10EAF4;
  v9 = dword_10EAF8;
  *v5 |= 0x80000000;
  *v8 = v9;
  v10 = *v7;
  v11 = *v7;
  v12 = *v7;
  v13 = *v7;
  *v7 &= ~0x80000u;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v7 |= 0x400000u;
  result = sub_10E6FC(4u, 8u, a1);
  *v5 &= ~0x80000000;
  *v4 &= ~2u;
  *v7 = v10 & 0x80000 | *v7 & 0xFFF7FFFF;
  *v7 = v11 & 0x100000 | *v7 & 0xFFEFFFFF;
  *v7 = v12 & 0x200000 | *v7 & 0xFFDFFFFF;
  *v7 = v13 & 0x400000 | *v7 & 0xFFBFFFFF;
  return result;
}

