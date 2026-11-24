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


extern uint32_t off_124170;

// rf_write_synth @ 0x124150, size 30 bytes
int  rf_write_synth(int a1)
{
  int v1; // r1

  v1 = (HIWORD(*(uint32_t *)off_124170) << 16) | (a1 << 8) | a1;
  *(uint32_t *)off_124170 = v1;
  dispatch_event_handler_1(" %x\r\n", v1);
  return 0;
}
