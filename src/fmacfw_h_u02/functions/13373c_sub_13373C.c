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

// hci_opcode_check @ 0x13373c, size 98 bytes
int  hci_opcode_check(int a1, int a2)
{
  int v2; // r3

  v2 = *(uint16_t *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( hci_cmd_handler(6u) == 5 )
        ke_msg_handler(a2);
      break;
    case 16:
    case 48:
      if ( hci_cmd_handler(6u) == 8 )
        hci_send_vendor_cmd(a2);
      break;
    case 192:
    case 160:
      return sub_135528(a2);
    default:
      if ( v2 == 208 && *(uint8_t *)(a2 + 12) == 8 )
        ll_conn_get_by_index(a2);
      break;
  }
  return 0;
}

