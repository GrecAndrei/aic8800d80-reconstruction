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

extern uint32_t off_125950;
extern uint32_t dword_125954;
extern uint32_t dword_125948;
extern uint32_t dword_12594C;

// bt_task_init @ 0x125904, size 66 bytes
int  bt_task_init(int a1)
{
  int v2; // r0
  uint8_t *v3; // r2
  int v4; // r1
  int v5; // r4
  int v6; // r0
  int v7; // r6

  v2 = *(uint8_t *)(a1 + 9);
  v3 = off_125950;
  v4 = dword_125954;
  v5 = dword_125948 + 1320 * v2;
  v6 = dword_12594C + 620 * v2;
  v7 = *(uint8_t *)(v5 + 107);
  *((uint8_t *)off_125950 + 9) = 1;
  v3[10] = 0;
  memcpy(v6 + 108, v4 + (v7 << 9), *(uint16_t *)(a1 + 4));
  return ipc_trace_send(v5);
}

