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

extern uint32_t off_10CAFC;
extern uint32_t off_10CB00;
extern uint32_t off_10CB04;
extern uint32_t dword_10CB0C;
extern uint32_t dword_10CB08;

// invoke_event_handler @ 0x10caa4, size 86 bytes
int invoke_event_handler()
{
  uint32_t *v0; // r4
  int v1; // r0
  int v2; // r3
  int v4; // r3

  v0 = off_10CAFC;
  while ( !*(uint32_t *)off_10CAFC )
    ;
  if ( *(uint32_t *)(*(uint32_t *)off_10CB00 + 612) )
  {
    v1 = list_pop(*(uint32_t *)off_10CB00 + 612);
    v2 = **(int16_t **)off_10CB04;
    *v0 = 1;
    if ( v2 >= 0 || v1 )
      return v1 + 20;
  }
  else
  {
    v4 = **(int16_t **)off_10CB04;
    *(uint32_t *)off_10CAFC = 1;
    if ( v4 >= 0 )
      return 20;
  }
  irq_disable_mmio_write(dword_10CB0C, dword_10CB08, 1101);
  return 20;
}

