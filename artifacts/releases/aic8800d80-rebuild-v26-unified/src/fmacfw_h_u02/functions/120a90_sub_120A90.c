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

extern uint32_t off_120E14;
extern uint32_t off_120D9C;
extern uint32_t off_120E18;
extern uint32_t off_120DA0;
extern uint32_t off_120DA4;
extern uint32_t off_120E1C;
extern uint32_t off_120DA8;
extern uint32_t off_120DAC;
extern uint32_t dword_120DD4;
extern uint32_t off_120DB8;
extern uint32_t off_120DE4;
extern uint32_t dword_120DEC;
extern uint32_t dword_120DE8;
extern uint32_t off_120DD8;
extern uint32_t off_120DDC;
extern uint32_t dword_120DF4;
extern uint32_t off_120DC0;
extern uint32_t dword_120DC4;
extern uint32_t dword_120E10;
extern uint32_t dword_120E08;
extern uint32_t off_120DC8;
extern uint32_t off_120E0C;
extern uint32_t dword_120F3C;
extern uint32_t off_120F38;
extern uint32_t off_120F44;
extern uint32_t off_120F40;
extern uint32_t off_120DD0;
extern uint32_t off_120DCC;
extern uint32_t off_120F54;
extern uint32_t off_120F70;
extern uint32_t off_120F48;
extern uint32_t dword_120F64;
extern uint32_t off_120F5C;
extern uint32_t off_120F58;
extern uint32_t dword_120F6C;
extern uint32_t off_120F60;
extern uint32_t off_120F4C;
extern uint32_t off_120F50;
extern uint32_t off_120DB0;
extern uint32_t dword_120DB4;
extern uint32_t dword_120DBC;
extern uint32_t dword_120E00;
extern uint32_t dword_120DFC;
extern uint32_t dword_120E04;
extern uint32_t dword_120DF8;
extern uint32_t dword_120DF0;
extern uint32_t dword_120DE0;

