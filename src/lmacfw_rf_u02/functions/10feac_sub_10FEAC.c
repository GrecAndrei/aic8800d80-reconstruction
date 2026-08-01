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

// mem_alloc_checked @ 0x10feac, size 62 bytes
uint32_t * mem_alloc_checked(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FEEC == 1 )
    v2 = (uint32_t *)irq_disable_set_flag_2();
  else
    v2 = list_iterate(dword_10FEF0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( mem_is_in_heap((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  log_printf(dword_10FEF4, v2);
  return v2;
}

