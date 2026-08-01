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

extern uint32_t off_1424D0;
extern uint32_t dword_1424D8;
extern uint32_t dword_1424D4;

// global_table_lookup @ 0x142494, size 58 bytes
int  global_table_lookup(int a1, unsigned int a2)
{
  if ( **(int16_t **)off_1424D0 < 0 && *(uint8_t *)(a2 + 8) == 255 )
    irq_disable_mmio_write(dword_1424D8, dword_1424D4, 50);
  if ( (*(uint16_t *)(a2 + 2) & 0xFC) == 0xD0 )
    bt_data_process(a2);
  return 0;
}

