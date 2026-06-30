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

extern uint32_t off_125F14;

// sub_125EFC @ 0x125efc, size 22 bytes
char * sub_125EFC(int a1, char a2)
{
  char *result; // r0

  if ( !*((uint32_t *)off_125F14 + 1) )
    return (char *)sub_125260(a1, a2);
  result = (char *)off_125F14 + a1;
  result[20] = a2;
  return result;
}

