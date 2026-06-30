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

extern uint32_t dword_11C918;
extern uint32_t off_11C91C;
extern uint32_t dword_11C928;
extern uint32_t dword_11C924;
extern uint32_t off_11C920;

// rf_chan_set_n1cc @ 0x11c88c, size 138 bytes
// Doc: rf_chan_set_n1cc [rf]: Set RF channel via 0x11e34c, validate result==3
// rf_chan_set_n1cc [rf]: Set RF channel via 0x11e34c, validate result==3
int rf_chan_set_n1cc()
{
  int v0; // r0
  uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( sub_11E34C(2) != 3 )
  {
    v0 = sub_11E34C(2);
    msg_parse(dword_11C918, v0);
  }
  if ( **(int16_t **)off_11C91C < 0 && sub_11E34C(2) != 3 )
    rf_cmd_send_n264(dword_11C928, dword_11C924, 201);
  v1 = off_11C920;
  v2 = *(uint32_t *)off_11C920;
  v3 = *(uint8_t *)(*(uint32_t *)off_11C920 + 367);
  v4 = (uint8_t)(*((uint8_t *)off_11C920 + 10) + 1);
  *((uint8_t *)off_11C920 + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    sub_11DEE8(v2 - 12);
    v5 = *((uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      sub_11CD0C(0, v5);
      v1[11] = 0;
    }
    else
    {
      sub_11DED8(2050, v5, 2);
    }
    sub_11E1E4(2);
    return 0;
  }
  else
  {
    sub_11CAC8();
    return 0;
  }
}

