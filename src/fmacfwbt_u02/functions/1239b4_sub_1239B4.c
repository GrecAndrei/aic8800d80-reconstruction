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

// output_byte_cr @ 0x1239b4, size 32 bytes
int  output_byte_cr(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r3

  phy_txpower_calc(*a2);
  hci_evt_alloc_send(13, a4, a3, v4);
  return 0;
}

