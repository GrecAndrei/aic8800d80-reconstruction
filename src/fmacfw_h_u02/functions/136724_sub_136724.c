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

extern uint32_t dword_136848;
extern uint32_t off_13683C;
extern uint32_t off_136840;
extern uint32_t dword_136844;

// send_hci_event @ 0x136724, size 280 bytes
uint32_t *send_hci_event()
{
  int v0; // r11
  int v1; // r4
  int v2; // r9
  int v3; // r6
  int v4; // r5
  int v5; // r8
  int v6; // r10
  uint8_t *v7; // r7
  int v8; // r9
  int v9; // r0
  int v10; // r0
  uint8_t *v12; // r0

  v0 = dword_136848;
  v1 = *(uint32_t *)off_13683C;
  v2 = *(uint8_t *)(*(uint32_t *)off_13683C + 51);
  v3 = tx_send_pdu(24, 0, 7, 8u);
  v4 = tx_send_pdu(22, 0, 7, 8u);
  v5 = tx_send_pdu(20, 0, 7, 4u);
  v6 = v0 + 1320 * v2;
  v7 = (uint8_t *)tx_send_pdu(5143, 5, 7, 2u);
  is_hci_ready();
  if ( *(uint8_t *)(v6 + 1224) )
  {
    *(uint32_t *)off_136840 &= ~4u;
    *(uint32_t *)(v6 + 4) |= 0x20u;
  }
  else
  {
    v12 = (uint8_t *)tx_send_pdu(5145, 5, 7, 2u);
    *v12 = 1;
    v12[1] = *(uint8_t *)(v6 + 107);
    wlan_ioctl_handler_1((int)off_13683C + 4, (uint32_t *)v12 - 3);
  }
  v8 = v0 + 1320 * v2;
  v9 = *(uint32_t *)(v8 + 100);
  *(uint16_t *)(v3 + 4) = *(uint16_t *)(v8 + 104);
  *(uint32_t *)v3 = v9;
  *(uint8_t *)(v3 + 6) = *(uint8_t *)(v1 + 51);
  wlan_ioctl_handler_1(dword_136844, (uint32_t *)(v3 - 12));
  *(uint8_t *)(v4 + 5) = *(uint8_t *)(v1 + 16);
  *(uint32_t *)v4 = handle_rx_packet((uint8_t *)v1, 1);
  *(uint8_t *)(v4 + 4) = *(uint8_t *)(v1 + 51);
  wlan_ioctl_handler_1(dword_136844, (uint32_t *)(v4 - 12));
  *(uint16_t *)v5 = *(uint16_t *)(v1 + 40);
  *(uint8_t *)(v5 + 2) = *(uint8_t *)(v1 + 51);
  wlan_ioctl_handler_1(dword_136844, (uint32_t *)(v5 - 12));
  *v7 = 1;
  v10 = dword_136844;
  v7[1] = *(uint8_t *)(v1 + 51);
  wlan_ioctl_handler_1(v10, (uint32_t *)v7 - 3);
  acquire_lock_check_state();
  return hci_cmd_preprocess(7u, 1);
}

