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

extern uint32_t dword_11B07C;
extern uint32_t off_11B080;
extern uint32_t dword_11B084;

// sub_11B044 @ 0x11b044, size 56 bytes
int sub_11B044()
{
  int result; // r0
  uint32_t *v1; // r4
  char *v2; // r5
  char *v3; // r4

  result = sub_11E7AC(dword_11B07C);
  if ( result )
  {
    v1 = off_11B080;
    sub_11AC10(dword_11B084);
    v1[18] = 0;
    v2 = (char *)(v1 + 6);
    v3 = (char *)(v1 + 8);
    do
    {
      sub_11E724(v2);
      result = sub_11E7AC(v3);
    }
    while ( result );
  }
  return result;
}

