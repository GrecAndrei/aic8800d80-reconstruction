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

extern uint32_t off_11C204;
extern uint32_t off_11C20C;
extern uint32_t off_11C208;

// read_int_status @ 0x11c1d0, size 52 bytes
int read_int_status()
{
  int result; // r0
  int v1; // r4
  int *v2; // r2
  int v3; // r3

  result = check_hw_counters();
  if ( (*(uint32_t *)off_11C204 & 0x8000) != 0 && (v1 = result, (result = rf_status_bit21()) != 0) && v1 )
  {
    v2 = (int *)off_11C20C;
    v3 = *(uint32_t *)off_11C20C;
    *((uint32_t *)off_11C208 + 4) = v1;
    *v2 = v3 | 0x80;
  }
  else
  {
    *((uint32_t *)off_11C208 + 4) = 0;
  }
  return result;
}

