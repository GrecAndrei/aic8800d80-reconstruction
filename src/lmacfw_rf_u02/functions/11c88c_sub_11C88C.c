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

// ke_timer_check @ 0x11c88c, size 138 bytes
int ke_timer_check()
{
  int v0; // r0
  uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( flash_write_byte(2) != 3 )
  {
    v0 = flash_write_byte(2);
    dispatch_event_handler(dword_11C918, v0);
  }
  if ( **(int16_t **)off_11C91C < 0 && flash_write_byte(2) != 3 )
    flash_ctrl_init(dword_11C928, dword_11C924, 201);
  v1 = off_11C920;
  v2 = *(uint32_t *)off_11C920;
  v3 = *(uint8_t *)(*(uint32_t *)off_11C920 + 367);
  v4 = (uint8_t)(*((uint8_t *)off_11C920 + 10) + 1);
  *((uint8_t *)off_11C920 + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    isr_forward(v2 - 12);
    v5 = *((uint16_t *)v1 + 4);
    if ( v1[11] )
    {
      tx_buf_alloc(0, v5);
      v1[11] = 0;
    }
    else
    {
      ke_evt_handler(2050, v5, 2);
    }
    flash_erase_sector(2);
    return 0;
  }
  else
  {
    queue_remove();
    return 0;
  }
}

