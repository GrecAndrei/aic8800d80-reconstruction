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

extern uint32_t off_13669C;
extern uint32_t off_1366A4;
extern uint32_t dword_1366A0;
extern uint32_t dword_1366A8;
extern uint32_t dword_1366AC;

// bt_get_buffer @ 0x136668, size 52 bytes
// Doc: sub_1236668 [util]: Returns boolean indicating firmware state flag status
// sub_1236668 [util]: Returns boolean indicating firmware state flag status
uint32_t *bt_get_buffer()
{
  if ( **(int16_t **)off_13669C >= 0 || !*((uint32_t *)off_1366A4 + 1) )
    return zero_8_bytes((uint32_t *)dword_1366A0);
  mmio_clear_register(dword_1366A8, dword_1366AC, 46);
  return zero_8_bytes((uint32_t *)dword_1366A0);
}

