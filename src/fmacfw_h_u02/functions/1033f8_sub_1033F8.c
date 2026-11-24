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


extern uint32_t dword_10356C;
extern uint32_t dword_1038D4;
extern uint32_t dword_1038FC;
extern uint32_t dword_103900;
extern uint32_t off_10355C;
extern uint32_t off_103560;
extern uint32_t off_103564;
extern uint32_t off_103568;
extern uint32_t off_103570;
extern uint32_t off_103574;
extern uint32_t off_103578;
extern uint32_t off_10357C;
extern uint32_t off_103580;
extern uint32_t off_103898;
extern uint32_t off_10389C;
extern uint32_t off_1038A0;
extern uint32_t off_1038A8;
extern uint32_t off_1038B4;
extern uint32_t off_1038B8;
extern uint32_t off_1038C0;
extern uint32_t off_1038C4;
extern uint32_t off_1038D0;
extern uint32_t off_1038E0;
extern uint32_t off_1038E4;
extern uint32_t off_1038EC;
extern uint32_t off_1038F0;
extern uint32_t off_1038F4;
extern uint32_t off_1038F8;
extern uint32_t off_103904;
extern uint32_t off_103A24;
extern uint32_t off_103A28;
extern uint32_t off_103A2C;
extern uint32_t off_103A30;
extern uint32_t off_103A4C;
extern uint32_t off_151B24;
extern uint32_t off_151B28;

