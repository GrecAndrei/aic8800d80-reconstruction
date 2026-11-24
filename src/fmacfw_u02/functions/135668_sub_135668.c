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


extern uint32_t dword_1356FC;
extern uint32_t off_1356F8;

// sub_135668 @ 0x135668, size 144 bytes
int  sub_135668(int a1)
{
  int v2; // r6
  int result; // r0
  int v4; // r6
  int v5; // r4

  v2 = *(uint8_t *)(a1 + 8);
  if ( sub_12CE88(6u) == 10 || sub_12CE88(6u) == 9 )
    return 2;
  if ( sub_12CE88(6u) )
  {
    if ( *(uint8_t *)(*((uint32_t *)off_1356F8 + 4) + 61) != *(uint8_t *)(a1 + 8) )
      return 2;
    sub_12ECD0(256, aDeauthHandlerI);
    if ( sub_12C8B4(6154, 6) )
      sub_12C73C((char *)0x180A, 6);
    sub_134E04(1);
    return 0;
  }
  else
  {
    v4 = dword_1356FC + 1320 * v2;
    result = *(uint8_t *)(v4 + 108);
    if ( *(uint8_t *)(v4 + 108) )
    {
      v5 = *(uint16_t *)(a1 + 12);
      sub_12ECD0(256, "deauth_handler: reason code =%d\r\n", v5);
      sub_134D8C(v4, v5, 0);
      return 0;
    }
  }
  return result;
}
