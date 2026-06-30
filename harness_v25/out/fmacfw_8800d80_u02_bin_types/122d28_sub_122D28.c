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

extern uint32_t off_122F00;
extern uint32_t dword_122F18;
extern uint32_t dword_122F2C;
extern uint32_t dword_122F28;
extern uint32_t dword_122F1C;
extern uint32_t off_122F20;
extern uint32_t dword_122F24;

// sub_122D28 @ 0x122d28, size 472 bytes
void  __noreturn sub_122D28(int a1, int *a2, int a3, int a4)
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

  sub_12C92C(106, a4, a3, 16);
  v15 = 0;
  if ( (*(uint32_t *)off_122F00 & 0x2000000) != 0 )
  {
    rf_cmd_wait_n_7e(&v15);
    rf_fault_dump_n14c((uint8_t *)&v15 + 1);
    msg_parse(dword_122F18, (uint8_t)v15, HIBYTE(v15));
    v6 = (uint8_t)v15;
  }
  else
  {
    v18 = 0;
    if ( sub_114D34((int)&v18) )
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
    msg_parse(dword_122F2C, *((uint8_t *)a2 + 20), v5);
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
    msg_parse(dword_122F28, *((uint8_t *)a2 + 21), v5);
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
  rf_reg_write_masked(v8);
  msg_parse(dword_122F1C, (uint8_t)v15, v10);
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
  v13 = off_122F20;
  v14 = dword_122F24;
  *(uint32_t *)off_122F20 = *(uint32_t *)off_122F20 & 0xFF03FFFF | v12;
  msg_parse(v14, v11, v13);
  if ( !a2[3] )
  {
LABEL_11:
    v9 = *a2;
    v17 = a2[2];
    v16 = v9;
    tx_phy_dispatch_c5ec(0, 2437);
  }
LABEL_21:
  sub_10C830();
  goto LABEL_11;
}

