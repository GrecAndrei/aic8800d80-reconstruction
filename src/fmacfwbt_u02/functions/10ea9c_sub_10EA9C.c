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

extern uint32_t off_10EB9C;
extern uint32_t off_10EBA0;
extern uint32_t dword_10EBA4;
extern uint32_t dword_10EBA8;
extern uint32_t off_10EBBC;
extern uint32_t off_10EBAC;
extern uint32_t off_10EBC0;
extern uint32_t dword_10EBB0;
extern uint32_t off_10EBB4;
extern uint32_t dword_10EBB8;

// sub_10EA9C @ 0x10ea9c, size 256 bytes
int sub_10EA9C()
{
  unsigned int *v0; // r4
  uint32_t *v1; // r2
  int v2; // r0
  int v3; // r3
  uint32_t *v4; // r9
  uint32_t *v5; // r6
  uint32_t *v6; // r10
  int v7; // r5
  int *v8; // r2
  int v9; // r1
  unsigned int v10; // r8
  unsigned int v11; // r7
  unsigned int v12; // r6
  unsigned int v13; // r5
  int result; // r0
  uint32_t v15[2]; // [sp+4h] [bp-Ch] BYREF
  int16_t v16; // [sp+Ch] [bp-4h]

  v0 = (unsigned int *)off_10EB9C;
  v1 = off_10EBA0;
  v2 = dword_10EBA4;
  v3 = dword_10EBA8;
  v4 = off_10EBBC;
  v5 = off_10EBAC;
  v6 = off_10EBC0;
  v7 = dword_10EBB0;
  v16 = 0;
  *((uint32_t *)off_10EB9C + 14) = 296;
  v1[3] = v2 | v1[3] & 0xE0000000;
  v1[2] = v3 & v1[2] | 0x1200000D;
  *v4 |= 0x20000000u;
  *v5 &= ~1u;
  v15[0] = v7;
  v15[1] = 2442;
  sub_102898((uint16_t *)v15, 0);
  v8 = (int *)off_10EBB4;
  v9 = dword_10EBB8;
  v0 += 593954;
  *v6 |= 0x80000000;
  *v8 = v9;
  v10 = *v0;
  v11 = *v0;
  v12 = *v0;
  v13 = *v0;
  *v0 &= ~0x80000u;
  *v0 |= 0x100000u;
  *v0 |= 0x200000u;
  *v0 |= 0x400000u;
  result = mmio_field_set_n1d0(4);
  *v6 &= ~0x80000000;
  *v4 &= ~0x20000000u;
  *v0 = v10 & 0x80000 | *v0 & 0xFFF7FFFF;
  *v0 = v11 & 0x100000 | *v0 & 0xFFEFFFFF;
  *v0 = v12 & 0x200000 | *v0 & 0xFFDFFFFF;
  *v0 = v13 & 0x400000 | *v0 & 0xFFBFFFFF;
  return result;
}

