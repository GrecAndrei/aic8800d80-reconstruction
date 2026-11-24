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


extern uint32_t dword_1114FC;
extern uint32_t dword_111518;
extern uint32_t dword_111528;
extern uint32_t dword_111544;
extern uint32_t dword_111550;
extern uint32_t dword_1116DC;
extern uint32_t off_1114D4;
extern uint32_t off_1114D8;
extern uint32_t off_1114E0;
extern uint32_t off_1114E4;
extern uint32_t off_1114E8;
extern uint32_t off_1114EC;
extern uint32_t off_1114F0;
extern uint32_t off_1114F8;
extern uint32_t off_111500;
extern uint32_t off_111504;
extern uint32_t off_111508;
extern uint32_t off_11150C;
extern uint32_t off_111510;
extern uint32_t off_111514;
extern uint32_t off_111520;
extern uint32_t off_111524;
extern uint32_t off_11152C;
extern uint32_t off_111534;
extern uint32_t off_111538;
extern uint32_t off_111540;
extern uint32_t off_111548;
extern uint32_t off_11154C;
extern uint32_t off_111554;
extern uint32_t off_111558;
extern uint32_t off_1116D8;
extern uint32_t off_1116E0;
extern uint32_t off_1116EC;
extern uint32_t off_1116F4;
extern uint32_t off_1116F8;
extern uint32_t off_111700;
extern uint32_t off_111708;
extern uint32_t off_111710;
extern uint32_t off_111714;
extern uint32_t off_111718;
extern uint32_t off_11171C;
extern uint32_t off_111728;
extern uint32_t off_111738;

