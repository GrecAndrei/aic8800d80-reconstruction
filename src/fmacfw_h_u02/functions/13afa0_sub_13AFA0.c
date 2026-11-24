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


extern uint32_t dword_13B21C;
extern uint32_t dword_13B228;
extern uint32_t dword_13B22C;
extern uint32_t dword_13B230;
extern uint32_t dword_13B234;
extern uint32_t dword_13B238;
extern uint32_t dword_13B23C;
extern uint32_t dword_13B244;
extern uint32_t off_13B220;
extern uint32_t off_13B248;
extern uint32_t off_13B24C;

// parse_packet_header @ 0x13afa0, size 636 bytes
int  parse_packet_header(int a1, int a2, unsigned int a3)
{
  int v3; // r3
  int v6; // r5
  unsigned int v7; // r6
  unsigned int v9; // r7
  int v10; // r8
  unsigned int v11; // r2
  int v12; // r11
  unsigned int a5; // r7
  unsigned int v14; // r10
  uint16_t v15; // r8
  int v16; // r9
  uint16_t v17; // r3
  int v18; // r1
  int v19; // r4
  int v20; // r2
  volatile unsigned int v21; // r1
  int v22; // r8
  unsigned int v23; // r8
  uint16_t v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r7
  char v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r5
  int v32; // r3
  int a4; // [sp+14h] [bp-10h]
  uint32_t *a4a; // [sp+14h] [bp-10h]
  uint32_t *a2a; // [sp+1Ch] [bp-8h]

  v3 = *(uint8_t *)(a2 + 13);
  v6 = a2 + 12;
  v7 = a3 >> 8;
  if ( v3 == 1 )
  {
    v9 = *(uint16_t *)(a2 + 17);
    if ( hci_cmd_handler(a3) != 2 )
      return 0;
    v10 = dword_13B228;
    invalid_handler_12c5fc((char *)0x2000, a3);
    v11 = v10 + 32 * v7;
    v12 = 32 * v7;
    if ( *(uint8_t *)(v11 + 23) != *(uint8_t *)(v6 + 2)
      || *(uint8_t *)(v11 + 22) != ((v9 >> 2) & 0xF)
      || *(uint16_t *)(v6 + 3) )
    {
      get_table_entry_info(v7);
      wlan_ioctl_handler_1(dword_13B21C, (uint32_t *)(v10 + v12));
      hci_cmd_preprocess(a3, 0);
      return 0;
    }
    if ( *(uint16_t *)(v11 + 20) > v9 >> 6 )
      *(uint16_t *)(v11 + 20) = v9 >> 6;
    v29 = *((uint8_t *)off_13B24C + 377);
    v30 = v10 + v12;
    if ( v29 != 1 )
    {
      if ( v29 != 2 )
      {
        *(uint8_t *)(v30 + 24) = v9 & 1;
LABEL_38:
        v27 = *(uint8_t *)(a2 + 7);
        v28 = v7;
LABEL_31:
        build_hci_event(v27, v28);
        hci_cmd_preprocess(a3, 3);
        return 0;
      }
      LOBYTE(v29) = 0;
    }
    *(uint8_t *)(v30 + 24) = v29;
    goto LABEL_38;
  }
  if ( v3 == 2 )
  {
    if ( hci_cmd_handler(a3) != 4 )
    {
      if ( hci_cmd_handler(a3) == 1 || hci_cmd_handler(a3) == 3 )
      {
        hci_cmd_preprocess(a3, 4);
        a4a = (uint32_t *)(dword_13B228 + 32 * v7);
        if ( v7 > 0xF )
        {
          wlan_ioctl_handler_3(dword_13B234, (uint32_t *)(dword_13B228 + 32 * v7));
          wlan_ioctl_handler_1(dword_13B238, a4a);
        }
        else
        {
          wlan_ioctl_handler_3(dword_13B22C, (uint32_t *)(dword_13B228 + 32 * v7));
          wlan_ioctl_handler_1(dword_13B230, a4a);
        }
        rf_set_frequency_1(*(uint8_t *)(a2 + 7), v7);
        return 0;
      }
      v18 = dword_13B228 + 32 * v7;
      v19 = *(uint8_t *)(v18 + 16);
      v20 = *(uint8_t *)(v18 + 22);
      v21 = (*(volatile uint32_t *)0x40501010u);
      *(uint32_t *)(696 * v19 + 12 * v20 + dword_13B23C + 448) = v21;
      send_vendor_command_1(v7);
    }
    return 0;
  }
  if ( *(uint8_t *)(a2 + 13) )
    return 0;
  a5 = *(uint16_t *)(a2 + 15);
  v14 = (a5 >> 2) & 0xF;
  if ( v14 > 8 )
    return 0;
  v15 = *(uint8_t *)off_13B220;
  if ( *(uint8_t *)off_13B220 )
    return 0;
  v16 = *(uint8_t *)(a2 + 7);
  a4 = *(uint8_t *)(a2 + 14);
  check_feature_flag(2048, "handle addba_req:tid=%d\r\n", (a5 >> 2) & 0xF);
  if ( !ll_get_tx_power_alt(v16, (a5 >> 2) & 0xF) )
  {
    if ( hci_cmd_handler(a3) == 4 )
      return 2;
    v22 = dword_13B228;
    a2a = (uint32_t *)(dword_13B228 + 32 * v7);
    if ( list_contains((uint32_t **)dword_13B244, a2a) )
      wlan_ioctl_handler_3(dword_13B244, a2a);
    v23 = v22 + 32 * v7;
    *(uint8_t *)(v23 + 22) = v14;
    *(uint8_t *)(v23 + 16) = v16;
    *(uint8_t *)(v23 + 23) = a4;
    *(uint8_t *)(v23 + 18) = (a5 & 2) != 0;
    *(uint8_t *)(v23 + 17) = 0;
    v24 = *(uint16_t *)(v6 + 5);
    v25 = *(uint16_t *)(v6 + 7);
    *(uint16_t *)(v23 + 14) = v24;
    v26 = a5 >> 6;
    if ( v26 >= 0x40 )
      LOWORD(v26) = 64;
    *(uint16_t *)(v23 + 20) = v26;
    *(uint16_t *)(v23 + 12) = v25 >> 4;
    *(uint32_t *)(v23 + 4) = 0;
    if ( !v24 )
      *(uint16_t *)(v23 + 14) = *(uint16_t *)(*(uint32_t *)off_13B248 + 2);
    v27 = v16;
    v28 = v7;
    goto LABEL_31;
  }
  if ( hci_cmd_handler(a3) == 1 )
  {
    v31 = dword_13B228 + 32 * v7;
    v32 = a5 >> 6;
    if ( a5 >> 6 >= 0x40 )
      v32 = 64;
    if ( *(uint16_t *)(v31 + 20) == v32 )
    {
      v17 = v15;
    }
    else
    {
      hci_cmd_preprocess(a3, 4);
      wlan_ioctl_handler_3(dword_13B22C, (uint32_t *)v31);
      wlan_ioctl_handler_1(dword_13B230, (uint32_t *)v31);
      rf_set_frequency_1(v16, v7);
      v17 = 37;
    }
  }
  else
  {
    v17 = 37;
  }
  init_state_table(v16, 0, 1, a4, a5, v17, 0);
  return 0;
}
