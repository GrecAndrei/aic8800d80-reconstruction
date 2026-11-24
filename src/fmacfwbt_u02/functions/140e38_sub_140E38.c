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


extern uint32_t dword_140E5C;

// dma_tx_reset_1 @ 0x140e38, size 36 bytes
int dma_tx_reset_1()
{
  int *v0; // r4
  int result; // r0

  v0 = (int *)dword_140E5C;
  hci_cmd_send(0xBu, 0);
  result = (int)memset_byte(v0, 0, 0x1960u);
  v0[1620] = -1;
  return result;
}
