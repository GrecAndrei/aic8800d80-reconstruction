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

extern uint32_t off_101954;
extern uint32_t off_1019A8;
extern uint32_t dword_1019B0;
extern uint32_t dword_1019AC;

// tx_path_check @ 0x1017c0, size 404 bytes
// Doc: tx_path_check [util]: Checks firmware state flag (halfword) from global pointer
// tx_path_check [util]: Checks firmware state flag (halfword) from global pointer
void __noreturn tx_path_check()
{
  if ( **(int16_t **)off_101954 < 0
    && (uint8_t)BYTE2(*(uint32_t *)off_1019A8) + 10 * (HIBYTE(*(uint32_t *)off_1019A8) + 2) != 32 )
  {
    flash_ctrl_init(dword_1019B0, dword_1019AC, 6119);
  }
  periph_write_read();
}

