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


extern uint32_t off_1140E4;
extern uint32_t off_153308;
extern uint32_t off_15330C;

// check_global_value @ 0x114088, size 82 bytes
int  check_global_value(int a1)
{
  int result; // r0
  int v2; // r2

  if ( a1 == *(uint32_t *)asc_153304 )
  {
    v2 = 0;
  }
  else
  {
    if ( (_UNKNOWN *)a1 != off_153308 )
    {
      result = alloc_tx_event("%s, func 0x%x unknown\n", (const char *)a1, *(uint32_t *)asc_153304);
      goto LABEL_4;
    }
    v2 = 1;
  }
  result = alloc_tx_event("%s, func is %s\n", aUsbTransErrorH, (&off_15330C)[v2]);
LABEL_4:
  if ( BYTE1(((uint32_t *)(uintptr_t)off_1140E4)[88]) )
    return ke_event_handler(1068, 1, 1000 * BYTE2(((uint32_t *)(uintptr_t)off_1140E4)[88]));
  return result;
}
