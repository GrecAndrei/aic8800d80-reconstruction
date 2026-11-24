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


extern uint32_t off_126164;

// rf_is_ready @ 0x126104, size 94 bytes
int rf_is_ready()
{
  int v1; // r4
  int result; // [sp+Ch] [bp-14h] BYREF
  uint16_t a4; // [sp+10h] [bp-10h]
  uint16_t a4_2; // [sp+12h] [bp-Eh]
  uint8_t v5; // [sp+14h] [bp-Ch]

  if ( (*(uint32_t *)off_126164 & 0x2000000) != 0 )
    return 0;
  memset_thunk(&result, 0, 0xAu);
  v1 = mmio_write_1000000_10((int)&result);
  dispatch_event_handler_1("ret %d\n", v1);
  if ( v1 )
    dispatch_event_handler_1(aNoPcieInfoInFl_0);
  else
    dispatch_event_handler_1(
      "get vid 0x%x, did 0x%x, subsys_vid 0x%x, subsys_id 0x%x, rev_id 0x%x\r\n",
      (uint16_t)result,
      HIWORD(result),
      a4,
      a4_2,
      v5);
  return 0;
}
