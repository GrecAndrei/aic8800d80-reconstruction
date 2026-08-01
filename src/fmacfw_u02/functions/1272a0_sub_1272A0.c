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

extern uint32_t off_127328;
extern uint32_t off_12732C;
extern uint32_t dword_12733C;
extern uint32_t dword_127338;
extern uint32_t dword_127330;
extern uint32_t dword_127340;
extern uint32_t dword_127334;

// rf_read_calibration @ 0x1272a0, size 134 bytes
int rf_read_calibration()
{
  uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_127328;
  v1 = *((uint8_t *)off_127328 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(int16_t **)off_12732C < 0 && (v1 & 4) != 0 )
    {
      mmio_clear_register(dword_12733C, dword_127338, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return dma_setup_transfer(dword_127330);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(int16_t **)off_12732C < 0 && (v1 & 8) != 0 )
    {
      mmio_clear_register(dword_127340, dword_127338, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return dma_setup_transfer(dword_127334);
  }
  return result;
}

