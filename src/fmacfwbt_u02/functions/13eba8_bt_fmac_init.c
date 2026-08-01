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

// send_acl_data @ 0x13eba8, size 20 bytes
// Doc: send_acl_data [bt]: Bluetooth front-MAC init routine
// send_acl_data [bt]: Bluetooth front-MAC init routine
unsigned int  send_acl_data(int a1, unsigned int a2, int a3, int a4)
{
  return alloc_send_packet(a1, a2, a2 - a3, 1, a4);
}

