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

extern uint32_t off_142610;
extern uint32_t dword_142618;
extern uint32_t dword_142614;

// read_status_flag @ 0x1425d4, size 58 bytes
// Doc: sub_12425DE [unknown]: Helper routine with saved r4/lr; small wrapper
// sub_12425DE [unknown]: Helper routine with saved r4/lr; small wrapper
int  read_status_flag(int a1, unsigned int a2)
{
  if ( **(int16_t **)off_142610 < 0 && *(uint8_t *)(a2 + 8) == 255 )
    mmio_clear_register(dword_142618, dword_142614, 50);
  if ( (*(uint16_t *)(a2 + 2) & 0xFC) == 0xD0 )
    adv_report_process(a2);
  return 0;
}

