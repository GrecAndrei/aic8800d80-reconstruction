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

extern uint32_t dword_118B2C;
extern uint32_t dword_118B30;

// lock_acquire @ 0x118b04, size 38 bytes
int  lock_acquire(int a1, int a2)
{
  int v4; // r0
  int v5; // r1
  int v6; // r2
  int v7; // r4

  v4 = list_pop(dword_118B2C);
  v7 = v4;
  if ( v4 )
  {
    update_mic(v4, a1, a2);
    return v7;
  }
  else
  {
    alloc_tx_event(dword_118B30, v5, v6);
    return 0;
  }
}

