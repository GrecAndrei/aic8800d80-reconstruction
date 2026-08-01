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

extern uint32_t dword_138BA8;

// tx_power_cal_apply @ 0x138b78, size 46 bytes
uint32_t ** tx_power_cal_apply(uint32_t *a1)
{
  int v1; // r5

  v1 = dword_138BA8;
  tx_power_cal_read(0, 4, a1[5]);
  check_abort_flag_3(v1, a1);
  check_abort_flag(v1 - 8, a1);
  return process_pending_queue((uint32_t **)(v1 - 32));
}

