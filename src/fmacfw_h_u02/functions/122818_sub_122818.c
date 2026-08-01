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

extern uint32_t dword_122874;
extern uint32_t dword_122878;

// send_hci_le_meta_event @ 0x122818, size 90 bytes
int  send_hci_le_meta_event(int a1, uint8_t *a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r1

  v5 = tx_send_pdu(118, a4, a3, 12);
  v6 = dword_122874 + 696 * *a2;
  v7 = *(uint8_t *)(v6 + 34);
  if ( v7 == 255 )
    goto LABEL_4;
  v8 = dword_122878 + 1320 * v7;
  v9 = *(uint8_t *)(v8 + 106);
  *(uint32_t *)v5 = *(uint32_t *)(*(uint32_t *)(v6 + 336) + 20);
  *(uint32_t *)(v5 + 4) = 0;
  if ( !v9 )
  {
    *(uint8_t *)(v5 + 8) = *(uint8_t *)(v8 + 142);
LABEL_4:
    rx_process_packet(v5);
    return 0;
  }
  *(uint8_t *)(v5 + 8) = *(uint8_t *)(v6 + 689);
  rx_process_packet(v5);
  return 0;
}

