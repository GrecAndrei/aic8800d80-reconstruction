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

extern uint32_t dword_118BE4;

// check_packet_flag @ 0x118bbc, size 40 bytes
int  check_packet_flag(int result, int a2)
{
  int v2; // r4
  int ( *v4)(uint32_t, uint32_t); // r3

  v2 = result;
  if ( !*(uint8_t *)(result + 96) )
    result = wlan_ioctl_handler_1(dword_118BE4);
  if ( a2 )
  {
    v4 = *(int ( **)(uint32_t, uint32_t))(v2 + 88);
    if ( v4 )
      return v4(*(uint32_t *)(v2 + 92), 0);
  }
  return result;
}

