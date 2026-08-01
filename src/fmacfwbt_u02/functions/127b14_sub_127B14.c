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

extern uint32_t off_127B74;
extern uint32_t off_127B78;

// tx_acl_packet @ 0x127b14, size 94 bytes
int  tx_acl_packet(int a1)
{
  int result; // r0
  char v3; // r3
  int v4; // r3

  result = ke_event_lock(a1 + 24, *(uint32_t *)(a1 + 36) + *(uint32_t *)(a1 + 88));
  v3 = *(uint8_t *)(a1 + 85);
  *(uint8_t *)(a1 + 85) = v3 & 0xDF;
  if ( (v3 & 1) != 0 )
  {
    v4 = *((uint32_t *)off_127B74 + 9);
    if ( v4 && *(uint32_t *)(v4 + 12) == a1 + 76 )
    {
      hci_acl_buf_alloc();
      scan_adv_report(a1, *(uint32_t *)(a1 + 36), 0);
      return hci_send_acl(a1, *((uint32_t *)off_127B78 + 4), 0);
    }
    else
    {
      return scan_adv_report(a1, *(uint32_t *)(a1 + 36), 0);
    }
  }
  return result;
}

