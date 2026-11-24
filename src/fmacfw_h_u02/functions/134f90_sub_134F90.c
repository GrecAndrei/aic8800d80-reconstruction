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


extern uint32_t off_135020;

// acl_rx_process @ 0x134f90, size 142 bytes
int  acl_rx_process(int a1, int a2)
{
  int v2; // r5
  uint8_t *v3; // r7
  int result; // r0
  uint16_t v7; // r5

  v2 = *(uint32_t *)(a1 + 72);
  v3 = off_135020;
  check_feature_flag(
    256,
    "tx cfm:%d,%x,%x\r\n",
    *((uint8_t *)off_135020 + 34),
    a2,
    (uint8_t)*(uint16_t *)(v2 + 108));
  if ( !v3[34] )
    return assert_trace(1);
  v7 = *(uint16_t *)(v2 + 108);
  if ( hci_cmd_handler(6u) != 5 )
  {
    result = hci_cmd_handler(6u);
    if ( result != 8 )
    {
LABEL_5:
      v3[34] = 0;
      return result;
    }
  }
  result = hci_cmd_handler(6u);
  if ( result == 5 && (v7 & 0xFC) == 0xB0 || (result = hci_cmd_handler(6u), result == 8) && (v7 & 0xDC) == 0 )
  {
    if ( (a2 & 0x800000) == 0 )
    {
      result = sec_check(a1, 5);
      *(uint8_t *)(a1 + 98) = 1;
      return result;
    }
    goto LABEL_5;
  }
  return result;
}
