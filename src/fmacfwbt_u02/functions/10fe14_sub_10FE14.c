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

extern uint32_t off_10FE54;
extern uint32_t dword_10FE58;
extern uint32_t dword_10FE5C;

// check_radio_state @ 0x10fe14, size 62 bytes
uint32_t * check_radio_state(char a1)
{
  uint32_t *v2; // r4

  if ( **(uint8_t **)off_10FE54 == 1 )
    v2 = (uint32_t *)critical_enter_6();
  else
    v2 = rx_process_item(dword_10FE58, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( is_address_in_heap((unsigned int)v2) )
  {
    *((uint8_t *)v2 - 1) = a1;
    return v2;
  }
  printf_wrapper(dword_10FE5C, v2);
  return v2;
}

