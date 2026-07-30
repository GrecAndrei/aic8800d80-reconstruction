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

extern uint32_t off_125FE8;

// phy_init_or_register_n_e @ 0x125fbc, size 42 bytes
// Doc: phy_init_or_register_n_e [rf]: PHY init/register write with val 0x48
// phy_init_or_register_n_e [rf]: PHY init/register write with val 0x48
int  phy_init_or_register_n_e(int a1)
{
  uint8_t *v2; // r0
  uint32_t *v3; // r2

  v2 = (uint8_t *)rf_bus_setup_n3a8(72, *(uint16_t *)(a1 + 14), 0, 2);
  v2[1] = *(uint8_t *)(a1 + 24);
  v3 = off_125FE8;
  *v2 = *(uint8_t *)(a1 + 26);
  *v3 &= ~4u;
  return sub_12CBB4(v2);
}

