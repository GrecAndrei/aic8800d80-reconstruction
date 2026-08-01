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

// scheduler_run @ 0x11ba4c, size 22 bytes
int  scheduler_run(int a1, int a2, int a3)
{
  int result; // r0

  rf_state_process(a1, a2, a3);
  result = tx_schedule();
  if ( !result )
    return state_flag_check();
  return result;
}

