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

extern uint32_t off_127074;
extern uint32_t dword_127078;
extern uint32_t dword_12707C;

// ctrl_check_flags @ 0x127048, size 44 bytes
int ctrl_check_flags()
{
  uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = off_127074;
  if ( (*((uint8_t *)off_127074 + 88) & 8) != 0 )
  {
    v1 = dword_127078;
    goto LABEL_6;
  }
  if ( (*((uint8_t *)off_127074 + 88) & 4) != 0 )
  {
    v1 = dword_12707C;
LABEL_6:
    v2 = *((uint32_t *)off_127074 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return ctrl_poll_events();
  }
  if ( *((uint32_t *)off_127074 + 11) )
    return ctrl_poll_events();
  return result;
}

