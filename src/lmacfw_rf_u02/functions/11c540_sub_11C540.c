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


extern uint32_t dword_11C74C;
extern uint32_t dword_11C764;
extern uint32_t dword_11C774;
extern uint32_t off_11C750;
extern uint32_t off_11C768;
extern uint32_t off_11C77C;

// bt_conn_rx_schedule @ 0x11c540, size 522 bytes
int  bt_conn_rx_schedule(int a1)
{
  uint16_t **v1; // r8
  int v2; // r6
  int v3; // r5
  int v5; // r10
  int v6; // r9
  int v7; // r7
  char v8; // r3
  char v9; // r3
  int v10; // r6
  int v11; // r3
  char v12; // r4
  uint16_t *v14; // r2
  unsigned int v15; // r3
  int v16; // r1
  int v17; // r3
  int v18; // r2
  char *v19; // r1
  int v20; // r3
  int v21; // r1
  int v22; // r3
  uint32_t *v23; // r4
  int v24; // r2
  int v25; // r3

  v1 = (uint16_t **)off_11C77C;
  v2 = dword_11C74C;
  v3 = *(uint32_t *)(dword_11C74C + 224 * a1 + 72);
  v5 = 8 * a1;
  if ( **(uint16_t **)off_11C77C < 0 && !v3 )
    flash_ctrl_init((int)aCtxtNull, (int)aChanCtxtUnlink, 3149);
  v6 = v2 + 32 * (v5 - a1);
  v7 = off_11C750;
  check_interrupt_flag(
    256,
    "chan unlink: %d,%d,%d,%d,%d\r\n",
    *(uint8_t *)(v3 + 25),
    *(uint8_t *)(off_11C750 + 0x5B),
    *(uint8_t *)(off_11C750 + 0x5A),
    *(uint8_t *)(v6 + 85),
    *(uint8_t *)(v3 + 16));
  check_kernel_state_alt2(v7 + 16, (uint32_t *)(v2 + 224 * a1 + 76));
  v8 = *(uint8_t *)(v6 + 85);
  *(uint8_t *)(v6 + 85) = v8 & 0xFE;
  if ( (v8 & 2) != 0 )
  {
    v9 = *(uint8_t *)(v7 + 0x5B) - 1;
    *(uint8_t *)(v7 + 0x5B) = v9;
    if ( !v9 && (*(uint8_t *)(v7 + 0x58) & 0x40) != 0 )
    {
      dispatch_event_handler_1(aUnlinkFixUntil);
      rf_register_access(*(uint32_t *)(v7 + 0x50));
    }
  }
  v10 = v2 + 32 * (v5 - a1);
  *(uint8_t *)(v10 + 85) = 0;
  *(uint32_t *)(v10 + 72) = 0;
  v11 = *(uint8_t *)(v3 + 16);
  v12 = *(uint8_t *)(v3 + 25) - 1;
  *(uint8_t *)(v3 + 25) = v12;
  if ( v11 && !v12 )
  {
    check_kernel_state_alt2(dword_11C764, (uint32_t *)v3);
    *(uint8_t *)(v3 + 16) = 0;
    v14 = *v1;
    v15 = (uint8_t)(*(uint8_t *)(v7 + 0x5A) - 1);
    *(uint8_t *)(v7 + 0x5A) = v15;
    if ( *v14 < 0 && v15 > 1 )
    {
      flash_ctrl_init((int)aChanEnvNbSched, (int)aChanCtxtUnlink, 3210);
      v15 = *(uint8_t *)(v7 + 0x5A);
    }
    if ( v15 )
    {
      list_init_1((uint32_t *)dword_11C774);
      v20 = dword_11C74C;
      v21 = dword_11C74C + 896;
      do
      {
        *(uint8_t *)(v20 + 85) &= ~1u;
        v20 += 224;
      }
      while ( v21 != v20 );
      if ( !*(uint32_t *)(v7 + 0x50) )
        rx_buffer_alloc();
    }
    if ( *(uint32_t *)(v7 + 0x28) != v3 )
    {
      if ( *(uint32_t *)(v7 + 0x2C) != v3 )
        return bt_conn_find_by_ptr(v3);
      v16 = *(uint8_t *)(v3 + 24);
      v17 = v16 + 1;
      if ( v16 == 2 )
      {
        if ( *((uint8_t *)off_11C768 + 24) != 255 )
        {
          v17 = 0;
          v18 = 0;
          goto LABEL_41;
        }
        v17 = 1;
      }
      else
      {
        v18 = 8 * v17;
        if ( *((uint8_t *)off_11C768 + 28 * v17 + 24) != 255 )
          goto LABEL_41;
        v17 = v16 + 2;
        if ( v16 == 1 )
          v17 = 0;
      }
      v18 = 8 * v17;
      if ( *((uint8_t *)off_11C768 + 28 * v17 + 24) == 255 )
      {
        v19 = nullptr;
LABEL_22:
        *(uint32_t *)(v7 + 0x2C) = v19;
        dispatch_event_handler_1("unlink replace sw ctxt:%x\n", v19);
        return bt_conn_find_by_ptr(v3);
      }
LABEL_41:
      v19 = (char *)off_11C768 + 4 * (v18 - v17);
      goto LABEL_22;
    }
    v22 = *(uint8_t *)(v7 + 0x5A);
    *(uint32_t *)(v7 + 0x28) = 0;
    if ( !v22 )
      return bt_conn_find_by_ptr(v3);
    v23 = *(uint32_t **)(v7 + 0x2C);
    if ( v23 )
      return bt_conn_find_by_ptr(v3);
    dispatch_event_handler_1(aUnlinkSwChan);
    v24 = *(uint8_t *)(v3 + 24);
    v25 = v24 + 1;
    if ( v24 == 2 )
    {
      if ( *((uint8_t *)off_11C768 + 24) == 255 )
      {
        v25 = 1;
        goto LABEL_35;
      }
      v25 = 0;
    }
    else if ( *((uint8_t *)off_11C768 + 28 * v25 + 24) == 255 )
    {
      v25 = v24 + 2;
      if ( v24 == 1 )
        v25 = 0;
LABEL_35:
      if ( *((uint8_t *)off_11C768 + 28 * v25 + 24) == 255 )
        goto LABEL_36;
    }
    v23 = (uint32_t *)((char *)off_11C768 + 28 * v25);
LABEL_36:
    if ( *(uint32_t *)(v7 + 0x2C) )
      *(uint32_t *)(v7 + 0x2C) = v23;
    else
      list_search(v23);
  }
  return bt_conn_find_by_ptr(v3);
}
