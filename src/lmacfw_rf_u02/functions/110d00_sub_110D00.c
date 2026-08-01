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

extern uint32_t off_110F94;
extern uint32_t off_110F90;
extern uint32_t dword_111130;
extern uint32_t dword_11112C;
extern uint32_t off_11113C;
extern uint32_t off_111150;
extern uint32_t dword_111154;
extern uint32_t off_11115C;
extern uint32_t dword_111178;
extern uint32_t off_111158;
extern uint32_t dword_111188;
extern uint32_t off_111160;
extern uint32_t off_111180;
extern uint32_t dword_111184;
extern uint32_t off_111164;
extern uint32_t dword_11117C;
extern uint32_t dword_111168;
extern uint32_t dword_110F98;
extern uint32_t off_110F9C;
extern uint32_t off_110FA0;
extern uint32_t off_110FA4;
extern uint32_t dword_110FB0;
extern uint32_t dword_111138;
extern uint32_t off_111134;
extern uint32_t dword_111144;
extern uint32_t off_111140;
extern uint32_t dword_11114C;
extern uint32_t off_111148;
extern uint32_t off_110FB4;
extern uint32_t dword_111174;
extern uint32_t off_110FBC;
extern uint32_t dword_110FB8;
extern uint32_t off_110FC4;
extern uint32_t off_110FC0;
extern uint32_t off_110FC8;
extern uint32_t off_110FD0;
extern uint32_t off_110FCC;
extern uint32_t dword_110FD4;
extern uint32_t dword_11116C;
extern uint32_t off_111170;
extern uint32_t off_111014;
extern uint32_t off_11100C;
extern uint32_t dword_111010;
extern uint32_t dword_110FD8;
extern uint32_t off_110FDC;
extern uint32_t dword_110FF4;
extern uint32_t off_111004;
extern uint32_t off_111008;
extern uint32_t dword_110FE0;
extern uint32_t off_110FE4;
extern uint32_t off_110FE8;
extern uint32_t off_110FF8;
extern uint32_t off_110FFC;
extern uint32_t dword_111000;
extern uint32_t dword_110FEC;
extern uint32_t off_110FF0;

