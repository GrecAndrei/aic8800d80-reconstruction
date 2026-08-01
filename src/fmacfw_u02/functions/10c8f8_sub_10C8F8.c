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

extern uint32_t off_10C96C;
extern uint32_t dword_10C970;
extern uint32_t dword_10C974;
extern uint32_t off_10C978;
extern uint32_t off_10C97C;
extern uint32_t off_10C980;

// zero_buffer_range @ 0x10c8f8, size 114 bytes
int *zero_buffer_range()
{
  int v0; // r4
  int v1; // zf
  uint8_t v2; // r1
  int **v3; // r4

  v0 = *((uint32_t *)off_10C96C + 23);
  memset((int *)dword_10C970, 0, 0x28u);
  memset((int *)dword_10C974, 0, 0x1E6Cu);
  if ( (*(uint32_t *)off_10C978 & 8) != 0 )
  {
    while ( (*(uint32_t *)off_10C978 & 0x10) == 0 )
      ;
    v3 = (int **)off_10C97C;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10C97C;
    *(uint32_t *)off_10C978 |= 8u;
    if ( v1 )
      memset(*v3, v2, 0x288u);
    *(uint32_t *)off_10C978 |= 0x10u;
  }
  (*v3)[161] = *(uint32_t *)off_10C980;
  return gpio_af_select();
}

