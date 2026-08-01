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

extern uint32_t off_12B4CC;
extern uint32_t off_12B4D0;

// bt_save_conn_info @ 0x12b49c, size 46 bytes
int  bt_save_conn_info(int a1)
{
  uint32_t *v1; // r6
  char *v2; // r4
  int result; // r0

  v1 = off_12B4CC;
  v2 = (char *)off_12B4D0;
  v1[1] = memmove(off_12B4D0, *(uint16_t *)(*(uint32_t *)off_12B4CC + 364));
  result = bt_get_link_state();
  *(uint32_t *)&v2[-8] = *(uint32_t *)&v2[-12] - 1 + *(uint16_t *)(a1 + 364);
  *((uint32_t *)v2 - 1) = 0;
  return result;
}

