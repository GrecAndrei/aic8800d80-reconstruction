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

extern uint32_t dword_131754;

// rf_calib_load @ 0x131734, size 30 bytes
int  rf_calib_load(int a1, int a2, int16_t a3, int16_t a4)
{
  memcpy_aligned(dword_131754, a2, 254);
  hci_evt_alloc_send(5123, a4, a3);
  return 0;
}

