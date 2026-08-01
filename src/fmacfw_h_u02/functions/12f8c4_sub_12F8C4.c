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

extern uint32_t dword_12F8E4;
extern uint32_t dword_12F8E8;

// setup_global_table @ 0x12f8c4, size 32 bytes
int setup_global_table()
{
  uint32_t *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (uint32_t *)dword_12F8E4;
  v1 = dword_12F8E8;
  v2 = dword_12F8E4 + 112;
  do
  {
    if ( v0[1] )
      debug_printf(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (uint32_t *)v2 );
  return 0;
}

