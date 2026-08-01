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

extern uint32_t dword_13078C;
extern uint32_t dword_130790;
extern uint32_t dword_130794;

// format_bt_address @ 0x1306c0, size 204 bytes
char * format_bt_address(int a1)
{
  int v1; // r2
  uint16_t *v2; // r5
  uint8_t *v4; // r3
  int v5; // r0
  char v6; // t1
  int v7; // r2
  int v8; // r4
  int v9; // r0
  int v10; // r3
  char v11; // t1
  int v12; // r3
  int16_t v13; // r2
  uint16_t *v14; // r7
  int16_t v15; // r1
  int16_t v16; // r3
  char *result; // r0
  int v18; // r0
  int v19; // r3
  int v20; // r1
  int v21; // r2
  int v22; // r3
  char v23; // t1

  v1 = dword_13078C;
  **(uint8_t **)a1 = -1;
  *(uint8_t *)(*(uint32_t *)a1 + 2) = 35;
  v2 = *(uint16_t **)a1;
  v4 = (uint8_t *)(*(uint32_t *)a1 + 3);
  v5 = *(uint32_t *)a1 + 9;
  do
  {
    v6 = *(uint8_t *)++v1;
    *v4++ = v6;
  }
  while ( v4 != (uint8_t *)v5 );
  v7 = dword_130790;
  v8 = dword_130790 - 65;
  v9 = dword_130790 + 11;
  do
  {
    v10 = v7 - 56;
    v11 = *(uint8_t *)++v7;
    *((uint8_t *)v2 + v10 - v8) = v11;
  }
  while ( v7 != v9 );
  v12 = *(uint8_t *)(v8 + 0x42);
  v13 = *(uint16_t *)(v8 + 0x4E);
  v2[11] = *(uint16_t *)(v8 + 0x50);
  v2[10] = v13;
  v14 = v2 + 12;
  if ( (v12 & 8) != 0 )
  {
    v15 = *(uint16_t *)(v8 + 0x52);
    v2[13] = *(uint16_t *)(v8 + 0x54);
    v2[12] = v15;
    v14 = v2 + 14;
  }
  if ( ((v12 >> 1) & 8) != 0 )
  {
    v16 = *(uint16_t *)(v8 + 0x56);
    *v14 = v16;
    v14[1] = v16;
    v14 += 2;
  }
  if ( *(uint8_t *)(v8 + 0x48) >> 7 )
  {
    v18 = util_extract_bits();
    v19 = v18 + 1 + *(uint8_t *)(v8 + 0x175) * (v18 + 1);
    v20 = (uint8_t)((unsigned int)(6 * v19 + 14) >> 3);
    if ( (uint8_t)((unsigned int)(6 * v19 + 14) >> 3) )
    {
      v21 = dword_130794;
      do
      {
        v22 = v21 - 89;
        v23 = *(uint8_t *)++v21;
        *((uint8_t *)v14 + v22 - v8) = v23;
      }
      while ( v8 + 89 + v20 != v21 );
      v14 = (uint16_t *)((char *)v14 + v20);
    }
  }
  result = (char *)v14 - *(uint32_t *)a1;
  *(uint8_t *)(*(uint32_t *)a1 + 1) = (uint8_t)result - 2;
  *(uint32_t *)a1 += result;
  return result;
}

