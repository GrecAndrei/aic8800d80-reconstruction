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

extern uint32_t off_140464;
extern uint32_t dword_14046C;
extern uint32_t dword_140468;

// fw_cmd_query @ 0x140430, size 50 bytes
// Doc: fw_cmd_query [ipc]: Queries firmware command status (op 0xb)
// fw_cmd_query [ipc]: Queries firmware command status (op 0xb)
int fw_cmd_query()
{
  if ( msg_get_value(0xBu) == 1 )
  {
    sub_1415EC();
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_140464 < 0 )
      sub_12F49C(dword_14046C, dword_140468, 157);
    return 0;
  }
}

