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

extern uint32_t off_11BA0C;
extern uint32_t dword_11BA10;
extern uint32_t dword_11BA14;

// state_flag_check @ 0x11b9e0, size 44 bytes
int state_flag_check()
{
  uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = off_11BA0C;
  if ( (*((uint8_t *)off_11BA0C + 88) & 8) != 0 )
  {
    v1 = dword_11BA10;
    goto LABEL_6;
  }
  if ( (*((uint8_t *)off_11BA0C + 88) & 4) != 0 )
  {
    v1 = dword_11BA14;
LABEL_6:
    v2 = *((uint32_t *)off_11BA0C + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return rx_queue_reset();
  }
  if ( *((uint32_t *)off_11BA0C + 11) )
    return rx_queue_reset();
  return result;
}

