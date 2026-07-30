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
  int v4; // r5
  int v5; // r6
  int v6; // r7
  int v7; // r2
  int v8; // r3

  do
  {
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
    *(uint8_t *)(a1 + 30) = v4;
  }
  while ( _VF );
  *a3 = a1;
  a3[1] = a3;
  a3[2] = v4;
  a3[3] = v5;
  a3[4] = v6;
  *a3 = a1;
  a3[1] = a3 + 5;
  if ( (uint16_t)*(uint32_t *)off_1001EC == 49729
    || (*((uint32_t *)off_1001F0 + 23) & 3) != 2
    || (v7 = *((uint32_t *)off_1001F4 + 92), v8 = *((uint32_t *)off_1001F4 + 93), v7 >= 0)
    || v8 >= 0 )
  {
    dword_1001F8;
    
    return off_1001FC();
  }
  else
  {
    v7 & 0xFFFFFFF;
    
    return ((int (*)(void))(v8 & 0xFFFFFFF))();
  }
}

