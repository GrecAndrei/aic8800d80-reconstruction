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

extern uint32_t off_123134;
extern uint32_t dword_12314C;
extern uint32_t dword_123160;
extern uint32_t dword_12315C;
extern uint32_t dword_123150;
extern uint32_t off_123154;
extern uint32_t dword_123158;

// sub_122F5C @ 0x122f5c, size 472 bytes
void  __noreturn sub_122F5C(int a1, int *a2, int a3, int a4)
{
  int v5; // r2
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  int v9; // r7
  int v10; // r2
  int v11; // r1
  int v12; // r6
  void *v13; // r2
  int v14; // r0
  int16_t v15; // [sp+Ah] [bp-92h] BYREF
  int v16; // [sp+Ch] [bp-90h]
  int v17; // [sp+10h] [bp-8Ch]
  int v18; // [sp+14h] [bp-88h] BYREF

  rf_bus_setup_n3a8(106, a4, a3, 16);
  v15 = 0;
  if ( (*(uint32_t *)off_123134 & 0x2000000) != 0 )
  {
    sub_114EA4(&v15);
    sub_114ED0((uint8_t *)&v15 + 1);
    sub_12ECB0(dword_12314C, (uint8_t)v15, HIBYTE(v15));
    v6 = (uint8_t)v15;
  }
  else
  {
    v18 = 0;
    if ( sub_115370((int)&v18) )
    {
      v6 = (uint8_t)v15;
    }
    else
    {
      v6 = (uint8_t)v18;
      v5 = BYTE1(v18);
      v15 = v18;
    }
  }
  if ( !v6 && *((uint8_t *)a2 + 20) )
  {
    sub_12ECB0(dword_123160, *((uint8_t *)a2 + 20), v5);
    LOBYTE(v15) = *((uint8_t *)a2 + 20);
  }
  v7 = HIBYTE(v15);
  if ( HIBYTE(v15) )
  {
    v8 = (uint8_t)v15;
    if ( !(uint8_t)v15 )
      goto LABEL_18;
  }
  else if ( *((uint8_t *)a2 + 21) )
  {
    sub_12ECB0(dword_12315C, *((uint8_t *)a2 + 21), v5);
    v8 = (uint8_t)v15;
    v7 = *((uint8_t *)a2 + 21);
    HIBYTE(v15) = *((uint8_t *)a2 + 21);
    if ( !(uint8_t)v15 )
      goto LABEL_17;
  }
  else
  {
    v8 = (uint8_t)v15;
    if ( !(uint8_t)v15 )
      goto LABEL_10;
  }
  if ( v8 > 0x1F )
  {
    v8 = 31;
    LOBYTE(v15) = 31;
  }
  sub_10ED90(v8);
  sub_12ECB0(dword_123150, (uint8_t)v15, v10);
  v7 = HIBYTE(v15);
LABEL_17:
  if ( !v7 )
  {
LABEL_10:
    if ( !a2[3] )
      goto LABEL_11;
    goto LABEL_21;
  }
LABEL_18:
  if ( v7 > 0x3F )
  {
    v11 = 63;
    HIBYTE(v15) = 63;
    v12 = 16515072;
  }
  else
  {
    v11 = HIBYTE(v15);
    v12 = (HIBYTE(v15) << 18) & 0xFC0000;
  }
  v13 = off_123154;
  v14 = dword_123158;
  *(uint32_t *)off_123154 = *(uint32_t *)off_123154 & 0xFF03FFFF | v12;
  sub_12ECB0(v14, v11, v13);
  if ( !a2[3] )
  {
LABEL_11:
    v9 = *a2;
    v17 = a2[2];
    v16 = v9;
    tx_phy_dispatch(0, 2437);
  }
LABEL_21:
  sub_10C688();
  goto LABEL_11;
}

