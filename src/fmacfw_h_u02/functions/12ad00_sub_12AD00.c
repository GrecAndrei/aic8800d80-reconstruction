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

extern uint32_t dword_12AD30;

// init_all_chan_entries @ 0x12ad00, size 48 bytes
int *init_all_chan_entries()
{
  int *result; // r0
  uint8_t *v1; // r3
  int v2; // r1

  init_chan_entry(0);
  init_chan_entry(1);
  init_chan_entry(2);
  result = init_chan_entry(3);
  v1 = (uint8_t *)dword_12AD30;
  v2 = dword_12AD30 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (uint8_t *)v2 );
  return result;
}

