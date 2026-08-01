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

extern uint32_t off_12EF7C;
extern uint32_t dword_12EF80;
extern uint32_t off_12EF84;

// bt_coex_check_state @ 0x12ef20, size 90 bytes
int bt_coex_check_state()
{
  uint8_t *v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = off_12EF7C;
  v1 = invalid_handler_12c5fc(1070, 1);
  v2 = (char)v0[1];
  if ( v2 == 1 )
  {
    fw_version_get();
    ke_event_handler(1070, 1, dword_12EF80);
    v0[1] = 2;
    return 0;
  }
  else
  {
    if ( v2 == 2 )
    {
      sub_130370(v1);
      ke_event_handler(1070, 1, 1000 * *((uint32_t *)off_12EF84 + 91));
      v0[1] = 1;
    }
    return 0;
  }
}

