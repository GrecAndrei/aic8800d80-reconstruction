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


extern uint32_t dword_13B414;
extern uint32_t dword_13B418;
extern uint32_t dword_13B41C;
extern uint32_t dword_13B420;
extern uint32_t off_13B3FC;
extern uint32_t off_13B400;
extern uint32_t off_13B40C;
extern uint32_t off_13B410;

// wait_condition_status @ 0x13b25c, size 414 bytes
int  wait_condition_status(int a1, char *a2, unsigned int a3)
{
  char *v6; // r8
  char v7; // r10
  volatile unsigned int v8; // r3
  char v9; // r5
  char v10; // r6
  char *v11; // r0
  uint16_t v12; // r3
  char *v13; // r5
  volatile unsigned int v14; // r3

  if ( hci_cmd_handler(a3) == 3 )
  {
    v6 = (char *)off_13B400 + 32 * (a3 >> 8);
    if ( v6[17] )
    {
      if ( v6[17] == 1 )
      {
        if ( a2[2] )
        {
          get_table_entry_info(a3 >> 8);
          wlan_ioctl_handler_1(dword_13B41C, v6);
          hci_cmd_preprocess(a3, 0);
        }
        else
        {
          v7 = v6[20];
          rx_clear_packet((int)off_13B400 + 32 * (a3 >> 8));
          v8 = (*(volatile uint32_t *)0x40501010u);
          *((uint32_t *)v6 + 2) = v8;
          v9 = *a2;
          v10 = a2[1];
          v11 = (char *)tx_send_pdu(5131, 13, 5, 3);
          v11[2] = v7 - 4;
          *v11 = v9;
          v11[1] = v10;
          rx_process_packet_1((int)v11);
          get_global_base(a3 >> 8);
          hci_cmd_preprocess(a3, 1);
        }
      }
      else if ( **(uint16_t **)off_13B3FC < 0 )
      {
        mmio_write_field(off_13B40C, (int)aMmBaAddCfmHand, 218);
      }
    }
    else
    {
      v12 = HIBYTE(((uint32_t *)(uintptr_t)off_13B410)[92]);
      if ( HIBYTE(((uint32_t *)(uintptr_t)off_13B410)[92]) )
        v12 = *(uint8_t *)(dword_13B418
                                 + 1320
                                 * *(uint8_t *)(dword_13B414 + 696 * *((uint8_t *)off_13B400 + 16) + 34)
                                 + 106) == 0;
      v13 = (char *)off_13B400 + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        init_state_table(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((uint16_t *)v13 + 10) << 6),
          0x25u,
          0);
        wlan_ioctl_handler_1(dword_13B420, v13);
        hci_cmd_preprocess(a3, 0);
      }
      else
      {
        init_state_table(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((uint16_t *)v13 + 10) << 6),
          (uint8_t)a2[2],
          (uint8_t)a2[2]);
        *(uint8_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B414 + 452) = BYTE1(a3);
        v14 = (*(volatile uint32_t *)0x40501010u);
        *((uint32_t *)v13 + 2) = v14;
        get_global_base(a3 >> 8);
        hci_cmd_preprocess(a3, 1);
      }
    }
    return 0;
  }
  if ( **(uint16_t **)off_13B3FC >= 0 )
    return 0;
  mmio_write_field(off_13B40C, (int)aMmBaAddCfmHand, 109);
  return 0;
}
