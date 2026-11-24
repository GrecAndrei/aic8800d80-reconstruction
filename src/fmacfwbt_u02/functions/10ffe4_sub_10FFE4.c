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


extern uint32_t dword_11002C;
extern uint32_t dword_110034;
extern uint32_t off_110030;
extern uint32_t off_110038;

// rx_irq_handler @ 0x10ffe4, size 72 bytes
uint32_t *rx_irq_handler()
{
  void *v0; // r8
  uint32_t *result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  uint32_t *v6; // r0
  unsigned int v7; // r1

  v0 = off_110038;
  result = zero_struct((uint32_t *)dword_11002C);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = off_110030;
    v3 = dword_110034;
    v4 = dword_11002C;
    v5 = 0;
    do
    {
      v6 = rx_process_item(v3, 0x63Cu);
      result = (uint32_t *)check_abort_flag(v4, v6);
      v7 = *(uint16_t *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v7 > (uint16_t)v5 );
  }
  return result;
}
