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

extern uint32_t off_13A360;
extern uint32_t dword_13A36C;
extern uint32_t dword_13A368;
extern uint32_t dword_13A364;

// dma_rx_ring @ 0x13a320, size 64 bytes
int  dma_rx_ring(int a1, int a2)
{
  int v2; // r4
  uint32_t *v3; // r5
  int result; // r0

  v2 = a1 + 4 * a2;
  v3 = *(uint32_t **)(v2 + 408);
  if ( **(int16_t **)off_13A360 < 0 && !v3 )
    irq_disable_mmio_write(dword_13A36C, dword_13A368, 3320);
  mem_set_util((int)(v3 + 68));
  result = wlan_ioctl_handler_1(dword_13A364, v3);
  *(uint32_t *)(v2 + 408) = 0;
  return result;
}

