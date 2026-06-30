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

extern uint32_t off_11D44C;
extern uint32_t off_11D450;
extern uint32_t off_11D454;
extern uint32_t off_11D458;
extern uint32_t dword_11D45C;
extern uint32_t off_11D464;
extern uint32_t dword_11D46C;
extern uint32_t dword_11D468;
extern uint32_t off_11D460;

// sub_11D3DC @ 0x11d3dc, size 110 bytes
unsigned int sub_11D3DC()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  int16_t **v2; // r5
  int *v3; // r4
  int v4; // r3
  int16_t *v5; // r2
  unsigned int result; // r0
  uint32_t *v7; // r2

  v0 = off_11D44C;
  v1 = off_11D450;
  *(uint32_t *)off_11D44C &= ~1u;
  v2 = (int16_t **)off_11D454;
  v3 = (int *)off_11D458;
  v4 = dword_11D45C;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(uint32_t *)off_11D464 << 28 )
  {
    sub_1219F4(dword_11D46C, dword_11D468, 472);
    v4 = *v3;
  }
  *(uint32_t *)off_11D460 = v4 | v3[1];
  result = sub_1174B8(1);
  v7 = off_11D450;
  *(uint32_t *)off_11D450 = *(uint32_t *)off_11D450 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

