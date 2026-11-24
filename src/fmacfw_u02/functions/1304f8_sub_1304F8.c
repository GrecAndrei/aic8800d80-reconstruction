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


extern uint32_t off_1305A8;
extern uint32_t off_1305AC;

// rf_get_channel_calibration @ 0x1304f8, size 174 bytes
void rf_get_channel_calibration()
{
  uint8_t *v0; // r4
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  char v4; // r0
  int v5; // r1
  char v6; // r3
  uint8_t a1; // [sp+3h] [bp-Dh] BYREF
  int v8; // [sp+4h] [bp-Ch] BYREF
  int v9; // [sp+8h] [bp-8h] BYREF
  int v10; // [sp+Ch] [bp-4h] BYREF

  v0 = off_1305A8;
  v1 = *(char *)off_1305A8;
  if ( *(uint8_t *)off_1305A8 )
    return;
  a1 = *(uint8_t *)off_1305A8;
  v2 = *(uint32_t *)off_1305AC;
  v8 = v1;
  if ( (v2 & 0x2000000) != 0 )
  {
    rf_cmd6_read(&a1);
    rom_get_chip_version(&v8);
    goto LABEL_4;
  }
  v9 = 0;
  v10 = 0;
  if ( !ke_event_send_2((int)&v9) )
    a1 = v9;
  if ( ke_event_send_0x80((int)&v10) )
  {
LABEL_4:
    v3 = a1;
    if ( a1 )
      goto LABEL_5;
    goto LABEL_19;
  }
  v8 = (char)v10;
  v3 = a1;
  if ( a1 )
  {
LABEL_5:
    if ( v3 > 0x1F )
    {
      LOBYTE(v3) = 31;
      a1 = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  LOBYTE(v3) = 15;
LABEL_7:
  v0[4] = v3;
  v4 = rf_get_rssi();
  v5 = v8;
  v0[6] = v4;
  if ( v5 )
  {
    if ( v5 < -7 )
    {
      v6 = -7;
      v8 = -7;
      v5 = -7;
    }
    else if ( v5 > 8 )
    {
      v6 = 8;
      v8 = 8;
      v5 = 8;
    }
    else
    {
      v6 = v5;
    }
    v0[2] = v6;
    event_dispatch("\x9D\x89temp_lvl_calibed=%d\n", v5);
  }
  v0[3] = 0x80;
  *v0 = 1;
}
