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

// msg_alloc_401 @ 0x12f154, size 72 bytes
int  msg_alloc_401(int a1, uint32_t *a2, int a3, int a4)
{
  int v5; // r0
  int *v6; // r1
  int **v7; // r4
  int v8; // r3
  int v10; // r0

  v5 = bt_buf_alloc(1025, a4, a3, 8);
  v6 = (int *)*a2;
  v7 = (int **)v5;
  if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v10 = atomic_reg_read(*a2, 1);
    v6 = (int *)*a2;
    v7[1] = (int *)v10;
    v8 = v10;
  }
  else
  {
    v8 = *v6;
    *(uint32_t *)(v5 + 4) = *v6;
  }
  *v7 = v6;
  ke_event_schedule_1("\x9D\x81DBG: Reading memory: [0x%08x] = 0x%08x / %d\n", v6, v8, v8);
  hci_evt_send((int)v7);
  return 0;
}
