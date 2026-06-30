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

extern uint32_t off_130578;
extern uint32_t dword_13057C;

// sub_130500 @ 0x130500, size 120 bytes
int  sub_130500(int *a1)
{
  char *v1; // r4
  int16_t v2; // r3
  int v3; // r2
  int v4; // r6
  char *v5; // r3
  char v6; // t1
  char *v7; // r2
  int v8; // r5
  uint8_t *v9; // r3
  uint8_t *v10; // r5
  char v11; // t1

  v1 = (char *)off_130578;
  v2 = *((uint16_t *)off_130578 + 6);
  *(uint8_t *)*a1 = 45;
  *(uint8_t *)(*a1 + 1) = 26;
  v3 = *a1;
  *(uint16_t *)(v3 + 2) = v2 & 0xFFE3 | 0xC;
  *(uint8_t *)(v3 + 4) = v1[14];
  v4 = *a1;
  v5 = v1 + 15;
  do
  {
    v6 = *v5++;
    *(uint8_t *)(v5 - v1 + v4 - 11) = v6;
  }
  while ( v5 != v1 + 31 );
  v7 = (char *)dword_13057C;
  *(uint8_t *)(*a1 + 15) = 0;
  *(uint8_t *)(*a1 + 16) = 0;
  v8 = *a1;
  *(uint16_t *)(v8 + 21) = *((uint16_t *)v1 + 16);
  v9 = (uint8_t *)(v8 + 23);
  v10 = (uint8_t *)(v8 + 27);
  do
  {
    v11 = *v7++;
    *v9++ = v11;
  }
  while ( v9 != v10 );
  *(uint8_t *)(*a1 + 27) = v1[40];
  *a1 += 28;
  return 28;
}

