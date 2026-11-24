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


extern uint32_t dword_125EC4;
extern uint32_t dword_125EC8;
extern uint32_t dword_125ECC;
extern uint32_t dword_125ED0;
extern uint32_t dword_125EE4;
extern uint32_t dword_125EF0;
extern uint32_t dword_125EF4;
extern uint32_t dword_125EF8;
extern uint32_t off_125ED4;

// mac_handler @ 0x125cd4, size 496 bytes
int  mac_handler(int result)
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

  v1 = dword_125EC8;
  v2 = *(uint32_t *)(dword_125EC8 + 4);
  v3 = result;
  if ( **(uint16_t **)dword_125EC4 >= 0 || v2 )
  {
    v4 = v2 - 1;
    *(uint32_t *)(dword_125EC8 + 4) = v4;
    if ( !v4 )
    {
LABEL_20:
      v15 = (uint8_t *)dword_125EF4;
      check_clock_state();
      v16 = *(uint8_t *)(v3 + 107) + 32;
      if ( *v15 )
      {
        v23 = (uint8_t *)bt_buf_alloc(74, 13, v4, 4);
        *v23 = v16;
        v23[1] = v4;
        v23[2] = v4;
        hci_evt_send((int)v23);
        v5 = dword_125ECC;
        if ( *v15 )
        {
          v24 = dword_125ECC + 696 * v16;
          if ( (*(uint8_t *)(v24 + 53) & 2) != 0 )
          {
            *(uint8_t *)(v24 + 54) = 9;
            wlc_bsscfg_down(v3, v5 + 696 * v16, v4);
            *(uint8_t *)(v24 + 54) = v4;
          }
          *v15 = 0;
        }
      }
      else
      {
        v5 = dword_125ECC;
      }
      v17 = (uint8_t *)dword_125EF8;
      if ( *(uint8_t *)dword_125EF8 )
      {
        v20 = v5 + 696 * v16;
        for ( i = 0; i != 4; ++i )
        {
          while ( *(uint32_t *)(v20 + 584) )
          {
            v22 = list_pop_front(v20 + 584);
            tx_prepare_frame_path((unsigned int)v22, (uint8_t)i);
          }
          if ( *(uint32_t *)(v20 + 624) )
          {
            v25 = list_pop_front(v5 + 8 * (87 * v16 + 78 + i));
            tx_prepare_frame_path((unsigned int)v25, (uint8_t)i);
            ke_event_schedule_1(aThisWilleNever);
            while ( 1 )
              ;
          }
          v20 += 8;
        }
        *v17 = 0;
      }
      if ( *(uint8_t *)(v1 + 0xA) )
        timer_process(*(uint32_t *)v1);
      if ( *(uint32_t *)(v1 + 0xC) )
      {
        v18 = dword_125EE4;
        do
        {
          v19 = (uint16_t *)list_pop_front(v18);
          rx_header_parse(v19 + 6);
        }
        while ( *(uint32_t *)(v1 + 0xC) );
      }
      result = *(uint8_t *)(v3 + 107);
      if ( *(uint8_t *)(v1 + result + 20) && !*(uint32_t *)(v1 + 4) )
        result = tx_power_switch(result, *(uint8_t *)(v1 + result + 20));
      if ( *(uint8_t *)(v3 + 231) == 1 )
        result = (int)alloc_buffer(v3);
      goto LABEL_4;
    }
  }
  else
  {
    result = mmio_irq_clear((int)aMmBcnEnvTxCfm_0, (int)aMmBcnTransmitt, 764);
    v4 = *(uint32_t *)(v1 + 4) - 1;
    *(uint32_t *)(v1 + 4) = v4;
    if ( !v4 )
      goto LABEL_20;
  }
  v5 = dword_125ECC;
LABEL_4:
  v6 = (uint8_t *)dword_125ECC;
  v7 = dword_125ED0;
  v8 = dword_125EF0;
  v9 = dword_125ECC + 22272;
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
          result = init_once(v3);
          if ( result )
          {
            result = ble_conn_get(v6[35], off_125ED4, (int)v6);
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
    result = ke_event_schedule_1("apm send null to probe sta: sta_idx=%d\n", v14);
  }
  while ( v6 != (uint8_t *)v9 );
  return result;
}
