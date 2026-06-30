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

extern uint32_t dword_1287D8;
extern uint32_t off_1287DC;

// sub_12876C @ 0x12876c, size 106 bytes
int  sub_12876C(int result)
{
  int v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r3
  uint32_t *v5; // r2
  uint32_t *v6; // r2
  int v7; // r3
  int v8; // r2

  if ( *(uint8_t *)(result + 25) )
  {
    v1 = 0;
    v2 = dword_1287D8;
    while ( 1 )
    {
      v3 = *(uint32_t *)(v2 + 72);
      v2 += 1320;
      if ( v3 == result )
        break;
      if ( ++v1 == 4 )
      {
        v4 = 15;
        goto LABEL_6;
      }
    }
    v7 = dword_1287D8 + 1320 * v1;
    v8 = *(char *)(v7 + 110);
    v4 = *(char *)(v7 + 109);
    if ( v4 >= v8 )
      v4 = v8;
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = off_1287DC;
    *(uint8_t *)(result + 12) = v4;
    if ( v5[10] == result )
      return bt_hci_cmd_build_n6ac(v4);
  }
  else
  {
    v6 = off_1287DC;
    *(uint8_t *)(result + 12) = 15;
    if ( v6[10] == result )
      return bt_hci_cmd_build_n6ac(15);
  }
  return result;
}

