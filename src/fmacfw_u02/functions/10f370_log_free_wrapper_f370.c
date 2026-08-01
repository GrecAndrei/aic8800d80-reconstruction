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

// ipc_send_message @ 0x10f370, size 12 bytes
// Doc: ipc_send_message [util]: Releases a log buffer (size 0x50) and signals completion
// ipc_send_message [util]: Releases a log buffer (size 0x50) and signals completion
int  ipc_send_message(int a1, int a2)
{
  is_controller_mode(a2);
  return 1;
}

