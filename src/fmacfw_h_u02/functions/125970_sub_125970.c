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

extern uint32_t off_125B64;
extern uint32_t off_125B60;
extern uint32_t off_125B90;
extern uint32_t dword_125B68;
extern uint32_t off_125B94;
extern uint32_t dword_125B84;
extern uint32_t dword_125B80;
extern uint32_t dword_125B7C;
extern uint32_t dword_125B78;
extern uint32_t dword_125B6C;
extern uint32_t off_125B88;
extern uint32_t dword_125B8C;
extern uint32_t off_125B70;
extern uint32_t dword_125B74;

// patch_init_check @ 0x125970, size 496 bytes
int  patch_init_check(int result)
{
  int *v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r5
  int v5; // r9
  uint8_t *v6; // r4
  int v7; // r7
  uint32_t *v8; // r10
  int v9; // r8
  int v10; // r5
  unsigned int v11; // r3
  int v12; // cc
  int v13; // r2
  int v14; // r2
  int v15; // r1
  uint8_t *v16; // r10
  int v17; // r7
  uint8_t *v18; // r11
  int v19; // r5
  int v20; // r0
  int v21; // r8
  int i; // r10
  int v23; // r0
  int v24; // r2
  uint8_t *v25; // r0
  int v26; // r8
  int v27; // r0
  int v28; // r2
  int v29; // r1
  int v30; // r2

  v1 = (int *)off_125B64;
  v2 = *((uint32_t *)off_125B64 + 1);
  v3 = result;
  if ( **(int16_t **)off_125B60 >= 0 || v2 )
  {
    v4 = v2 - 1;
    *((uint32_t *)off_125B64 + 1) = v4;
    if ( !v4 )
    {
LABEL_20:
      v16 = off_125B90;
      check_config_flag();
      v17 = *(uint8_t *)(v3 + 107) + 32;
      if ( *v16 )
      {
        v25 = (uint8_t *)tx_send_pdu(74, 13, v4, 4);
        *v25 = v17;
        v25[1] = v4;
        v25[2] = v4;
        rx_process_packet(v25);
        v5 = dword_125B68;
        if ( *v16 )
        {
          v26 = dword_125B68 + 696 * v17;
          if ( (*(uint8_t *)(v26 + 53) & 2) != 0 )
          {
            *(uint8_t *)(v26 + 54) = 9;
            is_ll_event_pending(v3, v5 + 696 * v17, v4);
            *(uint8_t *)(v26 + 54) = v4;
          }
          *v16 = 0;
        }
      }
      else
      {
        v5 = dword_125B68;
      }
      v18 = off_125B94;
      if ( *(uint8_t *)off_125B94 )
      {
        v21 = v5 + 696 * v17;
        for ( i = 0; i != 4; ++i )
        {
          while ( *(uint32_t *)(v21 + 584) )
          {
            v23 = list_pop(v21 + 584);
            phy_txpower_calc(v23, (uint8_t)i, v24);
          }
          if ( *(uint32_t *)(v21 + 624) )
          {
            v27 = list_pop(v5 + 8 * (87 * v17 + 78 + i));
            phy_txpower_calc(v27, (uint8_t)i, v28);
            alloc_tx_event(dword_125B84, v29, v30);
            while ( 1 )
              ;
          }
          v21 += 8;
        }
        *v18 = 0;
      }
      if ( *((uint8_t *)v1 + 10) )
        bt_task_init(*v1);
      if ( v1[3] )
      {
        v19 = dword_125B80;
        do
        {
          v20 = list_pop(v19);
          rx_pkt_parse((uint16_t *)(v20 + 12));
        }
        while ( v1[3] );
      }
      result = *(uint8_t *)(v3 + 107);
      if ( *((uint8_t *)v1 + result + 20) && !v1[1] )
        result = bt_config_check(result, *((uint8_t *)v1 + result + 20));
      if ( *(uint8_t *)(v3 + 231) == 1 )
        result = alloc_ctrl_block(v3);
      goto LABEL_4;
    }
  }
  else
  {
    result = irq_disable_mmio_write(dword_125B7C, dword_125B78, 764);
    v4 = v1[1] - 1;
    v1[1] = v4;
    if ( !v4 )
      goto LABEL_20;
  }
  v5 = dword_125B68;
LABEL_4:
  v6 = (uint8_t *)dword_125B68;
  v7 = dword_125B6C;
  v8 = off_125B88;
  v9 = dword_125B8C;
  v10 = dword_125B68 + 22272;
  do
  {
    while ( 1 )
    {
      if ( v6[37] && v3 == v7 + 1320 * v6[34] )
      {
        v11 = v6[35];
        v12 = v11 > 0x23;
        if ( v11 > 0x23 )
        {
          v13 = 0;
        }
        else
        {
          v13 = 696;
          v11 = v5 + 696 * v11;
        }
        if ( !v12 )
          v13 = *(uint32_t *)(v11 + 664);
        if ( v9 - v8[4] + v13 < 0 )
        {
          result = phy_lock(v3);
          if ( result )
          {
            result = phy_get_channel(v6[35], (int)off_125B70, (int)v6);
            if ( !result )
              break;
          }
        }
      }
      v6 += 696;
      if ( v6 == (uint8_t *)v10 )
        return result;
    }
    v15 = v6[35];
    v6 += 696;
    result = alloc_tx_event(dword_125B74, v15, v14);
  }
  while ( v6 != (uint8_t *)v10 );
  return result;
}

