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

extern uint32_t dword_141E2C;
extern uint32_t off_141E30;
extern uint32_t dword_141E34;

// get_connection_env @ 0x141de8, size 66 bytes
int  get_connection_env(int a1, int a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r2

  v3 = *(uint32_t *)(a1 + 24)
     - 400
     - *(uint32_t *)(a1 + 48) * a2
     - *(uint32_t *)(dword_141E2C + 1320 * *(uint8_t *)(a1 + 47) + 40);
  v4 = ke_critical_enter();
  v5 = *((uint32_t *)off_141E30 + 4);
  *(uint32_t *)(a1 + 56) = dword_141E34;
  return ke_event_lock(a1 + 52, v5 + v3 - v4);
}

