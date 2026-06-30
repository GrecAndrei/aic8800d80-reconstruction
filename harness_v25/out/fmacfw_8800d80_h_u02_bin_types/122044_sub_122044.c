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

extern uint32_t dword_1220BC;
extern uint32_t dword_1220C0;
extern uint32_t dword_1220C4;
extern uint32_t off_1220B8;
extern uint32_t off_1220C8;
extern uint32_t off_1220D0;
extern uint32_t off_1220D4;
extern uint32_t off_1220CC;
extern uint32_t dword_1220D8;

// sub_122044 @ 0x122044, size 116 bytes
int  sub_122044(int a1)
{
  int *v1; // r3
  int v2; // r6
  int v3; // r5
  int *v4; // r0
  int *v5; // r1
  int v6; // r2
  int v7; // t1
  int v8; // r4
  uint8_t *v9; // r4
  uint8_t *v10; // r1
  uint8_t *v11; // r2
  int v12; // r1
  int v13; // r2
  uint32_t v15[7]; // [sp+0h] [bp-1Ch] BYREF

  v1 = (int *)dword_1220BC;
  v2 = dword_1220C0;
  v3 = dword_1220C4;
  v4 = (int *)(a1 + 12);
  v5 = (int *)(*(uint32_t *)off_1220B8 + 4);
  do
  {
    v7 = *v5++;
    v6 = v7;
    v8 = v7 & 0xFFF;
    if ( v7 )
    {
      if ( !v8 )
      {
        *v1 = *v4 & 0xFFF | v6 & v2;
        goto LABEL_5;
      }
    }
    else
    {
      v6 = *v4;
    }
    *v1 = v6;
LABEL_5:
    ++v1;
    ++v4;
  }
  while ( v1 != (int *)v3 );
  v9 = off_1220C8;
  sub_102AD0(*((uint8_t *)off_1220C8 + 409));
  v10 = off_1220D0;
  v11 = off_1220D4;
  *((uint8_t *)off_1220CC + 7) = v9[409];
  memset(&v15[1], 0, 16);
  *v10 = 0;
  v15[0] = 0;
  *v11 = 0;
  v15[5] = 0;
  sub_117B84((int)v15);
  return sub_12E948(dword_1220D8, v12, v13);
}

