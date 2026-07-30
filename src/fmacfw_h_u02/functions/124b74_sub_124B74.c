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

extern uint32_t dword_124BE0;
extern uint32_t off_124BDC;

// sub_124B74 @ 0x124b74, size 102 bytes
int  sub_124B74(int a1, uint16_t *a2, int a3, int a4)
{
  int v6; // r1
  int v7; // r0
  int v8; // [sp+4h] [bp-4h]
  int v9; // [sp+4h] [bp-4h]
  int v10; // [sp+4h] [bp-4h]
  int v11; // [sp+4h] [bp-4h]
  int v12; // [sp+4h] [bp-4h]

  switch ( *(uint32_t *)a2 )
  {
    case 0:
      v8 = a3;
      sub_124848(a2 + 2);
      a3 = v8;
      break;
    case 1:
      v10 = a3;
      sub_1248E4((uint8_t *)a2 + 4);
      a3 = v10;
      break;
    case 2:
      v11 = a3;
      sub_1249FC((uint8_t *)a2 + 4);
      a3 = v11;
      break;
    case 3:
      v12 = a3;
      sub_124AD4((uint8_t *)a2 + 4, a2);
      a3 = v12;
      break;
    case 6:
      v6 = *((uint8_t *)a2 + 4);
      v7 = dword_124BE0;
      v9 = a3;
      *(uint8_t *)off_124BDC = v6;
      sub_12E948(v7, v6, a3);
      a3 = v9;
      break;
    default:
      break;
  }
  sub_12C8D0(127, a4, a3);
  return 0;
}

