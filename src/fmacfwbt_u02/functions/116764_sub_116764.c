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

extern uint32_t off_116A54;
extern uint32_t off_116A58;
extern uint32_t dword_116A5C;
extern uint32_t dword_116A60;
extern uint32_t dword_116A74;
extern uint32_t dword_116A64;
extern uint32_t dword_116A68;
extern uint32_t dword_116A6C;
extern uint32_t dword_116A70;
extern uint32_t dword_116ABC;
extern uint32_t dword_116AB4;
extern uint32_t dword_116AB8;

// process_rx_status @ 0x116764, size 846 bytes
int  process_rx_status(int a1, int a2)
{
  int v2; // r3
  uint32_t *v3; // r5
  int v4; // r6
  int v5; // r7
  uint32_t *v7; // r8
  int v8; // r3
  int result; // r0
  int16_t **v10; // r7
  int v11; // r5
  uint16_t *v12; // r3
  int v13; // r3
  int v14; // r2
  int16_t v15; // r12
  int16_t **v16; // r9
  int v17; // r3
  int v18; // r3
  char v19; // r2
  int v20; // r2
  int16_t v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r7
  unsigned int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r2
  int16_t **v31; // r9
  int v32; // r7
  int16_t *v33; // r3
  int v34; // r3
  int16_t v35; // r12
  unsigned int v36; // r2
  int v37; // r2
  unsigned int v38; // r3
  uint16_t *v40; // r0
  char v41; // r3
  uint64_t v42; // kr00_8

  v2 = *(uint32_t *)(a1 + 36);
  v3 = *(uint32_t **)(a1 + 72);
  v4 = *(uint32_t *)(a1 + 76);
  v5 = v2 & 0x200000;
  v7 = v3 + 11;
  if ( (v2 & 0x200000) == 0 )
  {
    v15 = *(uint16_t *)(a1 + 30);
    if ( (v15 & 8) != 0 )
    {
      v16 = (int16_t **)off_116A54;
      if ( **(int16_t **)off_116A54 >= 0 )
      {
        v17 = *(uint32_t *)(v4 + 28);
        if ( v17 )
        {
LABEL_15:
          *(uint32_t *)(v4 + 68) &= 0xFF87FFFF;
          v19 = *(uint8_t *)(v17 + 4);
          *(uint32_t *)(v4 + 48) = v7;
          if ( (v19 & 1) == 0 )
            v5 = 512;
          v20 = v15 & 1;
          *(uint32_t *)(v4 + 64) = v5;
          if ( (v15 & 1) == 0 )
            *(uint32_t *)(v4 + 72) = 0;
LABEL_19:
          if ( v20 )
          {
            a2 = *(uint32_t *)(v4 + 64) | 1;
            v21 = *(uint16_t *)v17 | 0x800;
            *(uint32_t *)(v4 + 64) = a2;
            *(uint16_t *)v17 = v21;
          }
          if ( (*((uint8_t *)off_116A58 + 361) & 1) != 0 )
          {
            v22 = *(uint8_t *)(v17 + 4);
            a2 = v22 << 31;
            if ( (v22 & 1) == 0 )
            {
              v23 = *(uint32_t *)(a1 + 44);
              if ( v23 != dword_116A5C && v23 != dword_116A60 )
              {
                mmio_status_read(v3 + 16, v3 + 20);
                mmio_status_read(v3 + 17, v3 + 21);
                mmio_status_read(v3 + 18, v3 + 22);
                mmio_status_read(v3 + 19, v3 + 23);
              }
            }
          }
          v24 = v3[12];
          *(uint32_t *)(v4 + 44) = v3[25];
          v3[12] = v24 | 2;
          return set_cal_value(a1, a2);
        }
        v18 = *(uint32_t *)(v4 + 24);
LABEL_14:
        v17 = *(uint32_t *)(v18 + 8);
        goto LABEL_15;
      }
      if ( v3 )
      {
        v17 = *(uint32_t *)(v4 + 28);
        if ( v17 )
          goto LABEL_15;
      }
      else
      {
        mmio_irq_clear(dword_116A74, dword_116A64, 518);
        v17 = *(uint32_t *)(v4 + 28);
        if ( v17 )
        {
          v15 = *(uint16_t *)(a1 + 30);
          goto LABEL_15;
        }
        if ( **v16 >= 0 )
          goto LABEL_66;
      }
      v18 = *(uint32_t *)(v4 + 24);
      if ( v18 )
      {
LABEL_35:
        v15 = *(uint16_t *)(a1 + 30);
        goto LABEL_14;
      }
      mmio_irq_clear(dword_116A68, dword_116A64, 525);
LABEL_66:
      v18 = *(uint32_t *)(v4 + 24);
      goto LABEL_35;
    }
    rf_get_pll_setting();
    v30 = v3[24];
    *(uint32_t *)(v4 + 64) = v30;
    if ( !*(uint8_t *)(dword_116A6C + 1320 * *(uint8_t *)(a1 + 28) + 106)
      && (*(uint32_t *)(dword_116A70 + 696 * *(uint8_t *)(a1 + 29) + 4) & 0x20) != 0 )
    {
      v38 = *(uint32_t *)(*(uint32_t *)(a1 + 44) + 60);
      if ( !((*(uint16_t *)(a1 + 30) & 0x2000) != 0 ? (v38 >> 4) & 1 : (v38 >> 3) & 1) )
      {
        v40 = *(uint16_t **)(v4 + 28);
        if ( (*v40 & 0x8000) != 0 )
        {
          *v40 &= ~0x8000u;
          v41 = *(uint8_t *)(a1 + 50) - 4;
          *(uint8_t *)(a1 + 51) -= 4;
          *(uint8_t *)(a1 + 50) = v41;
          v42 = *(uint64_t *)(v4 + 32);
          *(uint32_t *)(v4 + 32) = v42 - 4;
          *(uint32_t *)(v4 + 36) = HIDWORD(v42) - 4;
        }
      }
    }
    v31 = (int16_t **)off_116A54;
    v32 = *(uint32_t *)(a1 + 76);
    v33 = *(int16_t **)off_116A54;
    *(uint32_t *)(v4 + 48) = v7;
    if ( *v33 >= 0 )
    {
      v17 = *(uint32_t *)(v32 + 28);
      if ( v17 )
      {
LABEL_46:
        v35 = *(uint16_t *)(a1 + 30);
        v36 = v30 & 0xFFFFF9FF;
        *(uint32_t *)(v4 + 64) = v36;
        a2 = *(uint8_t *)(v17 + 4);
        if ( (a2 & 1) == 0 )
          *(uint32_t *)(v4 + 64) = v36 | 0x200;
        v20 = v35 & 1;
        goto LABEL_19;
      }
      v34 = *(uint32_t *)(v32 + 24);
LABEL_45:
      v17 = *(uint32_t *)(v34 + 8);
      goto LABEL_46;
    }
    if ( *(uint32_t *)(a1 + 72) )
    {
      v17 = *(uint32_t *)(v32 + 28);
      if ( v17 )
        goto LABEL_46;
    }
    else
    {
      mmio_irq_clear(dword_116ABC, dword_116AB4, 518);
      v17 = *(uint32_t *)(v32 + 28);
      if ( v17 )
      {
        v30 = *(uint32_t *)(v4 + 64);
        goto LABEL_46;
      }
      if ( **v31 >= 0 )
        goto LABEL_74;
    }
    v34 = *(uint32_t *)(v32 + 24);
    if ( v34 )
    {
LABEL_57:
      v30 = *(uint32_t *)(v4 + 64);
      goto LABEL_45;
    }
    mmio_irq_clear(dword_116AB8, dword_116AB4, 525);
LABEL_74:
    v34 = *(uint32_t *)(v32 + 24);
    goto LABEL_57;
  }
  if ( (v2 & 0x380000) != 0x280000 )
  {
    v8 = *(uint16_t *)(a1 + 30);
    result = v8 << 31;
    if ( (v8 & 1) == 0 )
      return result;
LABEL_4:
    v10 = (int16_t **)off_116A54;
    v11 = *(uint32_t *)(a1 + 76);
    if ( **(int16_t **)off_116A54 >= 0 )
    {
      v12 = *(uint16_t **)(v11 + 28);
      if ( v12 )
      {
LABEL_8:
        v14 = *(uint32_t *)(v4 + 64) | 1;
        *v12 |= 0x800u;
        *(uint32_t *)(v4 + 64) = v14;
        return result;
      }
      goto LABEL_6;
    }
    if ( *(uint32_t *)(a1 + 72) )
    {
      v12 = *(uint16_t **)(v11 + 28);
      if ( v12 )
        goto LABEL_8;
    }
    else
    {
      result = mmio_irq_clear(dword_116A74, dword_116A64, 518);
      v12 = *(uint16_t **)(v11 + 28);
      if ( v12 )
        goto LABEL_8;
      if ( **v10 >= 0 )
        goto LABEL_6;
    }
    v13 = *(uint32_t *)(v11 + 24);
    if ( v13 )
      goto LABEL_7;
    result = mmio_irq_clear(dword_116A68, dword_116A64, 525);
LABEL_6:
    v13 = *(uint32_t *)(v11 + 24);
LABEL_7:
    v12 = *(uint16_t **)(v13 + 8);
    goto LABEL_8;
  }
  v25 = *(uint32_t *)(a1 + 68);
  v26 = *(uint32_t *)(v25 + 4);
  *(uint32_t *)(v25 + 52) = v7;
  if ( ((v26 >> 11) & 5) == 5 )
  {
    if ( (v26 & 0x600) == 0x400 )
      v37 = 0x20000;
    else
      v37 = 0x10000;
    if ( (*(uint8_t *)(v25 + 344) & 0x20) != 0 )
      v3[20] = v3[20] & 0xFFFCFFFF | v37 | 0x40000;
    else
      v3[20] = v3[20] & 0xFFF8FFFF | v37 & 0xFFFBFFFF;
  }
  if ( *((uint8_t *)off_116A58 + 361) != 2 )
    mmio_status_read(v25 + 4, v3 + 20);
  v27 = v3[12];
  v28 = v3[24];
  v3[16] = *(uint32_t *)(v25 + 4);
  *(uint32_t *)(v25 + 48) = v3[25];
  *(uint32_t *)(v25 + 68) = v28 | 0x600;
  v3[12] = v27 | 2;
  memcpy_aligned(v25 + 272, v3 + 11, 52);
  v29 = *(uint16_t *)(a1 + 30);
  result = v29 << 31;
  if ( (v29 & 1) != 0 )
    goto LABEL_4;
  return result;
}

