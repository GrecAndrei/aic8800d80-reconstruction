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

extern uint32_t dword_1285B4;
extern uint32_t off_1285B8;

// get_control_byte @ 0x128548, size 106 bytes
// Doc: sub_1228548 [unknown]: Unknown fmac utility
// sub_1228548 [unknown]: Unknown fmac utility
int  get_control_byte(int result)
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
    v2 = dword_1285B4;
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
    v7 = dword_1285B4 + 1320 * v1;
    v8 = *(char *)(v7 + 110);
    v4 = *(char *)(v7 + 109);
    if ( v4 >= v8 )
      v4 = v8;
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = off_1285B8;
    *(uint8_t *)(result + 12) = v4;
    if ( v5[10] == result )
      return util_format(v4);
  }
  else
  {
    v6 = off_1285B8;
    *(uint8_t *)(result + 12) = 15;
    if ( v6[10] == result )
      return util_format(15);
  }
  return result;
}

