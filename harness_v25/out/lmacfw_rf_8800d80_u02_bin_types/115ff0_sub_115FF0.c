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

extern uint32_t dword_116014;
extern uint32_t dword_116018;

// sub_115FF0 @ 0x115ff0, size 34 bytes
int  sub_115FF0(int a1, int a2, int a3)
{
  int v3; // r3

  v3 = dword_116014;
  **(uint32_t **)(a1 + 32) = a2;
  list_push_tail(v3 + 8 * a3);
  return irq_nesting_or(*(uint32_t *)(dword_116018 + 4 * a3));
}

