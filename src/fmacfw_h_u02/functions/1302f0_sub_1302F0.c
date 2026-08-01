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

extern uint32_t dword_13036C;
extern uint32_t dword_130360;
extern uint32_t off_130364;
extern uint32_t dword_130368;

// check_frame_len @ 0x1302f0, size 110 bytes
int  check_frame_len(int a1)
{
  signed int v1; // r0
  int v2; // r3
  int result; // r0

  if ( a1 > 29 )
    v1 = (unsigned int)(((unsigned int)dword_13036C * (unsigned uint64_t)(unsigned int)(a1 - 30)) >> 32) >> 3;
  else
    v1 = ((int)((unsigned uint64_t)(dword_130360 * (uint64_t)(a1 - 40)) >> 32) >> 2) - ((a1 - 40) >> 31);
  if ( v1 >= 8 )
    v1 = 8;
  if ( v1 < -7 )
    v1 = -7;
  v2 = *((uint8_t *)off_130364 + 4)
     + (char)(*(uint8_t *)(dword_130368 + v1 + 7) - *(uint8_t *)(dword_130368 + *((char *)off_130364 + 2) + 7));
  if ( v2 >= 31 )
    v2 = 31;
  if ( v2 < 1 )
    LOBYTE(v2) = 1;
  *((uint8_t *)off_130364 + 5) = v2;
  rf_temp_compensation(v1);
  result = is_id_lt_10(9u, 4u);
  if ( result )
    return rf_tx_power_lookup();
  return result;
}

