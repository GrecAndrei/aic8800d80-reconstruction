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

// rf_reg_write_setup_n4820 @ 0x114820, size 10 bytes
// Doc: rf_reg_write_setup_n4820 [rf]: Set up register write call (id=6, op=2)
// rf_reg_write_setup_n4820 [rf]: Set up register write call (id=6, op=2)
int  rf_reg_write_setup_n4820(int a1)
{
  return rf_msg_handler_main_45f4(2, a1, 6u);
}

