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


extern uint32_t dword_138AA4;

// tx_power_set @ 0x138a74, size 46 bytes
int  tx_power_set(int a1)
{
  int v1; // r5
  int v3; // r1

  v1 = dword_138AA4;
  tx_power_lookup(0, 4, *(uint32_t *)(a1 + 20));
  cmd_handler_c(v1, (uint32_t *)a1);
  cmd_handler_a(v1 - 8, (uint32_t *)a1);
  return (int)load_and_process_r0((int *)(v1 - 32), v3);
}
