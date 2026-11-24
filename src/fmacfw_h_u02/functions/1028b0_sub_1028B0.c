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


extern uint32_t dword_10291C;
extern uint32_t dword_102920;
extern uint32_t dword_102924;
extern uint32_t dword_102930;
extern uint32_t off_102918;
extern uint32_t off_102928;
extern uint32_t off_10292C;

// pll_clock_config @ 0x1028b0, size 102 bytes
int pll_clock_config()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  int *v3; // r3
  int v4; // r2

  is_scan_active();
  v0 = (int *)off_102918;
  *(uint32_t *)off_102918 = dword_10291C;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_102920;
  v1 = (int *)off_102918;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_102924;
  v2 = (int *)off_102918;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  rf_calibrate_tx((unsigned int)*v2 >> 31, 0x985u, 0x985u, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = (int *)off_10292C;
  v4 = dword_102930;
  *(uint32_t *)off_102928 = 12;
  *v3 = v4;
  return 12;
}
