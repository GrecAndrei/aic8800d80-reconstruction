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

extern uint32_t off_11B274;

// get_sched_item @ 0x11b228, size 74 bytes
int  get_sched_item(int result)
{
  uint32_t *v1; // r6
  char *v2; // r3
  int v3; // r2
  int v4; // r4
  int v5; // r5
  int v6; // r3

  v1 = off_11B274;
  v2 = (char *)off_11B274 + 28 * result;
  if ( v2[46] )
  {
    v3 = *((uint32_t *)off_11B274 + 52);
    v2[46] = 0;
    v4 = result;
    v5 = 8 * result;
    if ( (v3 & 1) == 0 || *((uint8_t *)v1 + 190) != result )
    {
      v6 = (int)&v1[7 * result];
      result = *(uint32_t *)(v6 + 36);
      if ( result )
        result = rf_switch_case(result, v4, v3, v6);
      v1[v5 - v4 + 9] = 0;
    }
  }
  return result;
}

