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


extern uint32_t dword_11FB00;
extern uint32_t dword_11FB04;
extern uint32_t dword_11FB08;
extern uint32_t dword_11FB0C;
extern uint32_t dword_11FB20;
extern uint32_t dword_11FB44;
extern uint32_t dword_11FB4C;
extern uint32_t dword_11FBB4;
extern uint32_t off_11FAE8;
extern uint32_t off_11FAEC;
extern uint32_t off_11FAF0;
extern uint32_t off_11FAF4;
extern uint32_t off_11FAFC;
extern uint32_t off_11FB10;
extern uint32_t off_11FB14;
extern uint32_t off_11FB18;
extern uint32_t off_11FB1C;
extern uint32_t off_11FB24;
extern uint32_t off_11FB38;
extern uint32_t off_11FB48;
extern uint32_t off_11FB50;
extern uint32_t off_11FB54;
extern uint32_t off_11FB58;
extern uint32_t off_11FBA8;

// task_event_handler @ 0x11f7c0, size 1000 bytes
int  task_event_handler(int a1, int a2, int a3, uint8_t *a4)
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

  v4 = off_11FAFC;
  if ( !*(uint32_t *)off_11FAFC )
    return 1;
  if ( a3 )
  {
    if ( a2 == 2 && *(uint8_t *)off_11FB58 )
      return 1;
    v5 = *(int ***)(off_11FAFC + 8);
    if ( v5 )
    {
      if ( *(uint8_t *)(off_11FAFC + 0x13) == 2 )
        return 1;
      goto LABEL_8;
    }
LABEL_52:
    read_mac_int_status((int *)a1);
    goto LABEL_11;
  }
  v5 = *(int ***)(off_11FAFC + 8);
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
    event_dispatch(aMacIsXXP2pD, v11, v12, *((uint8_t *)v5 + 1224));
    v5 = (int **)*v5;
    v9 |= v11 ^ v7;
    v7 &= v11;
    v8 |= v12 ^ v10;
    v10 &= v12;
  }
  while ( v5 );
  v13 = (int *)off_11FAEC;
  v14 = (int *)off_11FAF0;
  v15 = (int *)off_11FAF4;
  *(uint32_t *)off_11FAE8 = v8 | 0x300;
  *v13 = v9;
  *v14 = v52;
  *v15 = v53;
  event_dispatch("set mac:%x,%x, mask:%x,%x,p2p=%d\r\n", v52, v53, v9, v8, a3);
LABEL_11:
  v16 = mem_word_load(off_11FAFC);
  v17 = dword_11FB00;
  *((uint8_t *)v16 + 106) = a2;
  v18 = (int)v16;
  v19 = dword_11FB04;
  v16[25] = *(uint32_t *)a1;
  *((uint16_t *)v16 + 52) = *(uint16_t *)(a1 + 4);
  v20 = (uint8_t)(v19 * (((int)v16 - v17) >> 3));
  *((uint8_t *)v16 + 1224) = a3;
  v21 = dword_11FB08;
  v16[3] = 2627;
  v16[4] = v21;
  v16[5] = dword_11FB0C;
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
      mac_irq_enable_1();
      v38 = *(uint8_t *)(v4 + 0x12);
      v20 = *(uint8_t *)(v18 + 107);
      v39 = *(uint8_t *)(v18 + 1224);
    }
    v40 = dword_11FB44 + 696 * (v20 + 32);
    *(uint8_t *)(v4 + 0x12) = v38 + 1;
    *(uint8_t *)(v40 + 37) = 1;
    if ( v39 )
    {
      *(uint32_t *)(v18 + 28) = off_11FB48;
      *(uint32_t *)(v18 + 32) = v18;
    }
    stack_canary_check(v18);
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
      v42 = (int *)off_11FB14;
      v43 = dword_11FB4C;
      v44 = **(uint16_t **)off_11FB10;
      *(uint32_t *)off_11FB14 = dword_11FB4C;
      if ( v44 < 0 && *(uint32_t *)off_11FBA8 << 28 )
      {
        call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
        v43 = *v42;
      }
      v45 = *(uint32_t *)(v41 + 72);
      *(uint32_t *)off_11FB18 = v43 | v42[1];
      if ( v45 )
        sta_get_current(*(uint8_t *)(v45 + 24));
      v22 = *(uint8_t *)(v4 + 0x11);
    }
    else
    {
      *(uint32_t *)v55 = dword_11FBB4;
      v56 = 2437;
      mmio_disable_bit();
      if ( scan_find_empty_slot(v55, &a2a) )
        return 1;
      v47 = a2a;
      *(uint32_t *)(v18 + 4) |= 0x80u;
      sta_get_current(v47);
      v22 = *(uint8_t *)(v4 + 0x11);
    }
  }
  else
  {
    v22 = *(uint8_t *)(v4 + 0x11);
    if ( !a2 )
    {
      v16[7] = off_11FB50;
      v46 = off_11FB54;
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
    v24 = off_11FB14;
    v25 = **(uint16_t **)off_11FB10;
    v26 = *((uint32_t *)off_11FB14 + 1) | 0x100;
    *((uint32_t *)off_11FB14 + 1) = v26;
    if ( v25 < 0 && *(uint32_t *)off_11FB38 << 28 )
    {
      call_shared_handler((int)aNxmacCurrentSt, (int)aMmRxFilterSet_0, 472);
      v26 = v24[1];
      v23 = *(uint8_t *)(v4 + 0x11) + *(uint8_t *)(v4 + 0x12);
    }
    *(uint32_t *)off_11FB18 = v26 | *v24;
  }
  if ( v23 == 1 )
    *(uint32_t *)off_11FB1C |= 1u;
  if ( a3 )
  {
    v34 = *(uint8_t *)(v18 + 107);
    v35 = a2;
    if ( a2 )
      v35 = 1;
    ++*(uint8_t *)(v4 + 0x13);
    v36 = llc_poll_active(v34, v35);
    v37 = (uint16_t **)off_11FB10;
    *(uint8_t *)(v18 + 1225) = v36;
    if ( **v37 < 0 && v36 == 255 )
      mmio_clear_register((int)aVifP2pIndexP2p, (int)aVifMgmtRegiste_0, 498);
  }
  v27 = dword_11FB20;
  *a4 = *(uint8_t *)(v18 + 107);
  cmd_handler_a(v27, (uint32_t *)v18);
  v28 = (uint32_t *)(v18 + 1232);
  do
  {
    zero_8_bytes(v28);
    v29 = v28 + 10;
    v28 += 2;
    zero_8_bytes(v29);
  }
  while ( v28 != (uint32_t *)(v18 + 1272) );
  zero_8_bytes((uint32_t *)(v18 + 1312));
  v30 = *(uint8_t *)(v4 + 0x12);
  v31 = *(uint8_t *)(v4 + 0x11) + v30;
  *(uint32_t *)off_11FB24 = 0;
  if ( v31 <= 1 )
  {
    scan_active_get();
    v30 = *(uint8_t *)(v4 + 0x12);
    v31 = *(uint8_t *)(v4 + 0x11) + v30;
  }
  check_status_bits(256, "%s:%d,%d,%d,%d,%d\r\n", aVifMgmtRegiste, v31, v30, a2, a3, *a4);
  v32 = (uint32_t *)(*(uint8_t *)(v4 + 0x12) + *(uint8_t *)(v4 + 0x11));
  v33 = v32 == (uint32_t *)1;
  if ( v32 == (uint32_t *)1 )
    v32 = off_11FAE8;
  result = 0;
  if ( v33 )
    *v32 = 0;
  return result;
}
