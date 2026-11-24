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


extern uint32_t dword_138E98;
extern uint32_t off_138E9C;
extern uint32_t off_138EA0;

// rf_handle_command @ 0x138c64, size 554 bytes
int  rf_handle_command(unsigned int a1, uint64_t *a2, int a3, int a4)
{
  uint32_t *v4; // r8
  unsigned int v5; // r4
  uint64_t *v6; // r1
  uint64_t *v7; // r9
  int v9; // r5
  uint32_t *v10; // r6
  int v11; // r1
  uint64_t v12; // r0
  int v13; // r1
  uint16_t v14; // r2
  unsigned int v15; // r5
  unsigned int v16; // r4
  int v17; // cc
  uint64_t v18; // r0
  uint16_t **v19; // r10
  uint16_t **v20; // r12
  char *v21; // r0
  int v22; // r1
  uint64_t v23; // r2
  uint16_t v24; // r5
  uint16_t v25; // lr
  signed int v26; // r3
  uint8_t *v27; // r2
  int v28; // r3
  int v29; // r10
  uint8_t *v30; // r5
  int v31; // lr
  int v33; // r1
  uint64_t v34; // r0
  uint8_t *v35; // r5
  char *v36; // r3
  char *v37; // r2
  int v38; // r6
  uint8_t *v39; // r3
  char *v40; // r2
  uint8_t *v41; // r5
  int v42; // r0
  int v43; // r1
  int v44; // r2
  uint64_t v45; // r4
  int v46; // t1
  int v47; // [sp+Ch] [bp-10h]
  uint64_t v48; // [sp+10h] [bp-Ch] BYREF

  v4 = off_138E9C;
  v5 = a1;
  v7 = v6;
  if ( a3 )
  {
    bt_packet_parse(
      v33,
      (uint32_t *)(*((uint32_t *)off_138E9C + 8) + 88),
      (int *)off_138E9C + 9,
      (uint16_t *)off_138E9C + 21,
      *((uint8_t *)off_138E9C + 7));
    v13 = *((uint8_t *)v4 + 8);
    v10 = *(uint32_t **)(v5 + 28);
    LOWORD(v5) = *(uint16_t *)(v5 + 48) - v13;
    v14 = *((uint8_t *)v4 + 8);
  }
  else
  {
    v9 = *((uint8_t *)off_138E9C + 8);
    v10 = *(uint32_t **)(a1 + 28);
    v5 = (uint16_t)(*(uint16_t *)(a1 + 48) - v9);
    v11 += 16;
    if ( a4 && v5 <= 7 )
    {
      v47 = HIDWORD(v34);
      LODWORD(v34) = v7;
      v35 = (uint8_t *)(v9 + v10[2]);
      unaligned_word_load(v34, v5);
      v36 = (char *)&v48;
      v37 = (char *)&v48 + (uint8_t)(8 - v5);
      do
      {
        *v36 = v36[v47 + v5 - (uint32_t)&v48];
        ++v36;
      }
      while ( v37 != v36 );
      v38 = 8 - (uint8_t)(8 - v5);
      if ( v38 )
      {
        v39 = v35;
        v40 = (char *)(v37 - v35);
        v41 = &v35[v38];
        do
        {
          v39[(uint32_t)v40] = *v39;
          ++v39;
        }
        while ( v41 != v39 );
      }
      goto LABEL_36;
    }
    LODWORD(v12) = v7;
    unaligned_word_load(v12, 8u);
    v13 = *((uint8_t *)v4 + 8);
    v14 = *((uint8_t *)v4 + 8);
  }
  LODWORD(v18) = v10[2];
  v15 = (uint16_t)(v5 - 8);
  v16 = (uint16_t)(v10[3] + 1 - v18);
  v17 = (int)(v13 + v15) <= (int)v16;
  HIDWORD(v18) = v13 + v18;
  if ( v17 )
  {
    v16 = (uint16_t)(v14 + v15);
LABEL_11:
    LODWORD(v18) = v7;
    unaligned_word_load(v18, v15);
  }
  else
  {
    v19 = (uint16_t **)off_138EA0;
    while ( 1 )
    {
      LODWORD(v18) = v7;
      v15 = (uint16_t)(v15 + v14 - v16);
      unaligned_word_load(v18, (uint16_t)(v16 - v14));
      v14 = 0;
      if ( !(uint16_t)v15 )
        break;
      v10 = (uint32_t *)v10[1];
      if ( **v19 < 0 && !v10 )
      {
        unknown_12f2c8((int)aPdNull, (int)aRxuCntrlMicChe, 963);
        return 0;
      }
      HIDWORD(v18) = v10[2];
      v16 = (uint16_t)(v10[3] + 1 - WORD2(v18));
      if ( v16 >= (uint16_t)v15 )
      {
        v16 = (uint16_t)v15;
        goto LABEL_11;
      }
    }
  }
  v20 = (uint16_t **)off_138EA0;
  v21 = (char *)&v48;
  v22 = 8;
  while ( 1 )
  {
    v23 = *((uint64_t *)v10 + 1);
    v24 = v23;
    v25 = WORD2(v23) + 1;
    v26 = (uint16_t)(WORD2(v23) + 1 - v23);
    v27 = (uint8_t *)(v23 + v16);
    if ( (int)(v22 + v16) <= v26 )
      break;
    v28 = (uint16_t)(v26 - v16);
    v29 = v28 - 1;
    if ( v28 )
    {
      v22 = (uint16_t)(v22 + v16 + v24 - v25);
      goto LABEL_16;
    }
    v22 = (uint16_t)(v24 + v22 + v16 - v25);
LABEL_19:
    v10 = (uint32_t *)v10[1];
    v16 = 0;
    if ( **v20 < 0 && !v10 )
    {
      unknown_12f2c8((int)aPdNull, (int)aRxuCntrlMicChe, 1005);
      return 0;
    }
  }
  v28 = v22;
  v29 = v22 - 1;
  v22 = 0;
LABEL_16:
  v30 = &v27[v29 + 1];
  v31 = v21 - v27;
  do
  {
    v27[v31] = *v27;
    ++v27;
  }
  while ( v27 != v30 );
  v21 += v28;
  if ( v22 )
    goto LABEL_19;
  if ( !a4 )
  {
    v7[2] = v48;
    return 1;
  }
LABEL_36:
  ble_state_check_13362c((int)v7);
  if ( v48 == *v7 )
    return 1;
  v42 = tx_send_pdu(5126, 13, 5, 24);
  v43 = v4[6];
  v44 = dword_138E98 + 696 * *((uint8_t *)v4 + 9);
  v45 = *((uint64_t *)v4 + 2);
  v46 = *(uint32_t *)(v44 + 38);
  *(uint16_t *)(v42 + 4) = *(uint16_t *)(v44 + 42);
  *(uint64_t *)(v42 + 8) = v45;
  *(uint32_t *)v42 = v46;
  *(uint8_t *)(v42 + 18) = *((uint8_t *)v4 + 10);
  *(uint8_t *)(v42 + 16) = (v43 & 0x400) != 0;
  *(uint8_t *)(v42 + 17) = *(uint8_t *)(v4[8] + 97);
  rx_process_packet_1(v42);
  return 0;
}
