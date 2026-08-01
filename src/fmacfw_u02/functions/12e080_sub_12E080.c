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

extern uint32_t dword_12E0F8;
extern uint32_t dword_12E0FC;

// rf_trim_low @ 0x12e080, size 120 bytes
// Doc: sdio_buffer_prepare_n_8a [mac]: SDIO buffer preparation routine
// sdio_buffer_prepare_n_8a [mac]: SDIO buffer preparation routine
int  rf_trim_low(unsigned int a1)
{
  int result; // r0

  if ( a1 > dword_12E0F8 )
  {
    if ( a1 == dword_12E0FC )
    {
      return 1;
    }
    else if ( a1 == dword_12E0FC + 2 )
    {
      return 2;
    }
    else if ( a1 == dword_12E0FC - 3964929 )
    {
      return 4;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= dword_12E0F8 - 13 )
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

