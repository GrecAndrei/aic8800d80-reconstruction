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


extern uint32_t dword_1352BC;
extern uint32_t dword_1352D4;
extern uint32_t dword_1352DC;
extern uint32_t dword_1352E4;
extern uint32_t dword_1352E8;
extern uint32_t off_1352A0;
extern uint32_t off_1352A8;
extern uint32_t off_1352AC;
extern uint32_t off_1352B0;
extern uint32_t off_1352B4;
extern uint32_t off_1352C0;
extern uint32_t off_1352C4;
extern uint32_t off_1352C8;
extern uint32_t off_1352CC;
extern uint32_t off_1352D0;
extern uint32_t off_1352E0;

// event_dispatch_1 @ 0x135020, size 640 bytes
int  event_dispatch_1(int a1)
{
  int v1; // lr
  uint32_t *v3; // r5
  int v4; // r11
  int v5; // r1
  int v6; // r7
  int v7; // r4
  int v8; // r9
  int v9; // r10
  int result; // r0
  int v11; // r12
  uint8_t *v12; // r0
  unsigned int *v13; // r1
  unsigned int v14; // r2
  int *v15; // r3
  int v16; // r1
  int *v17; // r3
  int v18; // r3
  int v19; // r2
  char v20; // lr
  uint16_t v21; // r0
  int v22; // lr
  int v23; // r2
  int v24; // lr
  unsigned int v25; // r0
  unsigned int v26; // r3
  unsigned int v27; // r3
  int v28; // r2
  int v29; // r3
  int v30; // r3
  int v31; // r3
  uint16_t *v32; // r3
  int v33; // r3
  unsigned int v34; // r0
  volatile unsigned int v35; // r3
  uint32_t *v36; // r2
  int *v37; // r1
  int v38; // r0
  int v39; // [sp+Ch] [bp-8h]
  int v40; // [sp+Ch] [bp-8h]

  v3 = off_1352A0;
  v4 = dword_1352E8;
  v5 = *((uint32_t *)off_1352A0 + 4);
  v6 = *(uint8_t *)(v5 + 61);
  v7 = *((uint32_t *)off_1352A0 + 5);
  v39 = v5;
  v8 = dword_1352E8 + 1320 * v6;
  v9 = *(uint8_t *)(v8 + 116);
  result = ke_event_schedule_1("connect ind:%x, %x\n", v5, v1);
  v11 = v3[4];
  if ( v11 )
  {
    v12 = off_1352A8;
    v13 = (unsigned int *)off_1352AC;
    *(uint8_t *)(v7 + 9) = *(uint8_t *)(v39 + 61);
    v14 = *v13 & 0xFFFFFFEF;
    v15 = *((int **)off_1352B0 + 2);
    *(uint16_t *)v7 = a1;
    *v13 = v14;
    v16 = 0;
    v12[13] = 0;
    if ( v15 )
    {
      do
      {
        if ( !*((uint8_t *)v15 + 106) && *((uint8_t *)v15 + 108) )
          ++v16;
        v15 = (int *)*v15;
      }
      while ( v15 );
      if ( a1 )
        goto LABEL_8;
    }
    else
    {
      v16 = 0;
      if ( a1 )
      {
LABEL_8:
        v17 = (int *)off_1352B4;
        *(uint8_t *)(v7 + 8) = (*(uint32_t *)(v11 + 48) & 0x60) != 0;
        if ( *v17 < 0 && !v16 )
        {
          v36 = off_1352E0;
          v12[2] = 0;
          v37 = (int *)off_1352D0;
          v38 = dword_1352E4;
          *v36 |= 0x80000000;
          *v37 = v38;
        }
        hci_cmd_send(6u, 10);
        v3[2] = v8;
        *v3 = v7 - 12;
        write_hw_mmio_word(v8);
LABEL_10:
        state_check_feature(
          256,
          "connect:%d,%d,aid=%d\r\n",
          *(uint8_t *)(v7 + 9),
          a1,
          *(uint16_t *)(v7 + 820));
        result = (int)jump_to_tx_entry((char *)(v3[4] - 12));
        v3[4] = 0;
        *((uint8_t *)v3 + 33) = 0;
        return result;
      }
    }
    v18 = v4 + 1320 * v6;
    v19 = dword_1352BC;
    v20 = *(uint8_t *)(v18 + 116);
    *(uint32_t *)(v7 + 2) = *(uint32_t *)(v18 + 368);
    v21 = *(uint16_t *)(v18 + 372);
    *(uint8_t *)(v7 + 10) = v20;
    v22 = *(uint32_t *)(v18 + 72);
    *(uint16_t *)(v7 + 6) = v21;
    *(uint8_t *)(v7 + 11) = *(uint8_t *)(v22 + 24);
    v23 = *(uint8_t *)(v19 + 696 * v9 + 309);
    *(uint8_t *)(v7 + 826) = v23;
    *(uint8_t *)(v7 + 822) = *(uint8_t *)(v18 + 412);
    v24 = *(uint8_t *)(v18 + 413);
    v25 = *(uint16_t *)(v18 + 414);
    *(uint16_t *)(v7 + 824) = v25;
    if ( v24 == v23 )
    {
      *(uint32_t *)(v7 + 828) = *(uint16_t *)(v18 + 416);
    }
    else if ( v23 )
    {
      v26 = *(uint16_t *)(v18 + 416);
      if ( v25 >= v26 )
        v27 = v26 + 20;
      else
        v27 = v26 - 20;
      *(uint32_t *)(v7 + 828) = v27;
    }
    else
    {
      *(uint32_t *)(v7 + 828) = v25;
    }
    v28 = v4 + 1320 * v6;
    v29 = *(uint32_t *)(v28 + 472);
    *(uint32_t *)(v7 + 832) = *(uint16_t *)(v28 + 418);
    v30 = v29 & 1;
    *(uint8_t *)(v7 + 12) = v30;
    if ( v30 )
      LOBYTE(v30) = *(uint8_t *)(v28 + 457);
    *(uint8_t *)(v7 + 13) = v30;
    v31 = v4 + 1320 * v6;
    *(uint8_t *)(v7 + 8) = (*(uint32_t *)(v11 + 48) & 0x60) != 0;
    if ( *(uint8_t *)(v31 + 1224) )
    {
      *(uint32_t *)off_1352C0 = *(uint16_t *)(v31 + 100) | (*(uint16_t *)(v31 + 102) << 16);
      *(uint32_t *)off_1352C4 = *(uint16_t *)(v31 + 104);
      *(uint32_t *)off_1352C8 = *(uint16_t *)(v31 + 64) | (*(uint16_t *)(v31 + 66) << 16);
      *(uint32_t *)off_1352CC = *(uint16_t *)(v31 + 68);
    }
    v40 = v16;
    hci_evt_send(v7);
    *(uint32_t *)off_1352D0 = dword_1352D4;
    if ( v40 == 1 )
    {
      v32 = (uint16_t *)(v4 + 1320 * v6);
      *(uint32_t *)off_1352C0 = v32[50] | (v32[51] << 16);
      *(uint32_t *)off_1352C4 = v32[52];
    }
    if ( *(uint8_t *)(v4 + 1320 * v6 + 413) == 2 )
      bt_coex_control((int *)v8, 0, 1);
    v33 = v4 + 1320 * v6;
    v34 = *(uint16_t *)(v33 + 416);
    if ( v34 <= 0x1387 )
      hw_reg_write(v34 | (*(uint8_t *)(v33 + 413) << 16) | 0x80000000);
    *(uint8_t *)(v4 + 1320 * v6 + 149) = 1;
    v35 = (*(volatile uint32_t *)0x40501010u);
    ke_event_lock((uint32_t *)(1320 * v6 + 152 + v4), dword_1352DC + v35);
    hci_cmd_send(6u, 0);
    goto LABEL_10;
  }
  return result;
}
