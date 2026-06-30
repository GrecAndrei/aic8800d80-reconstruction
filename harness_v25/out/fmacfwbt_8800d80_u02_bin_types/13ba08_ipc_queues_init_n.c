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

extern uint32_t dword_13BA9C;
extern uint32_t dword_13BAA0;
extern uint32_t dword_13BAA4;

// ipc_queues_init_n @ 0x13ba08, size 146 bytes
// Doc: ipc_queues_init_n [ipc]: Initialize three IPC/queue structures at offsets 0/8/0x10
// ipc_queues_init_n [ipc]: Initialize three IPC/queue structures at offsets 0/8/0x10
uint32_t *ipc_queues_init_n()
{
  uint32_t *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  uint32_t *result; // r0

  v0 = (uint32_t *)dword_13BA9C;
  bt_xtal_init_check((uint32_t *)dword_13BA9C);
  bt_xtal_init_check(v0 + 2);
  bt_xtal_init_check(v0 + 4);
  bt_xtal_init_check(v0 + 6);
  bt_xtal_init_check(v0 + 8);
  bt_xtal_init_check(v0 + 10);
  v1 = dword_13BAA0;
  v2 = dword_13BAA4;
  for ( i = 0; ; ++i )
  {
    *(uint8_t *)(v1 + 16) = -1;
    *(uint8_t *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    list_push_tail((int)v0, (uint32_t *)v1);
    rf_bus_mark_n_3b7((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(uint32_t *)(v1 + 28) = v2 + 268 * i;
  list_push_tail((int)(v0 + 6), (uint32_t *)v1);
  result = rf_bus_mark_n_3b7((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}

