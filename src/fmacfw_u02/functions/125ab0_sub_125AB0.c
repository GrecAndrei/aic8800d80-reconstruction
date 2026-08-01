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

extern uint32_t off_125CA4;
extern uint32_t off_125CA0;
extern uint32_t off_125CD0;
extern uint32_t dword_125CA8;
extern uint32_t off_125CD4;
extern uint32_t dword_125CC4;
extern uint32_t dword_125CC0;
extern uint32_t dword_125CBC;
extern uint32_t dword_125CB8;
extern uint32_t dword_125CAC;
extern uint32_t off_125CC8;
extern uint32_t dword_125CCC;
extern uint32_t dword_125CB0;
extern uint32_t dword_125CB4;

// ke_schedule @ 0x125ab0, size 496 bytes
int  ke_schedule(int result)
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

  v1 = (int *)off_125CA4;
  v2 = *((uint32_t *)off_125CA4 + 1);
  v3 = result;
  if ( **(int16_t **)off_125CA0 >= 0 || v2 )
  {
    v4 = v2 - 1;
    *((uint32_t *)off_125CA4 + 1) = v4;
    if ( !v4 )
    {
LABEL_20:
      v16 = off_125CD0;
      check_hw_state();
      v17 = *(uint8_t *)(v3 + 107) + 32;
      if ( *v16 )
      {
        v25 = (uint8_t *)ke_msg_alloc(74, 13, v4, 4);
        *v25 = v17;
        v25[1] = v4;
        v25[2] = v4;
        ke_msg_send(v25);
        v5 = dword_125CA8;
        if ( *v16 )
        {
          v26 = dword_125CA8 + 696 * v17;
          if ( (*(uint8_t *)(v26 + 53) & 2) != 0 )
          {
            *(uint8_t *)(v26 + 54) = 9;
            llc_ccm_encrypt(v3, v5 + 696 * v17, v4);
            *(uint8_t *)(v26 + 54) = v4;
          }
          *v16 = 0;
        }
      }
      else
      {
        v5 = dword_125CA8;
      }
      v18 = off_125CD4;
      if ( *(uint8_t *)off_125CD4 )
      {
        v21 = v5 + 696 * v17;
        for ( i = 0; i != 4; ++i )
        {
          while ( *(uint32_t *)(v21 + 584) )
          {
            v23 = mem_word_load(v21 + 584);
            ll_conn_state_dispatch(v23, (uint8_t)i, v24);
          }
          if ( *(uint32_t *)(v21 + 624) )
          {
            v27 = mem_word_load(v5 + 8 * (87 * v17 + 78 + i));
            ll_conn_state_dispatch(v27, (uint8_t)i, v28);
            event_dispatch(dword_125CC4, v29, v30);
            while ( 1 )
              ;
          }
          v21 += 8;
        }
        *v18 = 0;
      }
      if ( *((uint8_t *)v1 + 10) )
        ke_task_init(*v1);
      if ( v1[3] )
      {
        v19 = dword_125CC0;
        do
        {
          v20 = mem_word_load(v19);
          hci_acl_header_parse((uint16_t *)(v20 + 12));
        }
        while ( v1[3] );
      }
      result = *(uint8_t *)(v3 + 107);
      if ( *((uint8_t *)v1 + result + 20) && !v1[1] )
        result = hci_packet_type_router(result, *((uint8_t *)v1 + result + 20));
      if ( *(uint8_t *)(v3 + 231) == 1 )
        result = alloc_kernel_message(v3);
      goto LABEL_4;
    }
  }
  else
  {
    result = mmio_clear_register(dword_125CBC, dword_125CB8, 764);
    v4 = v1[1] - 1;
    v1[1] = v4;
    if ( !v4 )
      goto LABEL_20;
  }
  v5 = dword_125CA8;
LABEL_4:
  v6 = (uint8_t *)dword_125CA8;
  v7 = dword_125CAC;
  v8 = off_125CC8;
  v9 = dword_125CCC;
  v10 = dword_125CA8 + 22272;
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
          result = isr_flag_dispatch(v3);
          if ( result )
          {
            result = rf_channel_get(v6[35], dword_125CB0, (int)v6);
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
    result = event_dispatch(dword_125CB4, v15, v14);
  }
  while ( v6 != (uint8_t *)v10 );
  return result;
}

