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


extern uint32_t dword_125B60;
extern uint32_t dword_125B64;
extern uint32_t dword_125B68;
extern uint32_t dword_125B6C;
extern uint32_t dword_125B80;
extern uint32_t dword_125B8C;
extern uint32_t dword_125B90;
extern uint32_t dword_125B94;
extern uint32_t off_125B70;

// patch_init_check @ 0x125970, size 496 bytes
int  patch_init_check(int result)
{
  unsigned int v1; // r4
  int v2; // r5
  int v3; // r6
  int v4; // r5
  unsigned int v5; // r9
  uint8_t *v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r8
  unsigned int v9; // r5
  unsigned int v10; // r3
  int v11; // cc
  int v12; // r2
  unsigned int v13; // r3
  int v14; // r1
  uint8_t *v15; // r10
  int v16; // r7
  uint8_t *v17; // r11
  unsigned int v18; // r5
  uint16_t *v19; // r0
  unsigned int v20; // r8
  int i; // r10
  uint32_t *v22; // r0
  uint8_t *v23; // r0
  unsigned int v24; // r8
  uint32_t *v25; // r0

  v1 = dword_125B64;
  v2 = *(uint32_t *)(dword_125B64 + 4);
  v3 = result;
  if ( **(uint16_t **)dword_125B60 >= 0 || v2 )
  {
    v4 = v2 - 1;
    *(uint32_t *)(dword_125B64 + 4) = v4;
    if ( !v4 )
    {
LABEL_20:
      v15 = (uint8_t *)dword_125B90;
      check_config_flag();
      v16 = *(uint8_t *)(v3 + 107) + 32;
      if ( *v15 )
      {
        v23 = (uint8_t *)tx_send_pdu(74, 13, v4, 4);
        *v23 = v16;
        v23[1] = v4;
        v23[2] = v4;
        rx_process_packet_1((int)v23);
        v5 = dword_125B68;
        if ( *v15 )
        {
          v24 = dword_125B68 + 696 * v16;
          if ( (*(uint8_t *)(v24 + 53) & 2) != 0 )
          {
            *(uint8_t *)(v24 + 54) = 9;
            is_ll_event_pending(v3, v5 + 696 * v16, v4);
            *(uint8_t *)(v24 + 54) = v4;
          }
          *v15 = 0;
        }
      }
      else
      {
        v5 = dword_125B68;
      }
      v17 = (uint8_t *)dword_125B94;
      if ( *(uint8_t *)dword_125B94 )
      {
        v20 = v5 + 696 * v16;
        for ( i = 0; i != 4; ++i )
        {
          while ( *(uint32_t *)(v20 + 584) )
          {
            v22 = list_pop(v20 + 584);
            phy_txpower_calc((unsigned int)v22, (uint8_t)i);
          }
          if ( *(uint32_t *)(v20 + 624) )
          {
            v25 = list_pop(v5 + 8 * (87 * v16 + 78 + i));
            phy_txpower_calc((unsigned int)v25, (uint8_t)i);
            alloc_tx_event(aThisWilleNever);
            while ( 1 )
              ;
          }
          v20 += 8;
        }
        *v17 = 0;
      }
      if ( *(uint8_t *)(v1 + 0xA) )
        bt_task_init(*(uint32_t *)v1);
      if ( *(uint32_t *)(v1 + 0xC) )
      {
        v18 = dword_125B80;
        do
        {
          v19 = (uint16_t *)list_pop(v18);
          rx_pkt_parse(v19 + 6);
        }
        while ( *(uint32_t *)(v1 + 0xC) );
      }
      result = *(uint8_t *)(v3 + 107);
      if ( *(uint8_t *)(v1 + result + 20) && !*(uint32_t *)(v1 + 4) )
        result = bt_config_check(result, *(uint8_t *)(v1 + result + 20));
      if ( *(uint8_t *)(v3 + 231) == 1 )
        result = (int)alloc_ctrl_block(v3);
      goto LABEL_4;
    }
  }
  else
  {
    result = irq_disable_mmio_write((int)aMmBcnEnvTxCfm_0, (int)aMmBcnTransmitt, 764);
    v4 = *(uint32_t *)(v1 + 4) - 1;
    *(uint32_t *)(v1 + 4) = v4;
    if ( !v4 )
      goto LABEL_20;
  }
  v5 = dword_125B68;
LABEL_4:
  v6 = (uint8_t *)dword_125B68;
  v7 = dword_125B6C;
  v8 = dword_125B8C;
  v9 = dword_125B68 + 22272;
  do
  {
    while ( 1 )
    {
      if ( v6[37] && v3 == v7 + 1320 * v6[34] )
      {
        v10 = v6[35];
        v11 = v10 > 0x23;
        if ( v10 > 0x23 )
        {
          v12 = 0;
        }
        else
        {
          v12 = 696;
          v10 = v5 + 696 * v10;
        }
        if ( !v11 )
          v12 = *(uint32_t *)(v10 + 664);
        v13 = v8 - (*(volatile uint32_t *)0x40501010u);
        if ( (int)(v13 + v12) < 0 )
        {
          result = phy_lock(v3);
          if ( result )
          {
            result = phy_get_channel(v6[35], off_125B70, (int)v6);
            if ( !result )
              break;
          }
        }
      }
      v6 += 696;
      if ( v6 == (uint8_t *)v9 )
        return result;
    }
    v14 = v6[35];
    v6 += 696;
    result = alloc_tx_event("apm send null to probe sta: sta_idx=%d\n", v14);
  }
  while ( v6 != (uint8_t *)v9 );
  return result;
}
