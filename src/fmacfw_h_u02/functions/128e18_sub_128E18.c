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

extern uint32_t off_128E40;
extern uint32_t off_128E3C;
extern uint32_t off_128E44;
extern uint32_t off_128E48;

// mfp_key_update @ 0x128e18, size 34 bytes
int  mfp_key_update(int a1, int16_t a2)
{
  uint8_t *v2; // r2
  uint8_t *v3; // r3
  int v4; // zf
  int (*v5)(void); // r3

  v2 = off_128E40;
  v3 = *(uint8_t **)off_128E3C;
  *((uint16_t *)off_128E40 + 1) = a2;
  v4 = *v3 == 2;
  v5 = (int (*)(void))off_128E44;
  if ( !v4 && a1 )
    v5 = (int (*)(void))off_128E48;
  v2[8] = 0;
  return v5();
}

