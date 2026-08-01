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

extern uint32_t dword_14139C;

// ke_timer_tick_inc @ 0x141344, size 88 bytes
uint32_t *ke_timer_tick_inc()
{
  int v0; // r3
  int v1; // r0
  int v2; // r4
  uint32_t *result; // r0

  v0 = dword_14139C;
  v1 = *(uint32_t *)(dword_14139C + 6480) + 1;
  *(uint32_t *)(dword_14139C + 6480) = v1;
  v2 = v0;
  do
  {
    if ( *(uint16_t *)(v2 + 4) > 1u )
      *(uint16_t *)(v2 + 4) = 1;
    v2 += 528;
  }
  while ( v2 != v0 + 6336 );
  if ( v1 >= *(uint32_t *)(v2 + 148) )
  {
    result = hci_cmd_preprocess(0xBu, 0);
    *(uint32_t *)(v2 + 144) = -1;
  }
  else
  {
    hci_cmd_preprocess(0xBu, 4);
    return (uint32_t *)mac_write_header_word(11264, 11, 11);
  }
  return result;
}

