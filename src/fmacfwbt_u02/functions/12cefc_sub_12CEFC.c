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

extern uint32_t dword_12CF54;

// list_process_count @ 0x12cefc, size 82 bytes
// Doc: message_dispatch_n38a [ipc]: Dispatch message slot 0x38a and tail-call handler
// message_dispatch_n38a [ipc]: Dispatch message slot 0x38a and tail-call handler
int  list_process_count(int a1, int *a2, int a3)
{
  int v3; // r3
  int v5; // r2
  int v6; // r4
  int v7; // r6
  int v8; // r5
  int result; // r0

  if ( !a3 )
    return 0;
  v3 = a3 - 1;
  v5 = *a2;
  while ( 1 )
  {
    v6 = *(uint16_t *)(v5 + 8 * v3);
    v7 = 8 * v3;
    v8 = v5 + 8 * v3--;
    if ( v6 == a1 )
      break;
    if ( v3 == -1 )
      return 0;
  }
  result = *(uint32_t *)(v8 + 4);
  if ( **(int16_t **)message_dispatch_n39c_cf50 < 0 && !result )
  {
    mmio_irq_clear(ipc_msg_dispatch, dword_12CF54, 239);
    return *(uint32_t *)(v7 + *a2 + 4);
  }
  return result;
}

