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

// ke_msg_send_no_param @ 0x12ca10, size 16 bytes
// Doc: message_dispatch_n86 [ipc]: Dispatch message with two short fields stored to message header
// message_dispatch_n86 [ipc]: Dispatch message with two short fields stored to message header
int  ke_msg_send_no_param(int16_t a1, int16_t a2, int16_t a3)
{
  int v3; // r0

  v3 = ke_msg_alloc(a1, a2, a3, 0);
  return ke_msg_send(v3);
}

