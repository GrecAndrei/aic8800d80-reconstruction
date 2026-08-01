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

extern uint32_t dword_136FE4;
extern uint32_t off_136FE8;

// rf_set_band_alt @ 0x136fa4, size 64 bytes
int  rf_set_band_alt(int a1, uint16_t *a2, int a3, int16_t a4)
{
  uint8_t *v5; // r4
  char *v6; // r0
  int v7; // r2

  v5 = (uint8_t *)ke_msg_alloc(4104, a4, 4, 2u);
  check_status_bits(8, dword_136FE4);
  v6 = (char *)off_136FE8;
  v7 = *a2;
  *(uint16_t *)off_136FE8 = v7;
  memcpy(v6 + 3, (char *)a2 + 3, v7);
  *v5 = 1;
  v5[1] = *((uint8_t *)a2 + 2);
  ke_msg_send((int)v5);
  return 0;
}

