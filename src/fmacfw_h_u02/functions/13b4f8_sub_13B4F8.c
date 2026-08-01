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

extern uint32_t dword_13B530;
extern uint32_t dword_13B52C;

// check_wait_status_2 @ 0x13b4f8, size 50 bytes
int  check_wait_status_2(int a1, int a2, unsigned int a3)
{
  if ( hci_cmd_handler(a3) == 2 )
  {
    get_table_entry_info(a3 >> 8);
    wlan_ioctl_handler_1(dword_13B530, (uint32_t *)(dword_13B52C + 32 * (a3 >> 8)));
    hci_cmd_preprocess(a3, 0);
  }
  return 0;
}

