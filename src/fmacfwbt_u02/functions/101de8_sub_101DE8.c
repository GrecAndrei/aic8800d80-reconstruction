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

// sub_101DE8 @ 0x101de8, size 2412 bytes
void  __noreturn sub_101DE8(int a1, int a2, int a3, int a4)
{
  sub_12ECB0(dword_102134, dword_102130, a1);
  if ( **(uint8_t **)off_102138 != 3 )
    feature_guard_sdio(4, dword_10213C);
  variant_update_cache(a4);
  rf_calib_init_handler();
}

