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
extern uint32_t dword_12F05C;

// msg_alloc_0x403 @ 0x12efe0, size 120 bytes
// Doc: sub_122EFE0 [ipc]: Host message send wrapper invoking message dispatch
// sub_122EFE0 [ipc]: Host message send wrapper invoking message dispatch
int  msg_alloc_0x403(int a1, int *a2, int16_t a3, int16_t a4)
{
  int *v5; // r0
  int *v6; // r5
  uint32_t *v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = (int *)ke_msg_alloc(1027, a4, a3, 8u);
  v6 = v5;
  if ( (unsigned int)**(uint8_t **)off_12F058 - 1 <= 1 )
  {
    v10 = a2[1];
    *(uint64_t *)v5 = *(uint64_t *)a2;
  }
  else
  {
    v7 = (uint32_t *)*a2;
    if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
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
  event_dispatch(dword_12F05C, v10);
  ke_msg_send((int)v6);
  return 0;
}

