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

extern uint32_t dword_107788;
extern uint32_t dword_10778C;
extern uint32_t dword_107790;
extern uint32_t dword_107794;
extern uint32_t dword_107798;

// sub_1076E4 @ 0x1076e4, size 164 bytes
int  sub_1076E4(unsigned int a1, uint32_t *a2, int a3)
{
  int v3; // r8
  int v7; // s15

  v3 = *(uint32_t *)(a3 + 8);
  sub_12EB90(1, dword_107788);
  sub_12EB90(1, dword_10778C);
  v7 = (int)(float)(COERCE_FLOAT(((int ( *)(uint32_t))sub_12D5A0)(vcvts_n_f32_u32(a1, 0xEu))) * 10.0);
  sub_12EB90(1, dword_107790);
  if ( a2[8] < v7 )
  {
    sub_12EB90(1, dword_107794);
    if ( a2[9] <= v7 )
      goto LABEL_3;
LABEL_5:
    sub_12EB90(1, dword_107798);
    goto LABEL_3;
  }
  if ( a2[9] > v7 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(a3 + 8) = (int)((float ( *)(uint32_t))sub_12D5C8)((float)(unsigned int)(a2[7] - v7 + v3));
  return sub_107620(a3);
}

