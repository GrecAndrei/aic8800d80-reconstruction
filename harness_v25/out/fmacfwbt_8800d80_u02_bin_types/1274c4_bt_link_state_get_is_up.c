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

extern uint32_t off_12754C;
extern uint32_t off_127550;
extern uint32_t dword_127560;
extern uint32_t dword_12755C;
extern uint32_t dword_127554;
extern uint32_t dword_127564;
extern uint32_t dword_127558;

// bt_link_state_get_is_up @ 0x1274c4, size 134 bytes
// Doc: bt_link_state_get_is_up [bt]: Read BT link state flag and return bit 0 (link up status)
// bt_link_state_get_is_up [bt]: Read BT link state flag and return bit 0 (link up status)
int bt_link_state_get_is_up()
{
  uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_12754C;
  v1 = *((uint8_t *)off_12754C + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(int16_t **)off_127550 < 0 && (v1 & 4) != 0 )
    {
      sub_12F694(dword_127560, dword_12755C, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return rf_init_or_attach_n488(dword_127554);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(int16_t **)off_127550 < 0 && (v1 & 8) != 0 )
    {
      sub_12F694(dword_127564, dword_12755C, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return rf_init_or_attach_n488(dword_127558);
  }
  return result;
}

