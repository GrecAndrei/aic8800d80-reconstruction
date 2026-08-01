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

extern uint32_t off_120B54;
extern uint32_t dword_120BA4;
extern uint32_t off_120B58;
extern uint32_t off_120B5C;
extern uint32_t off_120B60;
extern uint32_t dword_120B7C;
extern uint32_t dword_120B78;
extern uint32_t off_120B64;
extern uint32_t dword_120B74;
extern uint32_t off_120B68;
extern uint32_t off_120B6C;
extern uint32_t dword_120BA0;
extern uint32_t off_120B70;
extern uint32_t off_120B84;
extern uint32_t off_120B80;
extern uint32_t off_120B8C;
extern uint32_t off_120B88;
extern uint32_t off_120B94;
extern uint32_t off_120B90;
extern uint32_t dword_120BCC;
extern uint32_t dword_120B9C;
extern uint32_t dword_120B98;

// handle_rx_data @ 0x120840, size 898 bytes
int  handle_rx_data(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned int v8; // r9
  int v9; // r3
  unsigned int v10; // r7
  unsigned int v11; // r11
  int v12; // r10
  int v13; // r5
  char *v14; // r2
  int v15; // r8
  int *v16; // r0
  uint32_t *v17; // r2
  int16_t **v18; // r3
  int v19; // r5
  char *v20; // r1
  int *v21; // r0
  uint32_t *v22; // r1
  int v23; // r6
  int v24; // r5
  int v25; // r2
  unsigned uint64_t v26; // kr08_8
  uint64_t v27; // r0
  int v28; // r3
  unsigned uint64_t v29; // r0
  unsigned int v30; // r2
  int v31; // r1
  uint32_t *v32; // r6
  int v33; // r5
  int v34; // r2
  int v35; // r3
  int result; // r0
  uint8_t *v37; // r3
  uint32_t *v38; // r2
  uint8_t *v39; // r5
  int v40; // r1
  uint8_t *v41; // r1
  uint32_t *v42; // r2
  unsigned int v43; // [sp+8h] [bp-1Ch]
  int v44; // [sp+10h] [bp-14h]
  unsigned int v45; // [sp+14h] [bp-10h]
  int v47; // [sp+1Ch] [bp-8h]

  v8 = *(uint32_t *)(a3 + 32);
  v9 = *(uint16_t *)(a1 + 32);
  v45 = *(uint32_t *)(a3 + 36);
  v10 = *(uint32_t *)(a1 + 24);
  v11 = *(uint32_t *)(a1 + 28);
  v12 = v9 << 10;
  if ( !*(uint8_t *)(a4 + 106) && (v13 = *(uint16_t *)(a4 + 112), *(uint16_t *)(a4 + 112)) )
  {
    tx_arbiter_calc(*(uint8_t *)(a4 + 107), v9, (uint8_t)v13);
    v47 = v12 * v13;
  }
  else if ( a6 )
  {
    v13 = *(uint8_t *)(a6 + 2);
    if ( !*(uint8_t *)(a6 + 2) )
    {
      v13 = *(uint8_t *)(a6 + 3);
      tx_arbiter_calc(*(uint8_t *)(a4 + 107), v9, v13);
    }
    v47 = v12 * v13;
  }
  else
  {
    v47 = v9 << 10;
    v13 = 1;
  }
  v44 = v13 * *(uint16_t *)(a5 + 30);
  if ( *(uint8_t *)(a3 + 40) << 28 )
  {
    v23 = 500;
    v24 = 0;
  }
  else
  {
    v14 = (char *)off_120B54;
    v15 = dword_120BA4;
    v16 = (int *)off_120B58;
    *(uint32_t *)off_120B54 = *(uint8_t *)(dword_120BA4 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                          | *(uint32_t *)off_120B54 & 0xFFFFFF80;
    v17 = v14 + 8;
    *v16 = a2 | (*(uint8_t *)(a3 + 40) >> 7 << 20);
    *v17 = 0x80000000;
    __dsb(0xFu);
    while ( (*v17 & 0xC0000000) != 0x40000000 )
      ;
    v18 = (int16_t **)off_120B5C;
    if ( **(int16_t **)off_120B5C >= 0 || (*v17 & 0x40000000) != 0 )
    {
      v19 = (uint16_t)*(uint32_t *)off_120B60;
    }
    else
    {
      bad_func_0x12f408(dword_120B7C, dword_120B78, 430, off_120B5C);
      v19 = 500;
      v18 = (int16_t **)off_120B5C;
    }
    if ( !(*(uint8_t *)(a3 + 40) << 28) )
    {
      v20 = (char *)off_120B54;
      v21 = (int *)off_120B58;
      *(uint32_t *)off_120B54 = *(uint8_t *)(v15 + (*(uint8_t *)(a3 + 44) >> 4)) & 0x7F
                            | *(uint32_t *)off_120B54 & 0xFFFFFF80;
      v22 = v20 + 8;
      *v21 = (*(uint8_t *)(a3 + 40) >> 7 << 20) | 0x18;
      *v22 = 0x80000000;
      __dsb(0xFu);
      while ( (*v22 & 0xC0000000) != 0x40000000 )
        ;
      if ( **v18 >= 0 || (*v22 & 0x40000000) != 0 )
      {
        v23 = (uint16_t)*(uint32_t *)off_120B60;
        v24 = v19 - v23;
        goto LABEL_15;
      }
      bad_func_0x12f408(dword_120B7C, dword_120B78, 430, 2 * *v22);
    }
    v24 = v19 - 500;
    v23 = 500;
  }
LABEL_15:
  v25 = *(uint8_t *)(a4 + 106);
  v26 = __PAIR64__(v11, v10) - __PAIR64__(v45, v8) + (unsigned int)v24;
  *(uint64_t *)(a4 + 40) = v26;
  if ( !v25 )
  {
    *(uint32_t *)(a4 + 132) = v26;
    *(uint32_t *)(a4 + 136) = v44 + 400;
  }
  v27 = validate_args(v10, v11, v12, v12 >> 31);
  v43 = v10 - v23;
  v28 = v27 * (v12 >> 31) + v12 * HIDWORD(v27);
  v29 = (unsigned int)v27 * (unsigned uint64_t)(unsigned int)v12;
  HIDWORD(v29) += v28;
  if ( v29 < __PAIR64__(v11, v10) - (unsigned int)v23 )
    v43 = v29;
  v30 = v43 + v47;
  if ( (*(uint32_t *)off_120B64 & 0x2000000) != 0 )
    v31 = dword_120B74 - v44 - v26 + v30;
  else
    v31 = v30 - v44 - 400;
  v32 = off_120B68;
  v33 = *((uint32_t *)off_120B68 + 4) - *(uint32_t *)off_120B6C + v31;
  if ( v33 - v32[4] - 4300 - get_constant_1000() < 0 )
    v33 += v12;
  if ( (*(uint32_t *)(a4 + 4) & 1) != 0 )
  {
    v35 = *(uint8_t *)(a4 + 85);
    if ( (v35 & 2) != 0 && v33 - *((uint32_t *)off_120B68 + 4) - 10000 < 0 )
    {
      v33 += v12;
      event_dispatch(dword_120BA0, v35 << 30, v34);
    }
  }
  result = v33 - *((uint32_t *)off_120B68 + 4) - 4300 - get_constant_1000();
  if ( result >= 0 && *(uint32_t *)(a4 + 36) != v33 )
  {
    v37 = off_120B70;
    if ( *((uint32_t *)off_120B70 + 8) != a4 || (v38 = off_120B64, *(uint32_t *)(a4 + 36) = v33, (*v38 & 0x2000000) != 0) )
    {
      unknown_worker(a4 + 24, v33);
    }
    else
    {
      v39 = (uint8_t *)off_120B84;
      v40 = (uint8_t)v37[36];
      *(uint8_t *)off_120B84 = BYTE2(*(uint32_t *)off_120B80);
      if ( !v40 )
      {
        v41 = *(uint8_t **)off_120B8C;
        v39[1] = *(uint32_t *)off_120B88;
        v37[36] = 1;
        if ( *v41 == 1 )
        {
          v42 = off_120B94;
          *(uint32_t *)off_120B90 = 1;
          *v42 |= 1u;
        }
        if ( *v39 >= (unsigned int)v39[1] )
          event_dispatch(dword_120BCC, *v39, v39[1]);
        if ( **(int16_t **)off_120B5C < 0 && *v39 >= (unsigned int)v39[1] )
          mmio_clear_register(dword_120B9C, dword_120B98, 523);
      }
    }
    return wlc_is_running(a4);
  }
  return result;
}

