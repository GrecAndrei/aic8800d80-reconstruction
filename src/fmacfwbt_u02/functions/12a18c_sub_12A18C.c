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

extern uint32_t off_12A25C;
extern uint32_t dword_12A268;
extern uint32_t off_12A26C;
extern uint32_t dword_12A260;
extern uint32_t dword_12A264;

// sub_12A18C @ 0x12a18c, size 206 bytes
int  sub_12A18C(int a1, int a2)
{
  char *v2; // r4
  int v5; // r5
  char *v7; // r3
  int v8; // r1
  int v9; // r0
  int v10; // r8
  int v11; // r10
  int *v12; // r9
  int v13; // r2
  uint8_t *v14; // r12
  int v15; // r0
  int v16; // r1
  int v17; // r4
  int v18; // r1

  v2 = (char *)off_12A25C;
  if ( *((uint8_t *)off_12A25C + 113) == 255 )
  {
    v5 = 0;
    v10 = 0;
    v11 = 48;
    v12 = (int *)off_12A25C;
  }
  else
  {
    if ( *((uint8_t *)off_12A25C + 253) != 255 )
      return 255;
    v5 = 1;
    v10 = 1;
    v11 = 188;
    v12 = (int *)((char *)off_12A25C + 140);
  }
  memset_thunk(v12, 0, 0x8Cu);
  v7 = &v2[140 * v10];
  v7[113] = a1;
  v7[112] = a2;
  if ( a2 == 1 )
  {
    v13 = dword_12A268;
    v14 = off_12A26C;
    v7[66] = 1;
    v15 = v13 + 1320 * a1;
    LOBYTE(v13) = *v14;
    v16 = *(uint32_t *)(v15 + 4);
    v7[133] = 1;
    *((uint32_t *)v7 + 14) = &v2[v11];
    v17 = dword_12A260;
    *(uint32_t *)(v15 + 4) = v16 | 0x20;
    v18 = dword_12A264;
    *((uint32_t *)v7 + 2) = v12;
    v7[17] = v5;
    v7[65] = v5;
    *((uint32_t *)v7 + 26) = v12;
    *v14 = v13 + 1;
    *((uint32_t *)v7 + 1) = v17;
    *((uint32_t *)v7 + 13) = v17;
    v7[18] = 0;
    *((uint32_t *)v7 + 25) = v18;
  }
  else
  {
    v8 = dword_12A260;
    v9 = dword_12A264;
    *((uint32_t *)v7 + 14) = &v2[v11];
    *((uint32_t *)v7 + 2) = v12;
    v7[17] = v5;
    v7[65] = v5;
    *((uint32_t *)v7 + 26) = v12;
    *((uint32_t *)v7 + 1) = v8;
    *((uint32_t *)v7 + 13) = v8;
    v7[18] = 0;
    v7[66] = 1;
    v7[133] = 1;
    *((uint32_t *)v7 + 25) = v9;
  }
  return v5;
}

