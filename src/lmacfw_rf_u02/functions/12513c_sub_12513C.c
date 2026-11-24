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


extern uint32_t off_125284;
extern uint32_t off_125288;

// set_bdaddr @ 0x12513c, size 328 bytes
int  set_bdaddr(int a1, uint32_t *a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r7
  unsigned int v7; // r3
  int v8; // r6
  unsigned int v9; // r3
  int v10; // r9
  int v11; // r1
  int v12; // r2
  char v13; // r10
  int v14; // r4
  int v15; // r3
  int a5; // r7

  if ( a1 <= 2 )
  {
    dispatch_event_handler_1(asc_1303E8, a2);
    return 1;
  }
  else
  {
    v4 = (uint16_t)parse_number((uint8_t *)a2[1], nullptr, 0xAu);
    if ( a1 == 3 )
    {
      v5 = v4;
      v6 = parse_number((uint8_t *)a2[2], nullptr, 0x10u);
    }
    else
    {
      v5 = (uint16_t)parse_number((uint8_t *)a2[2], nullptr, 0xAu);
      v6 = parse_number((uint8_t *)a2[3], nullptr, 0x10u);
    }
    v7 = *(uint32_t *)off_125288 & 0x7F;
    if ( *((uint8_t *)off_125284 + 36) == 1 )
    {
      v8 = (*(uint32_t *)off_125288 >> 11) & 6;
      if ( v8 )
      {
        v8 = *(uint32_t *)off_125288 & 0x78;
        if ( v8 )
        {
          v8 = *((uint8_t *)off_125284 + 36);
        }
        else if ( v7 <= 2 )
        {
          v8 = 2;
        }
      }
      else if ( (*(uint32_t *)off_125288 & 0x78) == 0 )
      {
        v8 = 2;
      }
    }
    else if ( ((*(uint32_t *)off_125288 >> 11) & 6) != 0 )
    {
      v8 = v7 <= 4;
    }
    else
    {
      v8 = v7 <= 9;
    }
    if ( v5 > v4 )
    {
      v9 = v4;
      v4 = v5;
      v5 = v9;
    }
    v10 = (uint8_t)(v4 >> 5);
    v11 = (uint8_t)(v5 >> 5);
    if ( v10 == v11 )
    {
      mac_tx_frame(v8, v10, v5 & 0x1F, (1 << (v4 - v5 + 1)) - 1, v6 & ((1 << (v4 - v5 + 1)) - 1));
      goto LABEL_13;
    }
    v12 = v5 & 0x1F;
    if ( (v5 & 0x1F) != 0 )
    {
      v13 = 32 - v12;
      v14 = v4 & 0x1F;
      mac_tx_frame(v8, v11, v12, (1 << (32 - v12)) - 1, v6 & ((1 << (32 - v12)) - 1));
      v15 = (1 << (v14 + 1)) - 1;
      a5 = (v6 >> v13) & v15;
      if ( v14 != 31 )
      {
        mac_tx_frame(v8, v10, 0, v15, a5);
LABEL_13:
        dispatch_event_handler_1(asc_130320);
        return 0;
      }
      dispatch_event_handler_1(aPos1Err);
      return 1;
    }
    else
    {
      dispatch_event_handler_1(aPos2Err);
      return 1;
    }
  }
}
