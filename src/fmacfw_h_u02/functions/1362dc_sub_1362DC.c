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

extern uint32_t dword_136330;
extern uint32_t dword_136334;

// ble_encrypt_data @ 0x1362dc, size 84 bytes
int  ble_encrypt_data(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int v7; // r4

  check_feature_flag(256, dword_136330);
  v7 = dword_136334 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && *(uint8_t *)(v7 + 108) )
  {
    if ( hci_cmd_handler(7u) )
    {
      return 2;
    }
    else
    {
      send_ble_hci_command(v7);
      return 0;
    }
  }
  else
  {
    mac_write_header_word(7171, a4, a3);
    return 0;
  }
}

