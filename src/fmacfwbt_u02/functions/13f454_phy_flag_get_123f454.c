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

// set_flow_control_mode @ 0x13f454, size 44 bytes
// Doc: set_flow_control_mode [mac]: Get PHY capability flag from offset 0x15c, branch on mode
// set_flow_control_mode [mac]: Get PHY capability flag from offset 0x15c, branch on mode
int  set_flow_control_mode(int result, unsigned int a2)
{
  int v2; // r2
  uint32_t *v3; // r4
  int v4; // r3

  if ( a2 > 3 )
    v2 = 0;
  else
    v2 = *(uint16_t *)(result + 348) & 0x400;
  v3 = *(uint32_t **)(result + 336);
  v4 = v2 | a2 | 0x20000000;
  v3[5] = v4;
  v3[6] = v4;
  v3[7] = v4;
  v3[8] = v4;
  return result;
}

