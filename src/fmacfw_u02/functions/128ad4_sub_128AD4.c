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

extern uint32_t off_128B24;
extern uint32_t dword_128B28;

// sta_get_current @ 0x128ad4, size 80 bytes
int  sta_get_current(int a1)
{
  uint8_t *v1; // r6
  int v2; // r4
  uint8_t *v4; // r0

  v1 = (uint8_t *)off_128B24;
  v2 = dword_128B28 + 1320 * *((uint8_t *)off_128B24 + 16);
  if ( *(uint32_t *)(v2 + 72) )
  {
    sta_get_by_index(*((uint8_t *)off_128B24 + 16));
  }
  else
  {
    v4 = (uint8_t *)ke_msg_alloc(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(uint8_t *)(v2 + 107);
    ke_msg_send(v4);
  }
  return sta_lookup_by_bss(v1[16], a1);
}

