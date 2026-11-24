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


extern uint32_t off_102A4C;
extern uint32_t off_102A54;

// check_button @ 0x102a1c, size 38 bytes
int check_button()
{
  int result; // r0

  result = dispatch_event_handler_1("%s\r\n", aIntcSpurious);
  if ( **(uint16_t **)off_102A4C < 0 )
    return flash_ctrl_init(off_102A54, (int)aIntcSpurious_0, 61);
  return result;
}
