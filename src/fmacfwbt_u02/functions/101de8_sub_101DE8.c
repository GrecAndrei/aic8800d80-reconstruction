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

extern uint32_t dword_102134;
extern uint32_t dword_102130;
extern uint32_t off_102138;
extern uint32_t dword_10213C;

// format_log_message @ 0x101de8, size 2412 bytes
void  __noreturn format_log_message(int a1, int a2, int a3, int a4)
{
  ke_event_schedule(dword_102134, dword_102130, a1);
  if ( **(uint8_t **)off_102138 != 3 )
    state_check_feature(4, dword_10213C);
  timer_poll(a4);
  call_1006d8_with_args();
}

