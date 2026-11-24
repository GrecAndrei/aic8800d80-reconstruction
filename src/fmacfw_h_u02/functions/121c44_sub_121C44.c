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


extern uint32_t dword_121EA8;
extern uint32_t dword_121EAC;
extern uint32_t dword_121EC0;
extern uint32_t off_121EB0;
extern uint32_t off_121EB4;
extern uint32_t off_121EB8;
extern uint32_t off_121EBC;
extern uint32_t off_121EC4;
extern uint32_t off_121EC8;

// ll_channel_hop @ 0x121c44, size 610 bytes
int  ll_channel_hop(int a1)
{
  int v1; // r5
  int v2; // r7
  int v3; // r6
  int v4; // r4
  int v5; // r9
  int v6; // r8
  unsigned int v7; // r10
  int v8; // r3
  int v9; // r1
  int v10; // r7
  uint8_t *v11; // r3
  int v12; // r1
  uint32_t *v13; // r1
  char *v14; // r0
  uint32_t *v15; // r7
  uint32_t *v16; // r6
  int *v17; // r1
  int v18; // r2
  char *v19; // r5
  uint32_t *v20; // r6
  uint8_t v21; // r0
  uint32_t *v22; // r1
  unsigned int v23; // r0
  int v25; // r11
  int v26; // r9
  uint8_t *v27; // r10
  unsigned int v28; // r3
  int v29; // r6
  uint8_t *v30; // r0
  uint32_t *v31; // r3
  int v32; // r2
  int v33; // r1
  uint32_t *v34; // r8
  uint32_t *v35; // r4
  uint32_t *v36; // r10
  int v37; // r9
  uint32_t *v38; // r11
  int v39; // r3
  int v40; // r0
  uint32_t *v41; // r2
  int v42; // r1
  int v43; // [sp+Ch] [bp-8h]

  v1 = dword_121EA8;
  v2 = dword_121EA8 + 696 * a1;
  v3 = *(uint8_t *)(v2 + 34);
  v4 = a1;
  v5 = dword_121EA8 + 8 * (87 * (uint16_t)a1 + 78);
  v6 = 0;
  do
  {
    v7 = (uint8_t)v6++;
    if ( *(uint32_t *)(v2 + 584) )
      phy_dispatch(v7, v5 - 40, 0);
    v8 = *(uint32_t *)(v2 + 624);
    v9 = v5;
    v2 += 8;
    v5 += 8;
    if ( v8 )
      phy_dispatch(v7, v9, 0);
  }
  while ( v6 != 5 );
  v10 = dword_121EAC;
  v11 = (uint8_t *)(dword_121EAC + 1320 * v3);
  v12 = v11[106];
  if ( v11[106] )
  {
    v18 = *(uint8_t *)(v1 + 696 * v4 + 36);
    if ( v18 == 1 )
    {
      v18 = (uint8_t)(v11[234] - 1);
      v11[234] = v18;
      if ( !v18 )
      {
        v25 = (uint8_t)(v11[107] + 32);
        v26 = 696 * v25;
        v27 = (uint8_t *)(v1 + 696 * v25);
        if ( v27[36] )
        {
          v28 = v27[35];
          v27[36] = 0;
          if ( v28 <= 0x1F )
          {
            v30 = (uint8_t *)tx_send_pdu(73, 13, 0, 2);
            *v30 = v25;
            v30[1] = 0;
            rx_process_packet_1((int)v30);
            if ( !v27[36] && v27[35] <= 0x1Fu )
            {
              v31 = off_121EC4;
              v43 = v4;
              v32 = v10 + 1320 * v27[34];
              v33 = dword_121EC0 + v26;
              v34 = (uint32_t *)(v1 + v26);
              v35 = (uint32_t *)(v1 + 8 * (87 * (uint16_t)v25 + 78));
              v36 = (uint32_t *)(v10 + 8 * (165 * v27[34] + 159));
              v37 = v32;
              v38 = (uint32_t *)v33;
              do
              {
                if ( v34[146] )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    *(uint32_t *)off_121EC8 = 1;
                  }
                  ++*v31;
                  alloc_tx_event(aCatTobe);
                  get_ptr_value(v35 - 10, v36 - 10);
                  v39 = v34[147];
                  *(uint32_t *)(v37 + 1232) = v34[146];
                  *(uint32_t *)(v37 + 1236) = v39;
                  clear_stats_buf(v35 - 10);
                  v31 = off_121EC4;
                  v40 = *(uint32_t *)off_121EC4 - 1;
                  if ( *(uint32_t *)off_121EC4 )
                  {
                    v41 = off_121EC8;
                    *(uint32_t *)off_121EC4 = v40;
                    if ( !v40 )
                    {
                      if ( *v41 )
                        __enable_irq();
                    }
                  }
                }
                v42 = v34[156];
                v37 += 8;
                v34 += 2;
                if ( v42 )
                {
                  alloc_tx_event(aCatPs);
                  get_ptr_value(v36, v35);
                  clear_stats_buf(v35);
                  v31 = off_121EC4;
                }
                v35 += 2;
                v36 += 2;
              }
              while ( v35 != v38 );
              v4 = v43;
              irq_disable_global_2(512);
            }
          }
        }
        v29 = v10 + 1320 * v3;
        rf_get_rate_table_index(v29, (uint8_t)(*(uint8_t *)(v29 + 107) + 32));
        v12 = *(uint8_t *)(v29 + 106);
      }
    }
    if ( v12 == 2 )
    {
      v23 = v4;
      return get_connection_tx_power(v23, v12, v18, (int)v11);
    }
  }
  else
  {
    v11[116] = -1;
  }
  v13 = off_121EB0;
  v14 = (char *)off_121EB4;
  v15 = off_121EB8;
  v16 = off_121EBC;
  *(uint32_t *)off_121EB4 = -1;
  *v13 = -1;
  *v15 = 0;
  v17 = v13 + 1;
  *v16 = 0;
  *(int *)((char *)v17 + 0xFFFFFFF0) = 0;
  *(uint32_t *)&v14[-4] = 0;
  v18 = (int)v17;
  *v17 = ((uint8_t)(v4 + 16) << 16) | 0x40000000;
  do
    v11 = (uint8_t *)(*v17 & 0x40000000);
  while ( v11 );
  v12 = *(uint32_t *)(v1 + 696 * v4 + 44);
  if ( v12 )
  {
    v19 = (char *)off_121EB4;
    v20 = off_121EB0;
    v21 = *(uint8_t *)(v12 + 35) + 16;
    *(uint32_t *)off_121EB4 = -1;
    *v20 = -1;
    v22 = off_121EBC;
    *(uint32_t *)&v19[-16] = 0;
    *v22 = 0;
    *(uint32_t *)((char *)v20 + 0xFFFFFFF4) = 0;
    v12 = (int)(v22 + 5);
    *(uint32_t *)&v19[-4] = 0;
    *(uint32_t *)v18 = (v21 << 16) | 0x40000000;
    do
      v11 = (uint8_t *)(2 * *(uint32_t *)v12);
    while ( (*(uint32_t *)v12 & 0x40000000) != 0 );
  }
  v23 = v4;
  return get_connection_tx_power(v23, v12, v18, (int)v11);
}
