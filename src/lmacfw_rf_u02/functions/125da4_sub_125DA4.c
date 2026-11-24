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


extern uint32_t off_125DFC;

// check_mmio_status_flag @ 0x125da4, size 86 bytes
int check_mmio_status_flag()
{
  int v1; // r4
  int result[3]; // [sp+4h] [bp-Ch] BYREF

  if ( (*(uint32_t *)off_125DFC & 0x2000000) != 0 )
    return 0;
  memset_thunk(result, 0, 4u);
  v1 = mmio_write_400000_4((int)result);
  dispatch_event_handler_1("ret %d\n", v1);
  if ( v1 || HIWORD(result[0]) == 0xFFFF || LOWORD(result[0]) == 0xFFFF )
    dispatch_event_handler_1(aNoUsbInfoInFla_0);
  else
    dispatch_event_handler_1("get vid 0x%x, pid 0x%x\r\n", LOWORD(result[0]), HIWORD(result[0]));
  return 0;
}
