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

extern uint32_t off_123C78;
extern uint32_t off_123C7C;
extern uint32_t off_123C80;
extern uint32_t dword_123C88;
extern uint32_t dword_123C84;

// rf_init_subroutine @ 0x123bf4, size 130 bytes
// Doc: rf_init_subroutine [rf]: Call sub and branch on result == 3 (init/handshake check)
// rf_init_subroutine [rf]: Call sub and branch on result == 3 (init/handshake check)
int  rf_init_subroutine(int a1, uint8_t *a2, int a3, int a4)
{
  int v7; // r2
  uint16_t *v8; // r5
  int result; // r0

  if ( msg_get_value(a3) == 3 || msg_get_value(a3) == 4 )
    return 2;
  v7 = *a2;
  v8 = off_123C78;
  *((uint8_t *)off_123C78 + 31) = v7;
  if ( !v7 )
  {
    if ( msg_get_value(a3) != 2 )
    {
      mmio_init_reset();
LABEL_6:
      sub_12CA10(35, a4, a3);
      return 0;
    }
    return 2;
  }
  result = msg_get_value(a3);
  if ( !result )
  {
    if ( **(int16_t **)off_123C7C < 0 )
    {
      if ( *(uint32_t *)off_123C80 << 28 )
        sub_12F46C(dword_123C88, dword_123C84, 1522);
    }
    v8[9] = 0;
    goto LABEL_6;
  }
  if ( result != 2 )
  {
    sub_12B804(result);
    sub_12CD34(a3);
    return 2;
  }
  return result;
}

