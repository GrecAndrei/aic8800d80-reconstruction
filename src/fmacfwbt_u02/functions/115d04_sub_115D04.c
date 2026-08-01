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

extern uint32_t off_115D24;

// shutdown_sequence @ 0x115d04, size 32 bytes
int shutdown_sequence()
{
  int v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((uint8_t *)off_115D24 + 1) = 0;
  v0 = timer_clear();
  v1 = llm_env_reset(v0);
  v2 = run_deferred_init(v1);
  v3 = state_init(v2);
  return reset_hci_scratch(v3);
}

