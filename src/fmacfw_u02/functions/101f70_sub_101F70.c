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

extern uint32_t dword_1022BC;
extern uint32_t dword_1022B8;
extern uint32_t off_1022C0;
extern uint32_t dword_1022C4;

// tx_packet_handler @ 0x101f70, size 2412 bytes
void  __noreturn tx_packet_handler(int a1, int a2, int a3, int a4)
{
  event_dispatch(dword_1022BC, dword_1022B8, a1);
  if ( **(uint8_t **)off_1022C0 != 3 )
    check_status_bits(4, dword_1022C4);
  update_status_byte(a4);
  variadic_call_1006d8();
}

