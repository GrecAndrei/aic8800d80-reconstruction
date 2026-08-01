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

extern uint32_t off_117A44;
extern uint32_t dword_117A4C;
extern uint32_t dword_117A54;
extern uint32_t dword_117A50;
extern uint32_t dword_117A48;

// rf_cal_offset_apply @ 0x1179c8, size 124 bytes
int  rf_cal_offset_apply(int result)
{
  int v1; // r4
  int16_t v2; // r2
  int v3; // r1

  v1 = result;
  if ( **(int16_t **)off_117A44 < 0 && *(uint32_t *)(result + 20) != dword_117A4C )
    result = flash_ctrl_init(dword_117A54, dword_117A50, 1811);
  v2 = *(uint16_t *)(v1 + 48);
  if ( v2 )
  {
    switch ( *(uint32_t *)(v1 + 84) & 0x7C )
    {
      case 4:
      case 8:
        *(uint16_t *)(v1 + 48) = v2 - 8;
        break;
      case 0xC:
        *(uint16_t *)(v1 + 48) = v2 - 12;
        break;
      case 0x10:
      case 0x14:
      case 0x18:
      case 0x1C:
        *(uint16_t *)(v1 + 48) = v2 - 20;
        break;
      default:
        *(uint16_t *)(v1 + 48) = v2 - 4;
        break;
    }
  }
  v3 = dword_117A48;
  *(uint8_t *)(v1 + 16) = 2;
  *(uint8_t *)(v1 + 152) = 0;
  *(uint32_t *)(v1 + 12) = v1;
  *(uint32_t *)(v1 + 4) = v3;
  return result;
}

