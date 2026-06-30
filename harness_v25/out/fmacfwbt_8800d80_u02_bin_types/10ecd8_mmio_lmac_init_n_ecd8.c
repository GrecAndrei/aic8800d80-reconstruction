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

extern uint32_t dword_10ED1C;
extern uint32_t dword_10ED24;
extern uint32_t dword_10ED20;
extern uint32_t dword_10ED28;
extern uint32_t dword_10ED2C;

// mmio_lmac_init_n_ecd8 @ 0x10ecd8, size 66 bytes
// Doc: mmio_lmac_init_n_ecd8 [mmio]: Initialize LMAC MMIO control registers and doorbell
// mmio_lmac_init_n_ecd8 [mmio]: Initialize LMAC MMIO control registers and doorbell
int  mmio_lmac_init_n_ecd8(int a1, int a2, int a3)
{
  sub_12ECB0(dword_10ED1C, a1, a3);
  rf_reg_write_guard(dword_10ED24, 196608, dword_10ED20, 1);
  rf_reg_write_guard(1879048192, 1, 1, 1);
  sub_10EC30(dword_10ED28, a1, 1);
  return rf_reg_write_guard(dword_10ED2C, 2, 2, 1);
}

