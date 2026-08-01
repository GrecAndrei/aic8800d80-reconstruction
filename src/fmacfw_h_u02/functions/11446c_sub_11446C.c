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

extern uint32_t off_1144DC;
extern uint32_t off_1144E0;
extern uint32_t off_1144E4;
extern uint32_t dword_1144F4;
extern uint32_t off_1144E8;
extern uint32_t off_1144EC;
extern uint32_t off_1144F0;
extern uint32_t dword_1144F8;

// default_handler @ 0x11446c, size 110 bytes
int  default_handler(int result)
{
  if ( !result )
  {
    if ( *(uint32_t *)off_1144DC
      && (result = *((uint32_t *)off_1144E0 + 4),
          *(uint32_t *)(*(uint32_t *)off_1144DC + 12) - result - *((uint16_t *)off_1144E4 + 92) - 2000 < 0) )
    {
      result = check_feature_flag(2, dword_1144F4);
    }
    else
    {
      if ( !*(uint8_t *)off_1144E8
        || (result = *((uint32_t *)off_1144E0 + 4),
            *((uint32_t *)off_1144E8 + 1)
          + *((uint32_t *)off_1144E8 + 2)
          - result
          - *((uint16_t *)off_1144E4 + 92)
          - *(uint16_t *)(*(uint32_t *)off_1144EC + 52) >= 0) )
      {
        *(uint32_t *)off_1144F0 = 0x40000000;
        return result;
      }
      result = check_feature_flag(2, dword_1144F8);
    }
  }
  *(uint32_t *)off_1144F0 = 0x80000000;
  return result;
}

