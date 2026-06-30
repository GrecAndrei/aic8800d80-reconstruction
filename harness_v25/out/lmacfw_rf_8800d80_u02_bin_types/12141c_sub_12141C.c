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

extern uint32_t dword_12148C;

// sub_12141C @ 0x12141c, size 112 bytes
int  sub_12141C(int a1, int *a2, int16_t a3, int16_t a4)
{
  int *v5; // r5
  int v6; // r2
  int v7; // r0
  int v8; // r3
  int v9; // r1

  v5 = (int *)rf_setup_dispatch(1042, a4, a3, 8u);
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    sub_10F064(*a2, a2[2], a2[1], 1);
    v7 = sub_10EFBC(*a2, 1);
    v6 = *a2;
  }
  else
  {
    *(uint32_t *)*a2 ^= (a2[2] ^ *(uint32_t *)*a2) & a2[1];
    v6 = *a2;
    v7 = *(uint32_t *)*a2;
  }
  v5[1] = v7;
  v8 = a2[2];
  v9 = a2[1];
  *v5 = v6;
  msg_parse(dword_12148C, v9, v8, v8, v6, v7, v7);
  sub_11DE50((int)v5);
  return 0;
}

