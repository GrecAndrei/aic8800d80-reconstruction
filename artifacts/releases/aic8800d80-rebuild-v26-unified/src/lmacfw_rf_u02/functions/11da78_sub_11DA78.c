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

extern uint32_t off_11DAB8;
extern uint32_t off_11DABC;
extern uint32_t dword_11DAC4;
extern uint32_t dword_11DAC0;

// sub_11DA78 @ 0x11da78, size 64 bytes
int  sub_11DA78(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((uint8_t *)off_11DAB8 + 197) )
  {
    v2 = *(uint32_t *)(*(uint32_t *)(a2 + 32) + 44);
    v3 = sub_101C70((*(uint32_t *)(v2 + 20) >> 11) & 7, *(uint32_t *)(v2 + 20) & 0x7F, *(uint32_t *)(result + 72) + 4);
    result = v3 | (v3 << 8);
    *(uint32_t *)(v2 + 36) = result;
  }
  else if ( **(int16_t **)off_11DABC < 0 )
  {
    return rf_cmd_send_n264(dword_11DAC4, dword_11DAC0, 92);
  }
  return result;
}

