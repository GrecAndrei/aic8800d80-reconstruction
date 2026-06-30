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

extern uint32_t off_104B44;
extern uint32_t off_104B58;
extern uint32_t dword_104B48;
extern uint32_t off_104B5C;
extern uint32_t off_104B4C;
extern uint32_t dword_104B50;
extern uint32_t dword_104B54;

// sub_104A98 @ 0x104a98, size 172 bytes
int  sub_104A98(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r4
  int *v5; // r9
  int v6; // r5
  uint32_t *v7; // r11
  uint32_t *v12; // r2
  int v13; // r1
  unsigned int v14; // r5
  unsigned int v15; // r0
  int result; // r0
  int v17; // r1

  v4 = (unsigned int *)off_104B44;
  v5 = (int *)off_104B58;
  v6 = dword_104B48;
  v7 = off_104B5C;
  *(uint32_t *)off_104B44 &= ~0x20000000u;
  *v5 = *v5 & v6 | 0x80;
  sub_100560(300);
  *v5 = v6 & *v5 | a1 & 0xFFF;
  *v7 = 0;
  sub_100560(2);
  *v7 = 8;
  sub_100560(300);
  v12 = off_104B4C;
  v13 = dword_104B50;
  *v4 |= 0x40000000u;
  v14 = HIWORD(*v12) & 0x3FFF;
  v15 = *v4 & 0xBFFFFFFF;
  *(uint16_t *)(a2 + 2 * (a3 + 16 * a4)) = v14;
  *v4 = v15;
  result = sub_11F74C(1, v13, a1, a4);
  if ( v14 > 0x3E80 )
    return sub_11F504(dword_104B54, v17);
  return result;
}

