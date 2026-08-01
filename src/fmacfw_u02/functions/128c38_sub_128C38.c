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

extern uint32_t dword_128C84;
extern uint32_t off_128C8C;
extern uint32_t off_128C88;
extern uint32_t off_128C90;
extern uint32_t off_128C98;
extern uint32_t off_128C94;
extern uint32_t dword_128C9C;

// wlc_print_msg @ 0x128c38, size 76 bytes
int  wlc_print_msg(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = wlc_check_rate_flag(a1, a2, dword_128C84);
  if ( result )
  {
    v4 = off_128C8C;
    v5 = *((uint8_t *)off_128C88 + 2);
    *((uint8_t *)off_128C8C + 28) = 1;
    if ( v5 )
      *(uint32_t *)off_128C90 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((uint32_t *)off_128C98 + 4);
    v7 = *(uint16_t *)(*(uint32_t *)off_128C94 + 54);
    v8 = dword_128C9C;
    *((uint32_t *)v4 + 5) = a1;
    v4[29] = 4;
    result = unknown_worker(v8, v7 + v6);
    *(uint32_t *)(a1 + 4) |= 0x200u;
  }
  return result;
}

