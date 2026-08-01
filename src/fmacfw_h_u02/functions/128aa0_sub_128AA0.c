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

extern uint32_t off_128AE4;
extern uint32_t off_128AEC;
extern uint32_t off_128AE8;
extern uint32_t off_128AF0;
extern uint32_t dword_128AF4;

// wifi_disable_log @ 0x128aa0, size 66 bytes
int  wifi_disable_log(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r5
  int v5; // r3

  result = log_printf(a1, a2, (int)off_128AE4);
  if ( result )
  {
    v4 = off_128AEC;
    v5 = *((uint8_t *)off_128AE8 + 2);
    *((uint8_t *)off_128AEC + 28) = 0;
    if ( v5 )
      *(uint32_t *)off_128AF0 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = mem_set_util(dword_128AF4);
    v4[29] = 0;
    *(uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}

