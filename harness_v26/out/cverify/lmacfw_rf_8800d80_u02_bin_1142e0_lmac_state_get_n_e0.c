#include <stdint.h>
#define BYTE1(x) ((uint8_t)(((uint32_t)(x) >> 8) & 0xFFu))
#define BYTE2(x) ((uint8_t)(((uint32_t)(x) >> 16) & 0xFFu))
#define BYTE3(x) ((uint8_t)(((uint32_t)(x) >> 24) & 0xFFu))
#define __noreturn
#define _VF 0
#define _CF 0
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

#define off_11430C ((uint32_t)0x00180550u)
#define off_114310 ((uint32_t)0x00180554u)
#define off_114314 ((uint32_t)0x00180558u)
// lmac_state_get_n_e0 @ 0x1142e0, size 42 bytes
// Doc: lmac_state_get_n_e0 [util]: Get LMAC state value from global pointer
// lmac_state_get_n_e0 [util]: Get LMAC state value from global pointer
void lmac_state_get_n_e0()
{
  int *v0; // r4

  v0 = (int *)off_11430C;
  if ( !*(uint32_t *)off_11430C )
    *v0 = sub_114218();
  if ( !*(uint32_t *)off_114310 )
    *(uint32_t *)off_114310 = *v0 + 67092480;
  *(uint32_t *)off_114314 = 1;
}

