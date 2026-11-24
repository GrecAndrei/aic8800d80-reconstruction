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

// start @ 0x1001a8, size 88 bytes
int start()
{
  int v0; // r2
  int v1; // r3

  if ( (uint16_t)*(uint32_t *)off_1001EC == 49729
    || (*((uint32_t *)off_1001F0 + 23) & 3) != 2
    || (v0 = *((uint32_t *)off_1001F4 + 92), v1 = *((uint32_t *)off_1001F4 + 93), v0 >= 0)
    || v1 >= 0 )
  {
    _R0 = dword_1001F8;
    __asm volatile("msr msp, %0" : : "r"(_R0) : "memory");
    return off_1001FC();
  }
  else
  {
    _R2 = v0 & 0xFFFFFFF;
    __asm volatile("msr msp, %0" : : "r"(_R2) : "memory");
    return ((int (*)(void))(v1 & 0xFFFFFFF))();
  }
}
