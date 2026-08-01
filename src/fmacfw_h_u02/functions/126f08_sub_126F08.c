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

extern uint32_t off_126F34;
extern uint32_t dword_126F38;
extern uint32_t dword_126F3C;

// llc_flag_test_bit3 @ 0x126f08, size 44 bytes
int llc_flag_test_bit3()
{
  uint32_t *v0; // r3
  int v1; // r1
  int v2; // r2
  int result; // r0

  v0 = off_126F34;
  if ( (*((uint8_t *)off_126F34 + 88) & 8) != 0 )
  {
    v1 = dword_126F38;
    goto LABEL_6;
  }
  if ( (*((uint8_t *)off_126F34 + 88) & 4) != 0 )
  {
    v1 = dword_126F3C;
LABEL_6:
    v2 = *((uint32_t *)off_126F34 + 11);
    if ( v2 != v1 )
    {
      if ( v2 )
        *(uint8_t *)(v2 + 16) = 1;
      v0[11] = v1;
    }
    return llc_sem_lock();
  }
  if ( *((uint32_t *)off_126F34 + 11) )
    return llc_sem_lock();
  return result;
}

