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

extern uint32_t dword_116E34;
extern uint32_t off_116E30;
extern uint32_t dword_116E40;
extern uint32_t dword_116E3C;
extern uint32_t dword_116E38;
extern uint32_t dword_116E4C;
extern uint32_t dword_116E44;
extern uint32_t dword_116E48;
extern uint32_t off_116E28;
extern uint32_t dword_116E2C;

// sub_116C4C @ 0x116c4c, size 474 bytes
// Doc: sub_1216C4C [ipc]: Processes message buffer context struct
// sub_1216C4C [ipc]: Processes message buffer context struct
int  sub_116C4C(int a1, int a2, char a3)
{
  int v4; // r0
  int v5; // r8
  int v8; // r3
  int v9; // r4
  uint32_t *v10; // r2
  int *v12; // r3
  int v13; // r5
  int *v14; // r4
  int v15; // t1
  int v16; // r4
  int v17; // r5
  unsigned int v18; // r1
  int v19; // r2
  int v20; // r2
  int16_t **v21; // r6
  int v22; // r5
  uint16_t *v23; // r3
  int v24; // r3
  unsigned int v25; // r2
  int v26; // r0
  int v27; // r2
  unsigned int v28; // r2
  int *v29; // [sp+4h] [bp-4h]

  v4 = *(uint32_t *)(a1 + 36);
  v5 = *(uint32_t *)(a1 + 72);
  if ( (v4 & 0x200000) == 0 || (v4 & 0x380000) == 0x280000 )
  {
    v12 = *(int **)(a1 + 44);
    v13 = v5 + 40;
    v14 = v12;
    do
    {
      v15 = *v14++;
      *(uint32_t *)(v13 + 4) = v15;
      v13 += 4;
    }
    while ( v14 != v12 + 16 );
    if ( (*(uint16_t *)(a1 + 30) & 0x2000) != 0 )
    {
      v16 = *(uint32_t *)(dword_116E34 + 696 * *(uint8_t *)(a1 + 29) + 340);
      if ( **(int16_t **)off_116E30 >= 0 || v16 )
      {
        v17 = v5;
      }
      else
      {
        v29 = v12;
        sub_12F46C(dword_116E40, dword_116E3C, 475);
        v17 = *(uint32_t *)(a1 + 72);
        v12 = v29;
      }
      v18 = *(uint32_t *)(v16 + 156);
      *(uint32_t *)(v5 + 68) = v12[5];
      v19 = *(uint32_t *)(v16 + 160);
      *(uint32_t *)(v5 + 84) = v12[9];
      *(uint32_t *)(v5 + 64) = v18;
      *(uint32_t *)(v5 + 80) = v19;
      if ( ((v18 >> 11) & 5) == 5 )
      {
        v25 = v19 & 0xFFFCFFFF;
        if ( (v18 & 0x600) == 0x400 )
          v26 = 0x20000;
        else
          v26 = 0x10000;
        v27 = v25 | v26;
        if ( *(uint8_t *)(v16 + 165) )
          v28 = v27 | 0x40000;
        else
          v28 = v27 & 0xFFFBFFFF;
        *(uint32_t *)(v5 + 80) = v28;
      }
      if ( (v12[15] & 4) == 0 )
        *(uint32_t *)(v5 + 48) &= 0xFFFFFE7F;
      v5 = v17;
    }
  }
  *(uint8_t *)(v5 + 36) = a3;
  rf_phy_config_parse_n608(a1, a2);
  if ( *(uint16_t *)(a1 + 24) == 36488 )
    msg_parse(dword_116E38, 36488, *(uint32_t *)(*(uint32_t *)(a1 + 76) + 36));
  v8 = *(uint32_t *)(a1 + 8);
  v9 = *(uint32_t *)(a1 + 72);
  if ( v8 >= 0 || (v20 = *(uint16_t *)(a1 + 24), *(uint32_t *)(a1 + 84) = v8, v20 != 36488) )
  {
    if ( msg_get_value(6) == 6 )
      goto LABEL_24;
LABEL_7:
    v10 = *(uint32_t **)(a1 + 72);
    goto LABEL_8;
  }
  *(uint32_t *)(v9 + 60) = *(uint32_t *)(v9 + 60) & 0xFFFF00FF | 0xE00;
  if ( msg_get_value(6) != 6 )
    goto LABEL_7;
LABEL_24:
  v21 = (int16_t **)off_116E30;
  v22 = *(uint32_t *)(a1 + 76);
  if ( **(int16_t **)off_116E30 >= 0 )
  {
    v23 = *(uint16_t **)(v22 + 28);
    if ( v23 )
    {
LABEL_28:
      v10 = *(uint32_t **)(a1 + 72);
      goto LABEL_29;
    }
    goto LABEL_26;
  }
  v10 = *(uint32_t **)(a1 + 72);
  if ( !v10 )
  {
    sub_12F46C(dword_116E4C, dword_116E44, 518);
    v23 = *(uint16_t **)(v22 + 28);
    if ( v23 )
      goto LABEL_28;
    if ( **v21 >= 0 )
      goto LABEL_26;
    goto LABEL_41;
  }
  v23 = *(uint16_t **)(v22 + 28);
  if ( !v23 )
  {
LABEL_41:
    v24 = *(uint32_t *)(v22 + 24);
    if ( v24 )
      goto LABEL_27;
    sub_12F46C(dword_116E48, dword_116E44, 525);
LABEL_26:
    v24 = *(uint32_t *)(v22 + 24);
LABEL_27:
    v23 = *(uint16_t **)(v24 + 8);
    goto LABEL_28;
  }
LABEL_29:
  if ( (*v23 & 0xFC) == 0xB0 )
    *(uint32_t *)(v9 + 60) = *(uint32_t *)(v9 + 60) & 0xFFFF00FF | 0x1400;
LABEL_8:
  if ( *((uint8_t *)off_116E28 + 360) && (*(uint16_t *)(a1 + 30) & 8) == 0 && (*(uint32_t *)(a1 + 8) & 0x40000000) == 0 )
    *(uint8_t *)(v9 + 61) = *((uint8_t *)off_116E28 + 360);
  v10[4] = dword_116E2C;
  v10[2] = a1;
  v10[3] = a1;
  sub_116AB4(a1, a1, (int)v10, a2);
  return 0;
}

