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

extern uint32_t off_1319C0;
extern uint32_t dword_1319CC;
extern uint32_t dword_1319C8;
extern uint32_t off_1319C4;

// sub_131978 @ 0x131978, size 70 bytes
// Doc: me_chan_ctxt_update [mac]: Update MAC engine channel context fields
// me_chan_ctxt_update [mac]: Update MAC engine channel context fields
int  sub_131978(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_1319C0 < 0 && msg_get_value(a3) != 1 )
    sub_12F46C(dword_1319CC, dword_1319C8, 670);
  v4 = *((uint16_t *)off_1319C4 + 4);
  if ( v4 != 255 )
    sub_12CA10(5144, v4, a3);
  sub_12CD34(a3, 0);
  return 0;
}

