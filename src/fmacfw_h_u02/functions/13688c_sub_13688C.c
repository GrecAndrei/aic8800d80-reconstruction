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
extern uint32_t off_1369BC;
extern uint32_t off_1369C0;

// send_ble_hci_command @ 0x13688c, size 290 bytes
int  send_ble_hci_command(int a1)
{
  uint8_t *v2; // r6
  int v3; // r0
  uint8_t *v4; // r5
  int *v5; // r3
  unsigned int v6; // r2
  uint8_t *v7; // r0
  int v8; // r0
  int v9; // r1
  uint8_t *v10; // r3
  uint32_t *v11; // r0
  int v13; // r0

  v2 = (uint8_t *)tx_send_pdu(5145, 5, 7, 2);
  v3 = tx_send_pdu(5143, 5, 7, 2);
  *(uint8_t *)(dword_1369B0 + 696 * (*(uint8_t *)(a1 + 107) + 32) + 37) = 0;
  v4 = (uint8_t *)v3;
  is_hci_ready();
  *v2 = 0;
  v2[1] = *(uint8_t *)(a1 + 107);
  wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)v2 - 3);
  v5 = *((int **)off_1369B8 + 2);
  if ( v5 )
  {
    while ( 1 )
    {
      if ( (int *)a1 != v5 )
      {
        if ( *((uint8_t *)v5 + 108) )
        {
          v6 = *((uint16_t *)v5 + 208);
          if ( v6 <= 0x1387 )
            break;
        }
      }
      v5 = (int *)*v5;
      if ( !v5 )
        goto LABEL_6;
    }
    bt_set_address(v6 | (*((uint8_t *)v5 + 413) << 16) | 0x80000000);
  }
  else
  {
LABEL_6:
    bt_set_address(0);
  }
  check_non_null((int *)a1, 0, 0);
  if ( *(uint8_t *)(a1 + 108) )
  {
    v13 = tx_send_pdu(30, 0, 7, 4);
    *(uint8_t *)(v13 + 2) = 0;
    *(uint8_t *)(v13 + 3) = *(uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)(v13 - 12));
  }
  if ( *(uint32_t *)(a1 + 72) )
  {
    v7 = (uint8_t *)tx_send_pdu(57, 0, 7, 1);
    *v7 = *(uint8_t *)(a1 + 107);
    wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)v7 - 3);
  }
  *v4 = 0;
  v4[1] = *(uint8_t *)(a1 + 107);
  v8 = wlan_ioctl_handler_1(dword_1369B4, (uint32_t *)v4 - 3);
  acquire_lock_check_state(v8, v9);
  if ( !*(uint8_t *)(a1 + 1224) )
  {
    *(uint8_t *)off_1369C0 = 0;
    alloc_tx_event(aApLpExit);
  }
  v10 = off_1369BC;
  v11 = (uint32_t *)((char *)off_1369BC + 20);
  *((uint8_t *)off_1369BC + 13) = 0;
  v10[14] = 0;
  mem_set_util(v11);
  return hci_cmd_preprocess(7u, 3);
}
