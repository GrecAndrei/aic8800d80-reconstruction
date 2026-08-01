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

extern uint32_t dword_132880;

// rf_get_channel_cal @ 0x132860, size 32 bytes
int  rf_get_channel_cal(int a1)
{
  if ( *(uint8_t *)(dword_132880 + 1320 * a1 + 412) == 1 )
    return 5409;
  else
    return 5153;
}

