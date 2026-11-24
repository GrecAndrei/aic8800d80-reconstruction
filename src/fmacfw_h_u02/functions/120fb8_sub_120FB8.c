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


extern uint32_t dword_1211C0;
extern uint32_t dword_1211C4;
extern uint32_t dword_1211C8;
extern uint32_t dword_1211CC;
extern uint32_t dword_1211D0;
extern uint32_t dword_1211D4;
extern uint32_t dword_1211D8;
extern uint32_t dword_1211DC;
extern uint32_t dword_1211E0;
extern uint32_t dword_1211E8;
extern uint32_t dword_1211EC;
extern uint32_t dword_1211F4;
extern uint32_t dword_1211F8;

// ke_timer_handler @ 0x120fb8, size 520 bytes
void ke_timer_handler()
{
  unsigned int v0; // r6
  int v1; // r4
  uint32_t *v2; // r5
  int v3; // r3
  int v4; // r2
  uint32_t *v5; // r7
  uint32_t *v6; // r9
  int v7; // r5
  int v8; // r3
  uint32_t *v9; // r3
  unsigned int v10; // r10
  unsigned int v11; // r2
  int v12; // r10
  unsigned int v13; // r4
  volatile unsigned int v14; // r2
  unsigned int v15; // r3
  int v16; // zf
  int v17; // cc
  int v18; // r3
  int v19; // r1
  int v20; // r3
  int v21; // r2
  int v22; // r3
  volatile unsigned int v23; // r1
  uint32_t *v24; // r0
  int **i; // r3
  int v26; // r2
  int v27; // r1
  int v28; // r0
  int v29; // r12
  int v30; // r2

  v0 = dword_1211C0;
  v1 = *(uint32_t *)(dword_1211C0 + 8);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)dword_1211C4 = 1;
  }
  v2 = (uint32_t *)dword_1211C8;
  ++*(uint32_t *)dword_1211C8;
  mmio_modify_bit(4);
  phy_get_cfg_ptr(4u);
  if ( *v2 && (v3 = *v2 - 1, v4 = *(uint32_t *)dword_1211C4, (*v2 = v3) == 0) && v4 )
  {
    __enable_irq();
    if ( !v1 )
      goto LABEL_32;
  }
  else if ( !v1 )
  {
LABEL_32:
    patch_check_enable();
    return;
  }
  v5 = (uint32_t *)dword_1211CC;
  v6 = (uint32_t *)dword_1211F8;
  v7 = 0;
  do
  {
    while ( 1 )
    {
      if ( *(uint8_t *)(v1 + 106) != 2 )
        goto LABEL_7;
      v8 = (uint8_t)(*(uint8_t *)(v1 + 225) - 1);
      *(uint8_t *)(v1 + 225) = v8;
      if ( v8 )
        goto LABEL_7;
      v9 = *(uint32_t **)dword_1211D0;
      *(uint8_t *)(v1 + 225) = *(uint8_t *)(v1 + 224);
      if ( !v9 )
        break;
      while ( v9 != (uint32_t *)(v1 + 48) )
      {
        v9 = (uint32_t *)*v9;
        if ( !v9 )
          goto LABEL_15;
      }
      alloc_tx_event(aNextTbttTooClo);
LABEL_7:
      v1 = *(uint32_t *)v1;
      if ( !v1 )
        goto LABEL_26;
    }
LABEL_15:
    mmio_reg_addr(v1);
    bt_scan_poll(v1, *(uint32_t *)(v1 + 36) + 3048);
    v10 = 32 * *v5;
    if ( v10 <= 0xBE7 )
      v10 += *(uint16_t *)(v1 + 222) << 10;
    v11 = (*(volatile uint32_t *)0x40501010u) - 3048;
    v12 = v10 + v11;
    if ( *(uint32_t *)(v1 + 72) )
      cfm_dword_get(v1, *(uint32_t *)(v1 + 36), v12);
    if ( *(uint8_t *)(v1 + 1224) )
    {
      mem_copy_util((uint32_t *)(v1 + 24), v12);
    }
    else
    {
      if ( *(uint8_t *)(dword_1211D4 + 0x5A) > 1u )
      {
        for ( i = *(int ***)(dword_1211D4 + 0x10); i; i = (int **)*i )
        {
          if ( *((uint8_t *)i + 8) == *(uint8_t *)(v1 + 107) )
          {
            v26 = *(uint16_t *)(v1 + 222);
            v27 = *(uint32_t *)(v1 + 36);
            v28 = (int)i[1];
            v29 = v27 + (v26 << 10);
            v30 = v26 << 10;
            if ( v28 == v29 )
            {
              i[1] = (int *)v12;
              v28 = v12;
              v30 = *(uint16_t *)(v1 + 222) << 10;
            }
            if ( v27 + 2 * v30 == v28 )
              i[1] = (int *)(v30 + v12);
          }
        }
      }
      if ( *(uint8_t *)dword_1211D8 && (*(uint32_t *)(v0 + 0x10) & 0xFFFF00) == 0x10000 && (uint16_t)*v6 > 0x14u )
      {
        v14 = (*(volatile uint32_t *)0x40501010u);
        v15 = *(uint8_t *)dword_1211E8;
        v16 = v15 == 2;
        v17 = v15 > 2;
        v18 = (uint16_t)*v6;
        if ( v17 )
        {
          mem_copy_util((uint32_t *)dword_1211EC, v14 + 500 * v18);
        }
        else
        {
          if ( v16 )
            v19 = 250;
          else
            v19 = 200;
          mem_copy_util((uint32_t *)dword_1211EC, v14 + v19 * v18);
        }
      }
      *(uint32_t *)(v1 + 36) = v12;
    }
    if ( *(uint8_t *)(v1 + 412) == 1 )
      v7 = v1;
    v1 = *(uint32_t *)v1;
  }
  while ( v1 );
LABEL_26:
  patch_check_enable();
  if ( *(uint8_t *)(dword_1211DC + 0x19D) )
  {
    if ( v7 )
    {
      v13 = dword_1211E0;
      if ( *(uint8_t *)(dword_1211E0 + 0xF) )
      {
        if ( hci_cmd_handler(4u) != 1 )
        {
          if ( !*(uint8_t *)(v13 + 0xE)
            || (v20 = (uint8_t)(*(uint8_t *)(v13 + 0xE) - 1), *(uint8_t *)(v13 + 0xE) = v20, !v20) )
          {
            v21 = *(uint16_t *)(v7 + 222);
            v22 = *(uint32_t *)(v13 + 0x10);
            v23 = (*(volatile uint32_t *)0x40501010u);
            v24 = (uint32_t *)dword_1211F4;
            *(uint32_t *)(v13 + 0x1C) = v7;
            *(uint8_t *)(v13 + 0xE) = *(uint8_t *)(v13 + 0xF);
            mem_copy_util(v24, v23 + ((unsigned int)((v21 << 10) - v22) >> 1));
          }
        }
      }
    }
  }
}
