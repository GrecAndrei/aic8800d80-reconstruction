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

extern uint32_t dword_12C7F0;

// event_queue_push @ 0x12c73c, size 152 bytes
// Doc: message_dispatch_n_24a [ipc]: Dispatch message using sign-bit shift lookup
// message_dispatch_n_24a [ipc]: Dispatch message using sign-bit shift lookup
int  event_queue_push(int result, int a2)
{
  int *v2; // r5
  uint32_t *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r3
  int v7; // r2
  int v8; // r7
  int v9; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)message_dispatch_n_1b8 = 1;
  }
  v2 = (int *)sdio_buffer_prepare_n1c6_c7d8;
  v3 = message_dispatch_n_1b0;
  v4 = *((uint32_t *)message_dispatch_n_1b0 + 5);
  v5 = *(uint32_t *)sdio_buffer_prepare_n1c6_c7d8 + 1;
  *(uint32_t *)sdio_buffer_prepare_n1c6_c7d8 = v5;
  if ( v4 )
  {
    if ( *(uint16_t *)(v4 + 4) == result && *(uint16_t *)(v4 + 6) == a2 )
    {
      rf_bus_mark_n100_d2d0(v3 + 5);
      v8 = v3[5];
      v9 = (int)(v3 + 8);
      if ( v8 )
      {
        timestamp_update(v9, *(uint32_t *)(v8 + 8));
        if ( **(int16_t **)message_dispatch_n_1a4 < 0
          && *(uint32_t *)(v8 + 8) - *((uint32_t *)message_dispatch_n_1a0 + 4) < 0 )
        {
          sub_12F46C(message_dispatch_n_198, dword_12C7F0, 232);
        }
      }
      else
      {
        timestamp_remove(v9);
      }
    }
    else
    {
      result = list_find_remove_ca3c(message_dispatch_n_1a8, message_dispatch_n_1ac, a2 | (result << 16));
      v4 = result;
      if ( !result )
      {
        v5 = *v2;
        goto LABEL_8;
      }
    }
    result = sub_12CBC8(v4);
    v5 = *v2;
  }
LABEL_8:
  if ( v5 )
  {
    v6 = v5 - 1;
    v7 = *(uint32_t *)message_dispatch_n_1b8;
    *v2 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

