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

extern uint32_t dword_12A564;

// bt_conn_flush @ 0x12a540, size 34 bytes
uint8_t * bt_conn_flush(int a1)
{
  uint8_t *v1; // r0

  v1 = (uint8_t *)(dword_12A564 + 140 * *(uint8_t *)(a1 + 1225));
  v1[134] = 0;
  return state_machine_step(v1);
}

