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

extern uint32_t dword_1304AC;
extern uint32_t dword_1304A0;
extern uint32_t off_1304A4;
extern uint32_t dword_1304A8;

// rf_is_channel_valid @ 0x130430, size 110 bytes
int  rf_is_channel_valid(int a1)
{
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_1304AC * (unsigned uint64_t)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((unsigned uint64_t)(dword_1304A0 * (uint64_t)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((uint8_t *)off_1304A4 + 4)
     + (char)(*(uint8_t *)(dword_1304A8 + v1 + 7) - *(uint8_t *)(dword_1304A8 + *((char *)off_1304A4 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    LOBYTE(v2) = 1;
  *((uint8_t *)off_1304A4 + 5) = v2;
  rf_calibrate_channel_power(v1);
  result = get_flag_bit(9u, 4u);
  if ( result )
    return rf_configure_channel();
  return result;
}

