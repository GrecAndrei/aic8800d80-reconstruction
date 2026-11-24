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


extern uint32_t dword_11163C;
extern uint32_t dword_111658;
extern uint32_t dword_111668;
extern uint32_t dword_111684;
extern uint32_t dword_111690;
extern uint32_t dword_11181C;
extern uint32_t off_111614;
extern uint32_t off_111618;
extern uint32_t off_111620;
extern uint32_t off_111624;
extern uint32_t off_111628;
extern uint32_t off_11162C;
extern uint32_t off_111630;
extern uint32_t off_111638;
extern uint32_t off_111640;
extern uint32_t off_111644;
extern uint32_t off_111648;
extern uint32_t off_11164C;
extern uint32_t off_111650;
extern uint32_t off_111654;
extern uint32_t off_111660;
extern uint32_t off_111664;
extern uint32_t off_11166C;
extern uint32_t off_111674;
extern uint32_t off_111678;
extern uint32_t off_111680;
extern uint32_t off_111688;
extern uint32_t off_11168C;
extern uint32_t off_111694;
extern uint32_t off_111698;
extern uint32_t off_111818;
extern uint32_t off_111820;
extern uint32_t off_11182C;
extern uint32_t off_111834;
extern uint32_t off_111838;
extern uint32_t off_111840;
extern uint32_t off_111848;
extern uint32_t off_111850;
extern uint32_t off_111854;
extern uint32_t off_111858;
extern uint32_t off_11185C;
extern uint32_t off_111868;
extern uint32_t off_111878;

// check_mmio_and_mem @ 0x111390, size 1160 bytes
int check_mmio_and_mem()
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

  v0 = *(uint32_t *)off_111618;
  if ( **(uint16_t **)off_111614 < 0 && !v0 )
  {
    call_shared_handler((int)aIntStatus0, (int)aSdioIsr, 39);
    goto LABEL_10;
  }
  if ( (v0 & 0x2000) != 0 )
  {
    v44 = off_111834;
    v45 = *(uint32_t *)off_111848;
    *(uint32_t *)off_111848 = *(uint32_t *)off_111848;
    *v44 &= ~0x20u;
    check_status_bits(2, "int2dev:%d\n", v45);
    if ( (v45 & 4) != 0 )
    {
      *(uint8_t *)off_111854 = 1;
      check_status_bits(2, &aClrPreSleep[4]);
    }
    if ( (v45 & 1) != 0 )
    {
      v46 = off_111854;
      *(uint32_t *)off_111850 = 16;
      if ( *v46 )
      {
        check_status_bits(2, aClrPreSleep);
        *v46 = 0;
      }
      if ( *(uint8_t *)off_111858 )
      {
        v47 = off_111878;
        *((uint8_t *)off_111858 + 1) = 1;
        *v47 |= 1u;
        check_status_bits(2, aSoftwk);
      }
      *(uint8_t *)off_11185C = 0;
    }
    if ( (v45 & 2) != 0 )
    {
      *(uint8_t *)off_11185C = 1;
      check_status_bits(2, aBit1);
    }
    if ( (v45 & 8) != 0 )
      event_dispatch(aNotUsed);
  }
  if ( (v0 & 1) != 0 )
  {
    event_dispatch(aSdioHostSoftRe, v0 << 31);
    *(uint32_t *)off_111620 = 1;
  }
  if ( (v0 & 0x20) != 0 )
  {
    read_random_from_mmio(*(uint32_t *)off_111624);
    *(uint32_t *)off_111620 = 32;
  }
  if ( (v0 & 0x4000) != 0 )
  {
    v1 = off_11162C;
    v2 = *(uint32_t *)off_111628;
    v3 = off_111630;
    *(uint32_t *)off_111628 = *(uint32_t *)off_111628;
    event_dispatch("sdio func1 error bit:%x, func1 free cnt=%d, func1 free queue2 cnt=%d\r\n", v2, *v3, *v1);
  }
  if ( (v0 & 0x8000) == 0 )
    goto LABEL_10;
  v41 = *(uint32_t *)off_11182C;
  *(uint32_t *)off_11182C = *(uint32_t *)off_11182C;
  event_dispatch("sdio func1 other bit:%x\r\n", v41);
  if ( (v41 & 4) != 0 )
    *(uint32_t *)off_111834 &= ~1u;
  if ( (v41 & 8) == 0 )
  {
LABEL_10:
    if ( (v0 & 0x400000) == 0 )
      goto LABEL_11;
LABEL_60:
    v42 = *(uint32_t *)off_111838;
    *(uint32_t *)off_111838 = *(uint32_t *)off_111838;
    event_dispatch("sdio func2 error bit:%x\r\n", v42);
    if ( (v0 & 0x800000) == 0 )
      goto LABEL_12;
    goto LABEL_61;
  }
  *(uint32_t *)off_111834 &= ~4u;
  if ( (v0 & 0x400000) != 0 )
    goto LABEL_60;
LABEL_11:
  if ( (v0 & 0x800000) == 0 )
    goto LABEL_12;
LABEL_61:
  v43 = *(uint32_t *)off_111840;
  *(uint32_t *)off_111840 = *(uint32_t *)off_111840;
  event_dispatch("sdio func2 other bit:%x\r\n", v43);