// rf_irq_handler @ 0x110d00, size 1068 bytes
// Doc: rf_bus_reset2 [rf]: Reset the RF bus DMA chain (instance 2) by clearing descriptors, reprogramming the control word from RF register 0x1812, and re-arming the DMA engine at 0x40240018.
// rf_bus_reset2 [rf]: Reset the RF bus DMA chain (instance 2) by clearing descriptors, reprogramming the control word from RF register 0x1812, and re-arming the DMA engine at 0x40240018.
int rf_irq_handler()
{
  int v0; // r4
  int v1; // r1
  int v2; // r1
  uint8_t *v3; // r6
  unsigned int v4; // r1
  int v5; // r5
  unsigned int v6; // r2
  char *v7; // r3
  uint32_t *v8; // r7
  uint32_t *v9; // r0
  int v10; // r3
  char *v11; // r1
  uint32_t *v12; // r0
  uint8_t *v13; // r5
  unsigned int v14; // r1
  int result; // r0
  uint8_t *v16; // r0
  unsigned int v17; // r1
  uint32_t *v18; // r3
  uint32_t *v19; // r0
  unsigned int v20; // r2
  uint32_t *v21; // r3
  unsigned int v22; // r3
  uint32_t *v23; // r7
  unsigned int v24; // r3
  char *v25; // r2
  uint32_t *v26; // r5
  int v27; // r6
  int v28; // r7
  unsigned int v29; // r3
  char *v30; // r2
  int v31; // r0
  int v32; // r5
  int v33; // r0
  int v34; // r1
  int v35; // r0
  int v36; // r1
  unsigned int *v37; // r2
  int v38; // r5
  int v39; // r1
  unsigned int v40; // r3
  int v41; // r1
  uint8_t *v42; // r6
  void *v43; // r3
  int v44; // r1
  void *v45; // r3
  int v46; // r1
  int *v47; // r2
  int v48; // r1
  int v49; // r3

  v0 = *(uint32_t *)off_110F94;
  if ( **(int16_t **)off_110F90 < 0 && !v0 )
  {
    flash_cmd_exec(dword_111130, dword_11112C, 39);
    goto LABEL_10;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v37 = (unsigned int *)off_11113C;
    v38 = *(uint32_t *)off_111150;
    *(uint32_t *)off_111150 = *(uint32_t *)off_111150;
    v39 = dword_111154;
    v40 = *v37 & 0xFFFFFFDF;
    *v37 = v40;
    check_interrupt_flag(2, v39, v38, v40);
    if ( (v38 & 4) != 0 )
    {
      v43 = off_11115C;
      v44 = dword_111178;
      *(uint8_t *)off_11115C = 1;
      check_interrupt_flag(2, v44, 1, v43);
    }
    if ( (v38 & 1) != 0 )
    {
      v42 = off_11115C;
      *(uint32_t *)off_111158 = 16;
      if ( *v42 )
      {
        check_interrupt_flag(2, dword_111188, 16, (uint8_t)*v42);
        *v42 = 0;
      }
      if ( *(uint8_t *)off_111160 )
      {
        v47 = (int *)off_111180;
        *((uint8_t *)off_111160 + 1) = 1;
        v48 = dword_111184;
        v49 = *v47 | 1;
        *v47 = v49;
        check_interrupt_flag(2, v48, v47, v49);
      }
      *(uint8_t *)off_111164 = 0;
    }
    if ( (v38 & 2) != 0 )
    {
      v45 = off_111164;
      v46 = dword_11117C;
      *(uint8_t *)off_111164 = 1;
      check_interrupt_flag(2, v46, 1, v45);
    }
    if ( (v38 & 8) != 0 )
      dispatch_event_handler(dword_111168, v41);
  }
  if ( (v0 & 1) != 0 )
  {
    dispatch_event_handler(dword_110F98, v0 << 31);
    *(uint32_t *)off_110F9C = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    rf_reg_update(*(uint32_t *)off_110FA0);
    *(uint32_t *)off_110F9C = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = *(uint32_t *)off_110FA4;
    *(uint32_t *)off_110FA4 = *(uint32_t *)off_110FA4;
    dispatch_event_handler(dword_110FB0, v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v31 = dword_111138;
  v32 = *(uint32_t *)off_111134;
  *(uint32_t *)off_111134 = *(uint32_t *)off_111134;
  dispatch_event_handler(v31, v32);
  if ( (v32 & 4) != 0 )
    *(uint32_t *)off_11113C &= ~1u;
  if ( (v32 & 8) == 0 )
  {
LABEL_10:
    v2 = v0 << 9;
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_50:
    v33 = dword_111144;
    v34 = *(uint32_t *)off_111140;
    *(uint32_t *)off_111140 = *(uint32_t *)off_111140;
    dispatch_event_handler(v33, v34);
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_51;
  }
  v2 = v0 << 9;
  *(uint32_t *)off_11113C &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_50;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_51:
  v35 = dword_11114C;
  v36 = *(uint32_t *)off_111148;
  *(uint32_t *)off_111148 = *(uint32_t *)off_111148;
  dispatch_event_handler(v35, v36);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v3 = off_110FB4;
    v4 = *((uint8_t *)off_110FB4 + 1621);
    if ( v4 >= *((uint8_t *)off_110FB4 + 1622) )
    {
      dispatch_event_handler(dword_111174, v4);
    }
    else
    {
      v5 = *(uint32_t *)off_110FBC;
      v6 = *((uint8_t *)off_110FB4 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_110FB8
                          * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_110FB4 + 1620) + 1)) >> 32) >> 6);
      v7 = (char *)off_110FB4 + 20 * v6;
      v8 = off_110FC4;
      *((uint32_t *)v7 + 1) = *(uint32_t *)off_110FC0;
      v3[1621] = v4 + 1;
      v9 = off_110FC8;
      *((uint32_t *)v7 + 2) = *v8;
      v7[12] = v5;
      v3[1620] = v6;
      v7[13] = BYTE1(v5) & 7;
      *v9 = 16;
      do
        v10 = *v9 & 0x20;
      while ( v10 );
      v11 = &v3[20 * v6];
      if ( (v11[13] & 4) == 0 )
        v10 = *(uint32_t *)(*((uint32_t *)v11 + 2) + 4);
      v12 = off_110FD0;
      *(uint32_t *)off_110FCC = v10;
      *v12 = 16;
      check_kernel_state(dword_110FD4);
      set_busy_flag_alt(2048);
    }
    *(uint32_t *)off_110F9C = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    dispatch_event_handler(dword_11116C, v2);
    *(uint32_t *)off_111170 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v13 = off_110FB4;
    v14 = *((uint8_t *)off_110FB4 + 2433);
    if ( v14 < *((uint8_t *)off_110FB4 + 2434) )
    {
      v27 = *(uint32_t *)off_111014;
      v28 = *(uint32_t *)off_11100C;
      v29 = *((uint8_t *)off_110FB4 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_111010
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_110FB4 + 2432) + 1)) >> 32) >> 5);
      v30 = (char *)off_110FB4 + 20 * v29;
      *((uint8_t *)off_110FB4 + 2432) = v29;
      v30[1645] = BYTE1(v27) & 7;
      *((uint32_t *)v30 + 409) = v28;
      *((uint32_t *)v30 + 410) = v28;
      v30[1644] = v27;
      v13[2433] = v14 + 1;
      check_kernel_state(v13 + 2436);
      set_busy_flag_alt(0x1000000);
    }
    else
    {
      dispatch_event_handler(dword_110FD8, v14);
    }
    *(uint32_t *)off_110F9C = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    v16 = off_110FDC;
    v17 = *((uint8_t *)off_110FDC + 3074);
    if ( v17 < *((uint8_t *)off_110FDC + 3073) )
    {
      v24 = *((uint8_t *)off_110FDC + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_110FDC + 3072) + 1)) >> 32) >> 7);
      v25 = (char *)off_110FDC + 16 * v24;
      *((uint32_t *)v25 + 1) = *(uint32_t *)off_111004;
      v26 = off_111008;
      v16[3072] = v24;
      *((uint16_t *)v25 + 4) = *v26;
      v16[3074] = v17 + 1;
      check_kernel_state(v16 + 3080);
      result = set_busy_flag_alt(1024);
    }
    else
    {
      result = dispatch_event_handler(dword_110FE0, v17);
    }
    v18 = off_110FE4;
    *(uint32_t *)off_110F9C = 4096;
    if ( !*v18 )
      *(uint8_t *)off_110FE8 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    v19 = off_110FDC;
    v20 = *((uint8_t *)off_110FDC + 6162);
    if ( *((uint8_t *)off_110FDC + 6161) > v20 )
    {
      v22 = *((uint8_t *)off_110FDC + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_110FF4
                           * (unsigned uint64_t)((unsigned int)*((uint8_t *)off_110FDC + 6160) + 1)) >> 32) >> 7);
      v23 = off_110FF8;
      *((uint8_t *)off_110FDC + 6160) = v22;
      v19[4 * v22 + 773] = *v23;
      LOWORD(v19[4 * v22 + 774]) = *(uint32_t *)off_110FFC;
      *((uint8_t *)v19 + 6162) = v20 + 1;
      check_kernel_state(dword_111000);
      result = set_busy_flag_alt(512);
    }
    else
    {
      result = dispatch_event_handler(dword_110FEC, v20);
    }
    v21 = off_110FF0;
    *(uint32_t *)off_110F9C = 2048;
    if ( !*v21 )
      *(uint8_t *)off_110FE8 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(uint32_t *)off_110F9C = 4;
  if ( (v0 & 8) != 0 )
    *(uint32_t *)off_110F9C = 8;
  return result;
}

