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

// ll_get_conn_interval @ 0x131100, size 72 bytes
// Doc: sub_1231100 [ipc]: Forward event/message to handler at 0x12dd08
// sub_1231100 [ipc]: Forward event/message to handler at 0x12dd08
int  ll_get_conn_interval(uint8_t *a1, int a2, int a3)
{
  int result; // r0
  int v5; // r3
  int16_t v6; // r3
  int16_t v7; // r2

  result = (int)check_one_12dd08(a1, a2);
  if ( result )
  {
    *(uint16_t *)a3 = *(uint8_t *)(result + 2) | (*(uint8_t *)(result + 3) << 8);
    *(uint8_t *)(a3 + 2) = *(uint8_t *)(result + 4);
    v5 = a3 + 2;
    do
    {
      *(uint8_t *)(v5 + 1) = *(uint8_t *)(result + v5 + 3 - a3);
      ++v5;
    }
    while ( v5 != a3 + 18 );
    v6 = *(uint8_t *)(result + 21);
    v7 = *(uint8_t *)(result + 22);
    *(uint32_t *)(a3 + 24) = *(uint16_t *)(result + 23);
    *(uint16_t *)(a3 + 20) = v6 | (v7 << 8);
    *(uint8_t *)(a3 + 28) = *(uint8_t *)(result + 27);
    return 1;
  }
  return result;
}

