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

extern uint32_t dword_11CA24;
extern uint32_t dword_11CA20;
extern uint32_t off_11CA28;
extern uint32_t dword_11CA34;
extern uint32_t dword_11CA30;
extern uint32_t off_11CA2C;

// sub_11C9A4 @ 0x11c9a4, size 124 bytes
int  sub_11C9A4(int a1, int a2, int a3, int a4)
{
  int16_t v4; // r6
  uint8_t *v6; // r4
  int v7; // r0
  uint8_t *v8; // r2

  v4 = a4;
  v6 = (uint8_t *)rf_setup_dispatch(2049, a4, a3, 1);
  v7 = sub_11E34C(2);
  sub_11F74C(4, dword_11CA24, dword_11CA20, v7);
  if ( sub_11E34C(2) )
  {
    *v6 = 8;
    sub_11DE50(v6);
    return 0;
  }
  else
  {
    if ( **(int16_t **)off_11CA28 < 0 && !*(uint8_t *)(a2 + 367) )
      rf_cmd_send_n264(dword_11CA34, dword_11CA30, 73);
    v8 = off_11CA2C;
    *v6 = 0;
    *(uint32_t *)v8 = a2;
    v8[10] = 0;
    *((uint16_t *)v8 + 4) = v4;
    rf_pwr_tbl_init_n0c8(a2);
    sub_11DE50(v6);
    return 1;
  }
}

