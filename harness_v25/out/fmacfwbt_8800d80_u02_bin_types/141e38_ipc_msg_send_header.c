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

// ipc_msg_send_header @ 0x141e38, size 50 bytes
// Doc: ipc_msg_send_header [ipc]: Builds and sends IPC message header (id=0x3002, len=0xc) to target
// ipc_msg_send_header [ipc]: Builds and sends IPC message header (id=0x3002, len=0xc) to target
int  ipc_msg_send_header(char a1, int a2)
{
  int v4; // r0
  int16_t v5; // r2

  v4 = rf_bus_setup_n3a8(12290, 13, 12, 8u);
  v5 = *(uint16_t *)(a2 + 8);
  *(uint32_t *)(v4 + 2) = *(uint32_t *)(a2 + 4);
  *(uint16_t *)(v4 + 6) = v5;
  *(uint8_t *)(v4 + 1) = *(uint8_t *)(a2 + 46);
  *(uint8_t *)v4 = a1;
  return sub_12CBB4(v4);
}

