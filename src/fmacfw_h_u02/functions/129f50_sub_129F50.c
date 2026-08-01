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

extern uint32_t dword_129FE8;

// bt_scan_start @ 0x129f50, size 152 bytes
uint8_t * bt_scan_start(uint8_t *result, int a2)
{
  int v2; // r5
  int v3; // r7
  uint8_t *v4; // r8
  int v5; // r9
  int v6; // r4
  uint8_t *v7; // r5
  int v8; // r3

  if ( result[1224] && !(result[106] | a2) )
  {
    v2 = result[1225];
    v3 = dword_129FE8;
    v4 = (uint8_t *)(dword_129FE8 + 140 * v2);
    v5 = 140 * v2;
    if ( v4[16] )
    {
      mem_set_util(dword_129FE8 + 140 * v2);
      v4[16] = 0;
    }
    v6 = v3 + 140 * v2;
    if ( *(uint8_t *)(v6 + 64) )
    {
      mem_set_util(v5 + 48 + v3);
      *(uint8_t *)(v6 + 64) = 0;
    }
    v7 = (uint8_t *)(v3 + 140 * v2);
    v8 = v7[114];
    v7[115] = 0;
    v7[120] = 0;
    v7[132] = 0;
    if ( v8 )
    {
      mem_set_util(v5 + 96 + v3);
      v7[114] = 0;
    }
    return rsn_parse_ie(v4);
  }
  return result;
}

