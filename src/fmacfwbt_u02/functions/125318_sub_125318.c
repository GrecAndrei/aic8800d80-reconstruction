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

extern uint32_t dword_1254E0;
extern uint32_t off_1254DC;
extern uint32_t dword_1254C8;
extern uint32_t dword_1254CC;
extern uint32_t off_1254E4;
extern uint32_t dword_1254D0;
extern uint32_t dword_1254D4;
extern uint32_t dword_1254D8;

// bt_link_get @ 0x125318, size 432 bytes
int  bt_link_get(int result)
{
  int v1; // r9
  int v2; // r2
  int v3; // r3
  int v4; // r1
  int v5; // r2
  uint8_t *v6; // r3
  int v7; // r4
  uint32_t *v8; // r11
  int v9; // r2
  unsigned int v10; // r5
  int v11; // cc
  int v12; // r6
  uint8_t *v13; // r5
  uint8_t *v14; // lr
  unsigned int v15; // r12
  int v16; // r6
  unsigned int v17; // lr
  int v18; // r7
  int v19; // r8
  int v20; // r5
  unsigned int v21; // r7
  int v22; // r8
  unsigned int v23; // r8
  int v24; // r6
  int v25; // r12
  int v26; // r5
  int16_t v27; // r8
  int v28; // lr
  int v29; // [sp+0h] [bp-Ch]
  int v30; // [sp+4h] [bp-8h]

  v1 = dword_1254E0;
  v2 = 696 * (*(uint8_t *)(result + 107) + 32);
  v3 = dword_1254E0 + v2;
  v4 = dword_1254E0 + 40 + v2;
  while ( !*(uint32_t *)(v3 + 584) )
  {
    v5 = *(uint32_t *)(v3 + 624);
    v3 += 8;
    if ( v5 )
      break;
    if ( v3 == v4 )
      goto LABEL_5;
  }
  *(uint8_t *)off_1254DC = 1;
LABEL_5:
  v6 = (uint8_t *)dword_1254C8;
  v7 = dword_1254CC;
  v8 = off_1254E4;
  v9 = dword_1254C8 + 22272;
  do
  {
    while ( 1 )
    {
      if ( v6[5] && result == v7 + 1320 * v6[2] )
      {
        v10 = v6[3];
        v11 = v10 > 0x23;
        if ( v10 > 0x23 )
        {
          v12 = 0;
        }
        else
        {
          v12 = 696;
          v10 = v1 + 696 * v10;
        }
        if ( !v11 )
          v12 = *(uint32_t *)(v10 + 664);
        v13 = v6 - 32;
        v14 = v6 - 24;
        if ( !*((uint32_t *)v6 + 138) )
        {
          while ( !*((uint32_t *)v13 + 156) )
          {
            if ( v6 == v13 )
            {
              if ( 15000000 - v8[4] + v12 >= 0 )
                goto LABEL_6;
              break;
            }
            v13 = v14;
            v14 += 8;
            if ( *((uint32_t *)v13 + 146) )
              break;
          }
        }
        v15 = *v6;
        v29 = *(uint8_t *)(result + 107);
        v16 = dword_1254D0 + 252 * v29;
        v17 = v15 >> 3;
        v18 = 1 << (v15 & 7);
        v19 = *(uint8_t *)((v15 >> 3) + v16);
        v30 = v16 + (v15 >> 3);
        v20 = v29;
        if ( (v18 & v19) == 0 )
          break;
      }
LABEL_6:
      v6 += 696;
      if ( (uint8_t *)v9 == v6 )
        return result;
    }
    *(uint8_t *)(v17 + v16) = v18 | v19;
    v21 = *(uint8_t *)(result + 228);
    ++*(uint16_t *)(result + 220);
    if ( v21 > v17 )
    {
      LOWORD(v21) = v17 & 0x1E;
      v22 = dword_1254D4 + 40 * v29;
      v20 = v29;
      *(uint8_t *)(result + 228) = v17 & 0x1E;
      *(uint32_t *)(v22 + 28) = v16 + ((v15 >> 3) & 0x1E);
    }
    v23 = *(uint8_t *)(result + 229);
    v24 = 4 * v20;
    if ( v23 < v17 )
    {
      *(uint8_t *)(result + 229) = v17;
      *(uint32_t *)(dword_1254D4 + 8 * (v24 + v29) + 32) = v30;
      LOWORD(v23) = v15 >> 3;
    }
    v25 = dword_1254D8 + 8 * v29;
    v26 = dword_1254D4;
    v27 = v23 + 6 - v21;
    v28 = dword_1254D4 + 8 * (v24 + v29);
    *(uint16_t *)(result + 218) = v27;
    *(uint8_t *)(v25 + 1) = v27 - 2;
    v6 += 696;
    *(uint8_t *)(v25 + 4) = *(uint8_t *)(result + 228);
    *(uint32_t *)(v28 + 12) = v25 + 4;
    *(uint32_t *)(v28 + 4) = v26 + 40 * v29 + 20;
  }
  while ( (uint8_t *)v9 != v6 );
  return result;
}

