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

extern uint32_t off_102E80;
extern uint32_t off_102E7C;

// sub_102E48 @ 0x102e48, size 50 bytes
int  sub_102E48(int a1)
{
  int *v1; // r2
  int v2; // r3

  if ( a1 )
  {
    v1 = (int *)off_102E80;
    *(uint32_t *)off_102E7C &= ~0x400u;
    v2 = *v1 | 0x8000000;
  }
  else
  {
    v1 = (int *)off_102E7C;
    *(uint32_t *)off_102E80 &= ~0x8000000u;
    v2 = *v1 | 0x400;
  }
  *v1 = v2;
  return rf_init_or_config_helper(a1);
}

