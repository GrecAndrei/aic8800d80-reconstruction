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

extern uint32_t dword_139F58;

// scan_parse_response @ 0x139ef8, size 96 bytes
// Doc: scan_parse_response [scan]: Parses scan info-element with signed byte and 0x78-masked option flags
// scan_parse_response [scan]: Parses scan info-element with signed byte and 0x78-masked option flags
int  scan_parse_response(char *a1, char a2, int a3)
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
  result = memcpy(&v6, &a1[(uint8_t)(v3 + 6)], 2);
  if ( v6 == 36488 )
    return event_dispatch(dword_139F58, 36488, a3);
  return result;
}

