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


extern uint32_t dword_133F04;
extern uint32_t dword_133F18;
extern uint32_t off_133EF8;
extern uint32_t off_133EFC;
extern uint32_t off_133F00;
extern uint32_t off_133F1C;
extern uint32_t off_133F20;

// ke_lock_and_read @ 0x133d58, size 416 bytes
int  ke_lock_and_read(int a1, int a2, int a3, int a4)
{
  int v4; // r9
  uint16_t v6; // r7
  uint16_t v7; // r6
  uint8_t *v8; // r5
  int v9; // r8
  uint8_t *v10; // r3
  uint16_t **v11; // r10
  uint32_t *v12; // r9
  int *v13; // r1
  int v14; // r2
  int v15; // r3
  int v16; // r3
  int v17; // r0
  int v18; // r6
  int v19; // r4
  int v21; // r1
  int v22; // [sp+0h] [bp-8h] BYREF
  int a2a; // [sp+4h] [bp-4h] BYREF

  v4 = *(uint8_t *)(a2 + 61);
  v6 = a3;
  v7 = a4;
  if ( hci_cmd_handler(6u) != 10 )
  {
    v8 = (uint8_t *)tx_send_pdu(6145, v7, v6, 1);
    if ( hci_cmd_handler(6u) )
    {
      *v8 = 8;
      v19 = 0;
    }
    else if ( *(uint8_t *)(a2 + 61) > 3u
           || (v9 = dword_133F18, v10 = (uint8_t *)(dword_133F18 + 1320 * v4), v10[106]) )
    {
      *v8 = 4;
      v19 = 0;
    }
    else
    {
      if ( !v10[108] )
      {
        v11 = (uint16_t **)off_133F1C;
        if ( **(uint16_t **)off_133F1C < 0 )
        {
          if ( (uint8_t)v10[116] == 255
            || (irq_disable_mmio_write((int)aVifUStaApIdInv, (int)aSmConnectReqHa, 102), **v11 < 0) )
          {
            if ( *(uint32_t *)(v9 + 1320 * v4 + 72) )
              irq_disable_mmio_write((int)aVifChanCtxtNul_0, (int)aSmConnectReqHa, 103);
          }
        }
        v12 = off_133F20;
        *((uint8_t *)off_133F20 + 33) = 0;
        goto LABEL_8;
      }
      v21 = *(uint32_t *)(a2 + 48) & 0x20;
      if ( v21 )
      {
        v12 = off_133F20;
        *((uint8_t *)off_133F20 + 33) = 1;
        alloc_tx_event(aReassoc, v21);
LABEL_8:
        v13 = (int *)off_133EFC;
        v14 = off_133F00;
        *(uint8_t *)off_133EF8 = 0;
        v15 = *v13;
        *(uint8_t *)(v14 + 0x20) = 0;
        *v13 = v15 | 0x10;
        v16 = *(uint8_t *)(a2 + 59);
        *(uint8_t *)(v14 + 0xE) = 1;
        if ( v16 == 3 && mac_backoff_rand(a2 + 64, *(uint16_t *)(a2 + 54), v14, 3) > 0 )
          *(uint8_t *)(a2 + 59) = 0;
        v12[4] = a2;
        v17 = tx_send_pdu(6146, v7, v6, 852);
        v18 = *((uint8_t *)v12 + 33);
        v12[5] = v17;
        if ( v18 )
        {
          memcpy_1((char *)dword_133F04, (char *)(v9 + 1320 * *(uint8_t *)(a2 + 61) + 64), 6u);
          ke_timer_set(v9 + 1320 * *(uint8_t *)(a2 + 61), 0, 0);
        }
        else
        {
          v22 = 0;
          a2a = 0;
          ble_get_addr_flag(&v22, &a2a);
          if ( v22 && a2a )
            ble_parse_event(v22, a2a, 0);
          else
            hci_build_acl(v22, a2a);
        }
        *v8 = 0;
        v19 = 1;
        goto LABEL_13;
      }
      v19 = 0;
      *v8 = 9;
    }
LABEL_13:
    rx_process_packet_1((int)v8);
    return v19;
  }
  return 2;
}
