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

extern uint32_t dword_136D68;

// bt_get_link_context @ 0x136d14, size 84 bytes
int  bt_get_link_context(int result, int a2)
{
  int v2; // r4
  char v3; // r1
  int v4; // r0
  int16_t v5; // r1

  if ( *(uint8_t *)(result + 106) == 2 )
  {
    v2 = dword_136D68 + 696 * a2;
    result = llc_ccm_encrypt(result, v2, 0);
    v3 = *(uint8_t *)(v2 + 53);
    if ( (v3 & 0xA) != 0 )
    {
      *(uint8_t *)(v2 + 53) = v3 & 0xF5;
      if ( (v3 & 0xF5) == 0 )
      {
        v4 = ke_msg_alloc(65, 0, 5, 4u);
        v5 = *(uint16_t *)(v2 + 32);
        *(uint8_t *)(v4 + 3) = *(uint8_t *)(v2 + 34);
        *(uint8_t *)(v4 + 2) = 0;
        *(uint16_t *)v4 = v5;
        return ke_msg_send(v4);
      }
    }
  }
  return result;
}

