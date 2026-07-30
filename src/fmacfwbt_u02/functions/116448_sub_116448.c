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

extern uint32_t dword_116474;
extern uint32_t off_116478;
extern uint32_t dword_116480;
extern uint32_t dword_11647C;

// sub_116448 @ 0x116448, size 42 bytes
int sub_116448()
{
  int v0; // r0
  int v1; // r4

  v0 = sub_12D4F8(dword_116474);
  v1 = v0;
  if ( **(int16_t **)off_116478 < 0 && !v0 )
    sub_12F694(dword_116480, dword_11647C, 119);
  return v1;
}

