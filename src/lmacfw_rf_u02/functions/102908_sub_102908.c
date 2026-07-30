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

extern uint32_t dword_102940;
extern uint32_t dword_102944;

// sub_102908 @ 0x102908, size 52 bytes
int  sub_102908(uint8_t *a1, int a2)
{
  if ( !a2 )
    sub_101E18(*a1, *((uint16_t *)a1 + 1), *((uint16_t *)a1 + 2), a1[1]);
  return msg_parse(dword_102940, dword_102944);
}

