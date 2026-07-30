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

extern uint32_t off_1017F8;
extern uint32_t off_1017FC;

// sub_1017E0 @ 0x1017e0, size 24 bytes
int  sub_1017E0(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_1017F8 & 8) != 0 )
  {
    result = mmio_reg_read_pair(result, a2, a3, *(uint32_t *)off_1017F8 << 28);
    *(uint32_t *)off_1017FC = 8;
  }
  return result;
}

