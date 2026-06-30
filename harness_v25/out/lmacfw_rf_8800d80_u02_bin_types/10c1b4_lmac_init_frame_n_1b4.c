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

// lmac_init_frame_n_1b4 @ 0x10c1b4, size 56 bytes
// Doc: lmac_init_frame_n_1b4 [util]: Initialize local MAC frame descriptor and zero state
// lmac_init_frame_n_1b4 [util]: Initialize local MAC frame descriptor and zero state
void  __noreturn lmac_init_frame_n_1b4(int a1, int a2)
{
  sub_101E18(a1, a2, a2, 0);
}

