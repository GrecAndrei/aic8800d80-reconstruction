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

extern uint32_t off_1236A4;
extern uint32_t off_1236A8;
extern uint32_t dword_1236B0;
extern uint32_t dword_1236AC;

// rf_get_status @ 0x123660, size 68 bytes
int  rf_get_status(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r0

  if ( **(int16_t **)off_1236A4 < 0 )
  {
    v7 = *a2;
    if ( HIBYTE(*(uint32_t *)off_1236A8) + 8 >= v7 )
      goto LABEL_3;
    irq_disable_mmio_write(dword_1236B0, dword_1236AC, 1801);
  }
  v7 = *a2;
LABEL_3:
  rf_get_version(v7);
  mac_write_header_word(39, a4, a3);
  return 0;
}

