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


extern uint32_t off_11E5FC;
extern uint32_t off_11E600;

// tx_timeout_check @ 0x11e540, size 188 bytes
int  tx_timeout_check(int a1)
{
  int v1; // r4
  int v2; // r2
  int v3; // r3
  unsigned int v4; // r3
  uint32_t *v5; // r1
  int v6; // r2
  int v7; // cf
  unsigned int v8; // r2
  char *v10; // r0
  int v11; // r2
  int a1b; // [sp+4h] [bp-4h]
  int a1a; // [sp+4h] [bp-4h]

  if ( *(uint16_t *)(a1 + 48) )
  {
    v1 = *(uint32_t *)(a1 + 28);
    if ( **(uint16_t **)off_11E5FC < 0 && !v1 )
    {
      v10 = aPdNull;
      v11 = 393;
      return ke_int_lock_1((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v2 = *(uint32_t *)(a1 + 84);
    v3 = **(uint16_t **)(v1 + 8) & 0xFC;
    *(uint32_t *)(a1 + 84) = v2 & 0xFEFFFFFF;
    if ( v3 == 36 )
    {
      if ( (v2 & 0x2000) != 0 )
      {
        a1b = a1;
        rxreorder_process(a1);
        a1 = a1b;
      }
    }
    else if ( v3 == 148 && (~v2 & 0x2002) == 0 )
    {
      a1a = a1;
      ke_event_loop(a1, v2 & 0xFEFFFFFF, v2, 0);
      a1 = a1a;
    }
    v4 = (*(uint32_t *)(v1 + 12) & 0xFFFFFFFC) + 4;
  }
  else
  {
    if ( **(uint16_t **)off_11E5FC < 0 && *(uint32_t *)(a1 + 28) )
    {
      v10 = aDmaHdrdescHdFi;
      v11 = 436;
      return ke_int_lock_1((int)v10, (int)aRxlRxcntrlFram, v11);
    }
    v4 = a1 + 160;
  }
  v5 = off_11E600;
  v6 = *((uint32_t *)off_11E600 + 5);
  if ( *((uint32_t *)off_11E600 + 4) == v4 )
    v4 = *((uint32_t *)off_11E600 + 3);
  *(uint32_t *)(a1 + 152) = v4;
  v7 = v4 >= (v6 & 0x7FFFFFFFu);
  v8 = v6 & 0x80000000;
  if ( !v7 )
    v8 += 0x80000000;
  v5[5] = v4 | v8;
  return rf_tx_timestamp_check(a1);
}
