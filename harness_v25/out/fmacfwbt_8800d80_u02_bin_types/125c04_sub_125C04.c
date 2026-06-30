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

extern uint32_t off_125C64;

// sub_125C04 @ 0x125c04, size 94 bytes
int  sub_125C04(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  int v5; // r6
  int v7; // r2
  int v8; // r3
  int v9; // r6
  int v10; // r2

  v4 = (int *)off_125C64;
  v5 = *(uint32_t *)off_125C64;
  message_dispatch_n84(64, *(uint16_t *)(*(uint32_t *)off_125C64 - 4), 0, a4);
  sub_125734(a1, *v4);
  v7 = *v4;
  *(uint8_t *)(a1 + 231) = 0;
  v8 = *(uint8_t *)(v7 + 10);
  *(uint8_t *)(a1 + 232) = v8;
  *(uint8_t *)(a1 + 233) = *(uint8_t *)(v7 + 11);
  v9 = v5 - 12;
  if ( v8 )
    *(uint8_t *)(a1 + 231) = *(uint8_t *)(*(uint32_t *)(*(uint32_t *)(a1 + 192) + 28) + v8) + 1;
  v10 = *((uint8_t *)v4 + 8);
  *((uint8_t *)v4 + 9) = 0;
  if ( v10 )
    rf_msg_process_body_n446();
  *v4 = 0;
  return j_buffer_pool_get(v9);
}

