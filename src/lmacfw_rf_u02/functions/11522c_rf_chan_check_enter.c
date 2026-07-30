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

extern uint32_t off_1152B4;
extern uint32_t dword_1152B0;
extern uint32_t off_1152B8;
extern uint32_t off_1152BC;
extern uint32_t dword_1152C0;
extern uint32_t dword_1152C4;
extern uint32_t off_1152C8;

// rf_chan_check_enter @ 0x11522c, size 132 bytes
// Doc: rf_chan_check_enter [rf]: Checks RF channel/state flag and enters RF path
// rf_chan_check_enter [rf]: Checks RF channel/state flag and enters RF path
int rf_chan_check_enter()
{
  int **v0; // r5
  uint32_t *v1; // r6
  int *v2; // r0
  void *v3; // r9
  int v4; // r8
  uint16_t v5; // r10
  int result; // r0

  v0 = (int **)off_1152B4;
  sub_11E71C(dword_1152B0);
  if ( **(int16_t **)off_1152B8 < 0 )
  {
    v2 = *v0;
    v1 = off_1152BC;
    if ( !*v0 || !*(uint32_t *)off_1152BC )
    {
      rf_cmd_send_n264(dword_1152C0, dword_1152C4, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_1152BC;
    v2 = *v0;
  }
  v3 = off_1152C8;
  v4 = dword_1152B0;
  sub_100200(v2, 0, 44 * *(uint16_t *)(*(uint32_t *)off_1152C8 + 8) + 44);
  v5 = 0;
  do
  {
    (*v0)[11 * v5 + 8] = *v1 + 76 * v5;
    result = list_push_tail(v4);
    ++v5;
  }
  while ( *(uint16_t *)(*(uint32_t *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

