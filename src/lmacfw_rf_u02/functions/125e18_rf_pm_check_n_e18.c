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

extern uint32_t dword_125EE8;
extern uint32_t dword_125ECC;
extern uint32_t dword_125ED0;
extern uint32_t dword_125ED4;
extern uint32_t dword_125ED8;
extern uint32_t dword_125EDC;
extern uint32_t dword_125EE0;
extern uint32_t off_125EE4;
extern uint32_t dword_125EEC;

// acl_rx_handler @ 0x125e18, size 178 bytes
// Doc: acl_rx_handler [rf]: Check RF power management state
// acl_rx_handler [rf]: Check RF power management state
int  acl_rx_handler(int a1, int a2)
{
  uint8_t *v3; // r1
  uint8_t *v5; // r1
  int v6; // r0
  int v7; // r0
  int v8; // [sp+4h] [bp-4h]

  if ( a1 <= 1 )
  {
    dispatch_event_handler(dword_125EE8);
    return -1;
  }
  else
  {
    if ( memset_ff(*(uint32_t *)(a2 + 4)) == 1 || memset_ff(*(uint32_t *)(a2 + 4)) == 2 )
    {
      if ( memset_ff(*(uint32_t *)(a2 + 4)) == 1 )
      {
        v3 = *(uint8_t **)(a2 + 4);
        if ( !v3 || !util_list_find((uint8_t **)dword_125ECC, v3) )
        {
LABEL_7:
          dispatch_event_handler(dword_125ED0);
          return 0;
        }
      }
      else
      {
        if ( memset_ff(*(uint32_t *)(a2 + 4)) != 2 )
          return 0;
        v5 = *(uint8_t **)(a2 + 4);
        if ( !v5 || !util_list_find((uint8_t **)dword_125ED4, v5) )
          goto LABEL_7;
      }
      dispatch_event_handler(dword_125ED8);
      v8 = *(uint32_t *)(a2 + 4);
      v6 = memset_ff(v8);
      memcpy_large(dword_125EDC, v8, v6);
      dispatch_event_handler(dword_125EE0, dword_125EDC);
      if ( (*(uint32_t *)off_125EE4 & 0x2000000) == 0 )
        mmio_write_100000_2(dword_125EDC);
      return 0;
    }
    v7 = memset_ff(*(uint32_t *)(a2 + 4));
    dispatch_event_handler(dword_125EEC, v7);
    return -1;
  }
}

