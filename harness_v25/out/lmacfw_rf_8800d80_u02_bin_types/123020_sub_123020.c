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

extern uint32_t dword_12305C;
extern uint32_t dword_123064;
extern uint32_t dword_123060;

// sub_123020 @ 0x123020, size 60 bytes
int  sub_123020(int a1)
{
  unsigned int v1; // r4
  unsigned int v3; // r4

  if ( a1 )
  {
    if ( a1 == 1 )
    {
      sub_1141EC();
      v1 = patch_apply_slot_36();
      msg_parse(dword_12305C, v1);
    }
    else
    {
      msg_parse(dword_123064);
      return -21;
    }
    return v1;
  }
  else
  {
    v3 = patch_apply_slot_36();
    msg_parse(dword_123060, v3);
    return v3;
  }
}

