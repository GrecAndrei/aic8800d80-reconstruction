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

extern uint32_t dword_117E04;
extern uint32_t dword_117E08;

// register_handler @ 0x117dd8, size 44 bytes
int  register_handler(int a1, int a2, int a3)
{
  int v3; // r3
  int v5; // r0
  int result; // r0

  v3 = *(uint32_t *)(a1 + 76);
  v5 = dword_117E04;
  *(uint32_t *)(v3 + 4) = a2;
  result = wlan_ioctl_handler_1(v5 + 8 * a3);
  if ( (*(uint32_t *)(a1 + 36) & 0x200000) == 0 )
    return irq_disable_global_2(*(uint32_t *)(dword_117E08 + 4 * a3));
  return result;
}

