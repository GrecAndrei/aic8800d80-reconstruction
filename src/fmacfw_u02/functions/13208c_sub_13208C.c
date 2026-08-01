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

extern uint32_t dword_1320CC;

// bt_get_conn_by_idx @ 0x13208c, size 62 bytes
int  bt_get_conn_by_idx(int a1, uint8_t *a2)
{
  int v2; // r6
  int v4; // r0

  v2 = dword_1320CC;
  fault_handler(696 * *a2 + 672 + dword_1320CC);
  v4 = *a2;
  if ( *(uint8_t *)(v2 + 696 * v4 + 37) )
    ke_buf_alloc(v4);
  else
    ke_msg_send_no_param(5130, 13, 5);
  return 0;
}

