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

extern uint32_t off_115108;
extern uint32_t off_115128;
extern uint32_t off_115114;
extern uint32_t dword_11511C;
extern uint32_t off_115120;
extern uint32_t dword_115124;
extern uint32_t off_11510C;
extern uint32_t off_115110;
extern uint32_t off_115118;

// sub_115020 @ 0x115020, size 230 bytes
int sub_115020()
{
  int v0; // r4
  uint32_t *v1; // r3
  uint32_t *v2; // r2
  uint32_t *v3; // r3
  uint32_t *v4; // r3
  int v6; // r1
  int v7; // r1
  uint32_t *v8; // r2

  if ( **(uint8_t **)off_115108 == 2 )
  {
    if ( sub_112C9C() )
      v0 = *((uint32_t *)off_115128 + 87);
    else
      v0 = 16;
    sub_1129E8();
    *((uint32_t *)off_115114 + 34) = 1;
    __dsb(0xFu);
    __isb(0xFu);
    sub_12EA88(dword_11511C, v6, 1);
    v8 = off_115120;
    *((uint32_t *)off_115120 + 513) |= 2u;
    v8[4] |= 1u;
    while ( (v8[4] & 1) != 0 )
      ;
    sub_12EA88(dword_115124, v7, v8);
  }
  else
  {
    v0 = 16;
  }
  v1 = off_11510C;
  if ( (*((uint32_t *)off_11510C + 74) & 0x80) != 0 )
  {
    v2 = off_115110;
    *((uint32_t *)off_11510C + 74) = 128;
    if ( (v2[1] & 0x20000) != 0 )
    {
      v1[65] = 2;
      v2[1] &= ~0x20000u;
      v2[1] |= 0x40000u;
    }
  }
  v3 = off_115110;
  if ( (*((uint32_t *)off_115110 + 2) & 0x20000) != 0 )
  {
    *((uint32_t *)off_11510C + 65) = 8;
    v3[2] &= ~0x20000u;
    v3[2] |= 0x40000u;
  }
  v4 = off_115114;
  *((uint32_t *)off_115114 + 34) = 2;
  __dsb(0xFu);
  __isb(0xFu);
  v4[34] = 1;
  __dsb(0xFu);
  __isb(0xFu);
  sub_10D784();
  if ( *(uint8_t *)(*(uint32_t *)off_115118 + 3) )
    sub_1146F0();
  __disable_irq();
  return v0;
}

