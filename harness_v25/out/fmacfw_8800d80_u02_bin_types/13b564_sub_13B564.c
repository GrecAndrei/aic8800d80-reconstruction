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

extern uint32_t dword_13B5F4;
extern uint32_t dword_13B5F8;
extern uint32_t off_13B5FC;

// sub_13B564 @ 0x13b564, size 142 bytes
int  sub_13B564(int a1, char *a2, unsigned int a3)
{
  unsigned int v5; // r5
  int v6; // r6
  char v7; // r0
  char v8; // r8
  uint8_t v9; // r7
  char v10; // r6
  uint8_t *v11; // r0

  if ( a2[2] != 2 )
    return 0;
  v5 = a3 >> 8;
  if ( msg_get_value(a3 & 0xFF00 | 8) == 4 )
  {
    v6 = dword_13B5F4 + 32 * v5;
    if ( *(uint8_t *)(v6 + 17) == 1 )
    {
      v7 = sub_13C400(*(uint32_t *)(v6 + 28));
      v8 = *a2;
      v9 = a2[1];
      v10 = 4 - *(uint8_t *)(v6 + 20) + v7;
      v11 = (uint8_t *)sub_12C92C(5131, 13, 5, 3u);
      v11[2] = v10;
      *v11 = v8;
      v11[1] = v9;
      sdio_buffer_prepare_n_4e8((int)v11);
    }
    *(uint32_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B5F8 + 448) = *((uint32_t *)off_13B5FC
                                                                                                 + 4);
    tx_msg_submit_n_bc28(v5);
  }
  return 0;
}

