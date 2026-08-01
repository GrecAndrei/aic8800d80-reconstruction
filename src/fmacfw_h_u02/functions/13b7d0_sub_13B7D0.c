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

// get_bt_state @ 0x13b7d0, size 68 bytes
int  get_bt_state(int a1)
{
  int v1; // r3
  int v2; // r6
  int ( *v4)(int, int); // r2
  uint8_t v5; // r0

  v1 = *(uint8_t *)(a1 + 262) + a1;
  if ( *(uint8_t *)(v1 + 6) != 2 )
    return 0;
  LOBYTE(v2) = 0;
  do
  {
    *(uint8_t *)(v1 + 6) = 0;
    v4 = *(int ( **)(int, int))a1;
    *(uint16_t *)(a1 + 4) = (*(uint16_t *)(a1 + 4) + 1) & 0xFFF;
    v5 = v4(a1, 1);
    v1 = a1 + v5;
    *(uint8_t *)(a1 + 262) = v5;
    v2 = (char)(v2 + 1);
  }
  while ( *(uint8_t *)(v1 + 6) == 2 );
  return v2;
}

