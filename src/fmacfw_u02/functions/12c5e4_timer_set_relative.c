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

extern uint32_t off_12C730;
extern uint32_t dword_12C728;
extern uint32_t dword_12C708;
extern uint32_t dword_12C714;

// ke_task_create @ 0x12c5e4, size 288 bytes
// Doc: message_dispatch_n_382 [ipc]: Dispatch message with index increment and handler resolve (variant 382)
// message_dispatch_n_382 [ipc]: Dispatch message with index increment and handler resolve (variant 382)
int  ke_task_create(int a1, int a2, unsigned int a3)
{
  int16_t **v3; // r11
  int *v7; // r8
  uint32_t *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (int16_t **)off_12C730;
  if ( **(int16_t **)off_12C730 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > ipc_message_dispatch )
        mmio_clear_register(message_dispatch_n_268, message_dispatch_n_26c, 148);
    }
    else
    {
      mmio_clear_register(dword_12C728, message_dispatch_n_26c, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)message_dispatch_n_288 = 1;
  }
  v7 = (int *)message_dispatch_n_258;
  v8 = msg_dispatch_322;
  v9 = *((uint32_t *)msg_dispatch_322 + 5);
  ++*(uint32_t *)message_dispatch_n_258;
  if ( v9 )
    v9 = *(uint16_t *)(v9 + 4) == a1 && *(uint16_t *)(v9 + 6) == a2;
  v10 = pkt_word_get(message_dispatch_n_280, dword_12C708, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = pkt_buf_alloc(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      mmio_clear_register(message_dispatch_n_260, message_dispatch_n_26c, 165);
    *(uint16_t *)(v10 + 4) = a1;
    *(uint16_t *)(v10 + 6) = a2;
  }
  v11 = dword_12C714;
  v12 = message_dispatch_n_280;
  v13 = a3 + *((uint32_t *)message_dispatch_n_27c + 4);
  *(uint32_t *)(v10 + 8) = v13;
  result = list_process(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto message_dispatch_n_330;
LABEL_15:
    result = unknown_worker(message_dispatch_n_274, *(uint32_t *)(v10 + 8));
    goto message_dispatch_n_330;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
message_dispatch_n_330:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(uint32_t *)message_dispatch_n_288, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((uint32_t *)message_dispatch_n_27c + 4)) < 0 )
      return unknown_func_12d104(0x10000000);
  }
  else if ( (int)(v13 - *((uint32_t *)message_dispatch_n_27c + 4)) < 0 )
  {
    return unknown_func_12d104(0x10000000);
  }
  return result;
}

