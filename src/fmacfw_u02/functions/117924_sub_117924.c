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

extern uint32_t off_1179CC;
extern uint32_t off_1179E0;
extern uint32_t dword_1179D0;
extern uint32_t dword_1179D4;
extern uint32_t off_1179D8;
extern uint32_t off_1179E8;
extern uint32_t dword_1179DC;
extern uint32_t off_1179E4;
extern uint32_t dword_1179F0;
extern uint32_t dword_1179EC;

// chip_type_read @ 0x117924, size 168 bytes
// Doc: sub_1217924 [mmio]: Misc register poke helper with shift mask
// sub_1217924 [mmio]: Misc register poke helper with shift mask
int  chip_type_read(int result)
{
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r3
  unsigned int v4; // r4

  v1 = *(uint32_t *)off_1179CC;
  if ( (*(uint32_t *)off_1179CC & 0x1000) != 0 )
  {
    result = reset_radio_core(result, *(uint32_t *)off_1179CC << 19);
    *(uint32_t *)off_1179E0 = 4096;
  }
  v2 = dword_1179D0;
  if ( (v1 & dword_1179D0) != 0 )
  {
    result = handle_rx_event();
    *(uint32_t *)off_1179E0 = v2;
  }
  if ( (dword_1179D4 & v1) != 0 && (*(uint32_t *)off_1179D8 & 0x300000) == 0 )
  {
    *(uint32_t *)off_1179E8 |= 0x200u;
    v3 = dword_1179DC & v1;
    if ( (dword_1179DC & v1) == 0 )
      return result;
  }
  else
  {
    v3 = dword_1179DC & v1;
    if ( (dword_1179DC & v1) == 0 )
      return result;
  }
  if ( (v1 & 0x80000) != 0 )
  {
LABEL_9:
    *(uint32_t *)off_1179E0 = 0x80000;
    return phy_radio_switch(5);
  }
  v4 = (uint8_t)(25 - __clz(v3));
  if ( **(int16_t **)off_1179E4 >= 0 || v4 <= 6 )
  {
    if ( v4 == 5 )
      goto LABEL_9;
  }
  else
  {
    mmio_clear_register(dword_1179F0, dword_1179EC, 2883);
  }
  *(uint32_t *)off_1179E0 = 1 << (v4 + 6);
  return phy_radio_switch(v4);
}

