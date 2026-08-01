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
extern uint32_t dword_125E00;
extern uint32_t dword_125E08;
extern uint32_t dword_125E04;

// check_mmio_status_flag @ 0x125da4, size 86 bytes
int check_mmio_status_flag()
{
  int v1; // r4
  int v2[3]; // [sp+4h] [bp-Ch] BYREF

  if ( (*(uint32_t *)off_125DFC & 0x2000000) != 0 )
    return 0;
  sub_100200(v2, 0, 4u);
  v1 = mmio_write_400000_4((int)v2);
  dispatch_event_handler(dword_125E00, v1);
  if ( v1 || HIWORD(v2[0]) == 0xFFFF || LOWORD(v2[0]) == 0xFFFF )
    dispatch_event_handler(dword_125E08);
  else
    dispatch_event_handler(dword_125E04);
  return 0;
}

