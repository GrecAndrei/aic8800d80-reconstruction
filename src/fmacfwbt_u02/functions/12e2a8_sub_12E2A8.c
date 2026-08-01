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

extern uint32_t dword_12E320;
extern uint32_t dword_12E324;

// freq_to_chan_map2 @ 0x12e2a8, size 120 bytes
// Doc: sdio_buffer_prepare_2ba [mac]: Prepare SDIO scatter-gather buffer descriptor
// sdio_buffer_prepare_2ba [mac]: Prepare SDIO scatter-gather buffer descriptor
int  freq_to_chan_map2(unsigned int a1)
{
  int result; // r0

  if ( a1 > dword_12E320 )
  {
    if ( a1 == dword_12E324 )
    {
      return 1;
    }
    else if ( a1 == dword_12E324 + 2 )
    {
      return 2;
    }
    else if ( a1 == dword_12E324 - 3964929 )
    {
      return 4;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= dword_12E320 - 13 )
  {
    return 255;
  }
  else
  {
    switch ( a1 )
    {
      case 0xFAC01u:
        result = 0;
        break;
      case 0xFAC02u:
        return 1;
      case 0xFAC04u:
        return 2;
      case 0xFAC05u:
        result = 3;
        break;
      case 0xFAC06u:
        result = 5;
        break;
      case 0xFAC08u:
        result = 6;
        break;
      case 0xFAC09u:
        result = 7;
        break;
      case 0xFAC0Au:
        result = 8;
        break;
      case 0xFAC0Bu:
        result = 9;
        break;
      case 0xFAC0Cu:
        result = 10;
        break;
      case 0xFAC0Du:
        result = 11;
        break;
      default:
        return 255;
    }
  }
  return result;
}

