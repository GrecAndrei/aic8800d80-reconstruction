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

extern uint32_t off_12A6DC;
extern uint32_t off_12A6E0;
extern uint32_t dword_12A6E4;

// sub_12A690 @ 0x12a690, size 74 bytes
int sub_12A690()
{
  int result; // r0
  int *v1; // r3

  result = *(uint8_t *)off_12A6DC;
  if ( *(uint8_t *)off_12A6DC )
  {
    result = *((uint8_t *)off_12A6E0 + 17);
    if ( *((uint8_t *)off_12A6E0 + 17) )
    {
      return 0;
    }
    else if ( *((uint8_t *)off_12A6E0 + 18) <= 1u )
    {
      v1 = *((int **)off_12A6E0 + 2);
      if ( v1 )
      {
        while ( *((uint8_t *)v1 + 106) != 2 || !*((uint8_t *)v1 + 1224) )
        {
          v1 = (int *)*v1;
          if ( !v1 )
            return result;
        }
        return *(uint8_t *)(dword_12A6E4 + 140 * *((uint8_t *)v1 + 1225) + 133) == 0;
      }
    }
  }
  return result;
}

