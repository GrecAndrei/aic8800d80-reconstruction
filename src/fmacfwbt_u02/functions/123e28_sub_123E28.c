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

extern uint32_t off_123EAC;
extern uint32_t off_123EB0;
extern uint32_t off_123EB4;
extern uint32_t dword_123EBC;
extern uint32_t dword_123EB8;

// call_common_handler @ 0x123e28, size 130 bytes
// Doc: sub_1223E28 [unknown]: Unknown helper at 0x1223E28
// sub_1223E28 [unknown]: Unknown helper at 0x1223E28
int  call_common_handler(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r2
  uint16_t *v8; // r5
  int v9; // r3
  int result; // r0

  if ( hci_cmd_send_short(a3) == 3 || hci_cmd_send_short(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = off_123EAC;
  *((uint8_t *)off_123EAC + 31) = v7;
  if ( !v7 )
  {
    if ( hci_cmd_send_short(a3) != 2 )
    {
      write_pmu_control();
LABEL_6:
      hci_evt_alloc_send(35, a4, a3, v9);
      return 0;
    }
    return 2;
  }
  result = hci_cmd_send_short(a3);
  if ( !result )
  {
    if ( **(int16_t **)off_123EB0 < 0 )
    {
      if ( *(uint32_t *)off_123EB4 << 28 )
        mmio_irq_clear(dword_123EBC, dword_123EB8, 1522);
    }
    v9 = 0;
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    rf_check_clk_state(result);
    hci_cmd_send(a3);
    return 2;
  }
  return result;
}

