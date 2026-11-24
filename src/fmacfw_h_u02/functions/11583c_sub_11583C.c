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
extern uint32_t off_115974;
extern uint32_t off_115978;
extern uint32_t off_11597C;
extern uint32_t off_115980;
extern uint32_t off_115984;
extern uint32_t off_115988;
extern uint32_t off_11598C;
extern uint32_t off_115990;
extern uint32_t off_115994;
extern uint32_t off_115998;
extern uint32_t off_11599C;
extern uint32_t off_1159A0;

// chip_revision_read @ 0x11583c, size 300 bytes
uint8_t *chip_revision_read()
{
  uint32_t *v0; // r4
  uint8_t *v1; // r5
  uint32_t *v2; // r2
  uint32_t *v3; // r2
  int *v4; // r1
  int v5; // r1
  uint32_t *v6; // r2
  uint32_t *v7; // r1
  uint8_t **v8; // r1
  int v9; // r3
  uint8_t *result; // r0
  int v11; // r2
  uint32_t *v12; // r3
  uint32_t *v13; // r3
  uint32_t *v14; // r3

  v0 = off_115968;
  v1 = off_11596C;
  *(uint8_t *)off_11596C = *(uint8_t *)off_115968 & 0xF;
  check_feature_flag(2, "d %d,", *v0 & 0xF);
  if ( *v0 << 28 )
  {
    v2 = off_115978;
    *(uint32_t *)off_115974 &= ~0x80000000;
    *v0 = 0;
    while ( (*v2 & 4) == 0 )
      ;
    v3 = off_115974;
    v4 = (int *)off_115980;
    *(uint32_t *)off_11597C = 4;
    v5 = *((uint8_t *)v4 + 189);
    *v3 |= 0x80000000;
    if ( v5 )
      *(uint32_t *)((char *)v3 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(uint32_t *)off_115990 &= ~0x8000000u;
  }
  v6 = off_115984;
  v7 = off_115968;
  *(uint32_t *)off_115984 |= 0x111u;
  v1[1] = 1;
  *v7 = 32;
  v8 = (uint8_t **)off_115988;
  *v6 &= 0xFFFFFEEE;
  v9 = **v8;
  if ( v9 == 3 )
  {
    v13 = off_115994;
    *(uint32_t *)off_115994 |= 1u;
    if ( (*v13 & 4) != 0 )
      *(uint32_t *)off_115998 = 512;
  }
  else if ( v9 == 1 )
  {
    mmio_read_bit13();
    v14 = off_1159A0;
    *(uint32_t *)off_11599C |= 0x20u;
    v14[20] |= 0x20000u;
    v14[20] |= 0x8000u;
    v14[20] |= 0x10000u;
    v14[20] = v14[20] & 0xFFFFFFC0 | 0x37;
    v14[23] = v14[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_11598C;
  v11 = 0;
  *(uint8_t *)off_11598C = 0;
  while ( 1 )
  {
    v12 = (uint32_t *)(4 * v11++ - 536813312);
    if ( (v12[64] & *v12) != 0 )
      break;
    if ( v11 == 3 )
      return result;
  }
  *result = 1;
  return result;
}
