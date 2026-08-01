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

extern uint32_t dword_112CDC;

// rf_isr_clear @ 0x112ca8, size 48 bytes
// Doc: rf_cmd_wait_n_2a6 [rf]: Wait for RF command completion by polling status register
// rf_cmd_wait_n_2a6 [rf]: Wait for RF command completion by polling status register
uint8_t * rf_isr_clear(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)rf_cmd_wait_cd8 + 89) & 0x4000) != 0 )
    result = read_memory_byte((uint8_t *)rf_bus_reset_n300);
  else
    result = (uint8_t *)event_dispatch(dword_112CDC, a2, a3);
  v4 = rf_bus_reset_n2fc;
  *(uint8_t *)rf_state_check_n2f2 = 0;
  v4[896] &= ~1u;
  return result;
}

