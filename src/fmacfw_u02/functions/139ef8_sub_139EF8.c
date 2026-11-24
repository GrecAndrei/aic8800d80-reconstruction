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

// scan_parse_response @ 0x139ef8, size 96 bytes
char * scan_parse_response(char *a1, char a2, int a3)
{
  char v3; // r3
  char *result; // r0
  char a1a[2]; // [sp+6h] [bp-2h] BYREF

  if ( *a1 >= 0 )
    v3 = 24;
  else
    v3 = 26;
  *(uint16_t *)a1a = 0;
  if ( (a2 & 0x78) == 8 )
  {
    v3 += 8;
  }
  else if ( (a2 & 0x7C) == 4 )
  {
    v3 += 4;
  }
  result = memcpy(a1a, &a1[(uint8_t)(v3 + 6)], 2u);
  if ( *(uint16_t *)a1a == 36488 )
    return (char *)event_dispatch("rx eapol:%x,%d\r\n", 36488, a3);
  return result;
}
