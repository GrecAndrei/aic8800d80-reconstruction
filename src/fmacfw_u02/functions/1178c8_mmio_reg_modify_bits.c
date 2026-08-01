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

extern uint32_t dword_117918;
extern uint32_t off_117914;
extern uint32_t off_117920;
extern uint32_t off_11791C;

// core_rev_read @ 0x1178c8, size 76 bytes
// Doc: core_rev_read [mmio]: Read-modify-write MMIO register using mask 0xf0001f
// core_rev_read [mmio]: Read-modify-write MMIO register using mask 0xf0001f
unsigned int core_rev_read()
{
  int v0; // r4
  unsigned int result; // r0

  v0 = dword_117918 & *(uint32_t *)off_117914;
  if ( (*(uint32_t *)off_117914 & 0x10) != 0 )
  {
    if ( (*(uint32_t *)off_117914 & 0x1000) != 0 )
    {
      v0 |= 0x1000u;
      *((uint32_t *)off_117920 + 52) |= 4u;
    }
    enable_radio_clock();
  }
  result = v0 & 0xF00000;
  if ( (v0 & 0xF00000) != 0 )
    result = dispatch_command((uint8_t)(11 - __clz(result)));
  *(uint32_t *)off_11791C = v0;
  return result;
}