// check_short_value @ 0x111250, size 1160 bytes
int check_short_value()
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
  int *v20; // r5
  int v21; // r2
  uint8_t *v22; // r0
  unsigned int v23; // r1
  unsigned int v24; // r2
  uint32_t *v25; // r3
  int *v26; // r5
  int v27; // r2
  uint16_t *v28; // r0
  unsigned int v29; // r2
  uint32_t *v30; // r3
  unsigned int v31; // r3
  uint32_t *v32; // r7
  uint32_t *v33; // r1
  unsigned int v34; // r3
  char *v35; // r2
  uint32_t *v36; // r5
  int v37; // r6
  int v38; // r7
  unsigned int v39; // r3
  char *v40; // r2
  int v41; // r5
  int v42; // r1
  int v43; // r1
  uint32_t *v44; // r2
  int v45; // r5
  uint8_t *v46; // r6
  uint32_t *v47; // r2

  v0 = *(uint32_t *)off_1114D8;
  if ( **(uint16_t **)off_1114D4 < 0 && !v0 )
  {
    mmio_write_field((int)aIntStatus0, (int)aSdioIsr, 39);
    goto LABEL_10;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v44 = off_1116F4;
    v45 = *(uint32_t *)off_111708;
    *(uint32_t *)off_111708 = *(uint32_t *)off_111708;
    *v44 &= ~0x20u;
    check_feature_flag(2, "int2dev:%d\n", v45);
    if ( (v45 & 4) != 0 )
    {
      *(uint8_t *)off_111714 = 1;
      check_feature_flag(2, &aClrPreSleep[4]);
    }
    if ( (v45 & 1) != 0 )
    {
      v46 = off_111714;
      *(uint32_t *)off_111710 = 16;
      if ( *v46 )
      {
        check_feature_flag(2, aClrPreSleep);
        *v46 = 0;
      }
      if ( *(uint8_t *)off_111718 )
      {
        v47 = off_111738;
        *((uint8_t *)off_111718 + 1) = 1;
        *v47 |= 1u;
        check_feature_flag(2, aSoftwk);
      }
      *(uint8_t *)off_11171C = 0;
    }
    if ( (v45 & 2) != 0 )
    {
      *(uint8_t *)off_11171C = 1;
      check_feature_flag(2, aBit1);
    }
    if ( (v45 & 8) != 0 )
      alloc_tx_event(aNotUsed);
  }
  if ( (v0 & 1) != 0 )
  {
    alloc_tx_event(aSdioHostSoftRe, v0 << 31);
    *(uint32_t *)off_1114E0 = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    timer_get_raw(*(uint32_t *)off_1114E4);
    *(uint32_t *)off_1114E0 = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = off_1114EC;
    v2 = *(uint32_t *)off_1114E8;
    v3 = off_1114F0;
    *(uint32_t *)off_1114E8 = *(uint32_t *)off_1114E8;
    alloc_tx_event("sdio func1 error bit:%x, func1 free cnt=%d, func1 free queue2 cnt=%d\r\n", v2, *v3, *v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v41 = *(uint32_t *)off_1116EC;
  *(uint32_t *)off_1116EC = *(uint32_t *)off_1116EC;
  alloc_tx_event("sdio func1 other bit:%x\r\n", v41);
  if ( (v41 & 4) != 0 )
    *(uint32_t *)off_1116F4 &= ~1u;
  if ( (v41 & 8) == 0 )
  {
LABEL_10:
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_60:
    v42 = *(uint32_t *)off_1116F8;
    *(uint32_t *)off_1116F8 = *(uint32_t *)off_1116F8;
    alloc_tx_event("sdio func2 error bit:%x\r\n", v42);
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_61;
  }
  *(uint32_t *)off_1116F4 &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_60;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_61:
  v43 = *(uint32_t *)off_111700;
  *(uint32_t *)off_111700 = *(uint32_t *)off_111700;
  alloc_tx_event("sdio func2 other bit:%x\r\n", v43);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v4 = off_1114F8;
    v5 = *((uint8_t *)off_1114F8 + 1621);
    v6 = *((uint8_t *)off_1114F8 + 1622);
    if ( v5 >= v6 )
    {
      alloc_tx_event("rxused=%d, total=%d\r\n", v5, v6);
    }
    else
    {
      v7 = *(uint32_t *)off_111500;
      v8 = *((uint8_t *)off_1114F8 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_1114FC
                          * (uint64_t)((unsigned int)*((uint8_t *)off_1114F8 + 1620) + 1)) >> 32) >> 6);
      v9 = (char *)off_1114F8 + 20 * v8;
      v10 = off_111508;
      *((uint32_t *)v9 + 1) = *(uint32_t *)off_111504;
      v4[1621] = v5 + 1;
      v11 = off_11150C;
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
      v15 = off_111514;
      *(uint32_t *)off_111510 = v12;
      *v15 = 16;
      wlan_ioctl_handler_1(dword_111518, &v4[4 * v14]);
      irq_disable_global_2(256);
    }
    *(uint32_t *)off_1114E0 = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    alloc_tx_event(aUnexpectH2dCon);
    *(uint32_t *)off_111728 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v16 = off_1114F8;
    v17 = *((uint8_t *)off_1114F8 + 2433);
    v18 = *((uint8_t *)off_1114F8 + 2434);
    if ( v17 < v18 )
    {
      v37 = *(uint32_t *)off_1116E0;
      v38 = *(uint32_t *)off_1116D8;
      v39 = *((uint8_t *)off_1114F8 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_1116DC
                           * (uint64_t)((unsigned int)*((uint8_t *)off_1114F8 + 2432) + 1)) >> 32) >> 5);
      v40 = (char *)off_1114F8 + 20 * v39;
      *((uint8_t *)off_1114F8 + 2432) = v39;
      v40[1645] = BYTE1(v37) & 7;
      *((uint32_t *)v40 + 409) = v38;
      *((uint32_t *)v40 + 410) = v38;
      v40[1644] = v37;
      v16[2433] = v17 + 1;
      wlan_ioctl_handler_1((int)(v16 + 2436), (uint32_t *)v40 + 408);
      irq_disable_global_2(0x400000);
    }
    else
    {
      alloc_tx_event("msgrxused=%d, total=%d\r\n", v17, v18);
    }
    *(uint32_t *)off_1114E0 = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    if ( *(uint8_t *)off_111520 )
    {
      v20 = (int *)off_111524;
      v21 = BYTE1(((uint32_t *)(uintptr_t)off_111524)[92]);
      *(uint8_t *)off_111520 = 0;
      if ( v21 )
        mmio_set_bit_1(1);
      else
        mmio_clear_bit_1(1);
      if ( *((uint8_t *)v20 + 374) == 1 )
        mem_set_util((uint32_t *)dword_111528);
    }
    v22 = off_11152C;
    v23 = *((uint8_t *)off_11152C + 3074);
    v24 = *((uint8_t *)off_11152C + 3073);
    if ( v23 < v24 )
    {
      v34 = *((uint8_t *)off_11152C + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111544
                           * (uint64_t)((unsigned int)*((uint8_t *)off_11152C + 3072) + 1)) >> 32) >> 7);
      v35 = (char *)off_11152C + 16 * v34;
      *((uint32_t *)v35 + 1) = *(uint32_t *)off_111554;
      v36 = off_111558;
      v22[3072] = v34;
      *((uint16_t *)v35 + 4) = *v36;
      v22[3074] = v23 + 1;
      wlan_ioctl_handler_1((int)(v22 + 3080), v35);
      result = irq_disable_global_2(128);
    }
    else
    {
      result = alloc_tx_event("txcused=%d, total=%d\r\n", v23, v24);
    }
    v25 = off_111534;
    *(uint32_t *)off_1114E0 = 4096;
    if ( !*v25 )
      *(uint8_t *)off_111538 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    if ( *(uint8_t *)off_111520 )
    {
      v26 = (int *)off_111524;
      v27 = BYTE1(((uint32_t *)(uintptr_t)off_111524)[92]);
      *(uint8_t *)off_111520 = 0;
      if ( v27 )
        mmio_set_bit_1(1);
      else
        mmio_clear_bit_1(1);
      if ( *((uint8_t *)v26 + 374) == 1 )
        mem_set_util((uint32_t *)dword_111528);
    }
    v28 = off_11152C;
    v29 = *((uint8_t *)off_11152C + 6162);
    if ( *((uint8_t *)off_11152C + 6161) > v29 )
    {
      v31 = *((uint8_t *)off_11152C + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111544
                           * (uint64_t)((unsigned int)*((uint8_t *)off_11152C + 6160) + 1)) >> 32) >> 7);
      v32 = off_111548;
      *((uint8_t *)off_11152C + 6160) = v31;
      v33 = &v28[8 * v31 + 1544];
      v33[1] = *v32;
      v28[8 * v31 + 1548] = *(uint32_t *)off_11154C;
      *((uint8_t *)v28 + 6162) = v29 + 1;
      wlan_ioctl_handler_1(dword_111550, v33);
      result = irq_disable_global_2(64);
    }
    else
    {
      result = alloc_tx_event("txcmsgused=%d, msgtotal=%d\r\n", v29, v29);
    }
    v30 = off_111540;
    *(uint32_t *)off_1114E0 = 2048;
    if ( !*v30 )
      *(uint8_t *)off_111538 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(uint32_t *)off_1114E0 = 4;
  if ( (v0 & 8) != 0 )
    *(uint32_t *)off_1114E0 = 8;
  return result;
}
