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

extern uint32_t off_139D74;
extern uint32_t off_139D78;
extern uint32_t dword_139D84;
extern uint32_t dword_139D7C;
extern uint32_t off_139D80;
extern uint32_t dword_139D8C;
extern uint32_t dword_139D88;

// sub_139B4C @ 0x139b4c, size 550 bytes
// Doc: sub_1239B4C [unknown]: Function with extensive register save; loads struct from arg+0x1c, processes 16-bit header
// sub_1239B4C [unknown]: Function with extensive register save; loads struct from arg+0x1c, processes 16-bit header
int  sub_139B4C(int a1, int a2)
{
  int v2; // r7
  int16_t *v3; // r9
  int v4; // r6
  uint8_t *v7; // r8
  int v8; // r0
  int v10; // r10
  int16_t v11; // r0
  int v12; // r9
  int v13; // r11
  char v14; // r5
  int16_t v15; // r3^2
  uint16_t *v16; // r0
  int *v17; // r3
  char v18; // r3
  int v19; // [sp+10h] [bp-24h]
  int16_t v20; // [sp+16h] [bp-1Eh]
  unsigned int v21; // [sp+1Ch] [bp-18h]
  uint8_t v22; // [sp+24h] [bp-10h] BYREF
  char v23; // [sp+25h] [bp-Fh] BYREF
  int16_t v24; // [sp+26h] [bp-Eh] BYREF
  uint64_t v25; // [sp+28h] [bp-Ch] BYREF

  v2 = *(uint32_t *)(a1 + 28);
  v3 = *(int16_t **)(v2 + 8);
  v22 = 1;
  if ( (*v3 & 0x400) == 0 )
  {
    v4 = v3[11] & 0xF;
    if ( !v4 )
    {
      if ( a2 == 255 )
      {
        if ( (*(uint32_t *)(a1 + 84) & 0x600) != 0 )
        {
LABEL_31:
          v18 = -1;
        }
        else
        {
          v17 = *((int **)off_139D74 + 2);
          if ( v17 )
          {
            while ( *((uint16_t *)v17 + 50) != (uint16_t)v3[2]
                 || *((uint16_t *)v17 + 51) != (uint16_t)v3[3]
                 || *((uint16_t *)v17 + 52) != (uint16_t)v3[4] )
            {
              v17 = (int *)*v17;
              if ( !v17 )
                goto LABEL_31;
            }
            v18 = *((uint8_t *)v17 + 107);
          }
          else
          {
            v18 = -1;
          }
        }
        v7 = off_139D78;
        *((uint8_t *)off_139D78 + 10) = v18;
      }
      else if ( *((uint8_t *)off_139D74 + 16) == 255 )
      {
        v7 = off_139D78;
      }
      else
      {
        v7 = off_139D78;
        if ( (v3[2] & 1) == 0 )
        {
          v16 = (uint16_t *)(1320 * *((uint8_t *)off_139D78 + 10) + 100 + dword_139D84);
          if ( *v16 == (uint16_t)v3[2] && v16[1] == (uint16_t)v3[3] && v16[2] == (uint16_t)v3[4] )
            *((uint8_t *)off_139D78 + 10) = -1;
        }
      }
      if ( sub_13C5B4(off_139D78, v3, *(uint16_t *)(a1 + 48), &v22) )
      {
        v8 = v22;
      }
      else
      {
        v20 = *v3;
        v19 = (uint8_t)v7[8];
        v10 = *(uint16_t *)(a1 + 48);
        v21 = *(uint32_t *)(v2 + 8);
        v11 = *v3;
        v23 = 0;
        v24 = 255;
        v8 = parse_rx_frame_n688(v11, v10, v19, a2, (uint8_t *)dword_139D7C, v21, &v24, &v23);
        if ( v24 != 255 )
        {
          v12 = rf_bus_setup_n3a8(10240, v24, 10, (uint16_t)(v10 + 12));
          sub_101818(&v25, 0);
          v13 = v10;
          if ( !v23 )
          {
            if ( **(int16_t **)off_139D80 < 0 && v19 << 30 )
              sub_12F6C4(dword_139D8C, dword_139D88, 2608);
            v4 = v19;
            v13 = v10 - v19;
            v10 = (uint16_t)(v10 - v19);
          }
          *(uint16_t *)v12 = v10;
          sub_11E610(v2, v10, v4, v12 + 12);
          *(uint8_t *)(v12 + 8) = v7[10];
          *(uint8_t *)(v12 + 7) = a2;
          *(uint16_t *)(v12 + 2) = v20;
          v14 = *(uint8_t *)(a1 + 65);
          sub_101968();
          v15 = WORD1(v25);
          *(uint8_t *)(v12 + 6) = v25;
          *(uint8_t *)(v12 + 9) = v14;
          *(uint16_t *)(v12 + 4) = v15;
          sub_12CBB4(v12);
          if ( v24 == 4 )
            sub_1417CC(
              v21,
              v13,
              *(uint32_t *)(a1 + 52),
              *(uint16_t *)(v12 + 4),
              *(uint8_t *)(v12 + 6),
              *(char *)(v12 + 9),
              *(uint8_t *)(a1 + 61));
          return 0;
        }
        v22 = v8;
      }
      if ( v8 )
      {
        sub_138E1C(a1, 3);
        return 1;
      }
    }
  }
  return 0;
}

