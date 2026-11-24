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


extern uint32_t dword_1065F0;

// sub_106568 @ 0x106568, size 124 bytes
int  sub_106568(int a1, int a2, int a3)
{
  uint64_t v5; // r0
  uint64_t v6; // r0
  int v7; // r9
  unsigned int v8; // r0
  int v9; // r7
  float v10; // r0
  uint64_t v11; // kr00_8
  int v12; // r5
  int v13; // r2

  v5 = sub_1429D4(a2);
  v6 = sub_142CFC(v5, *(uint64_t *)&dword_1065F0);
  v7 = a1 + 4 * a3;
  v8 = sub_14306C(v6);
  v9 = *(uint32_t *)(v7 + 140);
  v10 = COERCE_FLOAT(sub_12D6E0(v8));
  v11 = *(uint64_t *)(a1 + 164);
  v12 = (int)(float)(v10 * 20.0);
  if ( SHIDWORD(v11) < v12 )
  {
    sub_12ECD0(1, "sat> %d \n", HIDWORD(v11));
    v13 = *(uint32_t *)(a1 + 172);
    if ( v13 <= v12 )
      goto LABEL_3;
LABEL_5:
    sub_12ECD0(1, "sma %d\n", v13);
    goto LABEL_3;
  }
  v13 = *(uint32_t *)(a1 + 172);
  if ( v13 > v12 )
    goto LABEL_5;
LABEL_3:
  *(uint32_t *)(v7 + 140) = v9 + v11 - v12;
  return sub_1064BC(a1, a3);
}
