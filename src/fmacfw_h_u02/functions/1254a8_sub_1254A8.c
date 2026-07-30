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

extern uint32_t dword_1255E4;
extern uint32_t dword_1255F0;
extern uint32_t off_1255E8;
extern uint32_t off_1255EC;

// sub_1254A8 @ 0x1254a8, size 316 bytes
int  sub_1254A8(int a1)
{
  int v1; // r8
  uint8_t *v2; // r5
  char v4; // r7
  int v5; // r6
  int v6; // r0
  int v7; // r1
  int16_t v8; // r3
  int v9; // r3
  int v10; // r9
  char v11; // r7
  int v12; // r5
  int v13; // r3
  int v14; // r5
  int v15; // r0
  int v16; // r2
  int v17; // r3
  char v18; // r7
  uint8_t *v19; // r0

  v1 = *(uint32_t *)(a1 + 192);
  v2 = (uint8_t *)(dword_1255E4 + 8 * *(uint8_t *)(a1 + 107));
  v4 = v2[4];
  v5 = a1 + 116;
  v6 = sub_124FB4(a1);
  *(uint32_t *)(v1 + 36) = *(uint16_t *)(v6 + 216) + *(uint16_t *)(v6 + 218) + 4;
  if ( *(uint8_t *)(v6 + 1224) )
  {
    v15 = sub_12AA40(*(uint8_t *)(v6 + 1225));
    if ( v15 )
    {
      v16 = dword_1255F0 + 20 * *(uint8_t *)(a1 + 107);
      v17 = *(uint32_t *)(v16 + 8);
      *(uint32_t *)(v1 + 36) += v15;
      *(uint32_t *)(v16 + 12) = v15 + v17 - 1;
    }
  }
  v7 = *(uint32_t *)(v1 + 28);
  v8 = *((uint16_t *)off_1255E8 + 254) + 1;
  *((uint16_t *)off_1255E8 + 254) = v8;
  *(uint16_t *)(v7 + 22) = 16 * v8;
  v9 = *(uint8_t *)(a1 + 227);
  v2[2] = v9;
  v10 = *(uint8_t *)(a1 + 230);
  if ( v9 )
  {
    v10 &= 2u;
    if ( v10 )
    {
      v11 = v4 | 1;
      v10 = 1;
    }
    else
    {
      v11 = v4 & 0xFE;
    }
  }
  else
  {
    if ( *(uint8_t *)(a1 + 230) )
    {
      v11 = v4 | 1;
      v10 = 1;
    }
    else
    {
      v11 = v4 & 0xFE;
    }
    if ( *(uint8_t *)off_1255EC )
      v11 |= 1u;
    *(uint8_t *)(a1 + 227) = v2[3];
  }
  v2[4] = v11;
  v12 = *(uint8_t *)(a1 + 231);
  --*(uint8_t *)(a1 + 227);
  if ( v12 )
  {
    v13 = *(uint8_t *)(a1 + 232);
    v14 = (uint8_t)(v12 - 1);
    *(uint8_t *)(a1 + 231) = v14;
    if ( v13 )
    {
      *(uint8_t *)(*(uint32_t *)(v1 + 28) + v13) = v14;
      if ( *(uint8_t *)(a1 + 233) )
        *(uint8_t *)(*(uint32_t *)(v1 + 28) + *(uint8_t *)(a1 + 233)) = *(uint8_t *)(a1 + 231);
      v14 = *(uint8_t *)(a1 + 231);
    }
    if ( !v14
      || (v18 = *(uint8_t *)(a1 + 107),
          v19 = (uint8_t *)sub_12C7EC(78, 13, 0, 2),
          *v19 = v18,
          v19[1] = v14,
          sub_12C84C(v19),
          !*(uint8_t *)(a1 + 231)) )
    {
      *(uint8_t *)(a1 + 231) = 1;
    }
  }
  sub_12C3A8(a1, v5);
  return v10;
}

