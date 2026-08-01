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

extern uint32_t dword_13943C;
extern uint32_t dword_139440;

// tx_power_index_lookup @ 0x1393f8, size 66 bytes
uint32_t ** tx_power_index_lookup(int a1, int a2)
{
  uint32_t **result; // r0
  unsigned int v3; // r2
  int v4; // r1
  int v5; // r3
  int16_t v6; // r1

  result = *(uint32_t ***)(dword_13943C + 4 * (174 * a1 + (*(uint16_t *)(a2 + 16) >> 12) + 102));
  if ( result )
  {
    v3 = *(uint16_t *)(a2 + 18);
    v4 = *((uint16_t *)result + 4);
    if ( v4 != v3 >> 4 )
    {
      v5 = (v3 >> 4) - v4;
      v6 = (v3 >> 4) - v4;
      if ( (v5 & 0x800) == 0 )
      {
        list_find_nonnull((int)result, v6 & 0xFFF);
        return process_pending_queue((uint32_t **)dword_139440);
      }
    }
  }
  return result;
}

