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

// sub_101F70 @ 0x101f70, size 2412 bytes
void  __noreturn sub_101F70(int a1, int a2, int a3, int a4)
{
  msg_parse(dword_1022BC, dword_1022B8, a1);
  if ( **(uint8_t **)off_1022C0 != 3 )
    feature_guard_check(4, dword_1022C4);
  variant_update_cache(a4);
  rf_cmd_queue_next_n_d4();
}

