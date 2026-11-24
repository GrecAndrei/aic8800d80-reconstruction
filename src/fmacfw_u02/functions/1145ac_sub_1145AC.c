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


extern uint32_t off_11461C;
extern uint32_t off_114624;
extern uint32_t off_114628;
extern uint32_t off_11462C;
extern uint32_t off_114630;

// sub_1145ac @ 0x1145ac, size 110 bytes
unsigned int  sub_1145ac(unsigned int result)
{
  int v1; // r2

  if ( !result )
  {
    v1 = *(uint32_t *)off_11461C;
    if ( *(uint32_t *)off_11461C
      && (result = (*(volatile uint32_t *)0x40501010u), (int)(*(uint32_t *)(v1 + 12) - result - LOWORD(((uint32_t *)(uintptr_t)off_114624)[46]) - 2000) < 0) )
    {
      result = check_status_bits(2, "timer: not allow %x\r\n", *(uint32_t *)(v1 + 4));
    }
    else
    {
      if ( !*(uint8_t *)off_114628
        || (result = (*(volatile uint32_t *)0x40501010u),
            (int)(*((uint32_t *)off_114628 + 1)
                + *((uint32_t *)off_114628 + 2)
                - result
                - LOWORD(((uint32_t *)(uintptr_t)off_114624)[46])
                - *(uint16_t *)(*(uint32_t *)off_11462C + 52)) >= 0) )
      {
        *(uint32_t *)off_114630 = 0x40000000;
        return result;
      }
      result = check_status_bits(2, aOffsetNotAllow);
    }
  }
  *(uint32_t *)off_114630 = 0x80000000;
  return result;
}
