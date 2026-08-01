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

extern uint32_t dword_13BA00;
extern uint32_t dword_13BA04;
extern uint32_t dword_13BA08;

// ll_global_init @ 0x13b96c, size 146 bytes
uint32_t *ll_global_init()
{
  uint32_t *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  uint32_t *result; // r0

  v0 = (uint32_t *)dword_13BA00;
  zero_8_bytes((uint32_t *)dword_13BA00);
  zero_8_bytes(v0 + 2);
  zero_8_bytes(v0 + 4);
  zero_8_bytes(v0 + 6);
  zero_8_bytes(v0 + 8);
  zero_8_bytes(v0 + 10);
  v1 = dword_13BA04;
  v2 = dword_13BA08;
  for ( i = 0; ; ++i )
  {
    *(uint8_t *)(v1 + 16) = -1;
    *(uint8_t *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    cmd_handler_a((int)v0, (uint32_t *)v1);
    rx_phy_status_parse((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(uint32_t *)(v1 + 28) = v2 + 268 * i;
  cmd_handler_a((int)(v0 + 6), (uint32_t *)v1);
  result = rx_phy_status_parse((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}

