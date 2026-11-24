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


extern uint32_t off_1236C4;
extern uint32_t off_1236C8;
extern uint32_t off_1236CC;
extern uint32_t off_1236D0;
extern uint32_t off_1236D4;
extern uint32_t off_1236DC;
extern uint32_t off_1236E4;

// read_irq_status @ 0x1234e4, size 480 bytes
int  read_irq_status(int result)
{
  uint8_t *v1; // r6
  uint8_t *v2; // r5
  uint8_t *v3; // r7
  uint64_t v4; // r2
  uint8_t v5; // r4
  int v6; // r3
  int v7; // r3
  int v8; // r7
  int v9; // r4
  int v10; // r0
  int v11; // r4
  int v12; // r3
  int v13; // r6
  int v14; // r4
  int v15; // r0
  int *v16; // r2
  int v17; // r4
  int v18; // r3
  int v19; // r4
  int v20; // r2
  int v21; // r1
  int v22; // r4
  uint8_t a1; // [sp+Eh] [bp-6h] BYREF
  uint8_t v24[5]; // [sp+Fh] [bp-5h] BYREF

  v1 = off_1236C4;
  v2 = (uint8_t *)off_1236C8;
  v3 = off_1236CC;
  HIDWORD(v4) = *(uint8_t *)off_1236CC;
  LODWORD(v4) = *(uint8_t *)off_1236C4 | *(uint8_t *)off_1236C8;
  v5 = BYTE4(v4) | v4;
  if ( !v4 )
  {
    result = mmio_set_control();
    if ( (*(uint8_t *)off_1236D0 & 0xFD) == 1 )
    {
      a1 = v5;
      v24[0] = v5;
      mmio_read_status(&a1);
      mmio_read_byte(v24);
      dispatch_event_handler_1("xtal efuse=%x,%x\n", a1, v24[0]);
      result = a1;
      if ( a1 )
      {
        if ( a1 > 0x1Fu )
        {
          result = 31;
          a1 = 31;
        }
        set_xtal_ftune(result);
        result = dispatch_event_handler_1("set xtal_cap 0x%x\n", a1);
      }
      v21 = v24[0];
      if ( v24[0] )
      {
        if ( v24[0] > 0x3Fu )
        {
          v21 = 63;
          v24[0] = 63;
          v22 = 16515072;
        }
        else
        {
          v22 = (v24[0] << 18) & 0xFC0000;
        }
        *(uint32_t *)off_1236DC = *(uint32_t *)off_1236DC & 0xFF03FFFF | v22;
        result = dispatch_event_handler_1("set xtal_cap_fine 0x%x\n", v21);
      }
    }
    BYTE4(v4) = *v3;
  }
  v6 = (uint8_t)(BYTE4(v4) + 1);
  if ( v6 != 8 )
  {
    *v3 = v6;
    return result;
  }
  v7 = (uint8_t)*v1;
  *v3 = 0;
  if ( !v7 )
  {
    v8 = *(uint32_t *)off_1236D4;
    if ( (*(uint8_t *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v8 & 0x1000000) != 0 )
        v9 = 1;
      else
        v9 = -1;
      v10 = get_xtal_ftune() + v9;
      if ( v10 < 1 )
        v10 = 1;
      if ( v10 >= 31 )
        v10 = 31;
      set_xtal_ftune(v10);
    }
    v11 = get_xtal_ftune();
    rf_cmd_check(v11);
    result = dispatch_event_handler_1("xtal_cap : cnt%d %x %x\n", *v2, v11, v8);
    v12 = (uint8_t)(*v2 + 1);
    if ( v12 != 16 )
      goto LABEL_15;
    goto LABEL_33;
  }
  if ( v7 == 1 )
  {
    v18 = *(uint32_t *)off_1236D4;
    if ( (*(uint8_t *)off_1236D0 & 0xFD) != 1 )
    {
      if ( (v18 & 0x1000000) != 0 )
        v19 = 1;
      else
        v19 = -1;
      v20 = ((*(uint32_t *)off_1236DC >> 18) & 0x3F) + v19;
      if ( v20 < 1 )
        v20 = 1;
      if ( v20 >= 63 )
        v20 = 63;
      *(uint32_t *)off_1236DC = *(uint32_t *)off_1236DC & 0xFF03FFFF | (v20 << 18);
    }
    result = dispatch_event_handler_1("cur_cap_fine : cnt%d %x %x\n", *v2, (*(uint32_t *)off_1236DC >> 18) & 0x3F, v18);
    v12 = (uint8_t)(*v2 + 1);
    if ( v12 != 32 )
      goto LABEL_15;
LABEL_33:
    ++*v1;
    *v2 = 0;
    return result;
  }
  v13 = *(uint32_t *)off_1236D4;
  if ( (*(uint32_t *)off_1236D4 & 0x1000000) != 0 )
    v14 = 0x2000000 - v13;
  else
    v14 = *(uint32_t *)off_1236D4;
  v15 = get_xtal_ftune();
  result = dispatch_event_handler_1(
             "xtal_cap %x cap_fine %x cfophase %x %d\n",
             v15,
             (*(uint32_t *)off_1236DC >> 18) & 0x3F,
             v13,
             v14);
  v16 = (int *)off_1236E4;
  v12 = (uint8_t)(*v2 + 1);
  v17 = v14 + *(uint32_t *)off_1236E4;
  *(uint32_t *)off_1236E4 = v17;
  if ( v12 != 16 )
  {
LABEL_15:
    *v2 = v12;
    return result;
  }
  *v2 = 0;
  *v16 = v17 / 16;
  dispatch_event_handler_1("mean abs cfophase %d\n", v17 / 16);
  if ( (unsigned int)*(uint8_t *)off_1236D0 - 2 <= 1 )
    return ll_state_reset();
  else
    return rf_set_flag(2);
}
