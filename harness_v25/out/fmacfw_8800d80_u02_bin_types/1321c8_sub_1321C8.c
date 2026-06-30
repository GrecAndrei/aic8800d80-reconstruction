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

extern uint32_t dword_1321F8;

// sub_1321C8 @ 0x1321c8, size 46 bytes
int sub_1321C8()
{
  uint32_t *v0; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0
  int v4; // r0

  memset_thunk((int *)dword_1321F8, 0, 0x17Cu);
  v0 = sub_12CD34(5u, 0);
  v1 = ipc_msgbuf_alloc_init(v0);
  v2 = rf_bus_setup_n350(v1);
  v3 = sub_134434(v2);
  v4 = sub_13B96C(v3);
  return fw_init_post_handler(v4);
}

