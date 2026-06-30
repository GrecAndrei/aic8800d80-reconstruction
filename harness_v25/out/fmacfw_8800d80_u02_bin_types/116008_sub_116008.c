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

extern uint32_t dword_116034;
extern uint32_t off_116038;
extern uint32_t dword_116040;
extern uint32_t dword_11603C;

// sub_116008 @ 0x116008, size 42 bytes
int sub_116008()
{
  int v0; // r0
  int v1; // r4

  v0 = rf_bus_mark_n100_d2d0(dword_116034);
  v1 = v0;
  if ( **(int16_t **)off_116038 < 0 && !v0 )
    sub_12F46C(dword_116040, dword_11603C, 119);
  return v1;
}

