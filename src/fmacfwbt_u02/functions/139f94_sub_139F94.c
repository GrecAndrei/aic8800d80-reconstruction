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

extern uint32_t dword_139FF4;

// tx_power_set_band_alt @ 0x139f94, size 96 bytes
// Doc: sub_1239F94 [util]: Parses a signed byte string with bitmask extraction (mask 0x78)
// sub_1239F94 [util]: Parses a signed byte string with bitmask extraction (mask 0x78)
int  tx_power_set_band_alt(char *a1, char a2, int a3)
{
  char v3; // r3
  int result; // r0
  uint16_t v6; // [sp+6h] [bp-2h] BYREF

  if ( *a1 >= 0 )
    v3 = 24;
  else
    v3 = 26;
  v6 = 0;
  if ( (a2 & 0x78) == 8 )
  {
    v3 += 8;
  }
  else if ( (a2 & 0x7C) == 4 )
  {
    v3 += 4;
  }
  result = memcpy_aligned(&v6, &a1[(uint8_t)(v3 + 6)], 2);
  if ( v6 == 36488 )
    return ke_event_schedule(dword_139FF4, 36488, a3);
  return result;
}

