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

extern uint32_t off_133AB0;
extern uint32_t dword_133AB8;
extern uint32_t dword_133AB4;

// sub_133A54 @ 0x133a54, size 90 bytes
// Doc: sub_1233A54 [unknown]: Unidentified firmware routine in fmacfw
// sub_1233A54 [unknown]: Unidentified firmware routine in fmacfw
int sub_133A54()
{
  int v0; // r2
  int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF

  v0 = **(int16_t **)off_133AB0;
  v2 = 0;
  v3 = 0;
  if ( v0 < 0 && msg_get_value(6u) != 1 )
    sub_12F46C(dword_133AB8, dword_133AB4, 303);
  sub_134474(&v2, &v3);
  if ( v2 && v3 )
  {
    sub_1345C0();
    return 0;
  }
  else
  {
    sub_134E04(1);
    return 0;
  }
}

