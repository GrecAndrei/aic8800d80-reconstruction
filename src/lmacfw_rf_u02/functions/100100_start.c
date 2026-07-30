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
int  start(int a1, int a2, unsigned int a3)
{
  int v3; // r6
  int *v4; // r5
  int v5; // r2
  int v6; // r3

  do
  {
    while ( 1 )
    {
      v4 = *(int **)(a3 + 76);
      if ( a1 != 0 && a3 >= 0x1D )
        break;
      v3 += 8;
      a1 = *v4;
      a3 = v4[1];
    }
  }
  while ( a3 == 0 || a3 < 0x1D );
  *(uint16_t *)(a1 + 14) = a1;
  if ( (uint16_t)*(uint32_t *)off_1001EC == 49729
    || (*((uint32_t *)off_1001F0 + 23) & 3) != 2
    || (v5 = *((uint32_t *)off_1001F4 + 92), v6 = *((uint32_t *)off_1001F4 + 93), v5 >= 0)
    || v6 >= 0 )
  {
    dword_1001F8;
    
    return off_1001FC();
  }
  else
  {
    v5 & 0xFFFFFFF;
    
    return ((int (*)(void))(v6 & 0xFFFFFFF))();
  }
}

