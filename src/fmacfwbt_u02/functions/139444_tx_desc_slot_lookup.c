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

extern uint32_t off_139668;
extern uint32_t dword_13966C;
extern uint32_t dword_139684;
extern uint32_t off_139670;
extern uint32_t dword_139674;
extern uint32_t off_139678;
extern uint32_t dword_139680;
extern uint32_t dword_13967C;

// tx_desc_slot_lookup @ 0x139444, size 546 bytes
// Doc: tx_desc_slot_lookup [tx]: Index into TX descriptor slot table using queue id
// tx_desc_slot_lookup [tx]: Index into TX descriptor slot table using queue id
int  tx_desc_slot_lookup(int a1, int a2)
{
  uint16_t *v2; // r6
  int v3; // r7
  int v5; // r4
  int v7; // r12
  int v8; // r9
  int v9; // r1
  int v10; // r7
  int v11; // r3
  int16_t v12; // r3
  unsigned int v13; // r1
  int v14; // r2
  int v16; // r4
  int v17; // r0
  uint32_t *v18; // r2
  int v19; // r3
  int v20; // r2
  int16_t v21; // r2
  int16_t v22; // r3
  int v23; // r9
  int16_t *v24; // r2
  unsigned int v25; // r3
  int16_t v26; // r3
  int16_t v27; // r3

  v2 = off_139668;
  v3 = dword_13966C + 1320 * *((uint8_t *)off_139668 + 10);
  v5 = *(uint8_t *)(v3 + 1227);
  if ( !*(uint8_t *)(v3 + 1227) )
  {
    v7 = *((uint8_t *)off_139668 + 7);
    v8 = dword_139684;
    v9 = *((uint16_t *)off_139668 + 2);
    v10 = *(uint32_t *)(dword_139684 + 4 * (v7 + 174 * a2 + 102));
    v11 = *(uint16_t *)(v10 + 8);
    if ( v11 != v9 )
      goto LABEL_3;
    goto LABEL_28;
  }
  v8 = dword_139684;
  v17 = param_parse_setup((uint8_t *)(v3 + 107), (uint32_t *)(v3 + 1228), *(char **)(*(uint32_t *)(a1 + 28) + 8), 1);
  v7 = *((uint8_t *)v2 + 7);
  v9 = (uint16_t)v2[2];
  v10 = *(uint32_t *)(v8 + 4 * (v7 + 174 * a2 + 102));
  v11 = *(uint16_t *)(v10 + 8);
  v5 = v17 == 1;
  if ( v9 == v11 )
  {
LABEL_15:
    if ( v5 )
    {
      v16 = 0;
LABEL_17:
      v18 = off_139670;
      *(uint8_t *)(v10 + 288) = 1;
      v19 = *(uint8_t *)(v10 + 10);
      *(uint32_t *)(v10 + 4) = v18[4];
      v20 = v10 + 4 * v19;
      if ( *(uint32_t *)(v20 + 16) )
      {
        *(uint32_t *)(v20 + 16) = 0;
        --*(uint8_t *)(v10 + 11);
      }
      v21 = (*(uint16_t *)(v10 + 8) + 1) & 0xFFF;
      *(uint8_t *)(v10 + 10) = (v19 + 1) & 0x3F;
      *(uint16_t *)(v10 + 8) = v21;
      sub_138A5C(v10);
      table_lookup_n_696(a2, *((uint8_t *)v2 + 7));
      return v16;
    }
LABEL_28:
    v26 = *(uint16_t *)(a1 + 50) & 0xFF00;
    *(uint32_t *)(a1 + 96) |= 0x20u;
    *(uint16_t *)(a1 + 50) = v26;
    bt_channel_parse_n_db8(a1, 3);
    v16 = 1;
    goto LABEL_17;
  }
LABEL_3:
  while ( 1 )
  {
    v12 = v9 - v11;
    v13 = v12 & 0xFFF;
    if ( (v12 & 0xFC0) == 0 )
      break;
    if ( v13 > 0x7FE )
    {
      if ( !*(uint8_t *)(v10 + 288) )
      {
        if ( (*v2 & 0x800) == 0 )
        {
          LOWORD(v14) = v2[1];
LABEL_8:
          *(uint16_t *)(v8 + 2 * (v7 + 348 * a2) + 554) = v14;
          if ( !v5 )
          {
            v22 = *(uint16_t *)(a1 + 50) & 0xFF00;
            *(uint32_t *)(a1 + 96) |= 0x20u;
            *(uint16_t *)(a1 + 50) = v22;
            bt_channel_parse_n_db8(a1, 3);
          }
LABEL_10:
          table_lookup_n_696(a2, *((uint8_t *)v2 + 7));
          return (uint8_t)(1 - v5);
        }
        v14 = (uint16_t)v2[1];
        if ( *(uint16_t *)(v8 + 2 * (v7 + 348 * a2) + 554) != v14 )
          goto LABEL_8;
      }
      return 0;
    }
    sub_1393AC(v10, (uint16_t)(v13 - 63));
    v7 = *((uint8_t *)v2 + 7);
    v9 = (uint16_t)v2[2];
    v10 = *(uint32_t *)(v8 + 4 * (174 * a2 + v7 + 102));
    v11 = *(uint16_t *)(v10 + 8);
    if ( v9 == v11 )
      goto LABEL_15;
  }
  v23 = v10 + 4 * ((*(uint8_t *)(v10 + 10) + (uint8_t)v12) & 0x3F);
  *(uint8_t *)(v10 + 288) = 1;
  if ( !*(uint32_t *)(v23 + 16) )
  {
    if ( !v5 )
    {
      v27 = *(uint16_t *)(a1 + 50) & 0xFF00;
      *(uint32_t *)(a1 + 96) |= 0x20u;
      *(uint16_t *)(a1 + 50) = v27;
      bt_channel_parse_n_db8(a1, 3);
    }
    *(uint32_t *)(v23 + 16) = dword_139674;
    v24 = *(int16_t **)off_139678;
    v25 = (uint8_t)(*(uint8_t *)(v10 + 11) + 1);
    *(uint8_t *)(v10 + 11) = v25;
    if ( *v24 < 0 && v25 > 0x40 )
    {
      sub_12F694(dword_139680, dword_13967C, 1860);
      v25 = *(uint8_t *)(v10 + 11);
    }
    if ( v25 == 1 )
      timestamp_update_4f60(v10 + 272, *((uint32_t *)off_139670 + 4) + 50000);
    goto LABEL_10;
  }
  return 0;
}

