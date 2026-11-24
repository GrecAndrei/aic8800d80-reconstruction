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


extern uint32_t dword_110FB8;
extern uint32_t dword_110FD4;
extern uint32_t dword_110FF4;
extern uint32_t dword_111000;
extern uint32_t dword_111010;
extern uint32_t off_110F90;
extern uint32_t off_110F94;
extern uint32_t off_110F9C;
extern uint32_t off_110FA0;
extern uint32_t off_110FA4;
extern uint32_t off_110FA8;
extern uint32_t off_110FAC;
extern uint32_t off_110FB4;
extern uint32_t off_110FBC;
extern uint32_t off_110FC0;
extern uint32_t off_110FC4;
extern uint32_t off_110FC8;
extern uint32_t off_110FCC;
extern uint32_t off_110FD0;
extern uint32_t off_110FDC;
extern uint32_t off_110FE4;
extern uint32_t off_110FE8;
extern uint32_t off_110FF0;
extern uint32_t off_110FF8;
extern uint32_t off_110FFC;
extern uint32_t off_111004;
extern uint32_t off_111008;
extern uint32_t off_11100C;
extern uint32_t off_111014;
extern uint32_t off_111134;
extern uint32_t off_11113C;
extern uint32_t off_111140;
extern uint32_t off_111148;
extern uint32_t off_111150;
extern uint32_t off_111158;
extern uint32_t off_11115C;
extern uint32_t off_111160;
extern uint32_t off_111164;
extern uint32_t off_111170;
extern uint32_t off_111180;

