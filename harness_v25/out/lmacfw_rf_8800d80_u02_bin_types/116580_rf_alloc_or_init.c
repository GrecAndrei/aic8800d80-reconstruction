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

extern uint32_t dword_1165A8;
extern uint32_t dword_1165AC;

// rf_alloc_or_init @ 0x116580, size 38 bytes
// Doc: rf_alloc_or_init [rf]: Allocates/init RF context via 0x11e7ac then stores result
// rf_alloc_or_init [rf]: Allocates/init RF context via 0x11e7ac then stores result
int  rf_alloc_or_init(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r4

  v4 = sub_11E7AC(dword_1165A8);
  v6 = v4;
  if ( v4 )
  {
    rf_buf_setup_check(v4, a1, a2);
    return v6;
  }
  else
  {
    msg_parse(dword_1165AC, v5);
    return 0;
  }
}

