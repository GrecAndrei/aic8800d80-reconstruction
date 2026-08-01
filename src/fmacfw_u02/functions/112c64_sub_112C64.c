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

extern uint32_t off_112C8C;
extern uint32_t dword_112C90;

// get_state_byte @ 0x112c64, size 40 bytes
// Doc: rf_level_apply_2c86 [rf]: Apply RF TX power level adjustment
// rf_level_apply_2c86 [rf]: Apply RF TX power level adjustment
uint8_t * get_state_byte(int a1, int a2, int a3)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)off_112C8C + 89) & 0x4000) != 0 )
    result = read_memory_byte((uint8_t *)rf_cmd_send_378);
  else
    result = (uint8_t *)event_dispatch(dword_112C90, a2, a3);
  *(uint8_t *)rf_msg_handler_n_470_2c94 = 1;
  return result;
}

