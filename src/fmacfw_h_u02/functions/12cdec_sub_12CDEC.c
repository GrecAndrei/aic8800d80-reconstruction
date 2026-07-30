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

extern uint32_t off_12CE94;
extern uint32_t dword_12CEA4;
extern uint32_t dword_12CE9C;
extern uint32_t dword_12CE98;
extern uint32_t dword_12CEAC;
extern uint32_t dword_12CEA8;
extern uint32_t dword_12CEB0;
extern uint32_t dword_12CEA0;

// sub_12CDEC @ 0x12cdec, size 168 bytes
int  sub_12CDEC(int a1, unsigned int a2)
{
  int16_t **v2; // r4
  int v4; // r7
  unsigned int v5; // r5
  int v6; // r4
  int v7; // r7
  int v8; // r1
  int v9; // r4
  int v10; // r1
  int result; // r0
  int v12; // r1
  int v13; // r3

  v2 = (int16_t **)off_12CE94;
  v4 = (uint8_t)a2;
  v5 = a2 >> 8;
  if ( **(int16_t **)off_12CE94 >= 0 )
    goto LABEL_2;
  if ( (uint8_t)a2 > 0xDu )
  {
    sub_12F32C(dword_12CEA4, dword_12CE9C, 267);
    if ( **v2 >= 0 )
    {
LABEL_2:
      v6 = dword_12CE98;
      v7 = 16 * v4;
      goto LABEL_3;
    }
    if ( v4 != 14 )
      sub_12F32C(dword_12CEAC, dword_12CEA8, 183);
  }
  else if ( (uint8_t)a2 != 13 )
  {
    goto LABEL_10;
  }
  sub_12F32C(dword_12CEB0, dword_12CE9C, 268);
  if ( **v2 >= 0 )
    goto LABEL_2;
LABEL_10:
  v6 = dword_12CE98;
  v13 = dword_12CE98 + 16 * v4;
  v7 = 16 * v4;
  if ( *(uint16_t *)(v13 + 14) <= v5 )
    sub_12F32C(dword_12CEA0, dword_12CE9C, 269);
LABEL_3:
  v8 = *(uint32_t *)(v6 + v7);
  v9 = v6 + v7;
  if ( !v8
    || (v10 = v8 + 8 * *(uint16_t *)(*(uint32_t *)(v9 + 8) + 2 * v5),
        (result = sub_12CB94(a1, (int *)v10, *(uint16_t *)(v10 + 4))) == 0) )
  {
    v12 = *(uint32_t *)(v9 + 4);
    if ( v12 )
      return sub_12CB94(a1, (int *)v12, *(uint16_t *)(v12 + 4));
    else
      return 0;
  }
  return result;
}

