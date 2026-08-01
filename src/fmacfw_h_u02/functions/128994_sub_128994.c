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

extern uint32_t off_1289E4;
extern uint32_t dword_1289E8;

// bsscfg_current @ 0x128994, size 80 bytes
int  bsscfg_current(int a1)
{
  uint8_t *v1; // r6
  int v2; // r4
  uint8_t *v4; // r0

  v1 = (uint8_t *)off_1289E4;
  v2 = dword_1289E8 + 1320 * *((uint8_t *)off_1289E4 + 16);
  if ( *(uint32_t *)(v2 + 72) )
  {
    bsscfg_get(*((uint8_t *)off_1289E4 + 16));
  }
  else
  {
    v4 = (uint8_t *)tx_send_pdu(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(uint8_t *)(v2 + 107);
    rx_process_packet(v4);
  }
  return bsscfg_index(v1[16], a1);
}