LABEL_12:
  if ( (v0 & 0x400) != 0 )
  {
    v4 = off_111638;
    v5 = *((uint8_t *)off_111638 + 1621);
    v6 = *((uint8_t *)off_111638 + 1622);
    if ( v5 >= v6 )
    {
      event_dispatch("rxused=%d, total=%d\r\n", v5, v6);
    }
    else
    {
      v7 = *(uint32_t *)off_111640;
      v8 = *((uint8_t *)off_111638 + 1620)
         + 1
         - 81
         * ((unsigned int)(((unsigned int)dword_11163C
                          * (uint64_t)((unsigned int)*((uint8_t *)off_111638 + 1620) + 1)) >> 32) >> 6);
      v9 = (char *)off_111638 + 20 * v8;
      v10 = off_111648;
      *((uint32_t *)v9 + 1) = *(uint32_t *)off_111644;
      v4[1621] = v5 + 1;
      v11 = off_11164C;
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
      v15 = off_111654;
      *(uint32_t *)off_111650 = v12;
      *v15 = 16;
      cmd_handler_a(dword_111658, &v4[4 * v14]);
      unknown_func_12d104(256);
    }
    *(uint32_t *)off_111620 = 1024;
  }
  if ( (v0 & 0x200) != 0 )
  {
    event_dispatch(aUnexpectH2dCon);
    *(uint32_t *)off_111868 = 512;
  }
  if ( (v0 & 0x100) != 0 )
  {
    v16 = off_111638;
    v17 = *((uint8_t *)off_111638 + 2433);
    v18 = *((uint8_t *)off_111638 + 2434);
    if ( v17 < v18 )
    {
      v37 = *(uint32_t *)off_111820;
      v38 = *(uint32_t *)off_111818;
      v39 = *((uint8_t *)off_111638 + 2432)
          + 1
          - 40
          * ((unsigned int)(((unsigned int)dword_11181C
                           * (uint64_t)((unsigned int)*((uint8_t *)off_111638 + 2432) + 1)) >> 32) >> 5);
      v40 = (char *)off_111638 + 20 * v39;
      *((uint8_t *)off_111638 + 2432) = v39;
      v40[1645] = BYTE1(v37) & 7;
      *((uint32_t *)v40 + 409) = v38;
      *((uint32_t *)v40 + 410) = v38;
      v40[1644] = v37;
      v16[2433] = v17 + 1;
      cmd_handler_a((int)(v16 + 2436), (uint32_t *)v40 + 408);
      unknown_func_12d104(0x400000);
    }
    else
    {
      event_dispatch("msgrxused=%d, total=%d\r\n", v17, v18);
    }
    *(uint32_t *)off_111620 = 256;
  }
  result = v0 << 19;
  if ( (v0 & 0x1000) != 0 )
  {
    if ( *(uint8_t *)off_111660 )
    {
      v20 = (int *)off_111664;
      v21 = BYTE1(((uint32_t *)(uintptr_t)off_111664)[92]);
      *(uint8_t *)off_111660 = 0;
      if ( v21 )
        gpio_set_bit(1);
      else
        gpio_clear_bit(1);
      if ( *((uint8_t *)v20 + 374) == 1 )
        fault_handler((uint32_t *)dword_111668);
    }
    v22 = off_11166C;
    v23 = *((uint8_t *)off_11166C + 3074);
    v24 = *((uint8_t *)off_11166C + 3073);
    if ( v23 < v24 )
    {
      v34 = *((uint8_t *)off_11166C + 3072)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111684
                           * (uint64_t)((unsigned int)*((uint8_t *)off_11166C + 3072) + 1)) >> 32) >> 7);
      v35 = (char *)off_11166C + 16 * v34;
      *((uint32_t *)v35 + 1) = *(uint32_t *)off_111694;
      v36 = off_111698;
      v22[3072] = v34;
      *((uint16_t *)v35 + 4) = *v36;
      v22[3074] = v23 + 1;
      cmd_handler_a((int)(v22 + 3080), v35);
      result = unknown_func_12d104(128);
    }
    else
    {
      result = event_dispatch("txcused=%d, total=%d\r\n", v23, v24);
    }
    v25 = off_111674;
    *(uint32_t *)off_111620 = 4096;
    if ( !*v25 )
      *(uint8_t *)off_111678 &= ~1u;
  }
  if ( (v0 & 0x800) != 0 )
  {
    if ( *(uint8_t *)off_111660 )
    {
      v26 = (int *)off_111664;
      v27 = BYTE1(((uint32_t *)(uintptr_t)off_111664)[92]);
      *(uint8_t *)off_111660 = 0;
      if ( v27 )
        gpio_set_bit(1);
      else
        gpio_clear_bit(1);
      if ( *((uint8_t *)v26 + 374) == 1 )
        fault_handler((uint32_t *)dword_111668);
    }
    v28 = off_11166C;
    v29 = *((uint8_t *)off_11166C + 6162);
    if ( *((uint8_t *)off_11166C + 6161) > v29 )
    {
      v31 = *((uint8_t *)off_11166C + 6160)
          + 1
          - 192
          * ((unsigned int)(((unsigned int)dword_111684
                           * (uint64_t)((unsigned int)*((uint8_t *)off_11166C + 6160) + 1)) >> 32) >> 7);
      v32 = off_111688;
      *((uint8_t *)off_11166C + 6160) = v31;
      v33 = &v28[8 * v31 + 1544];
      v33[1] = *v32;
      v28[8 * v31 + 1548] = *(uint32_t *)off_11168C;
      *((uint8_t *)v28 + 6162) = v29 + 1;
      cmd_handler_a(dword_111690, v33);
      result = unknown_func_12d104(64);
    }
    else
    {
      result = event_dispatch("txcmsgused=%d, msgtotal=%d\r\n", v29, v29);
    }
    v30 = off_111680;
    *(uint32_t *)off_111620 = 2048;
    if ( !*v30 )
      *(uint8_t *)off_111678 &= ~2u;
  }
  if ( (v0 & 4) != 0 )
    *(uint32_t *)off_111620 = 4;
  if ( (v0 & 8) != 0 )
    *(uint32_t *)off_111620 = 8;
  return result;
}
