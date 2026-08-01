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

extern uint32_t off_13537C;
extern uint32_t dword_135380;

// get_conn_info @ 0x1352ec, size 142 bytes
int  get_conn_info(int a1, int a2)
{
  int v2; // r5
  uint8_t *v3; // r7
  int result; // r0
  int16_t v7; // r5

  v2 = *(uint32_t *)(a1 + 72);
  v3 = off_13537C;
  state_check_feature(
    256,
    dword_135380,
    *((uint8_t *)off_13537C + 34),
    a2,
    (uint8_t)*(uint16_t *)(v2 + 108));
  if ( !v3[34] )
    return event_dispatch(1);
  v7 = *(uint16_t *)(v2 + 108);
  if ( hci_cmd_send_short(6u) != 5 )
  {
    result = hci_cmd_send_short(6u);
    if ( result != 8 )
    {
LABEL_5:
      v3[34] = 0;
      return result;
    }
  }
  result = hci_cmd_send_short(6u);
  if ( result == 5 && (v7 & 0xFC) == 0xB0 || (result = hci_cmd_send_short(6u), result == 8) && (v7 & 0xDC) == 0 )
  {
    if ( (a2 & 0x800000) == 0 )
    {
      result = ble_event_dispatch(a1, 5);
      *(uint8_t *)(a1 + 98) = 1;
      return result;
    }
    goto LABEL_5;
  }
  return result;
}

