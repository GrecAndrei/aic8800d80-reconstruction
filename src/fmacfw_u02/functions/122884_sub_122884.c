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

extern uint32_t off_1228D4;
extern uint32_t off_1228D0;
extern uint32_t dword_1228E4;
extern uint32_t dword_1228E0;
extern uint32_t off_1228D8;
extern uint32_t off_1228DC;

// check_hw_version @ 0x122884, size 76 bytes
// Doc: sub_122288E [unknown]: Unknown helper in fmacfw
// sub_122288E [unknown]: Unknown helper in fmacfw
char *check_hw_version()
{
  int v0; // r4

  v0 = *(uint32_t *)off_1228D4 & 0x1800000;
  if ( **(int16_t **)off_1228D0 < 0 && v0 == 25165824 )
    mmio_clear_register(dword_1228E4, dword_1228E0, 1308);
  unknown_func_12d14c(v0);
  if ( *((uint8_t *)off_1228D8 + 18) )
    return (char *)event_queue_drain();
  else
    return read_config_byte(*((char **)off_1228DC + 8));
}

