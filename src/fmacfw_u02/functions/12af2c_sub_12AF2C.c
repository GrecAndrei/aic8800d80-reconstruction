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

extern uint32_t dword_12AF60;
extern uint32_t off_12AF64;

// ke_msg_dequeue @ 0x12af2c, size 48 bytes
// Doc: sub_122AF2C [util]: Initialization helper calling sub_122CE88 with table pointers
// sub_122AF2C [util]: Initialization helper calling sub_122CE88 with table pointers
int  ke_msg_dequeue(int a1, int a2, int a3, int a4)
{
  int value; // r4

  value = rx_rate_field_parse(2);
  check_status_bits(4, dword_12AF60);
  if ( value )
    *((uint8_t *)off_12AF64 + 11) = 1;
  else
    reg_read_indirect(1, a4);
  return 0;
}

