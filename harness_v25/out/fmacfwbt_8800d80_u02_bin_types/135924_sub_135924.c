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

extern uint32_t dword_135A60;
extern uint32_t dword_135A64;

// sub_135924 @ 0x135924, size 84 bytes
// Doc: sub_1235924 [unknown]: Unidentified helper routine in fmacfwbt image
// sub_1235924 [unknown]: Unidentified helper routine in fmacfwbt image
// positive sp value has been detected, the output may be wrong!
int  sub_135924(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  uint8_t *v11; // r4
  int v12; // r2
  int v13; // r3
  int v15; // r2
  int v16; // r6
  int v17; // r0
  int v18; // r7
  int16_t v19; // r3
  int v20; // r3
  int v22; // [sp-10h] [bp-24h] BYREF
  int v23; // [sp-Ch] [bp-20h]
  int16_t v24; // [sp-8h] [bp-1Ch]

  v11 = (uint8_t *)(dword_135A60 + 1320 * *(uint8_t *)(a1 + 8));
  v12 = (uint8_t)v11[108];
  v22 = 0;
  v23 = 0;
  v24 = 0;
  if ( !v12
    || v11[106]
    || (v13 = *(uint8_t *)(a1 + 7), v13 == 255)
    || (v15 = (uint8_t)v11[116], v15 != v13)
    || (v16 = dword_135A64 + 696 * v15, *(uint8_t *)(v16 + 52) != 2)
    || *(uint8_t *)(a1 + 13)
    || (v17 = sub_119084(*(uint8_t *)(a1 + 6) != 0, 512), (v18 = v17) == 0) )
  {
    
  }
  v19 = *(uint16_t *)(a1 + 4);
  LOBYTE(v22) = *(uint8_t *)(a1 + 6);
  LOWORD(v23) = v19;
  HIWORD(v22) = v19;
  ipc_msg_dispatch_454((int)v11, v17, (uint8_t *)&v22);
  v20 = *(uint32_t *)(v18 + 72);
  *(uint32_t *)(v20 + 112) = *(uint32_t *)(v16 + 38);
  *(uint8_t *)(v20 + 108) = -48;
  return sub_1359CC();
}

