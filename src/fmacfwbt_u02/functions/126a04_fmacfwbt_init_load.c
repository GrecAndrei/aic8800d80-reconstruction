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

extern uint32_t dword_126A3C;
extern uint32_t off_126A40;
extern uint32_t dword_126A44;

// fmacfwbt_init_load @ 0x126a04, size 56 bytes
// Doc: fmacfwbt_init_load [util]: Initialize FMAC+BT firmware image from 0x190c50 table
// fmacfwbt_init_load [util]: Initialize FMAC+BT firmware image from 0x190c50 table
int fmacfwbt_init_load()
{
  int result; // r0
  uint32_t *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_12D4F8(dword_126A3C);
  if ( result )
  {
    v1 = off_126A40;
    timestamp_remove_058(dword_126A44);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      list_push_tail(v2);
      result = sub_12D4F8(v3);
    }
    while ( result );
  }
  return result;
}

