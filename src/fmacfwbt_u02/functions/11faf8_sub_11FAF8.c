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


extern uint32_t dword_11FE38;
extern uint32_t dword_11FE3C;
extern uint32_t dword_11FE40;
extern uint32_t dword_11FE44;
extern uint32_t dword_11FE58;
extern uint32_t dword_11FE7C;
extern uint32_t dword_11FE84;
extern uint32_t dword_11FEEC;
extern uint32_t off_11FE20;
extern uint32_t off_11FE24;
extern uint32_t off_11FE28;
extern uint32_t off_11FE2C;
extern uint32_t off_11FE34;
extern uint32_t off_11FE48;
extern uint32_t off_11FE4C;
extern uint32_t off_11FE50;
extern uint32_t off_11FE54;
extern uint32_t off_11FE5C;
extern uint32_t off_11FE70;
extern uint32_t off_11FE80;
extern uint32_t off_11FE88;
extern uint32_t off_11FE8C;
extern uint32_t off_11FE90;
extern uint32_t off_11FEE0;

// wlc_ioctl @ 0x11faf8, size 1000 bytes
int  wlc_ioctl(int a1, int a2, int a3, uint8_t *a4)
{
  int v4; // r9
  int **v5; // r4
  int result; // r0
  int v7; // r6
  int v8; // r7
  int v9; // r8
  int v10; // r11
  int v11; // r5
  int v12; // r10
  int *v13; // r3
  int *v14; // r1
  int *v15; // r2
  uint32_t *v16; // r0
  int v17; // r2
  int v18; // r4
  char v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r3
  int v23; // r3
  uint32_t *v24; // r5
  int v25; // r1
  int v26; // r2
  int v27; // r0
  uint32_t *v28; // r5
  uint32_t *v29; // r0
  int v30; // r2
  int v31; // r3
  uint32_t *v32; // r3
  int v33; // zf
  int v34; // r0
  int v35; // r1
  int v36; // r0
  uint16_t **v37; // r3
  char v38; // r2
  int v39; // r5
  int v40; // r3
  int v41; // r6
  int *v42; // r5
  int v43; // r3
  int v44; // r2
  int v45; // r2
  void *v46; // r2
  int v47; // r0
  int v52; // [sp+20h] [bp-1Ch]
  int v53; // [sp+24h] [bp-18h]
  uint8_t a2a; // [sp+2Bh] [bp-11h] BYREF
  uint8_t v55[4]; // [sp+2Ch] [bp-10h] BYREF
  int v56; // [sp+30h] [bp-Ch]

  v4 = off_11FE34;
  if ( !*(uint32_t *)off_11FE34 )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(uint8_t *)off_11FE90 )
      return 1;
    v5 = *(int ***)(off_11FE34 + 8);
    if ( v5 )
    {
      if ( *(uint8_t *)(off_11FE34 + 0x13) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    read_hw_stats((int *)a1);
    goto LABEL_11;
  }
  v5 = *(int ***)(off_11FE34 + 8);
  if ( !v5 )
    goto LABEL_52;
LABEL_8:
  v7 = *(uint32_t *)a1;
  v52 = *(uint32_t *)a1;
  v8 = 0;
  v53 = *(uint16_t *)(a1 + 4);
  v9 = 0;
  v10 = v53;
  do
  {
    v11 = (int)v5[25];
    v12 = *((uint16_t *)v5 + 52);
    ke_event_schedule_1(aMacIsXXP2pD, v11, v12, *((uint8_t *)v5 + 1224));
    v5 = (int **)*v5;
    v9 |= v11 ^ v7;
    v7 &= v11;
    v8 |= v12 ^ v10;
    v10 &= v12;
  }
  while ( v5 );
  v13 = (int *)off_11FE24;
  v14 = (int *)off_11FE28;
  v15 = (int *)off_11FE2C;
  *(uint32_t *)off_11FE20 = v8 | 0x300;
  *v13 = v9;
  *v14 = v52;
  *v15 = v53;
  ke_event_schedule_1("set mac:%x,%x, mask:%x,%x,p2p=%d\r\n", v52, v53, v9, v8, a3);
LABEL_11:
  v16 = list_pop_front(off_11FE34);
  v17 = dword_11FE38;
  *((uint8_t *)v16 + 106) = a2;
  v18 = (int)v16;
  v19 = dword_11FE3C;
  v16[25] = *(uint32_t *)a1;
  *((uint16_t *)v16 + 52) = *(uint16_t *)(a1 + 4);
  v20 = (uint8_t)(v19 * (((int)v16 - v17) >> 3));
  *((uint8_t *)v16 + 1224) = a3;
  v21 = dword_11FE40;
  v16[3] = 2627;
  v16[4] = v21;
  v16[5] = dword_11FE44;
  *((uint16_t *)v16 + 611) = 1023;
  v16[2] = 2631;
  *((uint8_t *)v16 + 107) = v20;
  *((uint8_t *)v16 + 84) = v20;
  *((uint8_t *)v16 + 109) = 127;
  *((uint8_t *)v16 + 110) = 127;
  v16[18] = 0;
  *((uint8_t *)v16 + 140) = 0;
  if ( a2 == 2 )
  {
    v38 = *(uint8_t *)(v4 + 0x12);
    if ( v38 )
    {
      v39 = a3;
    }
    else
    {
      mmio_set_bit_1();
      v38 = *(uint8_t *)(v4 + 0x12);
      v20 = *(uint8_t *)(v18 + 107);
      v39 = *(uint8_t *)(v18 + 1224);
    }
    v40 = dword_11FE7C + 696 * (v20 + 32);
    *(uint8_t *)(v4 + 0x12) = v38 + 1;
    *(uint8_t *)(v40 + 37) = 1;
    if ( v39 )
    {
      *(uint32_t *)(v18 + 28) = off_11FE80;
      *(uint32_t *)(v18 + 32) = v18;
    }
    memory_pool_init(v18);
    v22 = *(uint8_t *)(v4 + 0x11);
  }
  else if ( a2 == 4 )
  {
    if ( *(uint8_t *)(v4 + 0x10) != 255 )
      return 1;
    v41 = *(uint32_t *)(v4 + 8);
    *(uint8_t *)(v4 + 0x10) = v20;
    if ( v41 )
    {
      v42 = (int *)off_11FE4C;
      v43 = dword_11FE84;
      v44 = **(uint16_t **)off_11FE48;
      *(uint32_t *)off_11FE4C = dword_11FE84;
      if ( v44 < 0 && *(uint32_t *)off_11FEE0 << 28 )
      {
        mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
        v43 = *v42;
      }
      v45 = *(uint32_t *)(v41 + 72);
      *(uint32_t *)off_11FE50 = v43 | v42[1];
      if ( v45 )
        get_current_entry_owner(*(uint8_t *)(v45 + 24));
      v22 = *(uint8_t *)(v4 + 0x11);
    }
    else
    {
      *(uint32_t *)v55 = dword_11FEEC;
      v56 = 2437;
      mmio_disable_irq();
      if ( find_free_conn(v55, &a2a) )
        return 1;
      v47 = a2a;
      *(uint32_t *)(v18 + 4) |= 0x80u;
      get_current_entry_owner(v47);
      v22 = *(uint8_t *)(v4 + 0x11);
    }
  }
  else
  {
    v22 = *(uint8_t *)(v4 + 0x11);
    if ( !a2 )
    {
      v16[7] = off_11FE88;
      v46 = off_11FE8C;
      v16[8] = v16;
      v22 = (uint8_t)(v22 + 1);
      *((uint16_t *)v16 + 73) = 0;
      v16[40] = v16;
      *(uint8_t *)(v4 + 0x11) = v22;
      *((uint8_t *)v16 + 116) = -1;
      v16[39] = v46;
    }
  }
  v23 = v22 + *(uint8_t *)(v4 + 0x12);
  if ( v23 > 1 || *(uint8_t *)(v4 + 0x12) )
  {
    v24 = off_11FE4C;
    v25 = **(uint16_t **)off_11FE48;
    v26 = *((uint32_t *)off_11FE4C + 1) | 0x100;
    *((uint32_t *)off_11FE4C + 1) = v26;
    if ( v25 < 0 && *(uint32_t *)off_11FE70 << 28 )
    {
      mmio_field_update((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
      v26 = v24[1];
      v23 = *(uint8_t *)(v4 + 0x11) + *(uint8_t *)(v4 + 0x12);
    }
    *(uint32_t *)off_11FE50 = v26 | *v24;
  }
  if ( v23 == 1 )
    *(uint32_t *)off_11FE54 |= 1u;
  if ( a3 )
  {
    v34 = *(uint8_t *)(v18 + 107);
    v35 = a2;
    if ( a2 )
      v35 = 1;
    ++*(uint8_t *)(v4 + 0x13);
    v36 = poll_ready(v34, v35);
    v37 = (uint16_t **)off_11FE48;
    *(uint8_t *)(v18 + 1225) = v36;
    if ( **v37 < 0 && v36 == 255 )
      mmio_irq_clear((int)aVifP2pIndexP2p, (int)aVifMgmtRegiste_0, 498);
  }
  v27 = dword_11FE58;
  *a4 = *(uint8_t *)(v18 + 107);
  check_abort_flag(v27, (uint32_t *)v18);
  v28 = (uint32_t *)(v18 + 1232);
  do
  {
    zero_struct(v28);
    v29 = v28 + 10;
    v28 += 2;
    zero_struct(v29);
  }
  while ( v28 != (uint32_t *)(v18 + 1272) );
  zero_struct((uint32_t *)(v18 + 1312));
  v30 = *(uint8_t *)(v4 + 0x12);
  v31 = *(uint8_t *)(v4 + 0x11) + v30;
  *(uint32_t *)off_11FE5C = 0;
  if ( v31 <= 1 )
  {
    si_secure_check();
    v30 = *(uint8_t *)(v4 + 0x12);
    v31 = *(uint8_t *)(v4 + 0x11) + v30;
  }
  state_check_feature(256, "%s:%d,%d,%d,%d,%d\r\n", aVifMgmtRegiste, v31, v30, a2, a3, *a4);
  v32 = (uint32_t *)(*(uint8_t *)(v4 + 0x12) + *(uint8_t *)(v4 + 0x11));
  v33 = v32 == (uint32_t *)1;
  if ( v32 == (uint32_t *)1 )
    v32 = off_11FE20;
  result = 0;
  if ( v33 )
    *v32 = 0;
  return result;
}
