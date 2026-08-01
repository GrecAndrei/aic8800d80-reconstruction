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

extern uint32_t off_10C9F0;
extern uint32_t off_10C9F8;
extern uint32_t off_10CA10;
extern uint32_t off_10C9F4;
extern uint32_t off_10C9FC;
extern uint32_t off_10CA00;
extern uint32_t off_10CA04;
extern uint32_t off_10CA08;
extern uint32_t dword_10CA0C;

// pmu_status_interrupt @ 0x10c938, size 182 bytes
// Doc: pmu_status_interrupt [util]: Thin wrapper allocating/processing an fmac message
// pmu_status_interrupt [util]: Thin wrapper allocating/processing an fmac message
int pmu_status_interrupt()
{
  int v0; // r4
  int result; // r0
  uint32_t *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2
  uint32_t *v5; // r2
  uint32_t *v6; // r2

  v0 = *(uint32_t *)off_10C9F0;
  if ( (*(uint32_t *)off_10C9F0 & 0x20) != 0 )
  {
    v6 = off_10C9F8;
    *(uint32_t *)off_10CA10 = 32;
    *v6 = 32;
    set_system_flag_1(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = off_10C9F8;
    *(uint32_t *)off_10CA10 = 16;
    *v5 = 16;
    result = set_system_flag_1(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = set_system_flag_1(0x8000000);
    *(uint32_t *)off_10CA10 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = check_radio_flag(1);
    *(uint32_t *)off_10C9F8 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = off_10C9F8;
    *(uint32_t *)off_10C9F4 = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = off_10C9FC;
    if ( !*(uint8_t *)off_10C9FC || !*(uint32_t *)off_10CA00 )
      return result;
LABEL_16:
    v4 = off_10CA04;
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = off_10C9FC;
  *(uint32_t *)off_10C9F8 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(uint32_t *)off_10CA08 & dword_10CA0C) == 0x10000 )
    return log_and_check_hw();
  return result;
}

