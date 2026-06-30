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

extern uint32_t off_13AF50;
extern uint32_t dword_13AF5C;
extern uint32_t dword_13AF58;
extern uint32_t dword_13AF54;

// sub_13AE40 @ 0x13ae40, size 270 bytes
int  sub_13AE40(int a1, int a2)
{
  int v2; // r5
  int v3; // r3
  int16_t v5; // r0
  int v6; // r3
  int v8; // r6
  int v9; // r0
  char v10; // r0
  int v11; // r3
  int result; // r0
  int v13; // r1
  int v14; // r3

  v2 = *(uint32_t *)(a1 + 76);
  v3 = *(uint16_t *)(a1 + 32);
  v5 = *(uint16_t *)(a1 + 30);
  v6 = 16 * v3;
  v8 = *(uint32_t *)(v2 + 4) & 0x800000;
  *(uint32_t *)(v2 + 4) = v6;
  if ( (v5 & 8) != 0 )
  {
    if ( (v5 & 0x20) != 0 )
    {
      if ( v8 )
      {
        if ( (v5 & 0x200) == 0 )
          goto LABEL_19;
LABEL_5:
        if ( **(int16_t **)off_13AF50 >= 0 )
          goto LABEL_6;
        goto LABEL_27;
      }
      sub_13A398();
      if ( (*(uint16_t *)(a1 + 30) & 0x200) != 0 )
        goto LABEL_5;
LABEL_9:
      if ( *(uint8_t *)(a1 + 27) == 255 )
        goto LABEL_10;
      goto LABEL_20;
    }
    if ( (v5 & 0x200) != 0 )
    {
      if ( **(int16_t **)off_13AF50 >= 0 )
        goto LABEL_6;
LABEL_27:
      v9 = *(uint8_t *)(a1 + 29);
      if ( v9 != 255 )
        goto LABEL_7;
      sub_12F32C(dword_13AF5C, dword_13AF58, 1325);
LABEL_6:
      v9 = *(uint8_t *)(a1 + 29);
LABEL_7:
      sub_118E08(v9, 23, 0, 0);
      *(uint8_t *)(dword_13AF54 + 696 * *(uint8_t *)(a1 + 29) + 54) = 0;
    }
LABEL_8:
    if ( !v8 )
      goto LABEL_9;
    goto LABEL_18;
  }
  if ( (v5 & 0x200) == 0 )
    goto LABEL_8;
  *(uint8_t *)(dword_13AF54 + 696 * *(uint8_t *)(a1 + 29) + 54) = 0;
  if ( !v8 )
    goto LABEL_9;
LABEL_18:
  v6 = *(uint32_t *)(v2 + 4);
LABEL_19:
  *(uint32_t *)(v2 + 4) = v6 | 8;
  if ( *(uint8_t *)(a1 + 27) == 255 )
  {
LABEL_10:
    v10 = 1;
    if ( (*(uint32_t *)(a1 + 36) & 0x200000) != 0 )
      goto LABEL_11;
    goto LABEL_17;
  }
LABEL_20:
  v13 = v8;
  if ( v8 )
    v13 = 1;
  v10 = sub_13C154(a1, v13, a2);
  v14 = *(uint32_t *)(a1 + 36);
  if ( (v14 & 0x200000) == 0 )
  {
LABEL_17:
    *(uint8_t *)(v2 + 1) = 1;
    goto LABEL_11;
  }
  if ( (v14 & 0x380000) != 0x380000 )
    *(uint8_t *)(v2 + 1) = 0;
LABEL_11:
  v11 = *(uint32_t *)(v2 + 4);
  *(uint8_t *)v2 = v10;
  result = v11 & 2;
  *(uint32_t *)(v2 + 4) = v11 | 1;
  if ( (v11 & 2) != 0 )
    return *(uint8_t *)(dword_13AF54 + 696 * *(uint8_t *)(a1 + 29) + 48) == 0;
  return result;
}

