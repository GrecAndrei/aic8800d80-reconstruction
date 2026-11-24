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


extern uint32_t off_124C58;
extern uint32_t off_124C5C;
extern uint32_t off_124C60;

// set_adv_type @ 0x124b04, size 338 bytes
int  set_adv_type(int a1, int a2)
{
  uint8_t v3; // r0
  unsigned int v4; // r4
  int v5; // r3
  int *v6; // r1
  unsigned int v8; // r5
  uint64_t result; // [sp+4h] [bp-18h] BYREF
  char v10; // [sp+Ch] [bp-10h] BYREF
  uint8_t a4[5]; // [sp+Dh] [bp-Fh]
  uint16_t v12; // [sp+12h] [bp-Ah]
  char v13; // [sp+16h] [bp-6h]

  v3 = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0xAu);
  if ( a1 <= 1 || (v4 = v3) == 0 )
  {
    dispatch_event_handler_1(asc_130184);
    return -1;
  }
  *(uint32_t *)off_124C58 |= 0x500000u;
  mac_time_get(&result, 0);
  if ( v4 <= 0x23 )
  {
    v5 = BYTE1(result);
    v10 = 0;
    a4[0] = BYTE1(result);
    if ( v4 > 0xD )
    {
      if ( v4 != 14 )
      {
        dispatch_event_handler_1("Not supported chan: %d\n", v4);
        return -2;
      }
      *(uint16_t *)&a4[3] = 2484;
      v12 = 0;
      v13 = 0;
      if ( !BYTE1(result) )
        goto LABEL_6;
LABEL_13:
      v8 = WORD1(result);
      if ( v5 == 1 )
      {
        if ( v8 < WORD2(result) )
          goto LABEL_21;
      }
      else
      {
        if ( v5 != 2 )
          goto LABEL_7;
        if ( (int)(v8 + 20) < WORD2(result) )
        {
          *(uint16_t *)&a4[1] = *(uint16_t *)&a4[3] - 30;
          goto LABEL_7;
        }
        if ( v8 < WORD2(result) )
        {
LABEL_21:
          *(uint16_t *)&a4[1] = *(uint16_t *)&a4[3] - 10;
          goto LABEL_7;
        }
        if ( WORD2(result) < (int)(v8 - 19) )
        {
          *(uint16_t *)&a4[1] = *(uint16_t *)&a4[3] + 30;
          goto LABEL_7;
        }
      }
      *(uint16_t *)&a4[1] = *(uint16_t *)&a4[3] + 10;
      goto LABEL_7;
    }
    *(uint16_t *)&a4[3] = 5 * v4 + 2407;
  }
  else
  {
    v5 = BYTE1(result);
    *(uint16_t *)&a4[3] = 5 * v4 + 5000;
    v10 = 1;
    a4[0] = BYTE1(result);
  }
  v12 = 0;
  v13 = 0;
  if ( v5 )
    goto LABEL_13;
LABEL_6:
  *(uint16_t *)&a4[1] = *(uint16_t *)&a4[3];
LABEL_7:
  *(uint8_t *)off_124C5C = 1;
  rx_process_pending(0, (int)&v10);
  v6 = (int *)off_124C60;
  *(uint32_t *)off_124C58 &= 0xFF87FFFF;
  if ( *v6 )
    init_with_stack(*v6);
  dispatch_event_handler_1("\x9A\x88Chan %d, Freq. %d, BW %d\n", v4, *(uint16_t *)&a4[3], a4[0]);
  return 0;
}
