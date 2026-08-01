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

extern uint32_t off_12C750;
extern uint32_t off_12C754;
extern uint32_t dword_12C75C;
extern uint32_t dword_12C758;

// scan_done_check @ 0x12c710, size 64 bytes
int  scan_done_check(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((uint8_t *)off_12C750 + 197) )
  {
    v2 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v3 = llm_rx_pdu_handler(
           (*(uint32_t *)(v2 + 20) >> 11) & 7,
           *(uint32_t *)(v2 + 20) & 0x7F,
           (uint8_t *)(*(uint32_t *)(result + 72) + 4));
    result = v3 | (v3 << 8);
    *(uint32_t *)(v2 + 36) = result;
  }
  else if ( **(int16_t **)off_12C754 < 0 )
  {
    return mmio_irq_clear(dword_12C75C, dword_12C758, 92);
  }
  return result;
}

