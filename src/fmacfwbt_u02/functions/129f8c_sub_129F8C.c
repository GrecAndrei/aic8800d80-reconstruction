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

// get_table_entry @ 0x129f8c, size 32 bytes
int  get_table_entry(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r0
  uint8_t v6; // r4

  v5 = lookup_table_entry(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  ke_event_lock(a1, v5);
  *(uint8_t *)(a1 + 16) = 1;
  return v6;
}

