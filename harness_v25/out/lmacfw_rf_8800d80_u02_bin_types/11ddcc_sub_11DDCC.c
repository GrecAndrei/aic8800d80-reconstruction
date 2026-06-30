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

extern uint32_t off_11DDEC;

// sub_11DDCC @ 0x11ddcc, size 32 bytes
// Doc: sub_121DDCC [unknown]: Load shared state pointer and read offset 0x14
// sub_121DDCC [unknown]: Load shared state pointer and read offset 0x14
int  sub_11DDCC(int a1, int a2)
{
  int **v2; // r3

  v2 = *((int ***)off_11DDEC + 5);
  if ( !v2 )
    return (int)v2;
  while ( *((uint16_t *)v2 + 2) != a1 || *((uint16_t *)v2 + 3) != a2 )
  {
    v2 = (int **)*v2;
    if ( !v2 )
      return (int)v2;
  }
  return 1;
}

