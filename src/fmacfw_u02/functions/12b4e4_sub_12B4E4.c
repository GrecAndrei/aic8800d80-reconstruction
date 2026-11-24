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

// reg_read_indirect @ 0x12b4e4, size 40 bytes
uint32_t * reg_read_indirect(char a1, uint16_t a2)
{
  char *v3; // r4

  v3 = (char *)ke_msg_alloc(2052, a2, 2, 1);
  check_status_bits(4, "%s\r\n", aScanSendCancel);
  *v3 = a1;
  return ke_msg_send_2((int)v3);
}
