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

extern uint32_t off_133B70;
extern uint32_t dword_133B78;
extern uint32_t dword_133B74;

// fw_feature_check_n370 @ 0x133b3c, size 52 bytes
// Doc: fw_feature_check_n370 [util]: Check firmware feature/flag word at shared address
// fw_feature_check_n370 [util]: Check firmware feature/flag word at shared address
int  fw_feature_check_n370(int value)
{
  int v2; // r0

  if ( **(int16_t **)off_133B70 >= 0 || (value = msg_get_value(6u), value == 10) )
  {
    sub_1349D8(value);
    return 0;
  }
  else
  {
    v2 = sub_12F694(dword_133B78, dword_133B74, 871);
    sub_1349D8(v2);
    return 0;
  }
}

