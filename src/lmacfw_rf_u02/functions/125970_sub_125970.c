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

extern uint32_t dword_125AAC;
extern uint32_t off_125A98;
extern uint32_t off_125AA0;
extern uint32_t off_125AA4;
extern uint32_t dword_125AA8;
extern uint32_t dword_125AB0;
extern uint32_t dword_125A9C;
extern uint32_t dword_125AB4;
extern uint32_t dword_125AB8;

// process_bt_service_search_event @ 0x125970, size 294 bytes
int  process_bt_service_search_event(int a1, int a2)
{
  int v4; // r0
  int v5; // r0
  char v6; // r1
  int v7; // r0
  uint8_t *v9; // r7
  int v10; // r0
  uint16_t *v11; // r2
  int v12; // r3
  int v13; // r4
  uint8_t *v14; // r7
  int v15; // r0
  uint16_t *v16; // r2
  int v17; // r3
  int v18; // r4

  v4 = parse_number(*(uint8_t **)(a2 + 4), 0, 0);
  switch ( v4 )
  {
    case 0:
      dispatch_event_handler(dword_125AAC, *(char *)off_125A98, *((char *)off_125A98 + 1), *((char *)off_125A98 + 2));
      return 0;
    case 1:
      v9 = off_125AA0;
      ++*(uint8_t *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v10 = parse_number(*(uint8_t **)(a2 + 8), 0, 0);
      v11 = (uint16_t *)off_125AA4;
      v12 = *((uint8_t *)off_125AA4 + 36);
      if ( v10 < -7 )
        v10 = -7;
      if ( v10 >= 7 )
        v10 = 7;
      v13 = v10;
      *(uint8_t *)off_125A98 = v10;
      if ( !v12 )
      {
        rf_ctrl_set(0, v11[20]);
        ++*v9;
      }
      dispatch_event_handler(dword_125AA8, v13);
      return 0;
    case 2:
      v14 = off_125AA0;
      ++*(uint8_t *)off_125AA0;
      if ( a1 <= 2 )
        goto LABEL_28;
      v15 = parse_number(*(uint8_t **)(a2 + 8), 0, 0);
      v16 = (uint16_t *)off_125AA4;
      v17 = *((uint8_t *)off_125AA4 + 36);
      if ( v15 < -7 )
        v15 = -7;
      if ( v15 >= 7 )
        v15 = 7;
      v18 = v15;
      *((uint8_t *)off_125A98 + 1) = v15;
      if ( v17 == 1 )
      {
        rf_ctrl_set(1, v16[20]);
        ++*v14;
      }
      dispatch_event_handler(dword_125AB0, v18);
      return 0;
    case 3:
      if ( a1 > 2 )
      {
        v5 = parse_number(*(uint8_t **)(a2 + 8), 0, 0);
        if ( v5 < -7 )
          v5 = -7;
        v6 = v5;
        if ( v5 >= 7 )
          v6 = 7;
        v7 = dword_125A9C;
        *((uint8_t *)off_125A98 + 2) = v6;
        dispatch_event_handler(v7);
        return 0;
      }
LABEL_28:
      dispatch_event_handler(dword_125AB4);
      return -1;
    default:
      dispatch_event_handler(dword_125AB8);
      return -1;
  }
}

