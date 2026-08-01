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

extern uint32_t dword_12AE20;
extern uint32_t off_12AE24;

// get_state_name @ 0x12adec, size 48 bytes
int  get_state_name(int a1, int a2, int a3, int a4)
{
  int v5; // r4

  v5 = hci_cmd_handler(2);
  check_feature_flag(4, dword_12AE20);
  if ( v5 )
    *((uint8_t *)off_12AE24 + 11) = 1;
  else
    rf_execute_cmd(1, a4);
  return 0;
}

