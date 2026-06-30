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

extern uint32_t off_125CF0;

// sub_125CD8 @ 0x125cd8, size 22 bytes
char * sub_125CD8(int a1, char a2)
{
  char *result; // r0

  if ( !*((uint32_t *)off_125CF0 + 1) )
    return (char *)sub_12503C(a1, a2);
  result = (char *)off_125CF0 + a1;
  result[20] = a2;
  return result;
}

