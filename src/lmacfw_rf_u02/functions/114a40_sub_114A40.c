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

extern uint32_t off_114A5C;
extern uint32_t dword_114A64;
extern uint32_t dword_114A60;

// assert_handler @ 0x114a40, size 28 bytes
// Doc: sub_1214A40 [util]: Reads and checks a half-word global (likely init/version check)
// sub_1214A40 [util]: Reads and checks a half-word global (likely init/version check)
void __noreturn assert_handler()
{
  if ( **(int16_t **)off_114A5C < 0 )
    flash_ctrl_init(dword_114A64, dword_114A60, 242);
  while ( 1 )
    ;
}

