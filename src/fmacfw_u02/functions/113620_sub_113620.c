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


extern uint32_t off_11368C;
extern uint32_t off_113690;
extern uint32_t off_113694;
extern uint32_t off_113698;
extern uint32_t off_11369C;
extern uint32_t off_1136A0;

// is_single_channel @ 0x113620, size 106 bytes
int * is_single_channel(int a1)
{
  int *result; // r0
  int *v2; // r4
  unsigned int v3; // r0

  switch ( a1 )
  {
    case 1:
      v2 = (int *)off_113694;
      memcpy((char *)off_113694, (char *)off_113698, 0x12u);
      if ( BYTE2(((uint32_t *)(uintptr_t)off_11369C)[92]) && get_hook_bit_9() )
      {
        v3 = call_hook_2();
        v2[2] = ((HIWORD(v3) << 16) + 0x10000) | (uint16_t)v3;
        return v2;
      }
      else if ( *(uint16_t *)off_1136A0 == 0xFFFF || *((uint16_t *)off_1136A0 + 1) == 0xFFFF )
      {
        return (int *)off_113694;
      }
      else
      {
        result = (int *)off_113694;
        v2[2] = *(uint32_t *)off_1136A0;
      }
      break;
    case 6:
      return (int *)off_113690;
    case 15:
      return (int *)off_11368C[0];
    default:
      return nullptr;
  }
  return result;
}
