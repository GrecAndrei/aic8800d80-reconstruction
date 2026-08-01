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

extern uint32_t dword_136238;
extern uint32_t dword_13623C;

// patch_get_entry @ 0x1361f4, size 68 bytes
int  patch_get_entry(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  uint16_t v5; // r7
  uint8_t *v8; // r0

  v5 = *((uint16_t *)a2 + 1);
  memcpy_aligned(dword_136238 + (*a2 << 9), a2 + 4, v5);
  *(uint16_t *)(dword_13623C + 2 * *a2) = v5;
  v8 = (uint8_t *)bt_buf_alloc(7177, a4, a3, 2u);
  *v8 = 1;
  v8[1] = *a2;
  hci_evt_send((int)v8);
  return 0;
}

