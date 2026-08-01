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

extern uint32_t off_103460;
extern uint32_t off_103464;

// enable_radio_controller @ 0x1032fc, size 356 bytes
// Doc: sub_12032FC [mmio]: Initialize SoC MMIO register block (set bits, configure peripheral)
// sub_12032FC [mmio]: Initialize SoC MMIO register block (set bits, configure peripheral)
void __noreturn enable_radio_controller()
{
  unsigned int *v0; // r6
  unsigned int *v1; // r5

  v0 = (unsigned int *)off_103460;
  v1 = (unsigned int *)off_103464;
  *(uint32_t *)off_103460 |= 0x10u;
  *v1 = *v1 & 0xFFFFC0FF | 0x300;
  *v0 &= ~0x200u;
  *v0 = *v0 & 0xFFFE03FF | 0x10000;
  *v1 |= 0x4000u;
  while ( 1 )
    ;
}

