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

extern uint32_t off_11EFF0;
extern uint32_t dword_11EFF8;
extern uint32_t dword_11F000;
extern uint32_t dword_11EFFC;
extern uint32_t off_11EFF4;

// chan_get_curr_id @ 0x11ef74, size 124 bytes
// Doc: chan_get_curr_id [mac]: Read current channel index from shared struct
// chan_get_curr_id [mac]: Read current channel index from shared struct
int  chan_get_curr_id(int result)
{
  int v1; // r4
  int16_t v2; // r2
  void *v3; // r1

  v1 = result;
  if ( **(int16_t **)off_11EFF0 < 0 && *(uint32_t *)(result + 20) != dword_11EFF8 )
    result = sub_12F694(dword_11F000, dword_11EFFC, 1811);
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
  v3 = off_11EFF4;
  *(uint8_t *)(v1 + 16) = 2;
  *(uint8_t *)(v1 + 156) = 0;
  *(uint32_t *)(v1 + 12) = v1;
  *(uint32_t *)(v1 + 4) = v3;
  return result;
}

