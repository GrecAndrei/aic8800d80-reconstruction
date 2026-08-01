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

extern uint32_t off_13F200;
extern uint32_t dword_13F204;
extern uint32_t dword_13F20C;
extern uint32_t dword_13F208;
extern uint32_t dword_13F214;
extern uint32_t dword_13F210;

// is_connection_active @ 0x13f158, size 168 bytes
int  is_connection_active(int a1)
{
  int16_t **v1; // r7
  int v2; // r6
  int16_t *v3; // r8
  unsigned int v4; // r5
  unsigned int v6; // r0
  int v7; // r0
  uint32_t v9[10]; // [sp+0h] [bp-28h] BYREF

  v1 = (int16_t **)off_13F200;
  v2 = dword_13F204;
  v3 = *(int16_t **)off_13F200;
  v4 = *(uint32_t *)(dword_13F204 + 696 * a1 + 340);
  if ( **(int16_t **)off_13F200 < 0 && !v4 )
  {
    mmio_irq_clear(dword_13F20C, dword_13F208, 3297);
    v3 = *v1;
  }
  v6 = scan_adv_state_switch(v4);
  *(uint16_t *)(v4 + 184) = v6;
  if ( *v3 < 0 )
  {
    if ( !v6 )
    {
      mmio_irq_clear(dword_13F214, dword_13F208, 3301);
      if ( **v1 >= 0 )
        goto LABEL_3;
      v6 = *(uint16_t *)(v4 + 184);
    }
    if ( v6 > 0xA )
      mmio_irq_clear(dword_13F210, dword_13F208, 3302);
  }
LABEL_3:
  process_packet_queue(v4);
  v7 = tx_handle_acked_list(v4, v9);
  scan_set_adv_flag(v7);
  *(uint8_t *)(v2 + 696 * a1 + 350) |= 1u;
  return 696;
}

