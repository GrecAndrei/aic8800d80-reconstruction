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

extern uint32_t dword_124FCC;
extern uint32_t dword_124FC8;

// sub_124F9C @ 0x124f9c, size 42 bytes
int  sub_124F9C(int a1, int a2)
{
  uint8_t v2; // r0

  if ( a1 <= 1 )
  {
    msg_parse(dword_124FCC);
    return 1;
  }
  else
  {
    v2 = parse_int(*(uint8_t **)(a2 + 4), 0, 0xAu);
    rf_pll_config_patch_n_8c(v2);
    msg_parse(dword_124FC8);
    return 0;
  }
}

