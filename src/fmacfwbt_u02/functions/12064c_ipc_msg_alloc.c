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

extern uint32_t off_120728;
extern uint32_t off_120724;
extern uint32_t dword_120720;

// alloc_buffer @ 0x12064c, size 210 bytes
// Doc: alloc_buffer [ipc]: Allocate IPC message buffer (id 0xd, size 0x58)
// alloc_buffer [ipc]: Allocate IPC message buffer (id 0xd, size 0x58)
int  alloc_buffer(int a1)
{
  uint8_t *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r0
  char v6; // r1
  int v7; // r3
  int v8; // r7
  char v10[5]; // [sp+7h] [bp-5h] BYREF

  v2 = (uint8_t *)bt_buf_alloc(88, 13, 0, 3);
  v3 = *(uint8_t *)(a1 + 107);
  v10[0] = -1;
  get_entry_by_index(v3);
  v4 = *(uint32_t *)(a1 + 1216);
  *(uint32_t *)(a1 + 412) = *(uint32_t *)(a1 + 1212);
  *(uint32_t *)(a1 + 416) = v4;
  *(uint16_t *)(a1 + 420) = *(uint16_t *)(a1 + 1220);
  *(uint8_t *)(a1 + 464) = 0;
  scan_rssi_compare(a1);
  v5 = find_free_conn(a1 + 1212, v10);
  v6 = v10[0];
  v2[1] = v5;
  v2[2] = v6;
  *v2 = *(uint8_t *)(a1 + 107);
  v7 = *(uint8_t *)(a1 + 106);
  if ( *(uint8_t *)(a1 + 106) )
  {
    if ( v7 == 2 )
    {
      *(uint8_t *)(a1 + 231) = 0;
      if ( !v5 )
      {
        update_entries_from_config();
        *((uint8_t *)off_120728 + 9) = 1;
      }
    }
    return hci_evt_send(v2);
  }
  *(uint8_t *)(a1 + 146) = v7;
  if ( !v5 )
  {
    v8 = *(uint8_t *)(a1 + 116);
    update_entries_from_config();
    ke_event_set_lock(a1 + 48);
    ke_event_lock(a1 + 24, *((uint32_t *)off_120724 + 4) + *(uint32_t *)(dword_120720 + 696 * v8 + 8));
    *(uint8_t *)(a1 + 128) = 0;
    *(uint8_t *)(a1 + 147) = 1;
    return hci_evt_send(v2);
  }
  mmio_read_phy(a1);
  return hci_evt_send(v2);
}

