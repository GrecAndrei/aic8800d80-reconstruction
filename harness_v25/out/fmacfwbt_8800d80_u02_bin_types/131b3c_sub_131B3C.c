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

extern uint32_t off_131B84;
extern uint32_t dword_131B90;
extern uint32_t dword_131B8C;
extern uint32_t off_131B88;

// sub_131B3C @ 0x131b3c, size 70 bytes
// Doc: sub_1231B46 [unknown]: Helper wrapper saving r2 to r4 before tail call
// sub_1231B46 [unknown]: Helper wrapper saving r2 to r4 before tail call
int  sub_131B3C(int a1, int a2, unsigned int a3)
{
  int v4; // r1

  if ( **(int16_t **)off_131B84 < 0 && msg_get_value(a3) != 1 )
    sub_12F694(dword_131B90, dword_131B8C, 822);
  v4 = *((uint16_t *)off_131B88 + 4);
  if ( v4 != 255 )
    message_dispatch_n84(5146, v4, a3);
  rf_bus_mark_n_3b7(a3, 0);
  return 0;
}

