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

extern uint32_t dword_13BF34;
extern uint32_t dword_13BF28;
extern uint32_t dword_13BF2C;
extern uint32_t dword_13BF30;

// sub_13BEB0 @ 0x13beb0, size 120 bytes
// Doc: sub_123BEB0 [util]: Large utility function iterating over descriptor tables from base pointers
// sub_123BEB0 [util]: Large utility function iterating over descriptor tables from base pointers
int  sub_13BEB0(int result)
{
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BF34;
  v2 = dword_13BF28;
  v3 = dword_13BF2C;
  v4 = result;
  v5 = dword_13BF34 - 8;
  v6 = dword_13BF34 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(uint16_t *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(uint8_t *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        list_remove_node_d510(v6, (uint32_t *)v3);
        list_push_tail(dword_13BF30, (uint32_t *)v3);
      }
      else
      {
        list_remove_node_d510(v1, (uint32_t *)v3);
        list_push_tail(v5, (uint32_t *)v3);
      }
      rf_bus_mark_n_3b7((uint16_t)((uint16_t)i << 8) | 8, 4);
      result = sub_13BE40(v4, (uint16_t)i);
    }
    v3 += 32;
  }
  return result;
}

