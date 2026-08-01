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

extern uint32_t off_13F2DC;
extern uint32_t dword_13F2C8;
extern uint32_t dword_13F2D0;
extern uint32_t dword_13F2CC;
extern uint32_t dword_13F2D8;
extern uint32_t dword_13F2D4;

// get_connection_state @ 0x13f218, size 174 bytes
// Doc: get_connection_state [bt]: Look up BT channel entry by index in fmacfwbt table
// get_connection_state [bt]: Look up BT channel entry by index in fmacfwbt table
int  get_connection_state(int a1, unsigned int a2, unsigned int a3)
{
  int16_t **v3; // r8
  int v4; // r3
  int result; // r0
  uint8_t *v7; // r4
  int16_t *v10; // r3

  v3 = (int16_t **)off_13F2DC;
  v4 = dword_13F2C8 + 696 * a1;
  result = **(int16_t **)off_13F2DC;
  v7 = *(uint8_t **)(v4 + 340);
  if ( result < 0 && !v7 )
    result = mmio_irq_clear(dword_13F2D0, dword_13F2CC, 3326);
  if ( (uint8_t)v7[179] != a2 || (uint8_t)v7[180] != a3 )
  {
    v10 = *v3;
    v7[179] = a2;
    if ( *v10 < 0 && a2 > 3 )
    {
      result = mmio_irq_clear(dword_13F2D8, dword_13F2CC, 3332);
      v10 = *v3;
    }
    v7[180] = a3;
    if ( *v10 < 0 && a3 > 7 )
      result = mmio_irq_clear(dword_13F2D4, dword_13F2CC, 3334);
    if ( (v7[166] & 0x20) != 0 )
      v7[166] |= 0x80u;
    else
      return is_connection_active(a1);
  }
  return result;
}

