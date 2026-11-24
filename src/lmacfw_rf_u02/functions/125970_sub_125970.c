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


extern uint32_t off_125A98;
extern uint32_t off_125AA0;
extern uint32_t off_125AA4;

// process_bt_service_search_event @ 0x125970, size 294 bytes
int  process_bt_service_search_event(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  int v6; // r1
  uint8_t *v8; // r7
  int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r4
  uint8_t *v13; // r7
  int v14; // r0
  int v15; // r2
  int v16; // r3
  int v17; // r4

  v4 = parse_number(*(uint8_t **)(a2 + 4), nullptr, 0);
  switch ( v4 )
  {
    case 0:
      dispatch_event_handler_1(
        "rf_tone_pwr_ofst=%d,%d,%d\n",
        *(char *)off_125A98,
        *(char *)(off_125A98 + 1),
        *(char *)(off_125A98 + 2));
      return 0;
    case 1:
      v8 = (uint8_t *)off_125AA0;
      ++*(uint8_t *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v9 = parse_number(*(uint8_t **)(a2 + 8), nullptr, 0);
      v10 = off_125AA4;
      v11 = *(uint8_t *)(off_125AA4 + 0x24);
      if ( v9 < -7 )
        v9 = -7;
      if ( v9 >= 7 )
        v9 = 7;
      v12 = v9;
      *(uint8_t *)off_125A98 = v9;
      if ( !v11 )
      {
        rf_ctrl_set(0, *(uint16_t *)(v10 + 0x28));
        ++*v8;
      }
      dispatch_event_handler_1("set rf_tone_pwr_ofst_2g4=%d\n", v12);
      return 0;
    case 2:
      v13 = (uint8_t *)off_125AA0;
      ++*(uint8_t *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v14 = parse_number(*(uint8_t **)(a2 + 8), nullptr, 0);
      v15 = off_125AA4;
      v16 = *(uint8_t *)(off_125AA4 + 0x24);
      if ( v14 < -7 )
        v14 = -7;
      if ( v14 >= 7 )
        v14 = 7;
      v17 = v14;
      *(uint8_t *)(off_125A98 + 1) = v14;
      if ( v16 == 1 )
      {
        rf_ctrl_set(1, *(uint16_t *)(v15 + 0x28));
        ++*v13;
      }
      dispatch_event_handler_1("set rf_tone_pwr_ofst_5g=%d\n", v17);
      return 0;
    case 3:
      if ( a1 > 2 )
      {
        v5 = parse_number(*(uint8_t **)(a2 + 8), nullptr, 0);
        if ( v5 < -7 )
          v5 = -7;
        v6 = v5;
        if ( v5 >= 7 )
          v6 = 7;
        *(uint8_t *)(off_125A98 + 2) = v6;
        dispatch_event_handler_1("set rf_tone_pwr_ofst_bt=%d\n", v6);
        return 0;
      }
LABEL_28:
      dispatch_event_handler_1(aWrongArgs);
      return -1;
    default:
      dispatch_event_handler_1(aWrongFunc_0);
      return -1;
  }
}
