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

extern uint32_t off_1280C4;
extern uint32_t dword_1280B0;
extern uint32_t dword_1280C0;
extern uint32_t dword_1280B8;
extern uint32_t dword_1280BC;
extern uint32_t dword_1280B4;

// bt_msg_handler_dispatch @ 0x128024, size 138 bytes
// Doc: bt_msg_handler_dispatch [bt]: BT message handler dispatch computing index*7 from global state
// bt_msg_handler_dispatch [bt]: BT message handler dispatch computing index*7 from global state
int * bt_msg_handler_dispatch(int a1)
{
  int16_t **v1; // r8
  int v2; // r5
  int *v4; // r6
  int v5; // r7
  int v6; // r4
  int *result; // r0

  v1 = (int16_t **)off_1280C4;
  v2 = dword_1280B0;
  v4 = (int *)(dword_1280B0 + 28 * a1);
  if ( **(int16_t **)off_1280C4 < 0 )
  {
    v5 = 8 * a1;
    if ( *(uint8_t *)(dword_1280B0 + 28 * a1 + 24) != 255
      || (sub_12F694(dword_1280C0, dword_1280B8, 3044), **v1 < 0) )
    {
      if ( *(uint8_t *)(v2 + 4 * (v5 - a1) + 25) )
        sub_12F694(dword_1280BC, dword_1280B8, 3046);
    }
  }
  else
  {
    v5 = 8 * a1;
  }
  list_push_tail(dword_1280B4);
  v6 = v2 + 4 * (v5 - a1);
  result = memset_thunk(v4, 0, 0x1Cu);
  *(uint16_t *)(v6 + 14) = 255;
  *(uint8_t *)(v6 + 24) = -1;
  *(uint8_t *)(v6 + 27) = -1;
  return result;
}

