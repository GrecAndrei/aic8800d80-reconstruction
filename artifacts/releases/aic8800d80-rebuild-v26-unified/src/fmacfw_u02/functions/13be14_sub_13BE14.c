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

extern uint32_t dword_13BE98;
extern uint32_t dword_13BE8C;
extern uint32_t dword_13BE90;
extern uint32_t dword_13BE94;

// sub_13BE14 @ 0x13be14, size 120 bytes
// Doc: sub_123BE14 [unknown]: Unknown behavioral helper, likely init/state helper
// sub_123BE14 [unknown]: Unknown behavioral helper, likely init/state helper
int  sub_13BE14(int result)
{
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BE98;
  v2 = dword_13BE8C;
  v3 = dword_13BE90;
  v4 = result;
  v5 = dword_13BE98 - 8;
  v6 = dword_13BE98 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(uint16_t *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(uint8_t *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        sub_12D2E8(v6, (uint32_t *)v3);
        list_push_tail(dword_13BE94, (uint32_t *)v3);
      }
      else
      {
        sub_12D2E8(v1, (uint32_t *)v3);
        list_push_tail(v5, (uint32_t *)v3);
      }
      sub_12CD34((uint16_t)((uint16_t)i << 8) | 8, 4);
      result = tx_build_frame_header(v4, (uint16_t)i);
    }
    v3 += 32;
  }
  return result;
}

