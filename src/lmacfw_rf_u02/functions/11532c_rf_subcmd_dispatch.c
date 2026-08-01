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

extern uint32_t off_11537C;
extern uint32_t off_115380;
extern uint32_t dword_115388;
extern uint32_t dword_115384;

// radio_pdu_type_cfg @ 0x11532c, size 80 bytes
// Doc: radio_pdu_type_cfg [rf]: Dispatch on subcommand (cmp r0, 5)
// radio_pdu_type_cfg [rf]: Dispatch on subcommand (cmp r0, 5)
int  radio_pdu_type_cfg(int result)
{
  switch ( result )
  {
    case 0:
      *(uint32_t *)off_11537C = 2;
      break;
    case 1:
      *(uint32_t *)off_11537C = 4;
      break;
    case 2:
      *(uint32_t *)off_11537C = 8;
      break;
    case 3:
      *(uint32_t *)off_11537C = 16;
      break;
    case 5:
      *(uint32_t *)off_11537C = 32;
      break;
    default:
      if ( **(int16_t **)off_115380 < 0 )
        result = flash_ctrl_init(dword_115388, dword_115384, 944);
      break;
  }
  return result;
}

