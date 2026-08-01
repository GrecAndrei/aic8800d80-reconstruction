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

extern uint32_t dword_1160C4;

// set_table_callback_data @ 0x1160a0, size 34 bytes
// Doc: sub_12160A0 [unknown]: Lookup 3*index entry in table at 0x187f98 and load field
// sub_12160A0 [unknown]: Lookup 3*index entry in table at 0x187f98 and load field
int  set_table_callback_data(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  int v4; // r2

  v2 = dword_1160C4;
  result = a1 + 22;
  v4 = dword_1160C4 + 8 * result;
  if ( *(uint32_t *)(v4 + 4) )
    v4 = *(uint32_t *)(v4 + 8);
  *(uint32_t *)(v4 + 4) = a2;
  *(uint32_t *)(v2 + 8 * result + 8) = a2;
  *(uint32_t *)(a2 + 4) = 0;
  return result;
}

