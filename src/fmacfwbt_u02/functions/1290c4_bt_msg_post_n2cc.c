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

extern uint32_t off_12910C;
extern uint32_t off_129110;
extern uint32_t off_129114;
extern uint32_t off_129118;

// mm_beacon_irq @ 0x1290c4, size 72 bytes
// Doc: mm_beacon_irq [bt]: BT mailbox message post via shared data structure at 0x190d1c
// mm_beacon_irq [bt]: BT mailbox message post via shared data structure at 0x190d1c
void mm_beacon_irq()
{
  uint8_t *v0; // r5
  unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  void *v4; // r6
  int v5; // r0

  v0 = off_12910C;
  if ( !*((uint8_t *)off_12910C + 28) )
  {
    v1 = (unsigned int *)off_129110;
    v2 = *(uint32_t *)off_129110;
    v3 = *((uint32_t *)off_129114 + 2);
    *((uint8_t *)off_12910C + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = off_129118;
      do
      {
        if ( !*(uint8_t *)(v3 + 106) )
        {
          if ( *(uint8_t *)(v3 + 108) )
          {
            v5 = *(uint8_t *)(v3 + 116);
            if ( v5 != 255 && !ble_conn_get(v5, (int)v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(uint32_t *)v3;
      }
      while ( v3 );
    }
  }
}

