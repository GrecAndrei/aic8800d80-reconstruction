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

extern uint32_t off_13429C;
extern uint32_t off_1342A0;
extern uint32_t off_1342A4;
extern uint32_t dword_1342A8;

// unknown_func_13424c @ 0x13424c, size 80 bytes
int unknown_func_13424c()
{
  int *v0; // r4
  uint8_t *v1; // r2
  int v2; // r1
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_13429C = 1;
  }
  v0 = (int *)off_1342A0;
  v1 = off_1342A4;
  v2 = *((uint8_t *)off_1342A4 + 15);
  v3 = *(uint32_t *)off_1342A0 + 1;
  *(uint32_t *)off_1342A0 = v3;
  if ( v2 )
  {
    hci_send_test_command();
    v3 = *v0;
  }
  else if ( v1[14] == 1 )
  {
    ble_scan_config();
    v3 = *v0;
  }
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(uint32_t *)off_13429C;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  alloc_tx_event(dword_1342A8);
  return 0;
}

