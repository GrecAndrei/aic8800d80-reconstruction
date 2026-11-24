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


extern uint32_t off_1134E8;
extern uint32_t off_1134EC;
extern uint32_t off_1134F0;
extern uint32_t off_1134F4;
extern uint32_t off_1134F8;
extern uint32_t off_1134FC;

// mode_to_config_get @ 0x11347c, size 106 bytes
int * mode_to_config_get(int a1)
{
  int *result; // r0
  int *v2; // r4
  unsigned int v3; // r0

  switch ( a1 )
  {
    case 1:
      v2 = (int *)off_1134F0;
      memcpy_aligned((char *)off_1134F0, (char *)off_1134F4, 0x12u);
      if ( BYTE2(((uint32_t *)(uintptr_t)off_1134F8)[92]) && get_hw_info_bit9() )
      {
        v3 = get_hw_info_2();
        v2[2] = ((HIWORD(v3) << 16) + 0x10000) | (uint16_t)v3;
        return v2;
      }
      else if ( *(uint16_t *)off_1134FC == 0xFFFF || *((uint16_t *)off_1134FC + 1) == 0xFFFF )
      {
        return (int *)off_1134F0;
      }
      else
      {
        result = (int *)off_1134F0;
        v2[2] = *(uint32_t *)off_1134FC;
      }
      break;
    case 6:
      return (int *)off_1134EC;
    case 15:
      return (int *)off_1134E8[0];
    default:
      return nullptr;
  }
  return result;
}
