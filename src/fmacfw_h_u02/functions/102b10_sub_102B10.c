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


extern uint32_t off_102B40;
extern uint32_t off_102B48;

// copy_cal_data @ 0x102b10, size 38 bytes
int copy_cal_data()
{
  int result; // r0

  result = alloc_tx_event("%s\r\n", aIntcSpurious);
  if ( **(uint16_t **)off_102B40 < 0 )
    return irq_disable_mmio_write(off_102B48, (int)aIntcSpurious_0, 61);
  return result;
}
