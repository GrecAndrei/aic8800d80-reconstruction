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

extern uint32_t dword_1369B0;
extern uint32_t dword_1369B4;
extern uint32_t off_1369B8;
extern uint32_t dword_1369C4;
extern uint32_t off_1369C0;
extern uint32_t off_1369BC;

// send_ble_hci_command @ 0x13688c, size 290 bytes
uint32_t * send_ble_hci_command(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int v5; // r1
  unsigned int v6; // r2
  int *v7; // r3
  uint8_t *v8; // r0
  uint8_t *v9; // r3
  char *v10; // r0
  int v12; // r0
  int v13; // r0

  v2 = (uint8_t *)tx_send_pdu(5145, 5, 7, 2u);
  v3 = tx_send_pdu(5143, 5, 7, 2u);
  *(uint8_t *)(dword_1369B0 + 696 * (*(uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  is_hci_ready();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)v2 - 3);
  v7 = *((int **)off_1369B8 + 2);
  if ( v7 )
  {
    v5 = 4999;
    while ( 1 )
    {
      if ( (int *)a1 != v7 )
      {
        v6 = *((uint8_t *)v7 + 108);
        if ( *((uint8_t *)v7 + 108) )
        {
          v6 = *((uint16_t *)v7 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v7 = (int *)*v7;
      if ( !v7 )
        goto LABEL_7;
    }
    bt_set_address(v6 | (*((uint8_t *)v7 + 413) << 16) | 0x80000000, 4999, v6);
  }
  else
  {
LABEL_7:
    bt_set_address(0, v5, v6);
  }
  check_non_null((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v12 = tx_send_pdu(30, 0, 7, 4u);
    *(uint8_t *)(v12 + 2) = 0;
    *(uint8_t *)(v12 + 3) = *(uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)(v12 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v8 = (uint8_t *)tx_send_pdu(57, 0, 7, 1u);
    *v8 = *(uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)v8 - 3);
  }
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)v4 - 3);
  acquire_lock_check_state();
  if ( !*(uint8_t *)(a1 + 1224) )
  {
    v13 = dword_1369C4;
    *(uint8_t *)off_1369C0 = 0;
    alloc_tx_event(v13);
  }
  v9 = off_1369BC;
  v10 = (char *)off_1369BC + 20;
  *((uint8_t *)off_1369BC + 13) = 0;
  v9[14] = 0;
  mem_set_util((int)v10);
  return hci_cmd_preprocess(7u, 3);
}

