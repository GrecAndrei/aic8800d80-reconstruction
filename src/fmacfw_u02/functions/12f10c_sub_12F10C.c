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

// msg_alloc_0x40e @ 0x12f10c, size 116 bytes
int  msg_alloc_0x40e(int a1, int *a2, int16_t a3, int16_t a4)
{
  int v5; // r0
  int v6; // r3
  uint32_t *v7; // r4
  int v9; // r5

  v5 = ke_msg_alloc(1038, a4, a3, 4u);
  v6 = a2[1];
  v7 = (uint32_t *)v5;
  switch ( v6 )
  {
    case 1:
      event_dispatch(loc_12F18C, *(uint32_t *)(*a2 + 4));
      break;
    case 2:
      event_dispatch(loc_12F190, *a2);
      break;
    case 3:
      v9 = *a2;
      event_dispatch(loc_12F188, v9);
      if ( !v9 )
        log_flush();
      ke_task_create(1068, 1, v9 << 10);
      break;
    default:
      event_dispatch(weird_sp_sequence);
      break;
  }
  *v7 = (uint8_t)call_hook_1();
  event_dispatch(loc_12F184);
  ke_msg_send((int)v7);
  return 0;
}

