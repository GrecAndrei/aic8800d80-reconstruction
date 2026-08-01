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

extern uint32_t off_1248D8;
extern uint32_t off_1248DC;
extern uint32_t dword_1248EC;
extern uint32_t dword_1248E0;
extern uint32_t off_1248E4;
extern uint32_t dword_1248E8;

// mmio_set_flag @ 0x1248a4, size 50 bytes
int mmio_set_flag()
{
  uint8_t *v0; // r4
  int *v1; // r3
  int v2; // r2

  if ( !*(uint8_t *)off_1248D8 )
    *(uint8_t *)off_1248D8 = 1;
  v0 = off_1248DC;
  if ( *(uint8_t *)off_1248DC )
  {
    dispatch_event_handler(dword_1248EC);
    return 0;
  }
  else
  {
    ke_event_loop(144, *(uint8_t *)off_1248DC, dword_1248E0);
    v1 = (int *)off_1248E4;
    v2 = dword_1248E8;
    *v0 = 1;
    *v1 = v2;
    return 0;
  }
}

