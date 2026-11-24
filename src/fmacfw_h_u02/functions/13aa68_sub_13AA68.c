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


extern uint32_t dword_13AD6C;
extern uint32_t dword_13AD78;
extern uint32_t dword_13AD7C;
extern uint32_t off_13AD74;
extern uint32_t off_13AD80;
extern uint32_t off_13AD84;
extern uint32_t off_13AD88;
extern uint32_t off_13AD8C;
extern uint32_t off_13AD90;
extern uint32_t off_13AD9C;
extern uint32_t off_13ADE0;

// phy_txpower_calc @ 0x13aa68, size 882 bytes
int  phy_txpower_calc(unsigned int a1, int a2)
{
  unsigned int v2; // r6
  int v5; // r3
  int v6; // r7
  int v7; // r3
  uint16_t v9; // r0
  int v10; // r2
  uint8_t *v11; // r7
  int v12; // r3
  uint16_t v13; // r8
  int v14; // r6
  int v15; // r8
  int *v16; // r9
  uint16_t **v17; // r10
  int v18; // r7
  unsigned int v19; // r0
  signed int v20; // r1
  unsigned int v21; // r0
  char v22; // r2
  int v23; // r9
  uint8_t *v24; // r8
  int v25; // r1
  int v26; // r3
  unsigned int v27; // r6
  uint32_t *v28; // r7
  int *v29; // r3
  uint16_t v30; // r3
  int v31; // r0
  void *v32; // r3
  int v33; // r0
  int v34; // r2
  uint32_t *v35; // r0
  int v36; // r2
  int v37; // r0
  char v38; // r2
  uint32_t *v39; // r0
  int v40; // r1
  char v41; // [sp+4h] [bp-10h]
  int a2a; // [sp+Ch] [bp-8h] BYREF

  v2 = *(uint8_t *)(a1 + 28);
  if ( v2 > 3 )
    return phy_set_channel_1(a1, a2, 0x80000000);
  v5 = *(uint8_t *)(a1 + 29);
  if ( v5 == 255 )
  {
    if ( (*(uint16_t *)(a1 + 30) & 8) == 0 )
    {
      alloc_tx_event(aDataStaInvalid);
      return phy_set_channel_1(a1, a2, 0x80000000);
    }
    goto LABEL_11;
  }
  v6 = dword_13AD6C;
  v7 = dword_13AD6C + 696 * v5;
  if ( !*(uint8_t *)(v7 + 37) || *(uint8_t *)(v7 + 48) )
    return phy_set_channel_1(a1, a2, 0x80000000);
  v9 = *(uint16_t *)(a1 + 30);
  if ( (v9 & 8) != 0 )
  {
LABEL_11:
    v11 = off_13AD74;
    v12 = *((uint8_t *)off_13AD74 + 13);
    a2a = 0;
    if ( v12 && (*((uint8_t *)off_13AD74 + 15) & 6) == 2 && (*(uint16_t *)(*(uint32_t *)(a1 + 72) + 172) & 0xFC) == 0xB0 )
    {
      ke_event_handler(6155, 6, dword_13AD78);
      enable_clock_2();
      v11[15] |= 4u;
    }
    v13 = *(uint16_t *)(a1 + 30);
    v14 = dword_13AD7C + 1320 * v2;
    if ( (v13 & 0x10) != 0 || *(uint8_t *)(v14 + 1224) )
    {
      *(uint32_t *)(a1 + 44) = off_13AD80;
    }
    else
    {
      v32 = off_13AD84;
      if ( *(uint8_t *)(*(uint32_t *)(v14 + 72) + 4) )
        v32 = off_13AD80;
      *(uint32_t *)(a1 + 44) = v32;
    }
    v15 = v13 & 0x80;
    if ( v15 )
    {
      v33 = bt_conn_is_active(a1, 192, 0);
      if ( v33 == 1 )
      {
        LOBYTE(v15) = phy_init(a1, &a2a);
        memcpy_1((char *)(*(uint32_t *)(a1 + 72) + 164), (char *)(*(uint32_t *)(a1 + 72) + 172), 0x18u);
        v41 = 24;
      }
      else
      {
        LOBYTE(v15) = 0;
        if ( v33 == 2 )
          a2a = 18;
        else
          *(uint16_t *)(a1 + 30) &= ~0x80u;
        v41 = 0;
      }
    }
    else
    {
      v41 = 0;
    }
    v16 = (int *)off_13AD88;
    v17 = (uint16_t **)off_13AD8C;
    v18 = 0;
    while ( 1 )
    {
      v19 = *(uint32_t *)(a1 + 8);
      v20 = v19 & 0x7F;
      if ( (v19 & 0x40000000) != 0 )
      {
        v21 = (v19 >> 11) & 7;
        *(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v18 + 20) = *(uint32_t *)(a1 + 8) & 0x387F | 0x20000000;
        if ( !*((uint8_t *)v16 + 197) )
          goto LABEL_22;
      }
      else
      {
        v21 = (*(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v18 + 20) >> 11) & 7;
        v20 = *(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v18 + 20) & 0x7F;
        if ( !*((uint8_t *)v16 + 197) )
        {
LABEL_22:
          if ( **v17 < 0 )
            irq_disable_mmio_write(off_13AD90, (int)aTxuCntrlUmacde, 414);
          goto LABEL_24;
        }
      }
      v31 = bt_packet_parser(v21, v20, (uint8_t *)(*(uint32_t *)(v14 + 72) + 4));
      *(uint32_t *)(*(uint32_t *)(a1 + 44) + 4 * v18 + 36) = v31 | (v31 << 8);
LABEL_24:
      if ( ++v18 == 4 )
      {
        *(uint8_t *)(a1 + 50) = v41;
        *(uint32_t *)(a1 + 36) = 0;
        *(uint32_t *)(a1 + 40) = 0;
        v22 = a2a;
        *(uint8_t *)(a1 + 51) = v15;
        *(uint8_t *)(a1 + 66) = v15;
        *(uint8_t *)(a1 + 53) = v22;
        return phy_set_rate_power(a1, a2);
      }
    }
  }
  v10 = *(uint8_t *)(v7 + 52);
  if ( *(uint16_t *)(v7 + 56) == (uint16_t)__rev16(*(uint16_t *)(a1 + 24)) )
  {
    *(uint16_t *)(a1 + 30) = v9 & 0xFEFF;
    if ( (unsigned int)(v10 - 1) > 1 )
    {
      v10 = *(uint8_t *)(v7 + 52);
      goto LABEL_9;
    }
  }
  else if ( v10 != 2 )
  {
LABEL_9:
    check_feature_flag(32, "port filter:%d\r\n", v10);
    return phy_set_channel_1(a1, a2, 0x80000000);
  }
  v23 = dword_13AD7C;
  v24 = (uint8_t *)(dword_13AD7C + 1320 * v2);
  if ( !v24[108] )
  {
    alloc_tx_event(aTxuVifInactive);
    return phy_set_channel_1(a1, a2, 0x80000000);
  }
  phy_reset(a1);
  v26 = v6 + 696 * *(uint8_t *)(a1 + 29);
  if ( *(uint8_t *)(v26 + 52) != 2 )
    goto LABEL_31;
  v34 = v24[106];
  if ( v24[106] )
  {
    if ( v34 != 2 || !*(uint8_t *)(v26 + 688) )
      goto LABEL_53;
LABEL_31:
    v27 = v23 + 1320 * v2;
    v28 = off_13AD84;
    v29 = (int *)off_13AD88;
    if ( *(uint8_t *)(*(uint32_t *)(v27 + 72) + 4) )
      v28 = off_13AD80;
    *(uint32_t *)(a1 + 44) = v28;
    if ( *((uint8_t *)v29 + 197) )
    {
      v37 = bt_packet_parser((v28[5] >> 11) & 7, v28[5] & 0x7F, (uint8_t *)(*(uint32_t *)(v27 + 72) + 4));
      v30 = *(uint16_t *)(a1 + 30);
      v28[9] = v37 | (v37 << 8);
    }
    else
    {
      if ( **(uint16_t **)off_13AD8C < 0 )
        irq_disable_mmio_write(off_13ADE0, (int)aTxuCntrlPush, 1195);
      v30 = *(uint16_t *)(a1 + 30);
    }
    goto LABEL_37;
  }
  if ( v24[149] )
    goto LABEL_31;
LABEL_53:
  if ( !*(uint8_t *)off_13AD9C )
    radio_irq_handler(a1, v25, v34, *(uint8_t *)off_13AD9C);
  l2c_state_check(a1);
  v35 = process_rx_event(v6 + 696 * *(uint8_t *)(a1 + 29));
  v30 = *(uint16_t *)(a1 + 30);
  *(uint32_t *)(a1 + 44) = v35;
  if ( (v30 & 0x2000) != 0 )
  {
    v36 = *(uint32_t *)(v6 + 696 * *(uint8_t *)(a1 + 29) + 340);
    *(uint32_t *)(a1 + 40) = *(uint32_t *)(v36 + 156);
    if ( *(uint8_t *)(v36 + 165) )
      *(uint8_t *)(a1 + 54) |= 0x20u;
  }
  else
  {
    v38 = *(uint8_t *)(a1 + 54);
    v39 = &v35[v38 & 3];
    v40 = v39[9];
    *(uint32_t *)(a1 + 40) = v39[5];
    if ( (v40 & 0x40000) != 0 )
      *(uint8_t *)(a1 + 54) = v38 | 0x20;
  }
LABEL_37:
  if ( (v30 & 1) == 0 )
    phy_check_chanspec(a1, (uint16_t *)(*(uint32_t *)(a1 + 72) + 172));
  return phy_set_rate_power(a1, a2);
}
