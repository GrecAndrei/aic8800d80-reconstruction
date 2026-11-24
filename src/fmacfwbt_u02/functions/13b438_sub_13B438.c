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


extern uint32_t dword_13B5F0;
extern uint32_t dword_13B5F4;
extern uint32_t dword_13B5F8;
extern uint32_t dword_13B5FC;
extern uint32_t off_13B5D8;
extern uint32_t off_13B5DC;
extern uint32_t off_13B5E8;
extern uint32_t off_13B5EC;

// rx_process_buffer @ 0x13b438, size 414 bytes
int  rx_process_buffer(int a1, char *a2, unsigned int a3)
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

  if ( hci_cmd_send_short(a3) == 3 )
  {
    v6 = (char *)off_13B5DC + 32 * (a3 >> 8);
    if ( v6[17] )
    {
      if ( v6[17] == 1 )
      {
        if ( a2[2] )
        {
          rf_get_chan_cfg(a3 >> 8);
          check_abort_flag(dword_13B5F8, v6);
          hci_cmd_send(a3, 0);
        }
        else
        {
          v7 = v6[20];
          tx_init_data_buffer((int)off_13B5DC + 32 * (a3 >> 8));
          v8 = (*(volatile uint32_t *)0x40501010u);
          *((uint32_t *)v6 + 2) = v8;
          v9 = *a2;
          v10 = a2[1];
          v11 = (char *)bt_buf_alloc(5131, 13, 5, 3);
          v11[2] = v7 - 4;
          *v11 = v9;
          v11[1] = v10;
          hci_evt_send((int)v11);
          sdio_wr_reg(a3 >> 8);
          hci_cmd_send(a3, 1);
        }
      }
      else if ( **(uint16_t **)off_13B5D8 < 0 )
      {
        mmio_field_update(off_13B5E8, (int)aMmBaAddCfmHand, 218);
      }
    }
    else
    {
      v12 = HIBYTE(((uint32_t *)(uintptr_t)off_13B5EC)[92]);
      if ( HIBYTE(((uint32_t *)(uintptr_t)off_13B5EC)[92]) )
        v12 = *(uint8_t *)(dword_13B5F4
                                 + 1320
                                 * *(uint8_t *)(dword_13B5F0 + 696 * *((uint8_t *)off_13B5DC + 16) + 34)
                                 + 106) == 0;
      v13 = (char *)off_13B5DC + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        dbg_printf(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((uint16_t *)v13 + 10) << 6),
          0x25u,
          0);
        check_abort_flag(dword_13B5FC, v13);
        hci_cmd_send(a3, 0);
      }
      else
      {
        dbg_printf(
          (uint8_t)v13[16],
          (int)v13,
          1,
          (uint8_t)v13[23],
          v12 | (4 * (uint8_t)v13[22]) | (2 * (uint8_t)v13[18]) | (*((uint16_t *)v13 + 10) << 6),
          (uint8_t)a2[2],
          (uint8_t)a2[2]);
        *(uint8_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B5F0 + 452) = BYTE1(a3);
        v14 = (*(volatile uint32_t *)0x40501010u);
        *((uint32_t *)v13 + 2) = v14;
        sdio_wr_reg(a3 >> 8);
        hci_cmd_send(a3, 1);
      }
    }
    return 0;
  }
  if ( **(uint16_t **)off_13B5D8 >= 0 )
    return 0;
  mmio_field_update(off_13B5E8, (int)aMmBaAddCfmHand, 109);
  return 0;
}
