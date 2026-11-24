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


extern uint32_t off_12F058;

// msg_alloc_0x403 @ 0x12efe0, size 120 bytes
int  msg_alloc_0x403(int a1, uint32_t *a2, int a3, int a4)
{
  int *v5; // r0
  int *v6; // r5
  uint32_t *v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = (int *)ke_msg_alloc(1027, a4, a3, 8);
  v6 = v5;
  if ( (unsigned int)**(uint8_t **)off_12F058 - 1 <= 1 )
  {
    v10 = a2[1];
    v8 = *a2;
    *(uint64_t *)v5 = *(uint64_t *)a2;
    v9 = v10;
  }
  else
  {
    v7 = (uint32_t *)*a2;
    if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      mmio_write32((int)v7, a2[1], 1);
      v9 = mmio_read32(*a2, 1);
      v8 = *a2;
    }
    else
    {
      *v7 = a2[1];
      v8 = *a2;
      v9 = *(uint32_t *)*a2;
    }
    v6[1] = v9;
    v10 = a2[1];
    *v6 = v8;
  }
  event_dispatch("\x9D\x81DBG: Writing memory with 0x%08x / %d: [0x%08x] = 0x%08x / %d\n", v10, v10, v8, v9, v9);
  ke_msg_send_2((int)v6);
  return 0;
}
