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

extern uint32_t dword_13BD58;
extern uint32_t dword_13BD4C;
extern uint32_t dword_13BD50;
extern uint32_t dword_13BD54;

// ke_event_schedule @ 0x13bcd4, size 120 bytes
int  ke_event_schedule(int result)
{
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BD58;
  v2 = dword_13BD4C;
  v3 = dword_13BD50;
  v4 = result;
  v5 = dword_13BD58 - 8;
  v6 = dword_13BD58 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(uint16_t *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(uint8_t *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        wlan_ioctl_handler_3(v6, (uint32_t *)v3);
        wlan_ioctl_handler_1(dword_13BD54, (uint32_t *)v3);
      }
      else
      {
        wlan_ioctl_handler_3(v1, (uint32_t *)v3);
        wlan_ioctl_handler_1(v5, (uint32_t *)v3);
      }
      hci_cmd_preprocess((uint16_t)((uint16_t)i << 8) | 8, 4);
      result = rf_set_frequency(v4, (uint16_t)i);
    }
    v3 += 32;
  }
  return result;
}

