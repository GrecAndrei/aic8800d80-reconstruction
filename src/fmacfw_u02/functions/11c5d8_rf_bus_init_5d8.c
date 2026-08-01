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

extern uint32_t off_11C8C4;
extern uint32_t dword_11C8E0;
extern uint32_t off_11C8C8;
extern uint32_t dword_11C8D0;
extern uint32_t off_11C8CC;
extern uint32_t dword_11C8DC;
extern uint32_t dword_11C8D8;
extern uint32_t off_11C8D4;

// process_tx_packet @ 0x11c5d8, size 748 bytes
// Doc: process_tx_packet [rf]: Initialize the RF bus interface
// process_tx_packet [rf]: Initialize the RF bus interface
int  process_tx_packet(int a1, int a2)
{
  uint8_t *v2; // r5
  int v3; // r11
  uint32_t *v4; // r7
  int v5; // r6
  int v7; // r10
  int v8; // r0
  int v9; // r9
  int16_t v10; // r3
  int16_t v11; // r3
  void *v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r8
  int v16; // r7
  int result; // r0
  int v18; // r9
  int v19; // r3
  int v20; // r10
  int v21; // r11
  int v22; // r1
  uint64_t v23; // kr00_8
  int v24; // r8
  char v25; // r3
  int *v26; // r3
  int *v27; // r2
  int v28; // r1
  int v29; // t1
  unsigned int v30; // r1
  int v31; // r2
  void *v32; // r1
  int v33; // r2
  unsigned int v34; // r2
  int v35; // r0
  int v36; // r2
  unsigned int v37; // r2
  int v38; // [sp+0h] [bp-Ch]
  int *v39; // [sp+4h] [bp-8h]

  v2 = (uint8_t *)off_11C8C4;
  v3 = *(uint32_t *)(a1 + 68);
  v4 = *(uint32_t **)(a1 + 76);
  v5 = *((uint8_t *)off_11C8C4 + 190);
  v7 = a2;
  if ( (a2 & 0x800000) != 0 )
  {
    v8 = rf_irq_status_check(a1);
    v9 = 9;
    while ( 1 )
    {
      v10 = *(uint16_t *)(v3 + 8);
      if ( (v10 & 0x20) != 0 )
        break;
      v8 = rf_irq_status_check(v8);
      if ( !--v9 )
      {
        v11 = *(uint16_t *)(v3 + 8);
        if ( (v11 & 0x60) != 0x20 )
        {
          if ( (v11 & 0x20) == 0 )
          {
            v15 = dword_11C8E0;
            v16 = 84 * v5;
            mem_word_load(84 * v5 + 28 + dword_11C8E0);
            dec_retry_count(v3);
            *(uint32_t *)(a1 + 68) = 0;
            goto LABEL_18;
          }
LABEL_7:
          dec_retry_count(v3);
          *(uint32_t *)(a1 + 68) = 0;
          v14 = v2[199];
          v15 = dword_11C8E0;
          v16 = 84 * v5;
          if ( v2[199] )
            goto LABEL_19;
LABEL_8:
          get_phy_status(v2[190], (int)v12, v13, v14);
          mem_word_load(v16 + 12 + v15);
          if ( *(uint16_t *)(a1 + 4) )
            return ipc_handler_register(a1, v7, v5);
          return free_buf_1882c0();
        }
        v7 &= ~0x800000u;
        v4[18] &= ~0x800000u;
        if ( (v11 & 0x20) == 0 )
          goto LABEL_22;
LABEL_31:
        dec_retry_count(v3);
        v15 = dword_11C8E0;
        *(uint32_t *)(a1 + 68) = 0;
        goto LABEL_12;
      }
    }
    if ( (v10 & 0x60) != 0x20 )
      goto LABEL_7;
    v7 &= ~0x800000u;
    v4[18] &= ~0x800000u;
    goto LABEL_31;
  }
  if ( (*(uint16_t *)(v3 + 8) & 0x20) != 0 )
  {
    v15 = dword_11C8E0;
    dec_retry_count(*(uint32_t *)(a1 + 68));
    *(uint32_t *)(a1 + 68) = 0;
  }
  else
  {
LABEL_22:
    v15 = dword_11C8E0;
    mem_word_load(84 * (int16_t)v5 + 28 + dword_11C8E0);
    dec_retry_count(v3);
    *(uint32_t *)(a1 + 68) = 0;
  }
LABEL_12:
  v18 = BYTE1(v7);
  if ( v2[199] )
  {
    v12 = off_11C8C8;
    v13 = HIBYTE(*(uint32_t *)off_11C8C8) & 7;
    v19 = v13 + 1;
    if ( v13 + 1 >= (unsigned int)v2[165] )
      v19 = v2[165];
    *(uint32_t *)off_11C8C8 = (v19 << 24) & 0x7000000 | *(uint32_t *)off_11C8C8 & 0xF8FFFFFF;
  }
  if ( BYTE1(v7) <= 4u )
  {
    v20 = *(uint32_t *)(a1 + 72);
    if ( v18 )
    {
      v21 = v20 + 44;
    }
    else
    {
      if ( *(uint16_t *)(a1 + 4) )
      {
        v26 = *(int **)(a1 + 44);
        v21 = v20 + 44;
        v27 = v26;
        v28 = v20 + 40;
        do
        {
          v29 = *v27++;
          *(uint32_t *)(v28 + 4) = v29;
          v28 += 4;
        }
        while ( v26 + 16 != v27 );
        if ( (*(uint16_t *)(a1 + 30) & 0x2000) != 0 )
        {
          v38 = *(uint32_t *)(dword_11C8D0 + 696 * *(uint8_t *)(a1 + 29) + 340);
          if ( **(int16_t **)off_11C8CC < 0 && !*(uint32_t *)(dword_11C8D0 + 696 * *(uint8_t *)(a1 + 29) + 340) )
          {
            v39 = v26;
            mmio_clear_register(dword_11C8DC, dword_11C8D8, 475);
            v26 = v39;
          }
          v30 = *(uint32_t *)(v38 + 156);
          *(uint32_t *)(v20 + 68) = v26[5];
          v31 = *(uint32_t *)(v38 + 160);
          *(uint32_t *)(v20 + 84) = v26[9];
          *(uint32_t *)(v20 + 64) = v30;
          *(uint32_t *)(v20 + 80) = v31;
          if ( ((v30 >> 11) & 5) == 5 )
          {
            v34 = v31 & 0xFFFCFFFF;
            if ( (v30 & 0x600) == 0x400 )
              v35 = 0x20000;
            else
              v35 = 0x10000;
            v36 = v34 | v35;
            if ( *(uint8_t *)(v38 + 165) )
              v37 = v36 | 0x40000;
            else
              v37 = v36 & 0xFFFBFFFF;
            *(uint32_t *)(v20 + 80) = v37;
          }
          if ( (v26[15] & 4) == 0 )
            *(uint32_t *)(v20 + 48) &= 0xFFFFFE7F;
        }
      }
      else
      {
        v21 = v20 + 44;
      }
      wait_channel_clear((unsigned int *)a1);
    }
    v22 = *(uint32_t *)&v2[28 * v5 + 36];
    v23 = *(uint64_t *)(v20 + 96);
    v4[16] = v23;
    v4[18] = (v18 + 1) << 8;
    v4[11] = HIDWORD(v23);
    v4[12] = v21;
    result = (int)(v4 + 3);
    if ( v22 )
    {
      v4[4] = v22;
    }
    else
    {
      v32 = off_11C8D4;
      *(uint32_t *)(v15 + 84 * v5) = result;
      v33 = 84 * v5 + v15;
      if ( !*(uint8_t *)(*(uint32_t *)v32 + 1) )
      {
        *(uint32_t *)(v33 + 4) = 0;
        *(uint32_t *)(v33 + 8) = 0;
      }
    }
    v24 = v15 + 84 * v5;
    v25 = *(uint8_t *)(v24 + 80) + 1;
    *(uint32_t *)&v2[28 * v5 + 36] = result;
    *(uint8_t *)(v24 + 80) = v25;
  }
  else
  {
    v4[18] |= 0x10000u;
    v16 = 84 * v5;
LABEL_18:
    v14 = v2[199];
    if ( !v2[199] )
      goto LABEL_8;
LABEL_19:
    *(uint32_t *)off_11C8C8 = (v2[164] << 24) & 0x7000000 | *(uint32_t *)off_11C8C8 & 0xF8FFFFFF;
    mem_word_load(v16 + 12 + v15);
    if ( !*(uint16_t *)(a1 + 4) )
      return free_buf_1882c0();
    return ipc_handler_register(a1, v7, v5);
  }
  return result;
}

