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
extern uint32_t off_114620;
extern uint32_t off_114624;
extern uint32_t dword_114634;
extern uint32_t off_114628;
extern uint32_t off_11462C;
extern uint32_t off_114630;
extern uint32_t dword_114638;

// sub_1145AC @ 0x1145ac, size 110 bytes
int  sub_1145AC(int result)
{
  if ( !result )
  {
    if ( *(uint32_t *)off_11461C
      && (result = *((uint32_t *)off_114620 + 4),
          *(uint32_t *)(*(uint32_t *)off_11461C + 12) - result - *((uint16_t *)off_114624 + 92) - 2000 < 0) )
    {
      result = sub_12ECD0(2, dword_114634);
    }
    else
    {
      if ( !*(uint8_t *)off_114628
        || (result = *((uint32_t *)off_114620 + 4),
            *((uint32_t *)off_114628 + 1)
          + *((uint32_t *)off_114628 + 2)
          - result
          - *((uint16_t *)off_114624 + 92)
          - *(uint16_t *)(*(uint32_t *)off_11462C + 52) >= 0) )
      {
        *(uint32_t *)off_114630 = 0x40000000;
        return result;
      }
      result = sub_12ECD0(2, dword_114638);
    }
  }
  *(uint32_t *)off_114630 = 0x80000000;
  return result;
}

