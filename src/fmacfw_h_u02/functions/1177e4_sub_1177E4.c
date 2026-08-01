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

extern uint32_t off_11788C;
extern uint32_t off_1178A0;
extern uint32_t dword_117890;
extern uint32_t dword_117894;
extern uint32_t off_117898;
extern uint32_t off_1178A8;
extern uint32_t dword_11789C;
extern uint32_t off_1178A4;
extern uint32_t dword_1178B0;
extern uint32_t dword_1178AC;

// radio_event_handler @ 0x1177e4, size 168 bytes
int  radio_event_handler(int result)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(uint32_t *)off_11788C;
  if ( (*(uint32_t *)off_11788C & 0x1000) != 0 )
  {
    result = dma_clear_interrupt(result, *(uint32_t *)off_11788C << 19);
    *(uint32_t *)off_1178A0 = 4096;
  }
  v2 = dword_117890;
  if ( (v1 & dword_117890) != 0 )
  {
    result = is_fw_ready();
    *(uint32_t *)off_1178A0 = v2;
  }
  if ( (dword_117894 & v1) != 0 && (*(uint32_t *)off_117898 & 0x300000) == 0 )
  {
    *(uint32_t *)off_1178A8 |= 0x200u;
    v3 = dword_11789C & v1;
    if ( (dword_11789C & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_11789C & v1;
    if ( (dword_11789C & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(uint32_t *)off_1178A0 = 0x80000;
    return phy_config_table(5);
  }
  v4 = (uint8_t)(25 - __clz(v3));
  if ( **(int16_t **)off_1178A4 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    irq_disable_mmio_write(dword_1178B0, dword_1178AC, 2883);
  }
  *(uint32_t *)off_1178A0 = 1 << (v4 + 6);
  return phy_config_table(v4);
}

