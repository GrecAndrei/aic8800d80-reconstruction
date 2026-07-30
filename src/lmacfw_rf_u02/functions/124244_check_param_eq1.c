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

extern uint32_t off_1242D4;
extern uint32_t dword_1242E0;
extern uint32_t dword_1242EC;
extern uint32_t dword_1242DC;
extern uint32_t dword_1242E8;
extern uint32_t dword_1242D8;
extern uint32_t off_1242E4;

// check_param_eq1 @ 0x124244, size 144 bytes
// Doc: check_param_eq1 [util]: Compare parameter against 1 and branch
// check_param_eq1 [util]: Compare parameter against 1 and branch
unsigned int  check_param_eq1(unsigned int result, unsigned int a2, int a3)
{
  int v3; // r2
  int v4; // r3
  int v5; // r2
  int v6; // r5
  int v7; // r4
  int v8; // r3
  unsigned int *v9; // r1
  unsigned int v10; // t1

  if ( result <= 1 )
  {
    if ( !result && a2 <= 3 )
    {
      *(uint32_t *)off_1242D4 = 0;
      return result;
    }
    v4 = dword_1242E0;
    v3 = 512;
    *(uint32_t *)off_1242D4 = 512;
  }
  else if ( result > 4 )
  {
    if ( a3 )
    {
      v3 = 2048;
      v4 = dword_1242EC;
    }
    else
    {
      v3 = 2048;
      v4 = dword_1242DC;
    }
    *(uint32_t *)off_1242D4 = 2048;
  }
  else
  {
    if ( a3 )
    {
      v3 = 512;
      v4 = dword_1242E8;
    }
    else
    {
      v3 = 512;
      v4 = dword_1242D8;
    }
    *(uint32_t *)off_1242D4 = 512;
  }
  v5 = v4 + 4 * v3 - 4;
  v6 = (*(uint32_t *)off_1242E4 >> 5) & 3;
  *(uint32_t *)off_1242E4 &= 0xFFFFFF9F;
  v7 = 1048580 - v4;
  v8 = v4 - 4;
  do
  {
    v9 = (unsigned int *)(v7 + v8);
    v10 = *(uint32_t *)(v8 + 4);
    v8 += 4;
    result = v10;
    *v9 = v10;
  }
  while ( v8 != v5 );
  if ( v6 )
    *(uint32_t *)off_1242E4 = *(uint32_t *)off_1242E4 & 0xFFFFFF9F | (32 * v6);
  return result;
}

