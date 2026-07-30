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

extern uint32_t off_125CD0;

// sub_125CBC @ 0x125cbc, size 18 bytes
int  sub_125CBC(int a1)
{
  uint8_t *v1; // r3
  int v2; // r2

  v1 = off_125CD0;
  v2 = *((uint32_t *)off_125CD0 + 1);
  *(uint32_t *)off_125CD0 = a1;
  if ( !v2 )
    return sub_125C68(a1);
  v1[10] = 1;
  return a1;
}