// rf_irq_handler_1 @ 0x110d00, size 1068 bytes
int rf_irq_handler_1()
{
  int v0; // r4
  uint32_t *v1; // r0
  int v2; // r1
  uint32_t *v3; // r2
  uint8_t *v4; // r6
  unsigned int v5; // r1
  unsigned int v6; // r2
  int v7; // r5
  unsigned int v8; // r2
  char *v9; // r3
  uint32_t *v10; // r7
  uint32_t *v11; // r0
  int v12; // r3
  char *v13; // r1
  int v14; // r2
  uint32_t *v15; // r0
  uint8_t *v16; // r5
  unsigned int v17; // r1
  unsigned int v18; // r2
  int result; // r0
  uint8_t *v20; // r0
  unsigned int v21; // r1
  unsigned int v22; // r2
  uint32_t *v23; // r3
  uint16_t *v24; // r0
  unsigned int v25; // r2
  uint32_t *v26; // r3
  unsigned int v27; // r3
  uint32_t *v28; // r7
  uint32_t *v29; // r1
  unsigned int v30; // r3
  char *v31; // r2
  uint32_t *v32; // r5
  int v33; // r6
  int v34; // r7
  unsigned int v35; // r3
  char *v36; // r2
  int v37; // r5
  int v38; // r1
  int v39; // r1
  uint32_t *v40; // r2
  int v41; // r5
  uint8_t *v42; // r6
  uint32_t *v43; // r2

  v0 = *(uint32_t *)off_110F94;
  if ( **(uint16_t **)off_110F90 < 0 && !v0 )
  {
    flash_cmd_exec((int)aIntStatus0, (int)aSdioIsr, 39);
    goto LABEL_10;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v40 = (uint32_t *)off_11113C;
    v41 = *(uint32_t *)off_111150;
    *(uint32_t *)off_111150 = *(uint32_t *)off_111150;
    *v40 &= ~0x20u;
    check_interrupt_flag(2, "int2dev:%d\n", v41);
    if ( (v41 & 4) != 0 )
    {
      *(uint8_t *)off_11115C = 1;
      check_interrupt_flag(2, &aClrPreSleep[4]);
    }
    if ( (v41 & 1) != 0 )
    {
      v42 = off_11115C;
      *(uint32_t *)off_111158 = 16;
      if ( *v42 )
      {
        check_interrupt_flag(2, aClrPreSleep);
        *v42 = 0;
      }
      if ( *(uint8_t *)off_111160 )
      {
        v43 = off_111180;
        *((uint8_t *)off_111160 + 1) = 1;
        *v43 |= 1u;
        check_interrupt_flag(2, aSoftwk);
      }
      *(uint8_t *)off_111164 = 0;
    }
    if ( (v41 & 2) != 0 )
    {
      *(uint8_t *)off_111164 = 1;
      check_interrupt_flag(2, aBit1);
    }
    if ( (v41 & 8) != 0 )
      dispatch_event_handler_1(aNotUsed);
  }
  if ( (v0 & 1) != 0 )
  {
    dispatch_event_handler_1(aSdioHostSoftRe, v0 << 31);
    *(uint32_t *)off_110F9C = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    rf_reg_update(*(uint32_t *)off_110FA0);
    *(uint32_t *)off_110F9C = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = off_110FA8;
    v2 = *(uint32_t *)off_110FA4;
    v3 = off_110FAC;
    *(uint32_t *)off_110FA4 = *(uint32_t *)off_110FA4;
    dispatch_event_handler_1("sdio func1 error bit:%x, func1 free cnt=%d, func1 free queue2 cnt=%d\r\n", v2, *v3, *v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v37 = *(uint32_t *)off_111134;
  *(uint32_t *)off_111134 = *(uint32_t *)off_111134;
  dispatch_event_handler_1("sdio func1 other bit:%x\r\n", v37);
  if ( (v37 & 4) != 0 )
    *(uint32_t *)off_11113C &= ~1u;
  if ( (v37 & 8) == 0 )
  {
LABEL_10:
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_50:
    v38 = *(uint32_t *)off_111140;
    *(uint32_t *)off_111140 = *(uint32_t *)off_111140;
    dispatch_event_handler_1("sdio func2 error bit:%x\r\n", v38);
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_51;
  }
  *(uint32_t *)off_11113C &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_50;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_51:
  v39 = *(uint32_t *)off_111148;
  *(uint32_t *)off_111148 = *(uint32_t *)off_111148;
  dispatch_event_handler_1("sdio func2 other bit:%x\r\n", v39);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v4 = off_110FB4;
    v5 = *((uint8_t *)off_110FB4 + 1621);
    v6 = *((uint8_t *)off_110FB4 + 1622);
    if ( v5 >= v6 )
    {
      dispatch_event_handler_1("rxused=%d, total=%d\r\n", v5, v6);
    }
    else
    {
      v7 = *(uint32_t *)off_110FBC;
      v8 = *((uint8_t *)off_110FB4 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_110FB8
                          * (uint64_t)((unsigned int)*((uint8_t *)off_110FB4 + 1620) + 1)) >> 32) >> 6);
      v9 = (char *)off_110FB4 + 20 * v8;
      v10 = off_110FC4;
      *((uint32_t *)v9 + 1) = *(uint32_t *)off_110FC0;
      v4[1621] = v5 + 1;
      v11 = off_110FC8;
      *((uint32_t *)v9 + 2) = *v10;
      v9[12] = v7;
      v4[1620] = v8;
      v9[13] = BYTE1(v7) & 7;
      *v11 = 16;
      do
        v12 = *v11 & 0x20;
      while ( v12 );
      v13 = &v4[20 * v8];
      v14 = 5 * v8;
      if ( (v13[13] & 4) == 0 )
        v12 = *(uint32_t *)(*((uint32_t *)v13 + 2) + 4);
      v15 = off_110FD0;
      *(uint32_t *)off_110FCC = v12;
      *v15 = 16;
      check_kernel_state(dword_110FD4, &v4[4 * v14]);
      set_busy_flag_alt(2048);
    }
    *(uint32_t *)off_110F9C = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    dispatch_event_handler_1(aUnexpectH2dCon);
    *(uint32_t *)off_111170 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v16 = off_110FB4;
    v17 = *((uint8_t *)off_110FB4 + 2433);
    v18 = *((uint8_t *)off_110FB4 + 2434);
    if ( v17 < v18 )
    {
      v33 = *(uint32_t *)off_111014;
      v34 = *(uint32_t *)off_11100C;
      v35 = *((uint8_t *)off_110FB4 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_111010
                           * (uint64_t)((unsigned int)*((uint8_t *)off_110FB4 + 2432) + 1)) >> 32) >> 5);
      v36 = (char *)off_110FB4 + 20 * v35;
      *((uint8_t *)off_110FB4 + 2432) = v35;
      v36[1645] = BYTE1(v33) & 7;
      *((uint32_t *)v36 + 409) = v34;
      *((uint32_t *)v36 + 410) = v34;
      v36[1644] = v33;
      v16[2433] = v17 + 1;
      check_kernel_state((int)(v16 + 2436), (uint32_t *)v36 + 408);
      set_busy_flag_alt(0x1000000);
    }
    else
    {
      dispatch_event_handler_1("msgrxused=%d, total=%d\r\n", v17, v18);
    }
    *(uint32_t *)off_110F9C = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    v20 = off_110FDC;
    v21 = *((uint8_t *)off_110FDC + 3074);
    v22 = *((uint8_t *)off_110FDC + 3073);
    if ( v21 < v22 )
    {
      v30 = *((uint8_t *)off_110FDC + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (uint64_t)((unsigned int)*((uint8_t *)off_110FDC + 3072) + 1)) >> 32) >> 7);
      v31 = (char *)off_110FDC + 16 * v30;
      *((uint32_t *)v31 + 1) = *(uint32_t *)off_111004;
      v32 = off_111008;
      v20[3072] = v30;
      *((uint16_t *)v31 + 4) = *v32;
      v20[3074] = v21 + 1;
      check_kernel_state((int)(v20 + 3080), v31);
      result = set_busy_flag_alt(1024);
    }
    else
    {
      result = dispatch_event_handler_1("txcused=%d, total=%d\r\n", v21, v22);
    }
    v23 = off_110FE4;
    *(uint32_t *)off_110F9C = 4096;
    if ( !*v23 )
      *(uint8_t *)off_110FE8 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    v24 = off_110FDC;
    v25 = *((uint8_t *)off_110FDC + 6162);
    if ( *((uint8_t *)off_110FDC + 6161) > v25 )
    {
      v27 = *((uint8_t *)off_110FDC + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (uint64_t)((unsigned int)*((uint8_t *)off_110FDC + 6160) + 1)) >> 32) >> 7);
      v28 = off_110FF8;
      *((uint8_t *)off_110FDC + 6160) = v27;
      v29 = &v24[8 * v27 + 1544];
      v29[1] = *v28;
      v24[8 * v27 + 1548] = *(uint32_t *)off_110FFC;
      *((uint8_t *)v24 + 6162) = v25 + 1;
      check_kernel_state(dword_111000, v29);
      result = set_busy_flag_alt(512);
    }
    else
    {
      result = dispatch_event_handler_1("txcmsgused=%d, msgtotal=%d\r\n", v25, v25);
    }
    v26 = off_110FF0;
    *(uint32_t *)off_110F9C = 2048;
    if ( !*v26 )
      *(uint8_t *)off_110FE8 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(uint32_t *)off_110F9C = 4;
  if ( (v0 & 8) != 0 )
    *(uint32_t *)off_110F9C = 8;
  return result;
}
