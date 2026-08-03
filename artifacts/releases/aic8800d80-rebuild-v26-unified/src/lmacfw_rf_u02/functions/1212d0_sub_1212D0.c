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

extern uint32_t off_121348;
extern uint32_t off_121354;
extern uint32_t off_121350;
extern uint32_t off_121358;
extern uint32_t dword_12134C;

// sub_1212D0 @ 0x1212d0, size 118 bytes
int  sub_1212D0(int a1, int a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int v6; // r1
  uint32_t *v7; // r4
  int v8; // r0
  uint32_t *v10; // r2
  uint8_t *v11; // r0
  uint32_t *v12; // r3
  uint32_t *v13; // r3

  v5 = rf_setup_dispatch(1040, a4, a3, 4u);
  v6 = *(uint16_t *)(a2 + 4);
  v7 = (uint32_t *)v5;
  if ( *((uint8_t *)off_121348 + 177) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v10 = off_121354;
    *(uint32_t *)off_121350 |= 0x2000000u;
    v11 = off_121358;
    v10[14] |= 0x10u;
    *v11 = 1;
  }
  if ( v6 == 1 )
  {
    v12 = off_121354;
    *((uint32_t *)off_121354 + 18) = *(uint32_t *)a2;
    v12[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v13 = off_121354;
    *((uint32_t *)off_121354 + 19) = *(uint32_t *)a2;
    v13[75] = 128;
  }
LABEL_5:
  v8 = dword_12134C;
  *v7 = 0;
  msg_parse(v8);
  sub_11DE50((int)v7);
  return 0;
}

