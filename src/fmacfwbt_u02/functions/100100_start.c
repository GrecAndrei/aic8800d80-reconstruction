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


extern uint32_t dword_1001F8;
extern uint32_t off_1001EC;
extern uint32_t off_1001F0;
extern uint32_t off_1001F4;
extern uint32_t off_1001FC;

// start @ 0x100100, size 236 bytes
int  start(int a1, int a2, int a3)
{
  int v4; // r4
  uint32_t *v5; // r6
  int v6; // r5
  int v7; // r2
  int v8; // r3

  v6 = *(uint8_t *)(a1 + 20);
  if ( !((a3 < 0) ^ _VF | (a3 == 0)) )
    JUMPOUT(0x1001F2);
  *v5 = a1;
  v5[1] = v4;
  v5[2] = v5;
  *v5 = a1;
  v5[1] = a3;
  v5[2] = a3;
  v5[3] = v6;
  v5[4] = v5;
  if ( (uint16_t)*(uint32_t *)off_1001EC == 49729
    || (*((uint32_t *)off_1001F0 + 23) & 3) != 2
    || (v7 = *((uint32_t *)off_1001F4 + 92), v8 = *((uint32_t *)off_1001F4 + 93), v7 >= 0)
    || v8 >= 0 )
  {
    _R0 = dword_1001F8;
    __asm volatile("msr msp, %0" : : "r"(R0) : "memory");
    return off_1001FC();
  }
  else
  {
    _R2 = v7 & 0xFFFFFFF;
    __asm volatile("msr msp, %0" : : "r"(R2) : "memory");
    return ((int (*)(void))(v8 & 0xFFFFFFF))();
  }
}
