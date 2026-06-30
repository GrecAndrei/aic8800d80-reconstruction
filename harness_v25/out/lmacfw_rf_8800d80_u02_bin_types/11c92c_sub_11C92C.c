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

extern uint32_t off_11C990;
extern uint32_t dword_11C994;
extern uint32_t off_11C998;
extern uint32_t dword_11C9A0;
extern uint32_t dword_11C99C;

// sub_11C92C @ 0x11c92c, size 98 bytes
int sub_11C92C()
{
  int v0; // r5
  int v1; // r4
  int v2; // r0

  v0 = *(uint32_t *)off_11C990;
  v1 = *((uint8_t *)off_11C990 + 10);
  if ( sub_11E34C(2) != 2 )
  {
    v2 = sub_11E34C(2);
    msg_parse(dword_11C994, v2);
  }
  if ( **(int16_t **)off_11C998 < 0 && sub_11E34C(2) != 2 )
    rf_cmd_send_n264(dword_11C9A0, dword_11C99C, 163);
  if ( (*(uint8_t *)(v0 + 6 * v1 + 3) & 1) == 0 )
    sub_11CBC8();
  sub_11E1E4(2);
  return 0;
}

