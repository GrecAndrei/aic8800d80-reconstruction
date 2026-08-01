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

extern uint32_t off_1018DC;
extern uint32_t off_101928;
extern uint32_t dword_101930;
extern uint32_t dword_10192C;

// event_queue_check @ 0x101754, size 390 bytes
// Doc: sub_1201754 [util]: Check signed half-word from shared state and branch on result
// sub_1201754 [util]: Check signed half-word from shared state and branch on result
void __noreturn event_queue_check()
{
  if ( **(int16_t **)off_1018DC < 0
    && (uint8_t)BYTE2(*(uint32_t *)off_101928) + 10 * (HIBYTE(*(uint32_t *)off_101928) + 2) != 32 )
  {
    mmio_clear_register(dword_101930, dword_10192C, 6119);
  }
  send_command();
}

