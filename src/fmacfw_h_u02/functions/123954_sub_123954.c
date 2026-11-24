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


extern uint32_t dword_123A0C;
extern uint32_t off_123A10;
extern uint32_t off_123A24;

// list_check_first @ 0x123954, size 182 bytes
void  list_check_first(int a1, int a2, int a3, int a4)
{
  uint16_t **v4; // r8
  int v5; // r0
  int v9; // [sp+0h] [bp-28h]
  uint16_t a1a[2]; // [sp+4h] [bp-24h] BYREF
  char v11; // [sp+Dh] [bp-1Bh]
  uint32_t v12[6]; // [sp+10h] [bp-18h] BYREF

  v4 = (uint16_t **)off_123A24;
  v5 = **(uint16_t **)off_123A24;
  memset(v12, 0, sizeof(v12));
  if ( v5 < 0 && hci_cmd_handler(a3) )
    irq_disable_mmio_write((int)aKeStateGetDest, (int)aMmStartReqHand, 337);
  set_rf_channel((int *)a2);
  v11 = 0;
  check_boot_flag(a1a, 0, dword_123A0C, 2484, v9, dword_123A0C, 2484);
  call_stack_helper(15);
  *((uint16_t *)off_123A10 + 14) = *(uint16_t *)(a2 + 68);
  poll_hw_ready((int)v12);
  if ( **v4 < 0 && (uint8_t)a4 > 0xEu )
  {
    irq_disable_mmio_write((int)aIdTaskMax, (int)aKeTaskLocal_2, 183);
    goto LABEL_7;
  }
  if ( (uint8_t)a4 > 0xCu )
LABEL_7:
    mac_write_header_word(3, a4, a3);
  rf_write_reg();
  rf_status_check();
  hci_cmd_preprocess(a3, 2);
}
