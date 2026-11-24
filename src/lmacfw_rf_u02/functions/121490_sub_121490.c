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

// rf_write_0x401 @ 0x121490, size 72 bytes
int  rf_write_0x401(int a1, uint32_t *a2, int a3, int a4)
{
  int v5; // r0
  int *v6; // r1
  int **v7; // r4
  int v8; // r3
  int v10; // r0

  v5 = ke_msg_send_1(1025, a4, a3, 8);
  v6 = (int *)*a2;
  v7 = (int **)v5;
  if ( ((*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v10 = critical_enter(*a2, 1);
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
  dispatch_event_handler_1("\x9D\x81DBG: Reading memory: [0x%08x] = 0x%08x / %d\n", v6, v8, v8);
  rx_irq_handler_1((int)v7);
  return 0;
}
