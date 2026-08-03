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

extern uint32_t dword_105FC8;
extern uint32_t dword_105FCC;
extern uint32_t dword_105FC0;
extern uint32_t dword_105FC4;

// sub_105F40 @ 0x105f40, size 124 bytes
int  sub_105F40(uint32_t *a1, int a2, int a3)
{
  uint64_t v5; // r0
  int v6; // r0
  uint32_t *v7; // r9
  int v8; // r0
  int v9; // r7
  float v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r5
  int v14; // r8
  int v15; // r2

  v5 = sub_12754C(a2);
  v6 = sub_127874(v5, HIDWORD(v5), dword_105FC8, dword_105FCC);
  v7 = &a1[a3];
  v8 = sub_127BE4(v6);
  v9 = v7[35];
  v10 = COERCE_FLOAT(sub_11EAA0(v8));
  v11 = a1[42];
  v12 = a1[41];
  v13 = (int)(float)(v10 * 20.0);
  v14 = v12 - v13;
  if ( v11 < v13 )
  {
    sub_11F74C(1, dword_105FC0, v11, v12);
    v15 = a1[43];
    if ( v15 <= v13 )
      goto LABEL_3;
LABEL_5:
    sub_11F74C(1, dword_105FC4, v15, v12);
    goto LABEL_3;
  }
  v15 = a1[43];
  if ( v15 > v13 )
    goto LABEL_5;
LABEL_3:
  v7[35] = v9 + v14;
  return crypto_table_copy_165d00((int)a1, a3);
}

