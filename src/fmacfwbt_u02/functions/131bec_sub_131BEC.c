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

extern uint32_t off_131C78;

// sub_131BEC @ 0x131bec, size 138 bytes
int  sub_131BEC(int a1, uint8_t *a2, unsigned int a3, int16_t a4)
{
  uint32_t *v5; // r5
  int v6; // r7
  int v8; // r0
  int v9; // r0
  int v10; // r3
  uint8_t *v12; // r0
  int v13; // r3
  char v14; // r3
  unsigned int v15; // [sp+4h] [bp-8h]

  v5 = off_131C78;
  v6 = *((uint32_t *)off_131C78 + 1);
  v8 = 1 << a2[1];
  if ( *a2 )
    v9 = v8 | v6;
  else
    v9 = v6 & ~v8;
  v10 = *((uint8_t *)off_131C78 + 375);
  *((uint32_t *)off_131C78 + 1) = v9;
  if ( !v10 )
    goto LABEL_7;
  v15 = a3;
  if ( sub_12D0B0(5u) == 1 )
    return 2;
  LOWORD(a3) = v15;
  if ( (uint8_t)v6 )
  {
    if ( *a2 )
    {
LABEL_7:
      sub_12CC38(5146, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    goto LABEL_7;
  }
  v12 = (uint8_t *)sub_12CB54(49, 0, v15, 1u);
  v13 = v5[1];
  *((uint16_t *)v5 + 4) = a4;
  if ( v13 )
    v14 = 0;
  else
    v14 = *((uint8_t *)v5 + 376);
  *v12 = v14;
  sub_12CBB4((int)v12);
  sub_12CF5C(v15, 1);
  return 0;
}