// sub_120A90 @ 0x120a90, size 1192 bytes
int sub_120A90()
{
  uint8_t *v0; // r10
  int v1; // r8
  int result; // r0
  void *v3; // r4
  uint32_t *v4; // r11
  int v5; // r1
  uint32_t *v6; // r7
  uint32_t *v7; // r5
  uint32_t *v8; // r9
  int v9; // r3
  int v10; // r2
  int v11; // r1
  int v12; // r1
  int v13; // r3
  int v14; // r6
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // r1
  int v18; // r3
  char v19; // r5
  uint8_t **v20; // r7
  uint8_t *v21; // r1
  uint32_t *v22; // r3
  int v23; // r3
  int16_t **v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r3
  void *v28; // r1
  char v29; // r1
  uint32_t *v30; // r2
  uint32_t *v31; // r7
  int v32; // r1
  int v33; // r1
  uint32_t *v34; // r1
  int *v35; // r9
  uint32_t *v36; // r5
  int v37; // r2
  int v38; // r6
  int v39; // r2
  uint32_t *v40; // r6
  int v41; // r3
  int v42; // r2
  uint32_t *v43; // r2
  int v44; // r8
  int v45; // r5
  int v46[3]; // [sp+0h] [bp-Ch]
  int v47; // [sp+0h] [bp-Ch]
  int v48; // [sp+0h] [bp-Ch]

  v0 = off_120E14;
  v1 = *((uint32_t *)off_120E14 + 8);
  result = sub_12D00C(0x40000);
  if ( v1 )
  {
    v3 = off_120D9C;
    v4 = off_120E18;
    v5 = *((uint8_t *)off_120D9C + 30);
LABEL_3:
    v6 = off_120DA0;
    v7 = off_120DA4;
    v8 = off_120E1C;
    while ( 1 )
    {
      if ( !v5 )
        return result;
      if ( (v5 & 8) != 0 )
      {
        v9 = *(uint32_t *)off_120DA8;
        *(uint32_t *)off_120DAC = 0x80000000;
        if ( *(uint32_t *)(v9 + 4) + *(uint32_t *)(v1 + 120) - v4[4] < 0
          && !sub_118C84(*(uint8_t *)(v1 + 116), 0, 0) )
        {
          *(uint32_t *)(v1 + 120) = v4[4];
        }
        v5 = *((uint8_t *)v3 + 30) & 0xF7;
        *((uint8_t *)v3 + 30) = v5;
      }
      if ( (v5 & 4) != 0 )
      {
        sub_12EB90(2, dword_120DD4);
        v24 = (int16_t **)off_120DB8;
        v25 = *((uint32_t *)v3 + 1);
        *v6 &= ~4u;
        v26 = **v24;
        v27 = v25 | 0x200;
        *((uint32_t *)v3 + 1) = v27;
        if ( v26 < 0 && *(uint32_t *)off_120DE4 << 28 )
        {
          sub_12F35C(dword_120DEC, dword_120DE8, 472);
          v27 = *((uint32_t *)v3 + 1);
        }
        v28 = off_120DD8;
        *(uint32_t *)off_120DDC = v27 | *(uint32_t *)v3;
        sub_12B170(*(uint8_t *)(v1 + 107), v28, v1);
        v29 = *((uint8_t *)v3 + 30);
        *v7 &= 0xFC0FFFFF;
        v5 = v29 & 0xFB;
        *v8 |= 0x400000u;
        *((uint8_t *)v3 + 30) = v5;
      }
      if ( (v5 & 2) != 0 )
      {
        *(uint32_t *)(v1 + 4) &= ~2u;
        if ( v0[29] == 5 )
        {
          sub_124CF4(dword_120DF4);
          LOBYTE(v5) = *((uint8_t *)v3 + 30);
          v0[29] = 0;
        }
        v5 &= 0xFDu;
        *((uint8_t *)v3 + 30) = v5;
      }
      result = v5 << 31;
      if ( (v5 & 1) != 0 )
        break;
LABEL_20:
      if ( (v5 & 0x20) != 0 )
      {
        v15 = *(uint32_t *)off_120DC0;
        v16 = (*(uint32_t *)off_120DC0 >> 5) & 3;
        sub_12EB90(2, dword_120DC4);
        v17 = *(uint32_t *)(v1 + 120);
        v18 = *(uint32_t *)(*(uint32_t *)off_120DA8 + 4);
        *(uint8_t *)(v1 + 128) = 0;
        v19 = v15 >> 5;
        if ( v18 + v17 - v4[4] < 0 )
        {
          v32 = dword_120E10;
          *((uint8_t *)v3 + 30) |= 8u;
          sub_12EB90(2, v32);
        }
        if ( v16 )
        {
          while ( (*(uint32_t *)off_120DC0 & 8) == 0 )
            ;
          v31 = off_120DC0;
          *(uint32_t *)off_120DC0 &= ~8u;
          if ( (*v31 & 0x10) != 0 )
          {
            sub_12EB90(2, dword_120E08);
            *(uint8_t *)off_120DC8 = BYTE2(*(uint32_t *)off_120E0C);
            sub_12903C(v16 >> 1, v19 & 1, v1);
            *v31 &= ~0x10u;
          }
          else
          {
            v33 = dword_120F3C;
            *(uint32_t *)off_120F38 = 1;
            sub_12EB90(2, v33);
            v34 = off_120F44;
            *(uint8_t *)off_120F40 = *((uint8_t *)off_120F40 + 1) > 1u;
            *v34 = 1;
          }
        }
        else
        {
          *(uint8_t *)off_120DC8 = *((uint8_t *)off_120DC8 + 1);
        }
        v20 = (uint8_t **)off_120DD0;
        *(uint32_t *)off_120DCC &= ~0x200u;
        *(uint32_t *)(v1 + 4) &= ~1u;
        result = sub_124CF4(v1 + 48);
        v21 = *v20;
        if ( **v20 == 2 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(uint32_t *)off_120F54 = 1;
          }
          v35 = (int *)off_120F70;
          v36 = off_120F48;
          v37 = *(uint32_t *)off_120F48;
          ++*(uint32_t *)off_120F70;
          *v36 = 0;
          v38 = v4[4];
          v39 = v37 & 0xF;
          while ( *v36 << 28 )
          {
            if ( (unsigned int)(v4[4] - v38) > 0x7530 )
            {
              v47 = v39;
              sub_12EB90(2, dword_120F64);
              v39 = v47;
            }
          }
          v40 = off_120F5C;
          result = *(uint32_t *)off_120F5C;
          if ( v39 )
          {
            result &= *(uint32_t *)off_120F58;
            if ( (result & 4) == 0 )
            {
              v48 = v1;
              v43 = off_120F58;
              v44 = v4[4];
              do
              {
                result = 30000;
                v45 = *v43 & *v40;
                if ( (unsigned int)(v4[4] - v44) > 0x7530 )
                {
                  result = sub_12EB90(2, dword_120F6C);
                  v43 = off_120F58;
                }
              }
              while ( (v45 & 4) == 0 );
              v1 = v48;
            }
          }
          *(uint32_t *)off_120F60 = 4;
          if ( *v35 )
          {
            v41 = *v35 - 1;
            v42 = *(uint32_t *)off_120F54;
            *v35 = v41;
            if ( !v41 )
            {
              if ( v42 )
                __enable_irq();
            }
          }
          v21 = *v20;
        }
        v22 = off_120DC0;
        *(uint32_t *)off_120DC0 &= ~1u;
        *v22 &= ~0x80u;
        v23 = *v21;
        if ( v23 == 1 )
        {
          result = sub_124BFC(v1 + 24, v4[4] + 32 * *(uint32_t *)off_120F4C - *((uint16_t *)off_120F50 + 93));
          v23 = **v20;
        }
        if ( v23 == 2 )
        {
          *(uint32_t *)off_120F48 = 48;
          result = sub_117978();
        }
        v5 = *((uint8_t *)v3 + 30) & 0xDF;
        *((uint8_t *)v3 + 30) = v5;
        goto LABEL_3;
      }
    }
    v10 = 32 * *(uint32_t *)off_120DB0;
    if ( (*(uint32_t *)off_120DB0 & 0x4000000) != 0 )
    {
      v11 = HIWORD(*(uint32_t *)off_120DB0);
      if ( (v11 & 0x3F0) != 0 )
      {
        v12 = (uint8_t)(v11 - 16);
        v13 = dword_120DB4 + 696 * v12;
        if ( *(uint8_t *)(v13 + 37) )
        {
          result = 1320;
          v14 = dword_120DBC + 1320 * *(uint8_t *)(v13 + 34);
          if ( **(int16_t **)off_120DB8 >= 0 || v1 == v14 )
          {
            if ( (*v7 & 0x70000) == 0 )
              goto LABEL_43;
          }
          else
          {
            result = sub_12F32C(dword_120E00, dword_120DFC, 864);
            if ( (*v7 & 0x70000) == 0 )
            {
LABEL_43:
              v46[0] = *(uint32_t *)off_120DB0 >> 31;
              v46[1] = (*(uint32_t *)off_120DB0 >> 30) & 1;
              sub_12EB90(2, dword_120E04);
              result = v46[0];
              if ( *(uint64_t *)v46 )
              {
                result = sub_12903C(v46[0], v46[1], v14);
                v30 = off_120DB0;
                *(uint32_t *)off_120DB0 &= ~0x80000000;
                *v30 &= ~0x40000000u;
              }
            }
          }
        }
        else
        {
          result = sub_12E948(dword_120DF8, v12, *(uint8_t *)(v13 + 37));
        }
      }
      else
      {
        result = sub_12E948(dword_120DF0, v11, v10);
      }
    }
    else
    {
      result = sub_12E948(dword_120DE0, v5, v10);
    }
    v5 = *((uint8_t *)v3 + 30) & 0xFE;
    *((uint8_t *)v3 + 30) = v5;
    goto LABEL_20;
  }
  return result;
}

