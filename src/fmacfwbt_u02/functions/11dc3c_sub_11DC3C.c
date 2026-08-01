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

extern uint32_t off_11DC60;

// is_tx_ready @ 0x11dc3c, size 34 bytes
int is_tx_ready()
{
  uint8_t *v0; // r4
  int v1; // r0
  char v2; // r0

  v0 = off_11DC60;
  rf_fifo_status();
  v1 = zero_struct(v0);
  v2 = return_two_stub(v1) - 1;
  v0[11] = v2;
  v0[10] = v2;
  return init_driver_locks();
}