// crypto_init @ 0x1033f8, size 1580 bytes
int crypto_init()
{
  uint8_t *v0; // r4
  int *v1; // r2
  uint32_t *v2; // r0
  int v3; // r1
  uint32_t *v4; // r5
  uint8_t **v5; // r5
  uint32_t *v6; // r1
  int v7; // r6
  uint32_t *v8; // r0
  int *v9; // r8
  int v10; // r2
  uint32_t *v11; // r3
  uint32_t *v12; // r1
  int v13; // r0
  uint32_t *v14; // r3
  uint32_t *v15; // r1
  uint32_t *v16; // r4
  char *v17; // r6
  int v18; // r9
  int i; // r4
  int v20; // r0
  int v21; // r9
  int v22; // r10
  int k; // r5
  int v24; // r0
  int v25; // r5
  int v26; // r10
  int v27; // r0
  int v28; // r9
  uint64_t v29; // kr00_8
  int v30; // zf
  uint8_t v31; // r2
  int v32; // r3
  unsigned int v33; // r1
  int v34; // r3
  uint16_t *v35; // r5
  int v36; // r0
  int v37; // r2
  int v38; // r0
  unsigned int *v39; // r2
  int v40; // r0
  int j; // r4
  uint8_t v43; // r2
  int *v44; // r2
  int v45; // r3
  int v46; // r6
  unsigned int v47; // r3
  int v48; // r0
  int *v49; // r5
  uint8_t *v50; // r4
  uint32_t *v51; // r3
  uint32_t *v52; // r1
  uint8_t *v53; // r3
  char v54; // r1
  char v55; // r2
  int v56; // r11
  uint8_t *v57; // r4
  uint8_t *v58; // r7
  int n; // r5
  char v60; // t1
  int v61; // r3
  uint32_t *v62; // r7
  int v63; // r11
  char *v64; // r10
  int m; // r4
  char v66; // t1
  int v67; // r1
  uint8_t v68[4]; // [sp+Ch] [bp-28h] BYREF
  uint32_t v69[3]; // [sp+10h] [bp-24h] BYREF
  uint8_t a2[24]; // [sp+1Ch] [bp-18h] BYREF

  v0 = off_103560;
  *((uint32_t *)off_10355C + 64) = 8;
  if ( !v0[2] )
    *((uint32_t *)off_103564 + 2) = *((uint32_t *)off_103564 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_103564;
  while ( (*((uint32_t *)off_103564 + 12) & 0x22) != 2 )
    ;
  v2 = off_103568;
  v3 = dword_10356C;
  v4 = off_10355C;
  *((uint32_t *)off_103564 + 2) = *((uint32_t *)off_103564 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (uint8_t **)off_103570;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  rf_chain_enable();
  v6 = off_103564;
  v7 = dword_10356C;
  v8 = off_10355C;
  v9 = (int *)off_103580;
  *(uint32_t *)off_103564 = *(uint32_t *)off_103564 & 0x3EF | 0x10 | *(uint32_t *)off_103564 & dword_10356C;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((uint8_t *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v44 = (int *)off_1038F0;
    v45 = v9[42] | 0x2000000;
    *(uint8_t *)off_1038EC = 1;
    *v44 = v45;
    v8[14] |= 0x10u;
  }
  else
  {
    *(uint32_t *)off_103574 = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(uint8_t **)off_103578 == 2 )
    {
      v51 = off_103A24;
      v52 = off_103A28;
      *((uint32_t *)off_103A24 + 20) |= 0x40000u;
      v52[7] &= ~0x100u;
      v51[9] = v51[9] & 0xFFFFFF00 | 0x60;
      v51[9] = v51[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      enable_irq();
      enable_clock_1();
      if ( !*(uint32_t *)off_10357C )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = off_103564;
    **(uint8_t **)off_103578 = 2;
    v12 = off_10355C;
    v13 = (uint8_t)v0[2];
    v11[20] |= 0x40000u;
    v12[7] &= ~0x100u;
    v11[9] = v11[9] & 0xFFFFFF00 | 0x60;
    v11[9] = v11[9] & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v14 = off_103898;
    v15 = off_10389C;
    *((uint32_t *)off_103898 + 20) |= 0x40000u;
    v15[7] &= ~0x100u;
    v14[9] = v14[9] & 0xFFFFFF00 | 0x60;
    v14[9] = v14[9] & 0xFFFF00FF | 0xDF00;
  }
  configure_radio();
  enable_clock_1();
  if ( *(uint32_t *)off_1038A0 )
  {
LABEL_14:
    rf_enable_rx();
    rf_hw_init_alt();
    rf_hw_init();
  }
LABEL_17:
  v16 = off_10389C;
  radio_is_idle();
  v16[4] |= 2u;
  aes_load_key();
  if ( (*v16 & 0x2000000) != 0 )
  {
    v17 = (char *)off_1038A8;
    v18 = 1;
    for ( i = 0; i != 3; ++i )
    {
      v20 = packet_prepare_a(i, *(uint32_t *)asc_151888 + 3 * i);
      if ( v20 != 546 )
      {
        v17[1] |= 1u;
        v18 = 0;
      }
    }
    if ( v18 )
    {
      for ( j = 0; j != 3; ++j )
      {
        a2[0] = 0;
        if ( rf_cmd_a(j, a2) <= 1 )
        {
          v43 = a2[0];
          *(uint8_t *)(*(uint32_t *)asc_151888 + j) = a2[0];
          *(uint8_t *)(*(uint32_t *)asc_151888 + j + 3) = v43;
          *(uint8_t *)(*(uint32_t *)asc_151888 + j + 6) = v43;
        }
      }
    }
    v21 = dword_1038FC;
    v22 = 1;
    for ( k = 0; k != 3; ++k )
    {
      v24 = packet_prepare_b(k, *(uint32_t *)a2_0 + 6 * k);
      if ( v24 != v21 )
      {
        v17[1] |= 1u;
        v22 = 0;
      }
    }
    if ( v22 )
    {
      v25 = 0;
      v26 = dword_103900;
      a2[0] = 0;
      v27 = 2;
      v28 = 4;
      do
      {
        v29 = (unsigned int)v26 * (uint64_t)(unsigned int)(2 * v25);
        v30 = v28 == HIDWORD(v29) >> 1;
        v28 = HIDWORD(v29) >> 1;
        if ( !v30 )
          v27 = rf_cmd_b(HIDWORD(v29) >> 1, a2);
        if ( v27 <= 1 )
        {
          v31 = a2[0];
          *(uint8_t *)(*(uint32_t *)a2_0 + v25) = a2[0];
          v32 = *(uint32_t *)a2_0 + v25;
          *(uint8_t *)(v32 + 6) = v31;
          *(uint8_t *)(v32 + 12) = v31;
        }
        ++v25;
      }
      while ( v25 != 6 );
    }
    v33 = 31 - __clz(rf_reg_0x1b());
    *v17 = v33;
  }
  else
  {
    memset(v69, 0, sizeof(v69));
    v46 = send_smc_cmd_4((int)v69);
    if ( v46 )
    {
      v17 = (char *)off_1038A8;
    }
    else
    {
      debug_printf(aFlTxpwrOfst24g);
      v62 = v69;
      do
      {
        debug_printf("\r\n  [%d] =", v46);
        v63 = 3 * v46;
        v64 = (char *)v62;
        for ( m = 0; m != 3; ++m )
        {
          v66 = *v64++;
          *(uint8_t *)(*(uint32_t *)asc_151888 + v63 + m) = v66;
          v67 = *(char *)(*(uint32_t *)asc_151888 + v63 + m);
          debug_printf(" %d", v67);
        }
        ++v46;
        v62 = (uint32_t *)((char *)v62 + 3);
      }
      while ( v46 != 3 );
      v17 = (char *)off_103A4C;
      debug_printf(&aNoTxDscrHdr[16]);
      v17[1] |= 1u;
    }
    memset(a2, 0, 20);
    if ( !send_smc_cmd_0x20((int)a2) )
    {
      debug_printf(aFlTxpwrOfst5g);
      v56 = 0;
      v57 = a2;
      do
      {
        debug_printf("\r\n  [%d] =", v56);
        v58 = v57;
        for ( n = 0; n != 6; ++n )
        {
          v60 = *v58++;
          *(uint8_t *)(*(uint32_t *)a2_0 + n + 6 * v56) = v60;
          v61 = *(uint32_t *)a2_0 + n;
          debug_printf(" %d", *(char *)(v61 + 6 * v56));
        }
        ++v56;
        v57 += 6;
      }
      while ( v56 != 3 );
      debug_printf(&aNoTxDscrHdr[16]);
      v17[1] |= 1u;
    }
    if ( patch_validate((int)v68) )
    {
      v33 = -1;
      *v17 = -1;
    }
    else
    {
      v47 = v68[0];
      *v17 = v68[0];
      v33 = v47;
    }
  }
  debug_printf("cal_ver=%d\n", v33);
  if ( *((uint8_t *)v9 + 372) )
  {
    if ( (*(uint32_t *)off_10389C & 0x2000000) != 0 )
    {
      if ( rf_reg_0x0f_bit_18() )
      {
        v48 = rf_reg_0x11_bits_0_2();
        v49 = (int *)off_1038F4;
        v50 = off_1038F8;
        *(uint8_t *)off_1038F8 = *((uint8_t *)off_1038F4 + v48);
        v50[1] = *((uint8_t *)v49 + rf_reg_0x11_bits_3_5());
        v50[2] = *((uint8_t *)v49 + rf_reg_0x11_bits_6_8());
      }
    }
    else
    {
      *(uint32_t *)a2 = 0;
      if ( !send_smc_cmd_0x40((int)a2) )
      {
        v53 = off_103A30;
        v54 = *((uint8_t *)off_103A2C + a2[1]);
        v55 = *((uint8_t *)off_103A2C + a2[2]);
        *(uint8_t *)off_103A30 = *((uint8_t *)off_103A2C + a2[0]);
        v53[1] = v54;
        v53[2] = v55;
      }
    }
  }
  v34 = off_1038B8;
  v35 = off_1038C0;
  *(uint32_t *)off_1038B4 &= 0xFFFFFFC7;
  uart_send_data(0, 0, 0x10u, v34);
  uart_send_data(0, 16, 0x10u, off_1038C4);
  uart_send_data(0, 32, 0x10u, (int)off_151B28);
  uart_send_data(0, 48, 0x10u, (int)off_151B24[0]);
  uart_send_data(0, 64, 0x10u, *(int *)aT);
  uart_send_data(1, 0, 0x10u, *(int *)aX);
  uart_send_data(1, 16, 0x10u, *(int *)asc_152738);
  rf_config_read_b();
  crypto_start_operation(1);
  rf_config_read_a(0);
  crypto_start_operation(0);
  *(uint32_t *)off_1038D0 |= 0x8000000u;
  v36 = rf_power_adjust();
  v37 = ((int)(((uint64_t)(dword_1038D4 * (uint64_t)(4 * (v36 - 35))) >> 32) + 4 * (v36 - 35)) >> 2)
      - ((4 * (v36 - 35)) >> 31)
      + 120;
  *(uint16_t *)off_103904 = v37;
  *v35 = v37;
  alloc_tx_event("Init T=%d C, ipa_target=%d\n", v36, v37);
  v38 = rf_gpio_init((int)a2);
  debug_printf("cal_ipa_5g offset=%d, cgm=%d\n", v38, *(uint32_t *)a2);
  if ( (v17[1] & 1) != 0 && *v17 < 0 )
  {
    v39 = (unsigned int *)off_1038E4;
    *(uint32_t *)off_1038E0 = *(uint32_t *)off_1038E0 & 0xFFFFFF87 | 0x40;
    *v39 = *v39 & 0xFFF87FFF | 0x40000;
  }
  v40 = rf_gpio_init_alt();
  return debug_printf("cal_ipa_24g offset=%d\n", v40);
}
