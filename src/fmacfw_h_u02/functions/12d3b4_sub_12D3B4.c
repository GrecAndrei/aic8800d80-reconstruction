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

extern uint32_t dword_12D3DC;

// crc32_update @ 0x12d3b4, size 40 bytes
unsigned int  crc32_update(uint8_t *a1, int a2, unsigned int a3)
{
  uint8_t *v3; // r1
  int v4; // t1

  if ( !a2 )
    return a3;
  v3 = &a1[a2];
  do
  {
    v4 = *a1++;
    a3 = *(uint32_t *)(dword_12D3DC + 4 * (v4 ^ HIBYTE(a3))) ^ (a3 << 8);
  }
  while ( v3 != a1 );
  return a3;
}

