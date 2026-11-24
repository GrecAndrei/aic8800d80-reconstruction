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


extern uint32_t dword_11DC00;
extern uint32_t off_11DBD4;
extern uint32_t off_11DBD8;
extern uint32_t off_11DBDC;
extern uint32_t off_11DBE4;
extern uint32_t off_11DBE8;
extern uint32_t off_11DBEC;
extern uint32_t off_11DBF4;
extern uint32_t off_11DBF8;
extern uint32_t off_11DBFC;
extern uint32_t off_11DC04;
extern uint32_t off_11DC08;

// radio_init @ 0x11da70, size 356 bytes
int  radio_init(int a1)
{
  uint32_t *v1; // r7
  int *v2; // r9
  int v3; // r8
  uint32_t *v4; // r11
  uint32_t *v5; // r10
  int i; // r5
  int v8; // r2
  BOOL v9; // r0
  int v10; // r3
  unsigned int v11; // r4
  int result; // r0
  void ( *v13)(uint32_t); // r2
  BOOL v14; // r0
  uint32_t *v15; // r5
  int v16; // [sp+14h] [bp-8h]

  v1 = off_11DBD4;
  v2 = (int *)off_11DBF4;
  v3 = dword_11DC00;
  v4 = off_11DC04;
  v5 = off_11DC08;
  for ( i = 0; ; ++i )
  {
    v11 = rf_status_poll();
    *v1 = 0x10000;
    result = unknown_func_12d14c(0x80000);
    if ( !v11 )
      break;
    if ( !a1 )
    {
      if ( *((uint8_t *)v2 + 192) )
      {
        if ( *(uint32_t *)off_11DBD8 > 0x80000u || i > 31 )
          return unknown_func_12d104(0x80000);
      }
      else if ( i > 3 )
      {
        return unknown_func_12d104(0x80000);
      }
    }
    if ( !check_rom_state() || !rf_chan_enabled() )
    {
      *((uint8_t *)off_11DBEC + 69) = 1;
      v14 = rf_chan_enabled();
      return check_status_bits(1024, "no host buffer:%d\r\n", !v14);
    }
    v8 = *(uint32_t *)(v11 + 20);
    if ( v8 != v3 )
      event_dispatch(
        "rxbuf1 %08x,%08x: start %08x, end %08x, read %08x, wrptr %08x, rdptr %08x\r\n",
        v11,
        v8,
        *(uint32_t *)off_11DBDC,
        *((uint32_t *)off_11DBDC + 1),
        *((uint32_t *)off_11DBDC + 2),
        *v4,
        *v5);
    ke_task_state_get(v11);
    v9 = rf_rx_check(v11);
    if ( v9 )
    {
      if ( !v9 )
        goto LABEL_10;
    }
    else if ( tx_check_allow(v11) )
    {
      goto LABEL_10;
    }
    llm_evt_queue_pop(v11);
LABEL_10:
    v10 = **(uint8_t **)off_11DBE4;
    switch ( v10 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(uint32_t *)off_11DBE8 || *(uint32_t *)(*(uint32_t *)off_11DBE8 + 12) != v11 || (*(uint8_t *)(v11 + 16) & 1) == 0 )
        {
LABEL_22:
          mac_wait_scan();
          continue;
        }
        v16 = *(uint32_t *)off_11DBE8;
        mem_word_load(off_11DBE8);
        v13 = *(void ( **)(uint32_t))(v16 + 4);
        *(uint8_t *)(v16 + 16) = 0;
        if ( v13 )
          v13(*(uint32_t *)(v16 + 8));
        radio_get_status(v11);
        break;
      case 3:
        mac_wait_tx();
        break;
    }
  }
  if ( LOBYTE(((uint32_t *)(uintptr_t)off_11DBF4)[48]) )
  {
    v15 = off_11DBF8;
    if ( *((uint8_t *)off_11DBF8 + 33) )
    {
      result = unknown_1(*((uint32_t *)off_11DBF8 + 4), *((uint32_t *)off_11DBF8 + 5), *((uint32_t *)off_11DBF8 + 6));
      v15[5] = 0;
      v15[7] = 0;
      v15[4] = 0;
      v15[6] = 0;
      *((uint8_t *)v15 + 33) = 0;
    }
  }
  *(uint32_t *)off_11DBFC |= 0x10000u;
  return result;
}
