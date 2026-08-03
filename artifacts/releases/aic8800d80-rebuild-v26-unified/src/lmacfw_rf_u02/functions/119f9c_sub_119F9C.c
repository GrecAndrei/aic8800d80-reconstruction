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

extern uint32_t off_11A020;
extern uint32_t off_11A024;
extern uint32_t off_11A028;
extern uint32_t dword_11A030;
extern uint32_t dword_11A02C;

// sub_119F9C @ 0x119f9c, size 130 bytes
int  sub_119F9C(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r2
  uint16_t *v8; // r5
  int result; // r0

  if ( sub_11E34C(a3) == 3 || sub_11E34C(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = off_11A020;
  *((uint8_t *)off_11A020 + 28) = v7;
  if ( !v7 )
  {
    if ( sub_11E34C(a3) != 2 )
    {
      mmio_init_clock_gate_n121();
LABEL_6:
      sub_11DED8(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = sub_11E34C(a3);
  if ( !result )
  {
    if ( **(int16_t **)off_11A024 < 0 )
    {
      if ( *(uint32_t *)off_11A028 << 28 )
        rf_cmd_send_n264(dword_11A030, dword_11A02C, 1522);
    }
    v8[8] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    sub_11D01C();
    sub_11E1E4(a3);
    return 2;
  }
  return result;
}

