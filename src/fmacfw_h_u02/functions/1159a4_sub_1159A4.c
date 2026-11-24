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


extern uint32_t dword_115BB8;
extern uint32_t dword_115BBC;
extern uint32_t dword_115BC0;
extern uint32_t dword_115BC4;
extern uint32_t dword_115BC8;
extern uint32_t dword_115BCC;
extern uint32_t dword_115BD0;
extern uint32_t dword_115BD4;
extern uint32_t dword_115BDC;
extern uint32_t dword_115BE0;
extern uint32_t dword_115BE4;
extern uint32_t dword_115BE8;
extern uint32_t dword_115BF0;
extern uint32_t dword_115BF4;
extern uint32_t dword_115BF8;
extern uint32_t dword_115BFC;
extern uint32_t dword_115C00;

// sleep_mode_read @ 0x1159a4, size 532 bytes
void  sleep_mode_read(int result)
{
  uint8_t **v1; // r5
  uint8_t *v2; // r1
  uint8_t **v3; // r6
  int v4; // r3
  int *v5; // r3
  uint8_t *v6; // r4
  uint8_t *v7; // r4
  int v8; // r3
  volatile unsigned int v9; // r2
  volatile unsigned int v10; // r1
  unsigned int v11; // r1
  int v12; // r3
  unsigned int v13; // r2
  char v14; // r0
  char v15; // r0
  char v16; // r0

  if ( !*(uint8_t *)dword_115BB8 || (*(uint32_t *)(dword_115BBC + 0x10) & 0xFFFF00) != 0x10000 )
  {
    if ( *(uint8_t *)(dword_115BBC + 0x12) )
    {
      v6 = (uint8_t *)dword_115BD4;
      goto LABEL_23;
    }
    v1 = (uint8_t **)dword_115BC0;
    v2 = *(uint8_t **)dword_115BC0;
    if ( **(uint8_t **)dword_115BC0 )
    {
      v3 = (uint8_t **)dword_115BC4;
    }
    else
    {
      v5 = *(int **)(dword_115BBC + 8);
      v6 = (uint8_t *)dword_115BD4;
      *(uint8_t *)dword_115BD4 = 1;
      while ( v5 )
      {
        if ( *((uint8_t *)v5 + 106) )
        {
          if ( *((uint8_t *)v5 + 106) == 2 )
          {
LABEL_20:
            if ( **(uint8_t **)dword_115BC4 != 3 )
              check_feature_flag(2, "lp=%d, ignore=%d\n", *v2, 0);
LABEL_23:
            *v6 = 0;
            return;
          }
        }
        else if ( *((uint8_t *)v5 + 108) )
        {
          goto LABEL_20;
        }
        v5 = (int *)*v5;
      }
      v3 = (uint8_t **)dword_115BC4;
      if ( **(uint8_t **)dword_115BC4 == 3 )
        goto LABEL_8;
      check_feature_flag(2, "lp=%d, ignore=%d\n", *v2, 1);
      *v6 = 1;
    }
    v4 = **v3;
    if ( v4 == 1 )
    {
      if ( **v1 == 3 )
      {
        v15 = wait_radio_flag();
        *(uint8_t *)dword_115BE0 = v15;
        if ( v15 )
          alloc_tx_event(aWifiidleBtAllo);
        else
          alloc_tx_event(aWifiidleBtNotA);
        if ( get_init_flag() )
          chip_revision_read();
        mmio_read_bit13();
        return;
      }
      if ( !get_init_flag() || *(uint8_t *)dword_115BF0 )
        return;
    }
    else if ( v4 == 2 )
    {
      return;
    }
LABEL_8:
    if ( !mfp_key_get_status()
      || *(uint32_t *)(dword_115BC8 + 0x1F8)
      || !((*(uint32_t *)dword_115BCC >> 25) & 1 | *(uint8_t *)(dword_115BD0 + 0x24))
      || *(uint8_t *)(dword_115BD0 + 0x1D)
      || !rf_radio_status() )
    {
      return;
    }
    v14 = wait_radio_flag();
    *(uint8_t *)dword_115BE0 = v14;
    if ( !v14 )
    {
      alloc_tx_event(aBt1);
      mmio_read_bit13();
    }
    if ( (uint8_t)**v1 > 1u )
      return;
LABEL_46:
    chip_revision_read();
    return;
  }
  v7 = (uint8_t *)dword_115BE0;
  v8 = *(uint8_t *)dword_115BDC;
  *(uint8_t *)dword_115BE0 = 0;
  if ( v8 )
  {
    check_feature_flag(2, aApPsForbid);
    return;
  }
  if ( !*(uint8_t *)dword_115BE4 )
  {
    check_feature_flag(2, aAa);
    return;
  }
  if ( *(uint32_t *)dword_115BE8 )
  {
    v9 = (*(volatile uint32_t *)0x40501010u);
    if ( (int)(*(uint32_t *)(*(uint32_t *)dword_115BE8 + 12) - v9 - 5000) < 0 )
    {
      check_feature_flag(2, aMm);
      return;
    }
  }
  if ( !*(uint8_t *)dword_115BF0
    && !*(uint32_t *)(dword_115BC8 + 0x1F8)
    && ((dword_115BF8 & *(uint32_t *)dword_115BF4) == 0 || (unsigned int)(32 * *(uint32_t *)dword_115BFC) > 0x1387) )
  {
    mmio_read_bit13();
    v10 = (*(volatile uint32_t *)0x40501010u);
    v11 = v10 + 28;
    do
      v12 = v11 - (*(volatile uint32_t *)0x40501010u);
    while ( v12 >= 0 );
    if ( **(uint8_t **)dword_115BC4 == 1 )
    {
      v16 = wait_radio_flag();
      *v7 = v16;
      if ( !v16 )
      {
        check_feature_flag(2, aWifiidleBtNotA);
        return;
      }
    }
    v13 = dword_115C00;
    *(uint8_t *)dword_115BD4 = 1;
    *(uint32_t *)(v13 + 0x38) |= 0x10u;
    if ( !get_init_flag() )
    {
      check_feature_flag(2, aSdioNotAllowed);
      return;
    }
    goto LABEL_46;
  }
}
