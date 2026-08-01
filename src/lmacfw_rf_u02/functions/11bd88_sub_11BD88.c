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

extern uint32_t off_11BE24;
extern uint32_t dword_11BE10;
extern uint32_t dword_11BE20;
extern uint32_t dword_11BE18;
extern uint32_t dword_11BE1C;
extern uint32_t dword_11BE14;

// lookup_7byte_channel @ 0x11bd88, size 136 bytes
int * lookup_7byte_channel(int a1)
{
  int16_t **v1; // r8
  int v2; // r5
  int *v4; // r6
  int v5; // r7
  int v6; // r5
  int *result; // r0

  v1 = (int16_t **)off_11BE24;
  v2 = dword_11BE10;
  v4 = (int *)(dword_11BE10 + 28 * a1);
  if ( **(int16_t **)off_11BE24 < 0 )
  {
    v5 = 8 * a1;
    if ( *(uint8_t *)(dword_11BE10 + 28 * a1 + 24) != 255
      || (flash_ctrl_init(dword_11BE20, dword_11BE18, 3044), **v1 < 0) )
    {
      if ( *(uint8_t *)(v2 + 4 * (v5 - a1) + 25) )
        flash_ctrl_init(dword_11BE1C, dword_11BE18, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  check_kernel_state(dword_11BE14);
  v6 = v2 + 4 * (v5 - a1);
  result = sub_100200(v4, 0, 0x1Cu);
  *(uint16_t *)(v6 + 14) = 255;
  *(uint8_t *)(v6 + 24) = -1;
  return result;
}

