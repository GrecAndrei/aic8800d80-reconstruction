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

extern uint32_t off_12A4B8;
extern uint32_t off_12A4BC;
extern uint32_t dword_12A4C0;

// controller_status_byte @ 0x12a46c, size 74 bytes
int controller_status_byte()
{
  int result; // r0
  int *v1; // r3

  result = *(uint8_t *)off_12A4B8;
  if ( *(uint8_t *)off_12A4B8 )
  {
    result = *((uint8_t *)off_12A4BC + 17);
    if ( *((uint8_t *)off_12A4BC + 17) )
    {
      return 0;
    }
    else if ( *((uint8_t *)off_12A4BC + 18) <= 1u )
    {
      v1 = *((int **)off_12A4BC + 2);
      if ( v1 )
      {
        while ( *((uint8_t *)v1 + 106) != 2 || !*((uint8_t *)v1 + 1224) )
        {
          v1 = (int *)*v1;
          if ( !v1 )
            return result;
        }
        return *(uint8_t *)(dword_12A4C0 + 140 * *((uint8_t *)v1 + 1225) + 133) == 0;
      }
    }
  }
  return result;
}

