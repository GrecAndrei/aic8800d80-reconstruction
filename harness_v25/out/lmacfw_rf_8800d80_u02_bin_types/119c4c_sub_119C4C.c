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

extern uint32_t off_119D04;
extern uint32_t dword_119D14;
extern uint32_t dword_119D0C;
extern uint32_t dword_119D10;
extern uint32_t off_119D08;

// sub_119C4C @ 0x119c4c, size 184 bytes
int  sub_119C4C(int a1, char *a2, int a3, int a4)
{
  uint8_t *v5; // r0
  int16_t **v6; // r6
  uint8_t *v7; // r5
  int v8; // r3

  v5 = (uint8_t *)rf_setup_dispatch(37, a4, a3, 2);
  v6 = (int16_t **)off_119D04;
  *v5 = 1;
  v7 = v5;
  if ( **v6 < 0 )
  {
    if ( (uint8_t)*a2 <= 3u || (rf_cmd_send_n264(dword_119D14, dword_119D0C, 1725), **v6 < 0) )
    {
      if ( (uint8_t)a2[4] > 0x20u )
        rf_cmd_send_n264(dword_119D10, dword_119D0C, 1726);
    }
  }
  switch ( a2[40] )
  {
    case 0:
    case 1:
    case 3:
      v8 = (*(uint32_t *)off_119D08 >> 6) & 1;
      goto LABEL_4;
    case 2:
    case 8:
      v8 = (*(uint32_t *)off_119D08 >> 7) & 1;
      goto LABEL_4;
    case 4:
      v8 = (*(uint32_t *)off_119D08 >> 13) & 1;
      goto LABEL_4;
    case 6:
    case 7:
      v8 = (*(uint32_t *)off_119D08 >> 9) & 1;
LABEL_4:
      if ( v8 && (uint8_t)a2[4] <= 0x20u && (uint8_t)*a2 <= 3u )
      {
        v7[1] = sub_118A60(a2);
        *v7 = 0;
      }
      break;
    default:
      break;
  }
  sub_11DE50(v7);
  return 0;
}

