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

extern uint32_t off_115BB8;
extern uint32_t off_115BBC;
extern uint32_t off_115BDC;
extern uint32_t off_115BE0;
extern uint32_t dword_115C08;
extern uint32_t off_115BE4;
extern uint32_t dword_115C0C;
extern uint32_t off_115BE8;
extern uint32_t off_115BEC;
extern uint32_t dword_115C14;
extern uint32_t off_115BF0;
extern uint32_t off_115BC8;
extern uint32_t dword_115BF8;
extern uint32_t off_115BF4;
extern uint32_t off_115BFC;
extern uint32_t off_115BD4;
extern uint32_t off_115BC0;
extern uint32_t off_115BC4;
extern uint32_t dword_115BD8;
extern uint32_t dword_115C1C;
extern uint32_t dword_115C10;
extern uint32_t off_115BCC;
extern uint32_t off_115BD0;
extern uint32_t dword_115C18;

// sleep_mode_read @ 0x1159a4, size 532 bytes
int  sleep_mode_read(int result)
{
  uint8_t **v1; // r5
  uint8_t **v2; // r6
  int v3; // r3
  int *v4; // r3
  uint8_t *v5; // r4
  int v6; // r3
  int v7; // r1
  void *v8; // r2
  char v9; // r0
  int v10; // r1
  void *v11; // r2
  int v12; // r0

  if ( *(uint8_t *)off_115BB8 && (*((uint32_t *)off_115BBC + 4) & 0xFFFF00) == 0x10000 )
  {
    v6 = *(uint8_t *)off_115BDC;
    *(uint8_t *)off_115BE0 = 0;
    if ( v6 )
      return check_feature_flag(2, dword_115C08);
    if ( !*(uint8_t *)off_115BE4 )
      return check_feature_flag(2, dword_115C0C);
    if ( *(uint32_t *)off_115BE8 && *(uint32_t *)(*(uint32_t *)off_115BE8 + 12) - *((uint32_t *)off_115BEC + 4) - 5000 < 0 )
      return check_feature_flag(2, dword_115C14);
    if ( !*(uint8_t *)off_115BF0
      && !*((uint32_t *)off_115BC8 + 126)
      && ((dword_115BF8 & *(uint32_t *)off_115BF4) == 0 || (unsigned int)(32 * *(uint32_t *)off_115BFC) > 0x1387) )
    {
      ((void (*)(void))mmio_read_bit13)();
      while ( 1 )
        ;
    }
    return result;
  }
  if ( *((uint8_t *)off_115BBC + 18) )
  {
    v5 = off_115BD4;
    goto LABEL_23;
  }
  v1 = (uint8_t **)off_115BC0;
  if ( **(uint8_t **)off_115BC0 )
  {
    v2 = (uint8_t **)off_115BC4;
    goto LABEL_6;
  }
  v4 = *((int **)off_115BBC + 2);
  v5 = off_115BD4;
  *(uint8_t *)off_115BD4 = 1;
  if ( !v4 )
  {
LABEL_38:
    v2 = (uint8_t **)off_115BC4;
    if ( **(uint8_t **)off_115BC4 == 3 )
      goto LABEL_8;
    result = check_feature_flag(2, dword_115BD8);
    *v5 = 1;
LABEL_6:
    v3 = **v2;
    if ( v3 == 1 )
    {
      if ( **v1 == 3 )
      {
        v9 = wait_radio_flag();
        v11 = off_115BE0;
        *(uint8_t *)off_115BE0 = v9;
        if ( v9 )
          alloc_tx_event(dword_115C1C, v10, v11);
        else
          alloc_tx_event(dword_115C10, v10, v11);
        if ( get_init_flag() )
          chip_revision_read();
        return ((int (*)(void))mmio_read_bit13)();
      }
      result = get_init_flag();
      if ( !result || *(uint8_t *)off_115BF0 )
        return result;
    }
    else if ( v3 == 2 )
    {
      return result;
    }
LABEL_8:
    result = mfp_key_get_status(result);
    if ( result )
    {
      if ( !*((uint32_t *)off_115BC8 + 126) )
      {
        if ( (*(uint32_t *)off_115BCC >> 25) & 1 | *((uint8_t *)off_115BD0 + 36) )
        {
          if ( !*((uint8_t *)off_115BD0 + 29) )
          {
            result = rf_radio_status();
            if ( result )
            {
              LOBYTE(result) = wait_radio_flag();
              v8 = off_115BE0;
              result = (uint8_t)result;
              *(uint8_t *)off_115BE0 = result;
              if ( !(uint8_t)result )
              {
                v12 = alloc_tx_event(dword_115C18, v7, v8);
                result = mmio_read_bit13(v12);
              }
              if ( (uint8_t)**v1 <= 1u )
                return (int)chip_revision_read();
            }
          }
        }
      }
    }
    return result;
  }
  while ( !*((uint8_t *)v4 + 106) )
  {
    if ( *((uint8_t *)v4 + 108) )
      goto LABEL_20;
LABEL_17:
    v4 = (int *)*v4;
    if ( !v4 )
      goto LABEL_38;
  }
  if ( *((uint8_t *)v4 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(uint8_t **)off_115BC4 != 3 )
    result = check_feature_flag(2, dword_115BD8);
LABEL_23:
  *v5 = 0;
  return result;
}

