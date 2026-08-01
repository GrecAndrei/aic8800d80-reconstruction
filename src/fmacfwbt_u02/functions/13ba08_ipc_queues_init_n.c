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

// rf_init_queues @ 0x13ba08, size 146 bytes
// Doc: rf_init_queues [ipc]: Initialize three IPC/queue structures at offsets 0/8/0x10
// rf_init_queues [ipc]: Initialize three IPC/queue structures at offsets 0/8/0x10
uint32_t *rf_init_queues()
{
  uint32_t *v0; // r9
  int v1; // r5
  int v2; // r8
  unsigned int i; // r4
  uint32_t *result; // r0

  v0 = (uint32_t *)dword_13BA9C;
  zero_struct((uint32_t *)dword_13BA9C);
  zero_struct(v0 + 2);
  zero_struct(v0 + 4);
  zero_struct(v0 + 6);
  zero_struct(v0 + 8);
  zero_struct(v0 + 10);
  v1 = dword_13BAA0;
  v2 = dword_13BAA4;
  for ( i = 0; ; ++i )
  {
    *(uint8_t *)(v1 + 16) = -1;
    *(uint8_t *)(v1 + 26) = i;
    if ( i > 0xF )
      break;
    check_abort_flag((int)v0, (uint32_t *)v1);
    hci_cmd_send((i << 8) & 0xFF00 | 8, 0);
LABEL_3:
    v1 += 32;
  }
  *(uint32_t *)(v1 + 28) = v2 + 268 * i;
  check_abort_flag((int)(v0 + 6), (uint32_t *)v1);
  result = hci_cmd_send((i << 8) & 0xFF00 | 8, 0);
  if ( i != 31 )
    goto LABEL_3;
  return result;
}

