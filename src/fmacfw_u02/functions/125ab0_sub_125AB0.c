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


extern uint32_t dword_125CA0;
extern uint32_t dword_125CA4;
extern uint32_t dword_125CA8;
extern uint32_t dword_125CAC;
extern uint32_t dword_125CC0;
extern uint32_t dword_125CCC;
extern uint32_t dword_125CD0;
extern uint32_t dword_125CD4;
extern uint32_t off_125CB0;

// ke_schedule @ 0x125ab0, size 496 bytes
int  ke_schedule(int result)
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

  v1 = dword_125CA4;
  v2 = *(uint32_t *)(dword_125CA4 + 4);
  v3 = result;
  if ( **(uint16_t **)dword_125CA0 >= 0 || v2 )
  {
    v4 = v2 - 1;
    *(uint32_t *)(dword_125CA4 + 4) = v4;
    if ( !v4 )
    {
LABEL_20:
      v15 = (uint8_t *)dword_125CD0;
      check_hw_state();
      v16 = *(uint8_t *)(v3 + 107) + 32;
      if ( *v15 )
      {
        v23 = (uint8_t *)ke_msg_alloc(74, 13, v4, 4);
        *v23 = v16;
        v23[1] = v4;
        v23[2] = v4;
        ke_msg_send_2((int)v23);
        v5 = dword_125CA8;
        if ( *v15 )
        {
          v24 = dword_125CA8 + 696 * v16;
          if ( (*(uint8_t *)(v24 + 53) & 2) != 0 )
          {
            *(uint8_t *)(v24 + 54) = 9;
            llc_ccm_encrypt(v3, v5 + 696 * v16, v4);
            *(uint8_t *)(v24 + 54) = v4;
          }
          *v15 = 0;
        }
      }
      else
      {
        v5 = dword_125CA8;
      }
      v17 = (uint8_t *)dword_125CD4;
      if ( *(uint8_t *)dword_125CD4 )
      {
        v20 = v5 + 696 * v16;
        for ( i = 0; i != 4; ++i )
        {
          while ( *(uint32_t *)(v20 + 584) )
          {
            v22 = mem_word_load(v20 + 584);
            ll_conn_state_dispatch((unsigned int)v22, (uint8_t)i);
          }
          if ( *(uint32_t *)(v20 + 624) )
          {
            v25 = mem_word_load(v5 + 8 * (87 * v16 + 78 + i));
            ll_conn_state_dispatch((unsigned int)v25, (uint8_t)i);
            event_dispatch(aThisWilleNever);
            while ( 1 )
              ;
          }
          v20 += 8;
        }
        *v17 = 0;
      }
      if ( *(uint8_t *)(v1 + 0xA) )
        ke_task_init_1(*(uint32_t *)v1);
      if ( *(uint32_t *)(v1 + 0xC) )
      {
        v18 = dword_125CC0;
        do
        {
          v19 = (uint16_t *)mem_word_load(v18);
          hci_acl_header_parse(v19 + 6);
        }
        while ( *(uint32_t *)(v1 + 0xC) );
      }
      result = *(uint8_t *)(v3 + 107);
      if ( *(uint8_t *)(v1 + result + 20) && !*(uint32_t *)(v1 + 4) )
        result = hci_packet_type_router(result, *(uint8_t *)(v1 + result + 20));
      if ( *(uint8_t *)(v3 + 231) == 1 )
        result = (int)alloc_kernel_message(v3);
      goto LABEL_4;
    }
  }
  else
  {
    result = mmio_clear_register((int)aMmBcnEnvTxCfm_0, (int)aMmBcnTransmitt, 764);
    v4 = *(uint32_t *)(v1 + 4) - 1;
    *(uint32_t *)(v1 + 4) = v4;
    if ( !v4 )
      goto LABEL_20;
  }
  v5 = dword_125CA8;
LABEL_4:
  v6 = (uint8_t *)dword_125CA8;
  v7 = dword_125CAC;
  v8 = dword_125CCC;
  v9 = dword_125CA8 + 22272;
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
          result = isr_flag_dispatch(v3);
          if ( result )
          {
            result = rf_channel_get(v6[35], off_125CB0, (int)v6);
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
    result = event_dispatch("apm send null to probe sta: sta_idx=%d\n", v14);
  }
  while ( v6 != (uint8_t *)v9 );
  return result;
}
