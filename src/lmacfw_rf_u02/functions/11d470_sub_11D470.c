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

extern uint32_t off_11D59C;
extern uint32_t off_11D5A0;
extern uint32_t dword_11D5BC;
extern uint32_t off_11D5A4;
extern uint32_t off_11D5C0;
extern uint32_t off_11D5C4;
extern uint32_t dword_11D5C8;
extern uint32_t off_11D5A8;
extern uint32_t off_11D5AC;
extern uint32_t off_11D5B0;
extern uint32_t dword_11D5B4;
extern uint32_t dword_11D5D0;
extern uint32_t dword_11D5D4;
extern uint32_t dword_11D5D8;
extern uint32_t dword_11D5CC;
extern uint32_t dword_11D5E0;
extern uint32_t dword_11D5DC;
extern uint32_t dword_11D5B8;

// rf_irq_handler @ 0x11d470, size 298 bytes
// Doc: sub_121D470 [mmio]: Copies MMIO register value 0x40328084 to 0x40328088
// sub_121D470 [mmio]: Copies MMIO register value 0x40328084 to 0x40328088
int rf_irq_handler()
{
  int v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r1
  int v4; // r0
  int v5; // r2
  char *v6; // r4
  int v7; // r1

  v0 = *(uint32_t *)off_11D59C;
  *(uint32_t *)off_11D5A0 = *(uint32_t *)off_11D59C;
  if ( (v0 & 0x400) != 0 )
    rf_state_machine();
  result = v0 << 23;
  if ( (v0 & 0x100) != 0 )
    result = hw_timer_load();
  if ( (v0 & 0x200) != 0 )
  {
    dispatch_event_handler(dword_11D5BC, v0 << 22);
    while ( 1 )
      ;
  }
  if ( (v0 & 0x800) == 0 )
  {
    if ( (v0 & 0x10) == 0 )
      goto LABEL_8;
LABEL_24:
    mmio_irq_set(4);
    result = llm_pdu_tx_cfg(4);
    if ( (v0 & 0x2F) == 0 )
      goto LABEL_13;
    goto LABEL_9;
  }
  result = set_busy_flag_alt(0x2000);
  if ( (v0 & 0x10) != 0 )
    goto LABEL_24;
LABEL_8:
  if ( (v0 & 0x2F) == 0 )
    goto LABEL_13;
LABEL_9:
  if ( *(uint8_t *)off_11D5A4 )
  {
    v6 = (char *)off_11D5C0;
    gpio_config(*((uint8_t *)off_11D5C0 + 411));
    v7 = v6[411];
    *((uint8_t *)off_11D5C4 + 9) = v7;
    return dispatch_event_handler(dword_11D5C8, v7);
  }
  if ( *(uint8_t *)off_11D5A8 )
  {
    result = *(uint32_t *)off_11D5AC << 28;
    if ( result )
      *((uint8_t *)off_11D5A8 + 6) = 1;
  }
LABEL_13:
  v2 = **(int16_t **)off_11D5B0;
  if ( v2 >= 0 )
    return result;
  if ( (v0 & 1) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5D0;
    v5 = 760;
    return ke_int_lock(v4, v3, v5, v2);
  }
  if ( (v0 & 2) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5D4;
    v5 = 761;
    return ke_int_lock(v4, v3, v5, v2);
  }
  v2 = v0 << 29;
  if ( (v0 & 4) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5D8;
    v5 = 762;
    return ke_int_lock(v4, v3, v5, v2);
  }
  result = v0 << 28;
  if ( (v0 & 8) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5CC;
    v5 = 763;
    return ke_int_lock(v4, v3, v5, v2);
  }
  if ( (v0 & 0x80) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5E0;
    v5 = 765;
    return ke_int_lock(v4, v3, v5, v2);
  }
  if ( (v0 & 0x40) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5DC;
    v5 = 767;
    return ke_int_lock(v4, v3, v5, v2);
  }
  v2 = v0 << 26;
  if ( (v0 & 0x20) != 0 )
  {
    v3 = dword_11D5B4;
    v4 = dword_11D5B8;
    v5 = 769;
    return ke_int_lock(v4, v3, v5, v2);
  }
  return result;
}

