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

extern uint32_t off_13596C;

// ke_msg_dispatch @ 0x135940, size 44 bytes
int  ke_msg_dispatch(int a1)
{
  uint32_t *v1; // r5

  v1 = off_13596C;
  invalid_handler_12c5fc(6154, 6);
  memcpy(a1, v1[4], 54);
  tx_process_jump(v1[4] - 12);
  v1[4] = a1;
  return mac_dma_setup();
}

