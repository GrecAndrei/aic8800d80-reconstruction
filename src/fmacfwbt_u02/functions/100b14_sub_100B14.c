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


extern uint32_t dword_100CC4;
extern uint32_t off_100CA4;
extern uint32_t off_100CA8;
extern uint32_t off_100CAC;
extern uint32_t off_100CB0;
extern uint32_t off_100CB4;
extern uint32_t off_100CB8;
extern uint32_t off_100CBC;
extern uint32_t off_100CC0;
extern uint32_t off_100CC8;
extern uint32_t off_100CCC;

// call_1006d8_with_args @ 0x100b14, size 400 bytes
char * call_1006d8_with_args(int a1, unsigned int a2, unsigned int a3, int a4, char a5)
{
  uint32_t *v9; // r2
  uint32_t *v10; // r2
  uint32_t *v11; // r1
  int v12; // r3
  char *v13; // r0
  unsigned int *v14; // r5
  unsigned int *v15; // r1
  int v16; // r2
  unsigned int *v17; // r1
  char *result; // r0
  unsigned int *v19; // r2
  signed int v20; // r3
  int v21; // r2
  unsigned int *v22; // r1
  unsigned int *v23; // r2
  int v24; // r2
  uint32_t *v25; // r1
  uint32_t *v26; // r0

  clock_start();
  v9 = off_100CA4;
  *(uint32_t *)off_100CA4 &= ~0x40u;
  if ( a1 == 1 )
  {
    v25 = off_100CA8;
    v26 = off_100CAC;
    *(uint32_t *)off_100CA8 = *(uint32_t *)off_100CA8 & 0xFFFE3FFF | 0x18000;
    *v26 &= ~1u;
    v25[27857] |= 0x100u;
    if ( (a5 & 4) != 0 )
      *v9 |= 0x40u;
  }
  else
  {
    v10 = off_100CA8;
    v11 = off_100CAC;
    *(uint32_t *)off_100CA8 = *(uint32_t *)off_100CA8 & 0xFFFE3FFF | 0xC000;
    *v11 |= 1u;
    v10[27857] &= ~0x100u;
  }
  if ( a4 == 1 )
  {
    if ( a2 >= a3 )
      v24 = 2;
    else
      v24 = 1;
    *(uint32_t *)off_100CB0 = v24;
    v12 = a2 >= a3;
  }
  else if ( a4 == 2 )
  {
    v20 = a3 - a2;
    if ( (int)(a3 - a2) <= 0 )
    {
      if ( v20 >= -10 )
        v21 = 2;
      else
        v21 = 3;
    }
    else
    {
      v21 = v20 <= 10;
    }
    v12 = ((uint8_t)((int)((uint64_t)(dword_100CC4 * (uint64_t)(int)(a2 - (a3 - 30))) >> 32) >> 3)
         - (uint8_t)((int)(a2 - (a3 - 30)) >> 31))
        & 7;
    *(uint32_t *)off_100CB0 = v21;
  }
  else
  {
    v12 = 0;
    *(uint32_t *)off_100CB0 = 0;
  }
  v13 = (char *)off_100CB4;
  v14 = (unsigned int *)off_100CB8;
  v15 = (unsigned int *)off_100CBC;
  *(uint32_t *)off_100CB4 = v12 | *(uint32_t *)off_100CB4 & 0xFFFFFFF8;
  v16 = (a4 << 24) & 0x3000000;
  *v14 = *v14 & 0xFCFFFFFF | v16;
  *v15 = (a4 << 16) & 0x30000 | *v15 & 0xFFFCFFFF;
  v17 = v15 + 16708;
  *(uint32_t *)&v13[-80] = *(uint32_t *)&v13[-80] & 0xFFFFFFF0 | a4 & 0xF;
  result = v13 - 80;
  *v17 = v16 | *v17 & 0xFCFFFFFF;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      result = (char *)off_100CC8;
      v22 = (unsigned int *)off_100CCC;
      v23 = (unsigned int *)off_100CC0;
      *(uint32_t *)off_100CC8 = *(uint32_t *)off_100CC8 & 0xFFFFFF | 0x18000000;
      *v22 = *v22 & 0xFFFFFFCF | 0x10;
      *v23 = *v23 & 0xFFFF00FF | 0x6C00;
    }
  }
  else
  {
    v19 = (unsigned int *)off_100CC0;
    *((uint32_t *)result + 1) = *((uint32_t *)result + 1) & 0xFFFFFF | 0x19000000;
    v17[15866] &= 0xFFFFFFCF;
    *v19 = *v19 & 0xFFFF00FF | 0x9C00;
  }
  return result;
}
