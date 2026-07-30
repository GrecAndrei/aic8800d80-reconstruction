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

extern uint32_t off_138D10;
extern uint32_t off_138D14;

// sub_138CB4 @ 0x138cb4, size 92 bytes
// Doc: sub_1238CB4 [unknown]: Unknown internal function (fmacfw)
// sub_1238CB4 [unknown]: Unknown internal function (fmacfw)
uint32_t * sub_138CB4(int a1, int16_t a2)
{
  uint32_t *v2; // r6
  int16_t v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r3

  v2 = off_138D10;
  v4 = a2;
  if ( *((uint8_t *)off_138D14 + 16) != 255 )
  {
    v4 = a2 | 0x80;
LABEL_3:
    v5 = (*((uint8_t *)off_138D10 + 10) << 8)
       | (*((uint8_t *)off_138D10 + 9) << 16)
       | (*((uint8_t *)off_138D10 + 11) << 24)
       | *(uint32_t *)(a1 + 96)
       | 0x80;
    goto LABEL_4;
  }
  if ( (a2 & 0x80) != 0 )
    goto LABEL_3;
  v5 = (*((uint8_t *)off_138D10 + 10) << 8)
     | (*((uint8_t *)off_138D10 + 9) << 16)
     | (*((uint8_t *)off_138D10 + 11) << 24)
     | *(uint32_t *)(a1 + 96) & 0xFFFFFF7F;
LABEL_4:
  if ( (v4 & 1) != 0 )
    v6 = v5 | 0x40;
  else
    v6 = v5 & 0xFFFFFFBF;
  *(uint32_t *)(a1 + 96) = v6;
  message_dispatch_n_16e(a1);
  return sub_1389D0(a1, v4, v2[16]);
}

