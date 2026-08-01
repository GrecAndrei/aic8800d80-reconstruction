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

extern uint32_t off_138CA0;
extern uint32_t dword_138CA4;
extern uint32_t dword_138CA8;
extern uint32_t dword_138CB0;
extern uint32_t dword_138CAC;

// rand_gen_u16 @ 0x138bf4, size 170 bytes
int  rand_gen_u16(uint16_t *a1)
{
  int v2; // r7
  int v3; // r5
  int i; // r4
  int v6; // r10
  uint32_t *v7; // r4

  if ( *((uint8_t *)off_138CA0 + 16) == 255 || (*a1 & 0xEC) != 0xC4 )
  {
    v2 = dword_138CA4;
    v3 = 0;
    for ( i = dword_138CA4; ; i += 1320 )
    {
      if ( *(uint8_t *)(i + 108) )
      {
        if ( *(uint8_t *)(i + 106) == 2 )
        {
          v6 = 1320 * v3;
          if ( !memcmp(a1 + 2, i + 100, 6) )
            break;
        }
      }
      if ( ++v3 == 4 )
        return 0;
    }
    v7 = *(uint32_t **)(v2 + v6 + 240);
    if ( v7 )
    {
      while ( memcmp(a1 + 5, (char *)v7 + 38, 6) )
      {
        v7 = (uint32_t *)*v7;
        if ( !v7 )
          goto LABEL_14;
      }
      event_dispatch(dword_138CA8, (uint16_t)a1[5], (uint16_t)a1[6], (uint16_t)a1[7]);
    }
    else
    {
LABEL_14:
      event_dispatch(dword_138CB0, dword_138CAC, (uint16_t)a1[5], (uint16_t)a1[6], (uint16_t)a1[7]);
      rx_process_callback(v2 + v6, (int)(a1 + 5));
    }
  }
  return 0;
}

