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

extern uint32_t off_121D2C;
extern uint32_t dword_121D40;
extern uint32_t dword_121D3C;
extern uint32_t off_121D30;
extern uint32_t off_121D34;
extern uint32_t off_121D38;

// sub_121CD4 @ 0x121cd4, size 86 bytes
int sub_121CD4()
{
  if ( **(int16_t **)off_121D2C < 0 && msg_get_value(0) != 3 )
    sub_12F694(dword_121D40, dword_121D3C, 1785);
  if ( *((uint8_t *)off_121D30 + 31) && *((uint8_t *)off_121D34 + 18) + *((uint8_t *)off_121D34 + 17) <= 1 )
    return rf_bus_mark_n_3b7(0);
  *(uint32_t *)off_121D38 = 48;
  return rf_bus_mark_n_3b7(0);
}

