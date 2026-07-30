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

extern uint32_t dword_10220C;
extern uint32_t dword_102208;
extern uint32_t off_102210;
extern uint32_t dword_102214;

// sub_101EC0 @ 0x101ec0, size 2412 bytes
void  __noreturn sub_101EC0(int a1, int a2, int a3, int a4)
{
  sub_12E948(dword_10220C, dword_102208, a1);
  if ( **(uint8_t **)off_102210 != 3 )
    sub_12EB90(4, dword_102214);
  sub_100670(a4);
  sub_100BE0();
}

