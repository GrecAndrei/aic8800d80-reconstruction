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

// mode_to_config_get @ 0x11347c, size 106 bytes
// Doc: rf_stream_start2_n26e [rf]: RF stream start variant; tail-calls helper at 0x114e84
// rf_stream_start2_n26e [rf]: RF stream start variant; tail-calls helper at 0x114e84
uint32_t * mode_to_config_get(int a1)
{
  uint32_t *result; // r0
  uint32_t *v2; // r4
  int v3; // r0
  unsigned int v4; // r0

  switch ( a1 )
  {
    case 1:
      v2 = rf_bus_write2_n1be;
      v3 = memcpy_aligned(rf_bus_write2_n1be, rf_stream_start2_n2a8, 18);
      if ( *((uint8_t *)rf_fault_dump_n_3ec + 370) && get_hw_info_bit9(v3) )
      {
        v4 = get_hw_info_2();
        v2[2] = ((HIWORD(v4) << 16) + 0x10000) | (uint16_t)v4;
        return v2;
      }
      else if ( *(uint16_t *)rf_stream_start2_n2b1 == 0xFFFF
             || *((uint16_t *)rf_stream_start2_n2b1 + 1) == 0xFFFF )
      {
        return rf_bus_write2_n1be;
      }
      else
      {
        result = rf_bus_write2_n1be;
        v2[2] = *(uint32_t *)rf_stream_start2_n2b1;
      }
      break;
    case 6:
      return (uint32_t *)rf_stream_start2_4ec;
    case 15:
      return (uint32_t *)rf_stream_start2_n29c;
    default:
      return 0;
  }
  return result;
}

