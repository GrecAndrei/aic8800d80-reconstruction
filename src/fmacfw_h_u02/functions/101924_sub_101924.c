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


extern uint32_t off_101938;

// check_clock_status @ 0x101924, size 18 bytes
int  check_clock_status(int a1, int a2, int a3)
{
  if ( *(uint32_t *)off_101938 << 28 )
    return alloc_tx_event("\x9B%s MAC state != IDLE\n", aPhyStop);
  return a1;
}
