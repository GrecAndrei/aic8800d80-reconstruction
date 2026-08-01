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

extern uint32_t off_13F100;
extern uint32_t dword_13F0EC;
extern uint32_t dword_13F0F4;
extern uint32_t dword_13F0F0;
extern uint32_t dword_13F0FC;
extern uint32_t dword_13F0F8;

// phy_get_channel_data @ 0x13f03c, size 174 bytes
int  phy_get_channel_data(int a1, unsigned int a2, unsigned int a3)
{
  int16_t **v3; // r8
  int v4; // r3
  int result; // r0
  uint8_t *v7; // r4
  int16_t *v10; // r3

  v3 = (int16_t **)off_13F100;
  v4 = dword_13F0EC + 696 * a1;
  result = **(int16_t **)off_13F100;
  v7 = *(uint8_t **)(v4 + 340);
  if ( result < 0 && !v7 )
    result = irq_disable_mmio_write(dword_13F0F4, dword_13F0F0, 3326);
  if ( (uint8_t)v7[179] != a2 || (uint8_t)v7[180] != a3 )
  {
    v10 = *v3;
    v7[179] = a2;
    if ( *v10 < 0 && a2 > 3 )
    {
      result = irq_disable_mmio_write(dword_13F0FC, dword_13F0F0, 3332);
      v10 = *v3;
    }
    v7[180] = a3;
    if ( *v10 < 0 && a3 > 7 )
      result = irq_disable_mmio_write(dword_13F0F8, dword_13F0F0, 3334);
    if ( (v7[166] & 0x20) != 0 )
      v7[166] |= 0x80u;
    else
      return phy_get_channel_config(a1);
  }
  return result;
}

