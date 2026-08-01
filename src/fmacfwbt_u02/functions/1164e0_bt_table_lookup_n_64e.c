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

extern uint32_t dword_116504;

// set_callback_arg @ 0x1164e0, size 34 bytes
// Doc: set_callback_arg [bt]: Lookup entry in BT table by indexed offset
// set_callback_arg [bt]: Lookup entry in BT table by indexed offset
int  set_callback_arg(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  int v4; // r2

  v2 = dword_116504;
  result = a1 + 22;
  v4 = dword_116504 + 8 * result;
  if ( *(uint32_t *)(v4 + 4) )
    v4 = *(uint32_t *)(v4 + 8);
  *(uint32_t *)(v4 + 4) = a2;
  *(uint32_t *)(v2 + 8 * result + 8) = a2;
  *(uint32_t *)(a2 + 4) = 0;
  return result;
}

