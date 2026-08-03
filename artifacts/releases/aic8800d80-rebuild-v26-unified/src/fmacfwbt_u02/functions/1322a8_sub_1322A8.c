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

extern uint32_t dword_1322E8;

// sub_1322A8 @ 0x1322a8, size 62 bytes
int  sub_1322A8(int a1, uint8_t *a2)
{
  int v2; // r6
  int v4; // r0

  v2 = dword_1322E8;
  timestamp_remove_058(696 * *a2 + 672 + dword_1322E8);
  v4 = *a2;
  if ( *(uint8_t *)(v2 + 696 * v4 + 37) )
    ipc_msg_alloc_init(v4);
  else
    message_dispatch_n84(5130, 13, 5);
  return 0;
}

