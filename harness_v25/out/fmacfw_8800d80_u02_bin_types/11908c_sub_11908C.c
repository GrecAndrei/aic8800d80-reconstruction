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

extern uint32_t dword_1190B0;

// sub_11908C @ 0x11908c, size 36 bytes
int  sub_11908C(int a1, int a2, int a3)
{
  if ( (*(uint32_t *)(dword_1190B0 + 696 * a1 + 4) & 0x20) != 0 )
    return rf_chan_table_lookup_8f48(a1, 7, a2, a3);
  else
    return sub_118DC4(a1, a2, a3);
}

