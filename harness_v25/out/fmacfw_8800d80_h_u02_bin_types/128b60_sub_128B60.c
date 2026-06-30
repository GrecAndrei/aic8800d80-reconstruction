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

extern uint32_t dword_128BA4;
extern uint32_t dword_128BA8;
extern uint32_t off_128BAC;

// sub_128B60 @ 0x128b60, size 64 bytes
int  sub_128B60(int a1, int a2)
{
  int result; // r0
  uint16_t *v5; // r2
  char v6; // r3

  sub_12EB90(2, dword_128BA4);
  result = sub_1289EC(a1, a2, dword_128BA8);
  if ( result )
  {
    v5 = (uint16_t *)off_128BAC;
    if ( !*((uint8_t *)off_128BAC + 8) || (v6 = *((uint8_t *)off_128BAC + 8) - 1, (*((uint8_t *)off_128BAC + 8) = v6) == 0) )
    {
      *(uint8_t *)v5 = 1;
      return sub_12C8D0(50, v5[1], 0);
    }
  }
  return result;
}

