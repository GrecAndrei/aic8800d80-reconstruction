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

extern uint32_t off_1001EC;
extern uint32_t off_1001F0;
extern uint32_t off_1001F4;
extern uint32_t dword_1001F8;
extern uint32_t off_1001FC;

// start @ 0x100100, size 236 bytes
int  start(int a1, int a2, uint32_t *a3)
{
  uint32_t *v4; // r4
  int v5; // r6
  int ( *v6)(int); // r9
  int v7; // r5
  int v9; // r0
  int v10; // r2
  int v11; // r3

  v7 = *(uint8_t *)(a1 + 3);
  if ( (a3 != 0) & 0 )
  {
    v9 = a1 + 220;
    if ( (uint16_t)*(uint32_t *)off_1001EC == 49729
      || (*((uint32_t *)off_1001F0 + 23) & 3) != 2
      || (v10 = *((uint32_t *)off_1001F4 + 92), v11 = *((uint32_t *)off_1001F4 + 93), v10 >= 0)
      || v11 >= 0 )
    {
      dword_1001F8;
      
      return off_1001FC();
    }
    else
    {
      v10 & 0xFFFFFFF;
      
      return ((int ( *)(int))(v11 & 0xFFFFFFF))(v9);
    }
  }
  else
  {
    *v4 = a1;
    v4[1] = a3;
    v4[2] = v7;
    *a3 = a1;
    a3[1] = a3;
    a3[2] = v5;
    return v6(a1);
  }
}

