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

extern uint32_t off_1366F8;
extern uint32_t off_1366FC;

// bt_link_active @ 0x1366b0, size 72 bytes
// Doc: sub_12366B8 [unknown]: Checks byte at offset 0x19c == 1; processes r6 byte at offset 0xd
// sub_12366B8 [unknown]: Checks byte at offset 0x19c == 1; processes r6 byte at offset 0xd
uint32_t * bt_link_active(uint32_t *result)
{
  uint32_t *v1; // r4
  uint32_t *v2; // r6
  int v3; // r3
  int v4; // r1

  if ( *((uint8_t *)result + 108) )
  {
    v1 = result;
    if ( *((uint8_t *)result + 412) == 1 )
    {
      v2 = off_1366F8;
      if ( *((uint8_t *)off_1366F8 + 13) )
      {
        *((uint8_t *)off_1366F8 + 13) = 0;
        return rf_config();
      }
      else
      {
        bt_init();
        v3 = v2[4];
        v4 = *((uint32_t *)off_1366FC + 4);
        *((uint8_t *)v2 + 13) = 1;
        v2[7] = v1;
        return (uint32_t *)unknown_worker((int)(v2 + 5), v4 + v3);
      }
    }
  }
  return result;
}

