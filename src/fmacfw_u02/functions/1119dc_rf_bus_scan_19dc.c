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

// table_lookup_wrapper @ 0x1119dc, size 30 bytes
// Doc: table_lookup_wrapper [rf]: Scans RF bus indices invoking sub_121196c per slot
// table_lookup_wrapper [rf]: Scans RF bus indices invoking sub_121196c per slot
int *table_lookup_wrapper()
{
  int i; // r4
  int v1; // r0
  int *result; // r0
  int v3; // [sp+4h] [bp-4h]

  for ( i = 1; i != 6; ++i )
  {
    v1 = (uint8_t)i;
    v3 = (uint8_t)i;
    table_lookup_entry(v1);
    result = table_lookup_entry_2(v3);
  }
  return result;
}

