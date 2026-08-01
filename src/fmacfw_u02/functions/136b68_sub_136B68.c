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

extern uint32_t dword_136BCC;

// tx_handle_pending_flag @ 0x136b68, size 100 bytes
int  tx_handle_pending_flag(int result, int a2)
{
  int v3; // r3
  int v4; // r0

  if ( (*(uint16_t *)(result + 30) & 0x1000) != 0 )
  {
    v3 = *(uint8_t *)(a2 + 310);
    if ( ((uint8_t)v3 & *(uint8_t *)(dword_136BCC + *(uint8_t *)(result + 27))) != 0 )
    {
      if ( (*(uint8_t *)(a2 + 53) & 8) == 0 )
      {
        *(uint8_t *)(a2 + 53) |= 8u;
        if ( v3 == 15 )
          goto LABEL_5;
      }
    }
    else if ( (*(uint8_t *)(a2 + 53) & 2) == 0 )
    {
      *(uint8_t *)(a2 + 53) |= 2u;
LABEL_5:
      v4 = ke_msg_alloc(65, 0, 5, 4u);
      *(uint16_t *)v4 = *(uint16_t *)(a2 + 32);
      *(uint8_t *)(v4 + 3) = *(uint8_t *)(a2 + 34);
      *(uint8_t *)(v4 + 2) = 1;
      return ke_msg_send(v4);
    }
  }
  return result;
}

