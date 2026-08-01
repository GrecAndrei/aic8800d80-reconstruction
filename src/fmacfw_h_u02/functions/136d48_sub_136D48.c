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

extern uint32_t dword_136D58;
extern uint32_t off_136D54;

// rf_rate_code_check_alt @ 0x136d48, size 12 bytes
int rf_rate_code_check_alt()
{
  int v0; // r0

  v0 = dword_136D58;
  *(uint8_t *)off_136D54 = 0;
  return alloc_tx_event(v0);
}

