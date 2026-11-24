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


extern uint32_t dword_138B64;
extern uint32_t off_138B60;

// rf_is_calibrated @ 0x138ab4, size 170 bytes
int  rf_is_calibrated(uint16_t *a1)
{
  int v2; // r7
  int v3; // r5
  int i; // r4
  int v6; // r10
  uint32_t *v7; // r4

  if ( *((uint8_t *)off_138B60 + 16) == 255 || (*a1 & 0xEC) != 0xC4 )
  {
    v2 = dword_138B64;
    v3 = 0;
    for ( i = dword_138B64; ; i += 1320 )
    {
      if ( *(uint8_t *)(i + 108) )
      {
        if ( *(uint8_t *)(i + 106) == 2 )
        {
          v6 = 1320 * v3;
          if ( !memcmp((unsigned int)(a1 + 2), i + 100, 6u) )
            break;
        }
      }
      if ( ++v3 == 4 )
        return 0;
    }
    v7 = *(uint32_t **)(v2 + v6 + 240);
    if ( v7 )
    {
      while ( memcmp((unsigned int)(a1 + 5), (unsigned int)v7 + 38, 6u) )
      {
        v7 = (uint32_t *)*v7;
        if ( !v7 )
          goto LABEL_14;
      }
      alloc_tx_event(
        "keyInValid[%04X:%04X:%04X]\n",
        (uint16_t)a1[5],
        (uint16_t)a1[6],
        (uint16_t)a1[7]);
    }
    else
    {
LABEL_14:
      alloc_tx_event(
        "%s: send_deauth[%04X:%04X:%04X]\n",
        aRxuCntrlSpurio,
        (uint16_t)a1[5],
        (uint16_t)a1[6],
        (uint16_t)a1[7]);
      rf_config_lookup(v2 + v6, (char *)a1 + 10);
    }
  }
  return 0;
}
