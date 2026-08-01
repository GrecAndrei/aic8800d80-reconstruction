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

extern uint32_t dword_11BF2C;
extern uint32_t off_11BF28;
extern uint32_t dword_11BF34;
extern uint32_t dword_11BF30;

// rf_tx_packet_check @ 0x11bec0, size 102 bytes
// Doc: rf_tx_packet_check [rf]: Look up RF channel entry from global table indexed by byte at offset 1
// rf_tx_packet_check [rf]: Look up RF channel entry from global table indexed by byte at offset 1
int  rf_tx_packet_check(int result, int a2)
{
  int v2; // r4
  int v3; // r5
  int v5; // r7
  unsigned int v6; // r3
  int v7; // r8

  v2 = *(uint8_t *)(result + 1);
  v3 = dword_11BF2C;
  if ( **(int16_t **)off_11BF28 < 0 )
  {
    v7 = dword_11BF2C + 28 * v2;
    v5 = 8 * v2;
    v6 = *(uint8_t *)(v7 + 16);
    if ( !*(uint8_t *)(v7 + 16) )
    {
      result = flash_ctrl_init(dword_11BF34, dword_11BF30, 3289);
      if ( *(uint8_t *)(v7 + 16) <= 3u )
        goto LABEL_4;
      return ke_evt_handler(62, a2, 0);
    }
  }
  else
  {
    v5 = 8 * v2;
    v6 = *(uint8_t *)(dword_11BF2C + 28 * v2 + 16);
  }
  if ( v6 <= 3 )
  {
LABEL_4:
    *(uint16_t *)(v3 + 4 * (v5 - v2) + 14) = a2;
    return result;
  }
  return ke_evt_handler(62, a2, 0);
}

