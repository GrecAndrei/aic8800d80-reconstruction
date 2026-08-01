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

extern uint32_t off_141758;
extern uint32_t dword_141744;
extern uint32_t dword_141754;
extern uint32_t dword_141748;
extern uint32_t dword_141750;
extern uint32_t dword_14174C;

// check_tx_power_valid @ 0x141688, size 186 bytes
int check_tx_power_valid()
{
  int16_t **v0; // r8
  int v1; // r5
  int v2; // r4
  int v3; // r6
  int v4; // r7
  int result; // r0

  v0 = (int16_t **)off_141758;
  v1 = dword_141744;
  v2 = *(uint32_t *)(dword_141744 + 6480);
  if ( **(int16_t **)off_141758 >= 0 || v2 < 0 && (result = mmio_irq_clear(dword_141754, dword_141748, 1734), **v0 >= 0) )
  {
    v3 = 16 * v2;
    if ( *(uint8_t *)(v1 + 136 * v2 + 6339) > 1u )
      return result;
    return timer_start(v1 + 8 * (v2 + v3) + 6336, 0);
  }
  v4 = v1 + 136 * v2;
  v3 = 16 * v2;
  if ( *(uint8_t *)(v4 + 6338) == 5 )
  {
    if ( *(uint8_t *)(v4 + 6339) <= 1u )
      return timer_start(v1 + 8 * (v2 + v3) + 6336, 0);
    return mmio_irq_clear(dword_141750, dword_141748, 1744);
  }
  result = mmio_irq_clear(dword_14174C, dword_141748, 1735);
  if ( *(uint8_t *)(v4 + 6339) <= 1u )
    return timer_start(v1 + 8 * (v2 + v3) + 6336, 0);
  if ( **v0 < 0 )
    return mmio_irq_clear(dword_141750, dword_141748, 1744);
  return result;
}

