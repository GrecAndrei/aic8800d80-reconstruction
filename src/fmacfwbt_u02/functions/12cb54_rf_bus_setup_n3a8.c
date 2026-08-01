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

extern uint32_t off_12CBA8;

// bt_buf_alloc @ 0x12cb54, size 82 bytes
// Doc: message_dispatch_n_1c [ipc]: Dispatches messages comparing slot 0x24
// message_dispatch_n_1c [ipc]: Dispatches messages comparing slot 0x24
int  bt_buf_alloc(int16_t a1, int16_t a2, int16_t a3, unsigned int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = mem_alloc_align(a4 + 12);
  v9 = v8;
  if ( **(int16_t **)off_12CBA8 < 0 && !v8 )
    mmio_irq_clear(message_dispatch_n_4, message_dispatch_2, 145);
  *(uint16_t *)(v9 + 4) = a1;
  *(uint16_t *)(v9 + 6) = a2;
  *(uint16_t *)(v9 + 8) = a3;
  *(uint16_t *)(v9 + 10) = a4;
  *(uint32_t *)v9 = 0;
  memset_byte((int *)(v9 + 12), 0, a4);
  return v9 + 12;
}

