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

extern uint32_t dword_12C534;

// rf_check_temperature @ 0x12c4e8, size 64 bytes
// Doc: message_dispatch_n_482 [ipc]: Dispatch incoming IPC/host message (variant n_482)
// message_dispatch_n_482 [ipc]: Dispatch incoming IPC/host message (variant n_482)
int  rf_check_temperature(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((uint8_t *)message_dispatch_n_464 + 197) )
  {
    v2 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v3 = rx_packet_handler(
           (*(uint32_t *)(v2 + 20) >> 11) & 7,
           *(uint32_t *)(v2 + 20) & 0x7F,
           (uint8_t *)(*(uint32_t *)(result + 72) + 4));
    result = v3 | (v3 << 8);
    *(uint32_t *)(v2 + 36) = result;
  }
  else if ( **(int16_t **)msg_dispatch_handler < 0 )
  {
    return mmio_clear_register(dword_12C534, message_dispatch_n_45c, 92);
  }
  return result;
}

