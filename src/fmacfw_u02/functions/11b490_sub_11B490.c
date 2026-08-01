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

extern uint32_t off_11B55C;
extern uint32_t off_11B560;
extern uint32_t off_11B564;
extern uint32_t dword_11B570;
extern uint32_t dword_11B574;
extern uint32_t dword_11B56C;
extern uint32_t dword_11B568;

// get_phy_status @ 0x11b490, size 204 bytes
int  get_phy_status(int result, int a2, int a3, int a4)
{
  uint32_t *v4; // r5
  char *v5; // r3
  int v6; // r2
  int v7; // r4
  int v8; // r6
  BOOL v9; // r3
  int16_t **v10; // r7

  v4 = off_11B55C;
  if ( *((uint8_t *)off_11B55C + 160) )
  {
    v5 = (char *)off_11B55C + 28 * result;
    v6 = *((uint32_t *)v5 + 6);
    v5[47] = 1;
    v7 = result;
    v8 = 8 * result;
    if ( !v6 )
    {
      switch ( (char)result )
      {
        case 0:
          v9 = (*(uint32_t *)off_11B560 & 0x30) == 0;
          goto LABEL_6;
        case 1:
          v9 = (*(uint32_t *)off_11B560 & 0x300) == 0;
          goto LABEL_6;
        case 2:
          v9 = (*(uint32_t *)off_11B560 & 0x3000) == 0;
          goto LABEL_6;
        case 3:
          v9 = (*(uint32_t *)off_11B560 & 0x30000) == 0;
          goto LABEL_6;
        case 4:
          v9 = (*(uint32_t *)off_11B560 & 3) == 0;
LABEL_6:
          if ( v9 )
            goto LABEL_9;
          v10 = (int16_t **)off_11B564;
          break;
        default:
          v10 = (int16_t **)off_11B564;
          if ( **(int16_t **)off_11B564 >= 0 )
            goto LABEL_9;
          mmio_clear_register(dword_11B570, dword_11B574, 520);
          break;
      }
      if ( **v10 < 0 )
      {
        return bad_func_0x12f408(dword_11B570, dword_11B56C, 684, a4);
      }
      else
      {
LABEL_9:
        v4[v8 - v7 + 6] = dword_11B568;
        return invalid_handler(v7);
      }
    }
  }
  return result;
}

