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

extern uint32_t off_118EB0;
extern uint32_t dword_118EC4;
extern uint32_t dword_118EC0;
extern uint32_t off_118EB4;
extern uint32_t off_118EB8;
extern uint32_t off_118EBC;

// rf_packet_available @ 0x118e58, size 86 bytes
int rf_packet_available()
{
  if ( **(int16_t **)off_118EB0 < 0 && flash_write_byte(0) != 3 )
    flash_ctrl_init(dword_118EC4, dword_118EC0, 1785);
  if ( *((uint8_t *)off_118EB4 + 28) && *((uint8_t *)off_118EB8 + 18) + *((uint8_t *)off_118EB8 + 17) <= 1 )
    return flash_erase_sector(0);
  *(uint32_t *)off_118EBC = 48;
  return flash_erase_sector(0);
}

