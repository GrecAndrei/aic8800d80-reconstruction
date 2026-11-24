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

// rf_enable_3 @ 0x136efc, size 32 bytes
int  rf_enable_3(int a1, int a2, int a3, int a4)
{
  int v4; // r0

  v4 = ke_msg_alloc(4107, a4, 4, 1);
  ke_msg_send_2(v4);
  check_status_bits(8, aScanuIdleCance);
  return 0;
}
