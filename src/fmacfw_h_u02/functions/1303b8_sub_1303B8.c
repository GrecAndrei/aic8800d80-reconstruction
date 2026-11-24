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


extern uint32_t off_130468;
extern uint32_t off_13046C;

// read_global_signed_flag @ 0x1303b8, size 174 bytes
void  read_global_signed_flag(int a1, int a2)
{
  uint8_t *v2; // r4
  int v3; // r2
  int v4; // r3
  unsigned int v5; // r3
  char v6; // r0
  int v7; // r1
  char v8; // r3
  uint8_t a1a; // [sp+3h] [bp-Dh] BYREF
  int v10; // [sp+4h] [bp-Ch] BYREF
  int v11; // [sp+8h] [bp-8h] BYREF
  int v12; // [sp+Ch] [bp-4h] BYREF

  v2 = off_130468;
  v3 = *(char *)off_130468;
  if ( *(uint8_t *)off_130468 )
    return;
  a1a = *(uint8_t *)off_130468;
  v4 = *(uint32_t *)off_13046C;
  v10 = v3;
  if ( (v4 & 0x2000000) != 0 )
  {
    rf_cmd_6_read(&a1a);
    rf_cmd_10(&v10);
    goto LABEL_4;
  }
  v11 = 0;
  v12 = 0;
  if ( !send_smc_cmd_2((int)&v11) )
    a1a = v11;
  if ( send_smc_cmd_0x80((int)&v12) )
  {
LABEL_4:
    v5 = a1a;
    if ( a1a )
      goto LABEL_5;
    goto LABEL_19;
  }
  v10 = (char)v12;
  v5 = a1a;
  if ( a1a )
  {
LABEL_5:
    if ( v5 > 0x1F )
    {
      LOBYTE(v5) = 31;
      a1a = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  LOBYTE(v5) = 15;
LABEL_7:
  v2[4] = v5;
  v6 = rf_get_status();
  v7 = v10;
  v2[6] = v6;
  if ( v7 )
  {
    if ( v7 < -7 )
    {
      v8 = -7;
      v10 = -7;
      v7 = -7;
    }
    else if ( v7 > 8 )
    {
      v8 = 8;
      v10 = 8;
      v7 = 8;
    }
    else
    {
      v8 = v7;
    }
    v2[2] = v8;
    alloc_tx_event("\x9D\x89temp_lvl_calibed=%d\n", v7);
  }
  v2[3] = 0x80;
  *v2 = 1;
}
