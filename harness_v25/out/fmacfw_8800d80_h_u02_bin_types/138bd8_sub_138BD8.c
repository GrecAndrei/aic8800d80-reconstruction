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

extern uint32_t off_138C60;
extern uint32_t off_138C5C;

// sub_138BD8 @ 0x138bd8, size 132 bytes
uint32_t * sub_138BD8(int a1, int16_t a2)
{
  void *v2; // r6
  int16_t v4; // r5
  int v5; // r2
  int v6; // r1
  int v7; // r3
  unsigned int v8; // r3
  unsigned int v9; // r3

  v2 = off_138C60;
  v4 = a2;
  if ( *((uint8_t *)off_138C5C + 16) == 255 )
  {
    v7 = (*((uint8_t *)off_138C60 + 10) << 8)
       | (*((uint8_t *)off_138C60 + 9) << 16)
       | *(uint32_t *)(a1 + 96);
    if ( (a2 & 0x80) == 0 )
    {
      v8 = (*((uint8_t *)off_138C60 + 10) << 8)
         | (*((uint8_t *)off_138C60 + 9) << 16)
         | *(uint32_t *)(a1 + 96) & 0xFFFFFF7D
         | 2;
      if ( (a2 & 1) != 0 )
        goto LABEL_6;
LABEL_10:
      v9 = v8 & 0xFFFFFFBF;
      goto LABEL_7;
    }
    v6 = a2 & 1;
  }
  else
  {
    v5 = *((uint8_t *)off_138C60 + 10);
    if ( v5 == 255 )
    {
      v6 = 0;
      v4 = 128;
    }
    else
    {
      v6 = a2 & 1;
      v4 |= 0x80u;
    }
    v7 = (v5 << 8) | (*((uint8_t *)off_138C60 + 9) << 16) | *(uint32_t *)(a1 + 96);
  }
  v8 = v7 | 0x82;
  if ( !v6 )
    goto LABEL_10;
LABEL_6:
  v9 = v8 | 0x40;
LABEL_7:
  *(uint32_t *)(a1 + 96) = v9;
  *((uint8_t *)v2 + 50) = 0;
  sub_11E4C4(a1);
  return sub_138890(a1, v4, *((uint32_t *)v2 + 16));
}

