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

extern uint32_t off_127040;
extern uint32_t dword_127048;
extern uint32_t dword_127044;

// rf_cmd_check @ 0x126fd8, size 104 bytes
int  rf_cmd_check(char a1)
{
  uint8_t *v1; // r4
  int v3; // r0
  int v4; // r2
  signed int v5; // r3

  v1 = off_127040;
  if ( *((uint8_t *)off_127040 + 1) )
  {
    v3 = *((char *)off_127040 + 3);
    v4 = v3;
  }
  else
  {
    sdio_core_reset_alt();
    v4 = (int)COERCE_FLOAT(wait_sdio_core_ready());
    v3 = (char)v4;
  }
  v1[4] = a1;
  v1[6] = a1;
  if ( v4 > 29 )
    v5 = (unsigned int)(((unsigned int)dword_127048 * (unsigned uint64_t)(unsigned int)(v4 - 30)) >> 32) >> 3;
  else
    v5 = ((int)((unsigned uint64_t)(dword_127044 * (uint64_t)(v4 - 40)) >> 32) >> 2) - ((v4 - 40) >> 31);
  if ( v5 >= 8 )
    v5 = 8;
  if ( v5 < -7 )
    LOBYTE(v5) = -7;
  v1[2] = v5;
  return freq_offset_to_channel(v3);
}

