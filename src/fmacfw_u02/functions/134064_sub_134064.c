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

extern uint32_t off_134108;
extern uint32_t dword_13410C;
extern uint32_t dword_134110;

// sub_134064 @ 0x134064, size 162 bytes
// Doc: sub_1234064 [unknown]: Calls helper and branches on result code 9
// sub_1234064 [unknown]: Calls helper and branches on result code 9
int sub_134064()
{
  int v1; // r4
  int v2; // r6
  int v3; // r5
  int v4; // r0
  int v5; // r2
  int v6; // r3
  int16_t v7; // r1
  uint8_t *v8; // r0

  if ( msg_get_value(6u) == 9 )
  {
    v1 = *((uint32_t *)off_134108 + 4);
    v2 = dword_13410C + 1320 * *(uint8_t *)(v1 + 61);
    v3 = *(uint8_t *)(v2 + 116);
    v4 = sub_12C92C(75, 0, 6, 6u);
    *(uint8_t *)(v4 + 4) = *(uint8_t *)(v1 + 58);
    *(uint16_t *)(v4 + 2) = *(uint16_t *)(v1 + 56);
    *(uint8_t *)v4 = *(uint8_t *)(v1 + 61);
    sdio_buffer_prepare_n_4e8(v4);
    v5 = dword_134110 + 696 * v3;
    v6 = 2 - (*(uint32_t *)(v2 + 1208) & 1);
    v7 = __rev16(*(uint16_t *)(v1 + 52));
    *(uint8_t *)(v5 + 52) = v6;
    *(uint16_t *)(v5 + 56) = v7;
    if ( v6 == 2 )
    {
      v8 = (uint8_t *)sub_12C92C(5145, 5, 6, 2u);
      *v8 = 0;
      v8[1] = *(uint8_t *)(v1 + 61);
      sdio_buffer_prepare_n_4e8((int)v8);
    }
    sub_134E04(0);
    return 0;
  }
  else
  {
    if ( msg_get_value(6u) == 10 )
      sub_1347BC(10);
    return 0;
  }
}

