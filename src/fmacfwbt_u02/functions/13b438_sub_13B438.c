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

extern uint32_t off_13B5DC;
extern uint32_t dword_13B5F8;
extern uint32_t off_13B5E0;
extern uint32_t off_13B5D8;
extern uint32_t dword_13B5E8;
extern uint32_t dword_13B5E4;
extern uint32_t off_13B5EC;
extern uint32_t dword_13B5F4;
extern uint32_t dword_13B5F0;
extern uint32_t dword_13B5FC;

// rx_process_buffer @ 0x13b438, size 414 bytes
int  rx_process_buffer(int a1, char *a2, unsigned int a3)
{
  char *v6; // r8
  char v7; // r10
  char v8; // r5
  uint8_t v9; // r6
  uint8_t *v10; // r0
  uint16_t v11; // r3
  char *v12; // r5
  int v13; // r0
  int v14; // r2
  uint32_t *v15; // r6

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
          tx_init_data_buffer((char *)off_13B5DC + 32 * (a3 >> 8));
          *((uint32_t *)v6 + 2) = *((uint32_t *)off_13B5E0 + 4);
          v8 = *a2;
          v9 = a2[1];
          v10 = (uint8_t *)bt_buf_alloc(5131, 13, 5, 3u);
          v10[2] = v7 - 4;
          *v10 = v8;
          v10[1] = v9;
          hci_evt_send((int)v10);
          sdio_wr_reg(a3 >> 8);
          hci_cmd_send(a3, 1);
        }
      }
      else if ( **(int16_t **)off_13B5D8 < 0 )
      {
        mmio_field_update(dword_13B5E8, dword_13B5E4, 218);
      }
    }
    else
    {
      v11 = *((uint8_t *)off_13B5EC + 371);
      if ( *((uint8_t *)off_13B5EC + 371) )
        v11 = *(uint8_t *)(dword_13B5F4
                                 + 1320
                                 * *(uint8_t *)(dword_13B5F0 + 696 * *((uint8_t *)off_13B5DC + 16) + 34)
                                 + 106) == 0;
      v12 = (char *)off_13B5DC + 32 * (a3 >> 8);
      if ( a2[2] )
      {
        dbg_printf(
          (uint8_t)v12[16],
          v12,
          1,
          (uint8_t)v12[23],
          v11
        | (uint16_t)((4 * (uint8_t)v12[22])
                           | (2 * (uint8_t)v12[18])
                           | (*((uint16_t *)v12 + 10) << 6)),
          37,
          0);
        check_abort_flag(dword_13B5FC, v12);
        hci_cmd_send(a3, 0);
      }
      else
      {
        dbg_printf(
          (uint8_t)v12[16],
          v12,
          1,
          (uint8_t)v12[23],
          v11
        | (uint16_t)((4 * (uint8_t)v12[22])
                           | (2 * (uint8_t)v12[18])
                           | (*((uint16_t *)v12 + 10) << 6)),
          (uint8_t)a2[2],
          (uint8_t)a2[2]);
        v13 = (uint8_t)*a2;
        v14 = (uint8_t)a2[1];
        v15 = off_13B5E0;
        *(uint8_t *)(696 * v13 + 12 * v14 + dword_13B5F0 + 452) = BYTE1(a3);
        *((uint32_t *)v12 + 2) = v15[4];
        sdio_wr_reg(a3 >> 8);
        hci_cmd_send(a3, 1);
      }
    }
    return 0;
  }
  if ( **(int16_t **)off_13B5D8 >= 0 )
    return 0;
  mmio_field_update(dword_13B5E8, dword_13B5E4, 109);
  return 0;
}

