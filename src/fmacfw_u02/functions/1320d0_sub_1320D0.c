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

extern uint32_t off_132130;

// sub_1320D0 @ 0x1320d0, size 96 bytes
int  sub_1320D0(int a1, char *a2, int16_t a3, int16_t a4)
{
  uint16_t *v7; // r4
  char v8; // r3
  int v9; // r1
  uint8_t *v10; // r0
  int v11; // r3

  if ( msg_get_value(5u) == 1 )
    return 2;
  v7 = off_132130;
  v8 = *a2;
  v9 = *((uint32_t *)off_132130 + 1);
  if ( *a2 )
    v8 = 1;
  *((uint8_t *)off_132130 + 375) = v8;
  if ( !v9 )
  {
    v10 = (uint8_t *)sub_12C92C(49, 0, 5, 1u);
    v11 = *((uint8_t *)v7 + 375);
    v7[4] = 255;
    if ( v11 )
      LOBYTE(v11) = *((uint8_t *)v7 + 376);
    *v10 = v11;
    sdio_buffer_prepare_n_4e8((int)v10);
    sub_12CD34(5u, 1);
  }
  sub_12CA10(5140, a4, a3);
  return 0;
}

