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

// rf_bus_scan_19dc @ 0x1119dc, size 30 bytes
// Doc: rf_bus_scan_19dc [rf]: Scans RF bus indices invoking sub_121196c per slot
// rf_bus_scan_19dc [rf]: Scans RF bus indices invoking sub_121196c per slot
int *rf_bus_scan_19dc()
{
  int i; // r4
  int v1; // r0
  int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (uint8_t)i;
    v3 = (uint8_t)i;
    sub_11196C(v1);
    result = rf_bus_write_9a4(v3);
  }
  return result;
}

