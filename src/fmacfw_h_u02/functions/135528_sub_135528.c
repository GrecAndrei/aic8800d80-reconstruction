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


extern uint32_t dword_1355BC;
extern uint32_t off_1355B8;

// mac_proc_bss_color_change @ 0x135528, size 144 bytes
int  mac_proc_bss_color_change(int a1)
{
  int v2; // r6
  int result; // r0
  int v4; // r6
  int v5; // r4

  v2 = *(uint8_t *)(a1 + 8);
  if ( hci_cmd_handler(6u) == 10 || hci_cmd_handler(6u) == 9 )
    return 2;
  if ( hci_cmd_handler(6u) )
  {
    if ( *(uint8_t *)(*((uint32_t *)off_1355B8 + 4) + 61) != *(uint8_t *)(a1 + 8) )
      return 2;
    check_feature_flag(256, aDeauthHandlerI);
    if ( rf_get_state_1(6154, 6) )
      invalid_handler_12c5fc((char *)0x180A, 6);
    assert_trace(1);
    return 0;
  }
  else
  {
    v4 = dword_1355BC + 1320 * v2;
    result = *(uint8_t *)(v4 + 108);
    if ( *(uint8_t *)(v4 + 108) )
    {
      v5 = *(uint16_t *)(a1 + 12);
      check_feature_flag(256, "deauth_handler: reason code =%d\r\n", v5);
      ke_timer_set(v4, v5, 0);
      return 0;
    }
  }
  return result;
}
