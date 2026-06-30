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

extern uint32_t dword_121508;
extern uint32_t off_12150C;

// rf_lmac_init_or_setup @ 0x1214dc, size 42 bytes
// Doc: rf_lmac_init_or_setup [rf]: LMAC RF setup helper that loads config pointer and dispatches to sub-handler
// rf_lmac_init_or_setup [rf]: LMAC RF setup helper that loads config pointer and dispatches to sub-handler
int  rf_lmac_init_or_setup(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  msg_parse(dword_121508, *a2);
  *((uint32_t *)off_12150C + 1) = *a2;
  sub_11DED8(1031, a4, a3);
  return 0;
}

