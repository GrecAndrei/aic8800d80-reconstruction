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

extern uint32_t off_10FEEC;
extern uint32_t dword_10FEF0;
extern uint32_t dword_10FEF4;

// sub_10FEAC @ 0x10feac, size 62 bytes
uint32_t * sub_10FEAC(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FEEC == 1 )
    v2 = (uint32_t *)sub_110370();
  else
    v2 = log_pool_alloc2_a18(dword_10FEF0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( log_ptr_in_range((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  sub_10DA6C(dword_10FEF4, v2);
  return v2;
}

