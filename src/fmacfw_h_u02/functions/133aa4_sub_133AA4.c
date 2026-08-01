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

extern uint32_t dword_133AE8;
extern uint32_t dword_133AEC;

// hci_apply_defaults @ 0x133aa4, size 66 bytes
int  hci_apply_defaults(int a1, uint8_t *a2)
{
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  check_feature_flag(256, dword_133AE8);
  result = hci_cmd_handler(6u);
  if ( result )
    return 2;
  v4 = dword_133AEC + 1320 * v2;
  v5 = *(uint8_t *)(v4 + 106);
  if ( !*(uint8_t *)(v4 + 106) )
  {
    result = *(uint8_t *)(v4 + 108);
    if ( *(uint8_t *)(v4 + 108) )
    {
      ke_timer_set(v4, 1, *(uint8_t *)(v4 + 106));
      return v5;
    }
  }
  return result;
}

