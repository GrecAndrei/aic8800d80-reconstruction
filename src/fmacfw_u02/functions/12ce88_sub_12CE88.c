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

extern uint32_t off_12CF0C;
extern uint32_t dword_12CF1C;
extern uint32_t dword_12CF14;
extern uint32_t dword_12CF10;
extern uint32_t dword_12CF24;
extern uint32_t dword_12CF20;
extern uint32_t dword_12CF28;
extern uint32_t dword_12CF18;

// sub_12CE88 @ 0x12ce88, size 130 bytes
int  sub_12CE88(unsigned int a1)
{
  int16_t **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (int16_t **)off_12CF0C;
  v2 = a1 >> 8;
  v3 = (uint8_t)a1;
  if ( **(int16_t **)off_12CF0C >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a1 > 0xDu )
  {
    sub_12F46C(dword_12CF1C, dword_12CF14, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12CF10;
      v5 = 16 * v3;
      return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      sub_12F46C(dword_12CF24, dword_12CF20, 183);
  }
  else if ( (uint8_t)a1 != 13 )
  {
    goto LABEL_6;
  }
  sub_12F46C(dword_12CF28, dword_12CF14, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12CF10;
  v7 = dword_12CF10 + 16 * v3;
  v5 = 16 * v3;
  if ( *(uint16_t *)(v7 + 14) > v2 )
    return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
  sub_12F46C(dword_12CF18, dword_12CF14, 212);
  return *(uint16_t *)(*(uint32_t *)(v4 + v5 + 8) + 2 * v2);
}

