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

extern uint32_t dword_11C884;
extern uint32_t dword_11C880;
extern uint32_t off_11C888;

// ke_timer_register @ 0x11c850, size 48 bytes
// Doc: sub_121C850 [mmio]: Allocate LMAC object via helper and stash return in r4
// sub_121C850 [mmio]: Allocate LMAC object via helper and stash return in r4
int  ke_timer_register(int a1, int a2, int a3, int a4)
{
  int v5; // r4

  v5 = flash_write_byte(2);
  check_interrupt_flag(4, dword_11C884, dword_11C880, v5);
  if ( v5 )
    *((uint8_t *)off_11C888 + 11) = 1;
  else
    tx_buf_alloc(1, a4);
  return 0;
}

