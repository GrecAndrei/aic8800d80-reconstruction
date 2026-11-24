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
int  tx_power_cal_apply(int a1)
{
  int v1; // r5
  int v3; // r1

  v1 = dword_138BA8;
  tx_power_cal_read(0, 4, *(uint32_t *)(a1 + 20));
  check_abort_flag_3(v1, (uint32_t *)a1);
  check_abort_flag(v1 - 8, (uint32_t *)a1);
  return (int)process_pending_queue((int *)(v1 - 32), v3);
}
