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

extern uint32_t dword_118980;
extern uint32_t off_118984;
extern uint32_t dword_118988;

// sub_118908 @ 0x118908, size 118 bytes
// Doc: sub_1218914 [unknown]: Indexed table entry lookup with multiplied offset
// sub_1218914 [unknown]: Indexed table entry lookup with multiplied offset
int  sub_118908(int result)
{
  int v1; // r5
  int v2; // r4
  unsigned int v3; // r3
  uint8_t *v4; // r2
  unsigned int v5; // r2
  int v6; // [sp+4h] [bp-14h]

  if ( *(uint8_t *)(result + 96) )
  {
    v1 = *(uint32_t *)(result + 36);
    v2 = result;
    v6 = *(uint32_t *)(dword_118980 + 152 * *(uint8_t *)(result + 102) + 8) + v1;
    sub_11AB18(result + 24, v6);
    sub_118310(v2);
    result = unknown_helper_2(v2, v1, v6);
    if ( !result )
    {
      v3 = (uint8_t)(*(uint8_t *)(v2 + 116) + 1);
      v4 = *(uint8_t **)off_118984;
      *(uint8_t *)(v2 + 116) = v3;
      v5 = *v4;
      if ( v3 > v5 )
      {
        return rf_channel_set_n6838(*(uint8_t *)(v2 + 102), dword_118988, v2);
      }
      else if ( v3 == v5 )
      {
        return rf_msg_handler_n0ec(v2);
      }
    }
  }
  return result;
}

