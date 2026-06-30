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

extern uint32_t off_113750;
extern uint32_t dword_113754;
extern uint32_t off_113764;
extern uint32_t off_113758;
extern uint32_t dword_113768;
extern uint32_t dword_11376C;
extern uint32_t off_113770;
extern uint32_t dword_113760;
extern uint32_t dword_11375C;

// sub_1136D4 @ 0x1136d4, size 124 bytes
int sub_1136D4()
{
  void *v0; // r7
  int result; // r0
  uint16_t *v2; // r9
  uint16_t *v3; // r6
  int v4; // r8
  int v5; // r11
  int16_t **v6; // r10
  uint16_t v7; // r5
  unsigned int v8; // r1
  int v9; // r2

  v0 = off_113750;
  result = sub_12D100(dword_113754);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 8) )
  {
    v2 = off_113764;
    v3 = off_113758;
    v4 = dword_113768;
    v5 = dword_11376C;
    v6 = (int16_t **)off_113770;
    v7 = 0;
    do
    {
      if ( !sub_10F9E8(v4, (uint16_t)(v2[153] - 4)) )
      {
        sub_12E948(v5, v7, v9);
        if ( **v6 < 0 )
          sub_12F32C(dword_113760, dword_11375C, 495);
      }
      result = sub_12D108(dword_113754);
      v8 = *(uint16_t *)(*(uint32_t *)v0 + 8);
      ++v7;
      ++*v3;
    }
    while ( v8 > v7 );
  }
  return result;
}

