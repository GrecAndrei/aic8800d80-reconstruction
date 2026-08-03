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

extern uint32_t dword_11E7A8;
extern uint32_t dword_11E7A4;

// sub_11E76C @ 0x11e76c, size 52 bytes
// Doc: sdio_buffer_prepare_776 [mmio]: Prepare SDIO buffer for DMA transfer
// sdio_buffer_prepare_776 [mmio]: Prepare SDIO buffer for DMA transfer
int  sub_11E76C(int result, uint32_t *a2)
{
  uint32_t *v2; // r5

  v2 = (uint32_t *)result;
  if ( **(int16_t **)sdio_buffer_prepare_e7a0 < 0 && !a2 )
    result = rf_cmd_send_n264(dword_11E7A8, dword_11E7A4, 95);
  if ( *v2 )
  {
    *a2 = *v2;
  }
  else
  {
    v2[1] = a2;
    *a2 = 0;
  }
  *v2 = a2;
  return result;
}

