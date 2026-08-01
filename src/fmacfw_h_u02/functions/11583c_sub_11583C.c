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

extern uint32_t off_115968;
extern uint32_t off_11596C;
extern uint32_t dword_115970;
extern uint32_t off_115978;
extern uint32_t off_115974;
extern uint32_t off_115980;
extern uint32_t off_11597C;
extern uint32_t off_115990;
extern uint32_t off_115984;
extern uint32_t off_115988;
extern uint32_t off_115994;
extern uint32_t off_115998;
extern uint32_t off_1159A0;
extern uint32_t off_11599C;
extern uint32_t off_11598C;

// chip_revision_read @ 0x11583c, size 300 bytes
uint8_t *chip_revision_read()
{
  uint32_t *v0; // r4
  uint8_t *v1; // r5
  int v2; // r1
  uint32_t *v3; // r2
  uint32_t *v4; // r2
  uint8_t *v5; // r1
  int v6; // r1
  uint32_t *v7; // r2
  uint32_t *v8; // r1
  uint8_t **v9; // r1
  int v10; // r3
  uint8_t *result; // r0
  int v12; // r2
  uint32_t *v13; // r3
  uint32_t *v14; // r3
  uint32_t *v15; // r3

  v0 = off_115968;
  v1 = off_11596C;
  v2 = dword_115970;
  *(uint8_t *)off_11596C = *(uint8_t *)off_115968 & 0xF;
  check_feature_flag(2, v2);
  if ( *v0 << 28 )
  {
    v3 = off_115978;
    *(uint32_t *)off_115974 &= ~0x80000000;
    *v0 = 0;
    while ( (*v3 & 4) == 0 )
      ;
    v4 = off_115974;
    v5 = (uint8_t *)off_115980;
    *(uint32_t *)off_11597C = 4;
    v6 = v5[189];
    *v4 |= 0x80000000;
    if ( v6 )
      *(uint32_t *)((char *)v4 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(uint32_t *)off_115990 &= ~0x8000000u;
  }
  v7 = off_115984;
  v8 = off_115968;
  *(uint32_t *)off_115984 |= 0x111u;
  v1[1] = 1;
  *v8 = 32;
  v9 = (uint8_t **)off_115988;
  *v7 &= 0xFFFFFEEE;
  v10 = **v9;
  if ( v10 == 3 )
  {
    v14 = off_115994;
    *(uint32_t *)off_115994 |= 1u;
    if ( (*v14 & 4) != 0 )
      *(uint32_t *)off_115998 = 512;
  }
  else if ( v10 == 1 )
  {
    mmio_read_bit13();
    v15 = off_1159A0;
    *(uint32_t *)off_11599C |= 0x20u;
    v15[20] |= 0x20000u;
    v15[20] |= 0x8000u;
    v15[20] |= 0x10000u;
    v15[20] = v15[20] & 0xFFFFFFC0 | 0x37;
    v15[23] = v15[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_11598C;
  v12 = 0;
  *(uint8_t *)off_11598C = 0;
  while ( 1 )
  {
    v13 = (uint32_t *)(4 * v12++ - 536813312);
    if ( (v13[64] & *v13) != 0 )
      break;
    if ( v12 == 3 )
      return result;
  }
  *result = 1;
  return result;
}

