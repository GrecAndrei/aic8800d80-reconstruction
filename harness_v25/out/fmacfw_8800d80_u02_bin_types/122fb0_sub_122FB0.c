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

extern uint32_t dword_12306C;
extern uint32_t off_123070;
extern uint32_t dword_12307C;
extern uint32_t off_123074;
extern uint32_t dword_123078;

// sub_122FB0 @ 0x122fb0, size 186 bytes
int  sub_122FB0(int a1, uint8_t *a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r2
  uint8_t *v7; // r5
  int v8; // r2
  uint8_t *v9; // r6
  unsigned int v10; // r7
  int v11; // r1
  int v13; // r2
  uint8_t v14[5]; // [sp+7h] [bp-5h] BYREF

  v14[0] = 0;
  v7 = (uint8_t *)sub_12C92C(124, a4, a3, 2);
  if ( *a2 )
  {
    msg_parse(dword_12306C, v5, v6);
    **(uint8_t **)off_123070 = 0;
  }
  else
  {
    msg_parse(dword_12307C, v5, v6);
    **(uint8_t **)off_123070 = 3;
  }
  sub_114B44(v14);
  v8 = v14[0];
  v7[1] = v14[0];
  if ( a2[1] )
  {
    v9 = off_123074;
    *((uint8_t *)off_123074 + 188) = (v8 & 0x20) != 0;
    v10 = ((v8 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v13 = (uint8_t)a2[2];
    v9 = off_123074;
    v10 = ((v13 ^ 0x40u) >> 6) & 1;
    *((uint8_t *)off_123074 + 188) = (v13 & 0x20) != 0;
  }
  if ( patch_apply_n_313() )
  {
    v9[188] = 0;
    v11 = 0;
  }
  else
  {
    v11 = (uint8_t)v9[188];
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((uint16_t *)v9 + 89) |= 0x4000u;
    msg_parse(dword_123078, v11, v10);
    LOBYTE(v11) = v9[188];
  }
  *v7 = v11;
  sdio_buffer_prepare_n_4e8(v7);
  return 0;
}

