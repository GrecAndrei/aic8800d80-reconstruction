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

extern uint32_t dword_12FA24;
extern uint32_t dword_12FA28;

// init_static_tables @ 0x12fa04, size 32 bytes
int init_static_tables()
{
  uint32_t *v0; // r4
  int v1; // r6
  int v2; // r5

  v0 = (uint32_t *)dword_12FA24;
  v1 = dword_12FA28;
  v2 = dword_12FA24 + 112;
  do
  {
    if ( v0[1] )
      log_printf(v1, *v0);
    v0 += 4;
  }
  while ( v0 != (uint32_t *)v2 );
  return 0;
}

