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


extern uint32_t off_114478;
extern uint32_t off_114480;
extern uint32_t off_114484;
extern uint32_t off_114488;
extern uint32_t off_11448C;

// check_radio_flag_1 @ 0x114408, size 110 bytes
unsigned int  check_radio_flag_1(unsigned int result)
{
  int v1; // r2

  if ( !result )
  {
    v1 = *(uint32_t *)off_114478;
    if ( *(uint32_t *)off_114478
      && (result = (*(volatile uint32_t *)0x40501010u), (int)(*(uint32_t *)(v1 + 12) - result - LOWORD(((uint32_t *)(uintptr_t)off_114480)[46]) - 2000) < 0) )
    {
      result = state_check_feature(2, "timer: not allow %x\r\n", *(uint32_t *)(v1 + 4));
    }
    else
    {
      if ( !*(uint8_t *)off_114484
        || (result = (*(volatile uint32_t *)0x40501010u),
            (int)(*((uint32_t *)off_114484 + 1)
                + *((uint32_t *)off_114484 + 2)
                - result
                - LOWORD(((uint32_t *)(uintptr_t)off_114480)[46])
                - *(uint16_t *)(*(uint32_t *)off_114488 + 52)) >= 0) )
      {
        *(uint32_t *)off_11448C = 0x40000000;
        return result;
      }
      result = state_check_feature(2, aOffsetNotAllow);
    }
  }
  *(uint32_t *)off_11448C = 0x80000000;
  return result;
}
