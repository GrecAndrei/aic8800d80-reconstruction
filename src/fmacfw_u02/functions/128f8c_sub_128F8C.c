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

extern uint32_t off_129158;
extern uint32_t dword_129154;
extern uint32_t off_12915C;
extern uint32_t off_129170;
extern uint32_t off_12916C;
extern uint32_t dword_129174;
extern uint32_t off_129160;
extern uint32_t off_129168;
extern uint32_t off_129164;
extern uint32_t off_129178;

// sub_128F8C @ 0x128f8c, size 454 bytes
// Doc: sub_1228F8C [mac]: Processes command structure, reads byte at offset 0x74 with size 0x2b8
// sub_1228F8C [mac]: Processes command structure, reads byte at offset 0x74 with size 0x2b8
unsigned int  sub_128F8C(unsigned int result, int a2, int a3)
{
  int v3; // r3
  uint32_t *v4; // r7
  int v6; // r2
  int v7; // r12
  unsigned int v8; // r6
  unsigned int v9; // r5
  uint8_t *v10; // r8
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r1
  uint8_t *v15; // r5
  uint32_t *v16; // r3
  int v17; // r3
  int v18; // r1
  int v19; // r0
  uint8_t *v20; // r5
  uint32_t *v21; // r2
  int v22; // r1
  int v23; // r0
  int v24; // r3

  v3 = *(uint8_t *)(a3 + 116);
  v4 = off_129158;
  v6 = *(uint32_t *)(a3 + 4);
  v7 = *(uint8_t *)off_129158;
  v8 = *(uint16_t *)(dword_129154 + 696 * v3 + 32);
  *(uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFE;
  v9 = result;
  if ( v7 )
  {
    if ( result )
    {
      if ( *(uint8_t *)(a3 + 114) )
      {
        v10 = (uint8_t *)(result + 4);
      }
      else
      {
        v10 = (uint8_t *)(result + 4);
        if ( ((*(uint8_t *)((*(uint8_t *)(a3 + 117) >> 3) + result + 4) >> (*(uint8_t *)(a3 + 117) & 7))
            & 1) != 0 )
        {
          v16 = off_12915C;
          *(uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC | 2;
          if ( (*v16 & 0x200) != 0 )
            *v16 &= ~0x200u;
          if ( !*((uint8_t *)v4 + 29) )
          {
            v17 = *((uint32_t *)off_129170 + 4);
            v18 = *(uint16_t *)(*(uint32_t *)off_12916C + 56);
            v19 = dword_129174;
            v4[5] = a3;
            *((uint8_t *)v4 + 29) = 5;
            timestamp_update(v19, v18 + v17);
          }
        }
        else
        {
          *(uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC;
        }
      }
      v11 = *v10 & 0xFE;
      result = v8 >> 3;
      if ( v11 <= v8 >> 3
        && result <= *(uint8_t *)(v9 + 1) - 4 + v11
        && (result += v9, (*(uint8_t *)(result - v11 + 5) & (1 << (v8 & 7))) != 0) )
      {
        if ( (*(uint32_t *)off_12915C & 0x200) != 0 )
          *(uint32_t *)off_12915C &= ~0x200u;
        if ( !*(uint8_t *)off_129160 )
        {
          sub_128EA0();
          if ( !*((uint8_t *)v4 + 28) || (*(uint32_t *)off_129168 & 4) != 0 )
          {
            *(uint8_t *)off_129164 = 0;
          }
          else
          {
            v20 = off_129164;
            if ( *(uint8_t *)off_129164 && (sub_1228E8() != 1 || !*((uint32_t *)off_129178 + 126)) )
              sub_118DC4(*(uint8_t *)(a3 + 116), 0, 0);
            *v20 = 1;
          }
          v21 = off_129170;
          v22 = *(uint16_t *)(*(uint32_t *)off_12916C + 58);
          v23 = dword_129174;
          *(uint32_t *)(a3 + 4) |= 4u;
          v24 = v21[4];
          v4[5] = a3;
          *((uint8_t *)v4 + 29) = 6;
          return timestamp_update(v23, v22 + v24);
        }
      }
      else
      {
        v12 = *(uint32_t *)(a3 + 4) & 0xFFFFFFFB;
        *(uint8_t *)off_129164 = 0;
        *(uint32_t *)(a3 + 4) = v12;
      }
    }
  }
  else if ( result
         && (*(uint32_t *)off_129168 & 4) == 0
         && (v13 = *(uint8_t *)(result + 4) & 0xFE, v14 = v8 >> 3, v13 <= v8 >> 3)
         && v14 <= *(uint8_t *)(result + 1) - 4 + v13
         && (*(uint8_t *)(result + v14 - v13 + 5) & (1 << (v8 & 7))) != 0 )
  {
    v15 = off_129164;
    if ( *(uint8_t *)off_129164 )
    {
      result = sub_1228E8();
      if ( result != 1 || !*((uint32_t *)off_129178 + 126) )
        result = sub_118DC4(*(uint8_t *)(a3 + 116), 0, 0);
    }
    *v15 = 1;
  }
  else
  {
    *(uint8_t *)off_129164 = 0;
  }
  return result;
}

