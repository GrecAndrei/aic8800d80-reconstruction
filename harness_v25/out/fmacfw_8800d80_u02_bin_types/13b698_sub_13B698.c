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

extern uint32_t dword_13B8F4;
extern uint32_t dword_13B8D8;
extern uint32_t off_13B8F8;
extern uint32_t dword_13B8E4;
extern uint32_t dword_13B8E0;
extern uint32_t off_13B8DC;
extern uint32_t dword_13B8E8;
extern uint32_t dword_13B8F0;
extern uint32_t dword_13B8EC;

// sub_13B698 @ 0x13b698, size 576 bytes
// Doc: sub_123B698 [unknown]: Complex handler with multiple parameters from stack
// sub_123B698 [unknown]: Complex handler with multiple parameters from stack
int  sub_13B698(int a1, int a2, int a3, char a4, int16_t a5, int16_t a6, int a7)
{
  int v7; // r9
  int v8; // r7
  int v9; // r8
  int16_t **v10; // r10
  int v13; // r0
  int v14; // r2
  int result; // r0
  int v16; // r4
  int v17; // r3
  int v18; // r2
  int v19; // r1
  int v20; // r5
  int v21; // r12
  int16_t v22; // r2
  int v23; // r5
  int v24; // r6
  uint32_t *v25; // r1
  int v26; // r5
  uint16_t *v28; // [sp+18h] [bp-14h]

  v7 = dword_13B8F4;
  v8 = dword_13B8D8;
  v9 = *(uint8_t *)(dword_13B8F4 + 696 * a1 + 34);
  v10 = (int16_t **)off_13B8F8;
  v13 = *(uint32_t *)(dword_13B8D8 + 1320 * v9 + 72);
  if ( !v13 )
  {
    if ( **(int16_t **)off_13B8F8 >= 0 )
    {
LABEL_19:
      result = sub_118C44(1, 512);
      v16 = result;
      if ( !result )
        return result;
      goto LABEL_4;
    }
LABEL_18:
    sub_12F46C(dword_13B8E4, dword_13B8E0, 520);
    goto LABEL_19;
  }
  v14 = *(uint8_t *)(v13 + 4);
  if ( **(int16_t **)off_13B8F8 < 0 && v14 == 2 )
    goto LABEL_18;
  result = sub_118C44((*(uint8_t *)(dword_13B8D8 + 1320 * v9 + 1224) | v14) != 0, 512);
  v16 = result;
  if ( !result )
    return result;
LABEL_4:
  sub_12C4E8(v8 + 1320 * v9, v16);
  v17 = *(uint32_t *)(v16 + 72);
  v18 = 696 * a1 + 38;
  *(uint8_t *)(v17 + 108) = -48;
  *(uint8_t *)(v17 + 109) = 0;
  *(uint8_t *)(v17 + 110) = 0;
  *(uint8_t *)(v17 + 111) = 0;
  *(uint16_t *)(v17 + 112) = *(uint16_t *)(v7 + v18);
  v19 = v7 + v18;
  v20 = 1320 * v9 + 100;
  *(uint16_t *)(v17 + 114) = *(uint16_t *)(v7 + v18 + 2);
  *(uint16_t *)(v17 + 116) = *(uint16_t *)(v7 + v18 + 4);
  *(uint16_t *)(v17 + 118) = *(uint16_t *)(v8 + v20);
  v21 = v8 + v20;
  *(uint16_t *)(v17 + 120) = *(uint16_t *)(v8 + v20 + 2);
  v28 = (uint16_t *)(v17 + 108);
  *(uint16_t *)(v17 + 122) = *(uint16_t *)(v8 + v20 + 4);
  if ( *(uint8_t *)(v8 + 1320 * v9 + 106) == 2 )
  {
    *(uint16_t *)(v17 + 124) = *(uint16_t *)(v8 + v20);
    *(uint16_t *)(v17 + 126) = *(uint16_t *)(v21 + 2);
    *(uint16_t *)(v17 + 128) = *(uint16_t *)(v21 + 4);
  }
  else
  {
    *(uint16_t *)(v17 + 124) = *(uint16_t *)(v7 + v18);
    *(uint16_t *)(v17 + 126) = *(uint16_t *)(v19 + 2);
    *(uint16_t *)(v17 + 128) = *(uint16_t *)(v19 + 4);
  }
  v22 = *((uint16_t *)off_13B8DC + 254) + 1;
  *((uint16_t *)off_13B8DC + 254) = v22;
  *(uint16_t *)(v17 + 130) = 16 * v22;
  *(uint8_t *)(v16 + 51) = 0;
  *(uint8_t *)(v16 + 53) = 0;
  *(uint8_t *)(v16 + 28) = v9;
  *(uint8_t *)(v16 + 29) = a1;
  if ( rf_msg_process_body_n37(v16, 208, 3) == 1 )
  {
    fmac_main_loop_0a0(v16, v28, 24);
    v23 = *(uint8_t *)(v16 + 51) + 24;
  }
  else
  {
    v23 = 24;
  }
  if ( a3 == 1 )
  {
    v24 = 3;
    v23 += sub_130D4C((int)v28 + v23, a2, a5, a4, a6);
  }
  else if ( a3 == 2 )
  {
    v24 = *(uint8_t *)(dword_13B8E8 + *(uint8_t *)(a2 + 22));
    v23 += sub_130D90((int)v28 + v23, a2, a6);
  }
  else if ( a3 )
  {
    if ( **v10 < 0 )
      sub_12F49C(dword_13B8F0, dword_13B8EC, 269);
    v24 = 3;
  }
  else
  {
    v24 = *(uint8_t *)(dword_13B8E8 + *(uint8_t *)(a2 + 22));
    v23 += sub_130D14((int)v28 + v23, a2);
  }
  v25 = *(uint32_t **)(v16 + 76);
  v26 = v23 + *(uint8_t *)(v16 + 53);
  v25[8] = v25[7] - 1 + v26;
  v25[9] = v26 + 4;
  if ( a7 )
  {
    *(uint32_t *)(v16 + 88) = a7;
    *(uint32_t *)(v16 + 92) = a2;
  }
  return rf_param_get_status(v16, v24);
}

