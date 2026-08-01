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

extern uint32_t off_1270FC;
extern uint32_t off_127100;
extern uint32_t dword_127104;

// rf_read_trim @ 0x12704c, size 174 bytes
void rf_read_trim()
{
  uint8_t *v0; // r4
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  char v4; // r0
  int v5; // r1
  char v6; // r3
  int v7; // r0
  uint8_t v8; // [sp+3h] [bp-Dh] BYREF
  int v9; // [sp+4h] [bp-Ch] BYREF
  int v10; // [sp+8h] [bp-8h] BYREF
  int v11; // [sp+Ch] [bp-4h] BYREF

  v0 = off_1270FC;
  v1 = *(char *)off_1270FC;
  if ( *(uint8_t *)off_1270FC )
    return;
  v8 = *(uint8_t *)off_1270FC;
  v2 = *(uint32_t *)off_127100;
  v9 = v1;
  if ( (v2 & 0x2000000) != 0 )
  {
    mmio_read_status(&v8);
    rf_reg10_status(&v9);
    goto LABEL_4;
  }
  v10 = 0;
  v11 = 0;
  if ( !bus_read32((int)&v10) )
    v8 = v10;
  if ( mmio_read_64((int)&v11) )
  {
LABEL_4:
    v3 = v8;
    if ( v8 )
      goto LABEL_5;
    goto LABEL_19;
  }
  v9 = (char)v11;
  v3 = v8;
  if ( v8 )
  {
LABEL_5:
    if ( v3 > 0x1F )
    {
      LOBYTE(v3) = 31;
      v8 = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  LOBYTE(v3) = 15;
LABEL_7:
  v0[4] = v3;
  v4 = get_xtal_ftune();
  v5 = v9;
  v0[6] = v4;
  if ( v5 )
  {
    if ( v5 < -7 )
    {
      v6 = -7;
      v9 = -7;
      v5 = -7;
    }
    else if ( v5 > 8 )
    {
      v6 = 8;
      v9 = 8;
      v5 = 8;
    }
    else
    {
      v6 = v5;
    }
    v7 = dword_127104;
    v0[2] = v6;
    dispatch_event_handler(v7, v5);
  }
  v0[3] = 0x80;
  *v0 = 1;
}

