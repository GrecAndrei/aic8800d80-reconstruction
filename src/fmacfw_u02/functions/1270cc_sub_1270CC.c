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

extern uint32_t off_12715C;
extern uint32_t off_127160;
extern uint32_t off_127164;
extern uint32_t off_127168;
extern uint32_t dword_12716C;

// ctrl_register_handler @ 0x1270cc, size 144 bytes
// Doc: sub_12270CC [unknown]: Load pointer from table and access field at offset 0x2c
// sub_12270CC [unknown]: Load pointer from table and access field at offset 0x2c
int  ctrl_register_handler(int result)
{
  uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  uint8_t *v4; // r0
  int *v5; // r6
  int v6; // r3
  int v7; // r2
  uint32_t *v8; // r0

  v1 = off_12715C;
  v2 = result;
  if ( *((uint32_t *)off_12715C + 11) )
  {
    *((uint32_t *)off_12715C + 11) = result;
  }
  else
  {
    v3 = *((uint32_t *)off_12715C + 10);
    if ( v3 == result )
    {
      *(uint8_t *)(v3 + 16) = 4;
    }
    else
    {
      if ( v3 && *(uint8_t *)(v3 + 24) != 3 )
      {
        v4 = (uint8_t *)ke_msg_alloc(69, 13, 0, 1);
        *v4 = *(uint8_t *)(v3 + 24);
        ke_msg_send(v4);
      }
      if ( *((int *)off_127160 + 1) > 0 )
      {
        if ( (__get_CPSR() & 1) == 0 )
        {
          __disable_irq();
          *(uint32_t *)off_127164 = 1;
        }
        v5 = (int *)off_127168;
        ++*(uint32_t *)off_127168;
        mmio_set_bit(4);
        phy_band_validate(4);
        if ( *v5 )
        {
          v6 = *v5 - 1;
          v7 = *(uint32_t *)off_127164;
          *v5 = v6;
          if ( !v6 )
          {
            if ( v7 )
              __enable_irq();
          }
        }
      }
      v1[11] = v2;
      *(uint8_t *)(v2 + 16) = 2;
      v8 = (uint32_t *)ke_msg_alloc(140, 0, 255, 4);
      *v8 = dword_12716C;
      return ke_msg_send(v8);
    }
  }
  return result;
}

