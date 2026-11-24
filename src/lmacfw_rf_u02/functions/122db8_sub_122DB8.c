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
extern uint32_t off_122F18;

// pack_control_data @ 0x122db8, size 344 bytes
int  pack_control_data(int a1, unsigned int a2)
{
  unsigned int v2; // r3
  int v3; // r5
  int v6; // r5
  int v7; // r4
  int v8; // r1
  int v9; // r0
  int v11; // r0
  unsigned int v12; // r4
  int v13; // r1
  unsigned int v14; // r1
  int v15; // r6
  int v16; // r5
  int v17; // r2
  int v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r1
  uint16_t a1a; // [sp+Ah] [bp-6h] BYREF
  int a3; // [sp+Ch] [bp-4h] BYREF

  a1a = 0;
  v2 = *(uint32_t *)off_122F10;
  a3 = 0;
  v3 = HIBYTE(v2) & 2;
  if ( v3 )
  {
    if ( !a1 )
    {
      v6 = mmio_read_status(&a1a);
      v7 = mmio_read_byte((uint8_t *)&a1a + 1);
      dispatch_event_handler_1(
        "read efuse cap:0x%x (remain:%x), cap_fine:0x%x (remain:%x)\n",
        (uint8_t)a1a,
        v6,
        HIBYTE(a1a),
        v7);
      v8 = v7 << 24;
      v9 = v6 << 16;
      return (uint8_t)a1a | (HIBYTE(a1a) << 8) | v8 | v9;
    }
  }
  else
  {
    v11 = bus_read32((int)&a3);
    if ( !a1 )
    {
      if ( v11 )
      {
        dispatch_event_handler_1(aEmpty_0);
        v9 = 917504;
        v8 = 234881024;
      }
      else
      {
        a1a = a3;
        dispatch_event_handler_1("read flash cap:0x%x, cap_fine:0x%x\n", (uint8_t)a3, BYTE1(a3));
        v9 = 983040;
        v8 = 251658240;
      }
      return (uint8_t)a1a | (HIBYTE(a1a) << 8) | v8 | v9;
    }
  }
  if ( a1 == 1 )
  {
    v13 = *(uint8_t *)(off_122F18 + 4);
    if ( a2 >= 0x1F )
      a2 = 31;
    if ( a2 == v13 )
    {
      v15 = *(char *)(off_122F18 + 2);
      if ( v3 )
      {
        v16 = mmio_get_field(a2);
        if ( v16 < 0 )
        {
          dispatch_event_handler_1(aNoRoom_0);
          v12 = 65280;
        }
        else
        {
          dispatch_event_handler_1("set xtal_cap to efuse: 0x%x\n", a2);
          v12 = a2 | (v16 << 8);
        }
      }
      else
      {
        LOBYTE(a3) = a2;
        bus_write32((int)&a3);
        v20 = a2;
        v12 = a2 | 0xF00;
        dispatch_event_handler_1("set xtal_cap to flash: 0x%x\r\n", v20);
      }
      check_radio_status(1, v15, v17);
    }
    else
    {
      v12 = ~((unsigned int)~(v13 << 23) >> 23);
      dispatch_event_handler_1("xtal_cap error, not the calibed val:0x%x\n", v13);
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
        dispatch_event_handler_1(aNoRoom_0);
        return 65280;
      }
      else
      {
        v19 = a2;
        v12 = a2 | (v18 << 8);
        dispatch_event_handler_1("set xtal_cap_fine to efuse: 0x%x, r %d\n", v19, v18);
      }
    }
    else
    {
      BYTE1(a3) = a2;
      bus_write32((int)&a3);
      v14 = a2;
      v12 = a2 | 0xF00;
      dispatch_event_handler_1("set xtal_cap_fine to flash: 0x%x\r\n", v14);
    }
  }
  else
  {
    return 0;
  }
  return v12;
}
