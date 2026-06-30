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

extern uint32_t off_12BB40;
extern uint32_t off_12BB44;
extern uint32_t off_12BB48;

// sub_12BB20 @ 0x12bb20, size 32 bytes
// Doc: sub_122BB20 [mmio]: MMIO clear of MSB bit on 0x40328074/0x40328080/0x40328068 register banks
// sub_122BB20 [mmio]: MMIO clear of MSB bit on 0x40328074/0x40328080/0x40328068 register banks
void *sub_12BB20()
{
  void *result; // r0
  uint32_t *v1; // r1
  uint32_t *v2; // r2

  result = off_12BB40;
  v1 = off_12BB44;
  v2 = off_12BB48;
  *(uint32_t *)off_12BB40 &= ~0x80000000;
  *v1 &= ~0x80000000;
  *v2 &= ~0x80000000;
  return result;
}

