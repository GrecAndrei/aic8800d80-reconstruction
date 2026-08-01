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

// rf_enable_txrx_patch @ 0x111694, size 40 bytes
// Doc: rf_bus_write2_n17b [rf]: RF bus 2-byte write with parameter validation
// rf_bus_write2_n17b [rf]: RF bus 2-byte write with parameter validation
int * rf_enable_txrx_patch(int *result, unsigned int a2)
{
  if ( result )
  {
    if ( a2 <= 5 )
      return (int *)rf_channel_get_flag(a2, 0x8000000, 0x200000);
  }
  else if ( a2 <= 5 )
  {
    return rf_channel_set_flag(a2, 0x8000000, 0x200000);
  }
  return result;
}

