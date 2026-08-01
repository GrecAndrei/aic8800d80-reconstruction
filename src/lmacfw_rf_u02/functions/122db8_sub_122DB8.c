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

extern uint32_t off_122F10;
extern uint32_t dword_122F14;
extern uint32_t dword_122F20;
extern uint32_t dword_122F24;
extern uint32_t off_122F18;
extern uint32_t dword_122F38;
extern uint32_t dword_122F2C;
extern uint32_t dword_122F34;
extern uint32_t dword_122F1C;
extern uint32_t dword_122F30;
extern uint32_t dword_122F28;

// pack_control_data @ 0x122db8, size 344 bytes
// Doc: sub_1222DB8 [rf]: Initializes LMAC RF control structure with zeroed params
// sub_1222DB8 [rf]: Initializes LMAC RF control structure with zeroed params
int  pack_control_data(int a1, unsigned int a2)
{
  unsigned int v2; // r3
  int v3; // r5
  int v6; // r5
  int status; // r4
  int v8; // r1
  int v9; // r0
  int v11; // r0
  int v12; // r4
  int v13; // r1
  unsigned int v14; // r1
  int v15; // r6
  int inited; // r5
  int v17; // r2
  int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r1
  int16_t v21; // [sp+Ah] [bp-6h] BYREF
  int v22; // [sp+Ch] [bp-4h] BYREF

  v21 = 0;
  v2 = *(uint32_t *)off_122F10;
  v22 = 0;
  v3 = HIBYTE(v2) & 2;
  if ( v3 )
  {
    if ( !a1 )
    {
      v6 = mmio_read_status(&v21);
      status = mmio_read_byte((uint8_t *)&v21 + 1);
      dispatch_event_handler(dword_122F14, (uint8_t)v21, v6, HIBYTE(v21), status);
      v8 = status << 24;
      v9 = v6 << 16;
      return (uint8_t)v21 | (HIBYTE(v21) << 8) | v8 | v9;
    }
  }
  else
  {
    v11 = bus_read32((int)&v22);
    if ( !a1 )
    {
      if ( v11 )
      {
        dispatch_event_handler(dword_122F20);
        v9 = 917504;
        v8 = 234881024;
      }
      else
      {
        v21 = v22;
        dispatch_event_handler(dword_122F24);
        v9 = 983040;
        v8 = 251658240;
      }
      return (uint8_t)v21 | (HIBYTE(v21) << 8) | v8 | v9;
    }
  }
  if ( a1 == 1 )
  {
    v13 = *((uint8_t *)off_122F18 + 4);
    if ( a2 >= 0x1F )
      a2 = 31;
    if ( a2 == v13 )
    {
      v15 = *((char *)off_122F18 + 2);
      if ( v3 )
      {
        inited = mmio_get_field(a2);
        if ( inited < 0 )
        {
          dispatch_event_handler(dword_122F38);
          v12 = 65280;
        }
        else
        {
          dispatch_event_handler(dword_122F2C, a2);
          v12 = a2 | (inited << 8);
        }
      }
      else
      {
        LOBYTE(v22) = a2;
        bus_write32((int)&v22);
        v20 = a2;
        v12 = a2 | 0xF00;
        dispatch_event_handler(dword_122F34, v20);
      }
      check_radio_status(1, v15, v17);
    }
    else
    {
      v12 = ~((unsigned int)~(v13 << 23) >> 23);
      dispatch_event_handler(dword_122F1C);
    }
  }
  else if ( a1 == 2 )
  {
    if ( a2 >= 0x3F )
      a2 = 63;
    if ( v3 )
    {
      v18 = mmio_wait_bit((uint8_t)a2);
      if ( v18 < 0 )
      {
        dispatch_event_handler(dword_122F38);
        return 65280;
      }
      else
      {
        v19 = a2;
        v12 = a2 | (v18 << 8);
        dispatch_event_handler(dword_122F30, v19);
      }
    }
    else
    {
      BYTE1(v22) = a2;
      bus_write32((int)&v22);
      v14 = a2;
      v12 = a2 | 0xF00;
      dispatch_event_handler(dword_122F28, v14);
    }
  }
  else
  {
    return 0;
  }
  return v12;
}

