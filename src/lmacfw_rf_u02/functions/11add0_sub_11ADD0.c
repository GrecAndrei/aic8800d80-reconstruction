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

extern uint32_t off_11AE1C;
extern uint32_t dword_11AE20;

// list_search @ 0x11add0, size 76 bytes
// Doc: sub_121ADD0 [util]: Lookup/validate state entry against stored pointer
// sub_121ADD0 [util]: Lookup/validate state entry against stored pointer
int  list_search(int result)
{
  uint32_t *v1; // r6
  int v2; // r5
  int v3; // r4
  uint8_t *v4; // r0
  uint32_t *v5; // r0

  v1 = off_11AE1C;
  v2 = *((uint32_t *)off_11AE1C + 10);
  if ( v2 == result )
  {
    *(uint8_t *)(v2 + 16) = 4;
  }
  else
  {
    v3 = result;
    if ( v2 )
    {
      if ( *(uint8_t *)(v2 + 24) != 3 )
      {
        v4 = (uint8_t *)ke_msg_send(69, 4, 0, 1);
        *v4 = *(uint8_t *)(v2 + 24);
        rx_irq_handler(v4);
      }
    }
    v1[11] = v3;
    *(uint8_t *)(v3 + 16) = 2;
    v5 = (uint32_t *)ke_msg_send(140, 0, 255, 4);
    *v5 = dword_11AE20;
    return rx_irq_handler(v5);
  }
  return result;
}

