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

extern uint32_t dword_102164;
extern uint32_t dword_102160;
extern uint32_t off_102168;
extern uint32_t dword_10216C;

// rf_calibrate @ 0x101e18, size 2476 bytes
void  __noreturn rf_calibrate(int a1, int a2, int a3, int a4)
{
  dispatch_event_handler(dword_102164, dword_102160);
  if ( **(uint8_t **)off_102168 != 3 )
    dispatch_event_handler(dword_10216C, a3);
  store_byte_value(a4);
  mac_send_frame();
}

