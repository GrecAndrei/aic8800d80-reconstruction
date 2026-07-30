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

extern uint32_t dword_12DF34;
extern uint32_t off_12DF38;
extern uint32_t dword_12DF3C;

// sub_12DE94 @ 0x12de94, size 158 bytes
int  sub_12DE94(char *a1)
{
  int result; // r0

  if ( (unsigned int)a1 > dword_12DF34 )
  {
    if ( a1 == (char *)off_12DF38 )
    {
      return 19;
    }
    else if ( a1 <= (char *)off_12DF38 )
    {
      if ( a1 == (char *)off_12DF38 - 1 )
        return 18;
      else
        return 255;
    }
    else if ( a1 == (char *)dword_12DF3C )
    {
      return 2;
    }
    else if ( a1 == (char *)(dword_12DF3C + 1) )
    {
      return 3;
    }
    else
    {
      return 255;
    }
  }
  else if ( (unsigned int)a1 <= dword_12DF34 - 18 )
  {
    return 255;
  }
  else
  {
    switch ( (unsigned int)a1 )
    {
      case 0xFAC01u:
        return 2;
      case 0xFAC02u:
        result = 3;
        break;
      case 0xFAC03u:
        result = 4;
        break;
      case 0xFAC04u:
        result = 5;
        break;
      case 0xFAC05u:
        result = 6;
        break;
      case 0xFAC06u:
        result = 7;
        break;
      case 0xFAC07u:
        result = 8;
        break;
      case 0xFAC08u:
        result = 9;
        break;
      case 0xFAC09u:
        result = 10;
        break;
      case 0xFAC0Bu:
        result = 11;
        break;
      case 0xFAC0Cu:
        result = 12;
        break;
      case 0xFAC0Du:
        result = 13;
        break;
      case 0xFAC0Fu:
        result = 14;
        break;
      case 0xFAC10u:
        result = 15;
        break;
      case 0xFAC11u:
        result = 16;
        break;
      case 0xFAC12u:
        result = 17;
        break;
      default:
        return 255;
    }
  }
  return result;
}

