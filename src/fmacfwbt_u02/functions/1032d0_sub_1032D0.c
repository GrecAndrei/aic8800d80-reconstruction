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


extern uint32_t dword_103444;
extern uint32_t dword_1037A4;
extern uint32_t dword_1037A8;
extern uint32_t dword_1037B0;
extern uint32_t dword_1037BC;
extern uint32_t dword_1037D4;
extern uint32_t dword_1037D8;
extern uint32_t off_103434;
extern uint32_t off_103438;
extern uint32_t off_10343C;
extern uint32_t off_103440;
extern uint32_t off_103448;
extern uint32_t off_10344C;
extern uint32_t off_103450;
extern uint32_t off_103454;
extern uint32_t off_103458;
extern uint32_t off_10376C;
extern uint32_t off_103770;
extern uint32_t off_103774;
extern uint32_t off_103778;
extern uint32_t off_10377C;
extern uint32_t off_103780;
extern uint32_t off_103788;
extern uint32_t off_10378C;
extern uint32_t off_103790;
extern uint32_t off_103794;
extern uint32_t off_103798;
extern uint32_t off_10379C;
extern uint32_t off_1037A0;
extern uint32_t off_1037AC;
extern uint32_t off_1037B4;
extern uint32_t off_1037B8;
extern uint32_t off_1037C8;
extern uint32_t off_1037CC;
extern uint32_t off_1037DC;
extern uint32_t off_10398C;
extern uint32_t off_103990;
extern uint32_t off_103994;
extern uint32_t off_103998;
extern uint32_t off_10399C;
extern uint32_t off_1039A0;
extern uint32_t off_1039A4;
extern uint32_t off_1039A8;
extern uint32_t off_1039B4;
extern uint32_t off_1039BC;

// hw_enable @ 0x1032d0, size 1722 bytes
int hw_enable()
{
  uint8_t *v0; // r4
  int *v1; // r2
  uint32_t *v2; // r0
  int v3; // r1
  uint32_t *v4; // r5
  uint8_t **v5; // r5
  uint32_t *v6; // r1
  int v7; // r6
  uint32_t *v8; // r0
  int *v9; // r8
  int v10; // r2
  uint32_t *v11; // r3
  uint32_t *v12; // r1
  int v13; // r0
  uint32_t *v14; // r3
  uint32_t *v15; // r1
  uint32_t *v16; // r4
  uint32_t *v17; // r5
  char *v18; // r6
  int v19; // r9
  int i; // r4
  int v21; // r0
  uint32_t *v22; // r4
  int v23; // r9
  int v24; // r10
  int k; // r5
  int v26; // r0
  int v27; // r5
  int v28; // r10
  int v29; // r0
  int v30; // r9
  uint64_t v31; // kr00_8
  int v32; // zf
  uint8_t v33; // r2
  int v34; // r3
  unsigned int v35; // r1
  int v36; // r3
  int *v37; // r4
  int *v38; // r2
  int v39; // r0
  int v40; // r1
  int *v41; // r3
  int v42; // r4
  int *v43; // r1
  uint16_t *v44; // r5
  int v45; // r0
  int v46; // r2
  int v47; // r0
  unsigned int *v48; // r2
  int v49; // r0
  int j; // r4
  uint8_t v52; // r2
  int *v53; // r2
  int v54; // r3
  int v55; // r6
  unsigned int v56; // r3
  int v57; // r0
  int *v58; // r5
  uint8_t *v59; // r4
  uint32_t *v60; // r3
  uint32_t *v61; // r1
  uint8_t *v62; // r3
  char v63; // r1
  char v64; // r2
  uint32_t *v65; // r4
  int v66; // r11
  uint32_t *v67; // r6
  uint8_t *v68; // r4
  uint8_t *v69; // r7
  int n; // r5
  char v71; // t1
  int v72; // r3
  uint32_t *v73; // r5
  uint32_t *v74; // r7
  int v75; // r11
  char *v76; // r10
  int m; // r4
  char v78; // t1
  int v79; // r1
  char *v80; // [sp+4h] [bp-30h]
  uint8_t v81[4]; // [sp+Ch] [bp-28h] BYREF
  uint32_t v82[3]; // [sp+10h] [bp-24h] BYREF
  uint8_t a2[24]; // [sp+1Ch] [bp-18h] BYREF

  v0 = off_103438;
  *((uint32_t *)off_103434 + 64) = 8;
  if ( !v0[2] )
    *((uint32_t *)off_10343C + 2) = *((uint32_t *)off_10343C + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_10343C;
  while ( (*((uint32_t *)off_10343C + 12) & 0x22) != 2 )
    ;
  v2 = off_103440;
  v3 = dword_103444;
  v4 = off_103434;
  *((uint32_t *)off_10343C + 2) = *((uint32_t *)off_10343C + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v5 = (uint8_t **)off_103448;
  *v1 = *v1 & 0x37F | 0x80 | *v1 & v3;
  if ( **v5 == 1 )
  {
    *v1 = *v1 & 0x3F7 | 8 | *v1 & v3;
    v1[21] = v3 & v1[21] | v1[21] & 0x3F7 | 8;
  }
  init_oscillators();
  v6 = off_10343C;
  v7 = dword_103444;
  v8 = off_103434;
  v9 = (int *)off_103458;
  *(uint32_t *)off_10343C = *(uint32_t *)off_10343C & 0x3EF | 0x10 | *(uint32_t *)off_10343C & dword_103444;
  v6[21] = v6[21] & 0x3EF | 0x10 | v6[21] & v7;
  v8[22] &= 0xFFFFFFC1;
  v10 = *((uint8_t *)v9 + 177);
  v8[22] |= 0x26u;
  if ( v10 && (v6[12] & 0x40) == 0 && (v6[12] & 4) != 0 )
  {
    v53 = (int *)off_103990;
    v54 = v9[42] | 0x2000000;
    *(uint8_t *)off_10398C = 1;
    *v53 = v54;
    v8[14] |= 0x10u;
  }
  else
  {
    *(uint32_t *)off_10344C = v9[42];
  }
  if ( v0[2] )
  {
    if ( **(uint8_t **)off_103450 == 2 )
    {
      v60 = off_1039A0;
      v61 = off_1039A4;
      *((uint32_t *)off_1039A0 + 20) |= 0x40000u;
      v61[7] &= ~0x100u;
      v60[9] = v60[9] & 0xFFFFFF00 | 0x60;
      v60[9] = v60[9] & 0xFFFF00FF | 0xDF00;
LABEL_13:
      irq_install();
      clock_enable();
      if ( !*(uint32_t *)off_103454 )
        goto LABEL_17;
      goto LABEL_14;
    }
    v11 = off_10343C;
    **(uint8_t **)off_103450 = 2;
    v12 = off_103434;
    v13 = (uint8_t)v0[2];
    v11[20] |= 0x40000u;
    v12[7] &= ~0x100u;
    v11[9] = v11[9] & 0xFFFFFF00 | 0x60;
    v11[9] = v11[9] & 0xFFFF00FF | 0xDF00;
    if ( v13 )
      goto LABEL_13;
  }
  else
  {
    v14 = off_10376C;
    v15 = off_103770;
    *((uint32_t *)off_10376C + 20) |= 0x40000u;
    v15[7] &= ~0x100u;
    v14[9] = v14[9] & 0xFFFFFF00 | 0x60;
    v14[9] = v14[9] & 0xFFFF00FF | 0xDF00;
  }
  watchdog_init();
  clock_enable();
  if ( *(uint32_t *)off_103774 )
  {
LABEL_14:
    periph_enable();
    system_init_mmio();
    radio_init_1();
  }
LABEL_17:
  v16 = off_103770;
  radio_process_packet();
  v16[4] |= 2u;
  read_hw_status();
  if ( (*v16 & 0x2000000) != 0 )
  {
    v17 = off_103778;
    v18 = (char *)off_10377C;
    v19 = 1;
    for ( i = 0; i != 3; ++i )
    {
      v21 = load_calib_data(i, *v17 + 3 * i);
      if ( v21 != 546 )
      {
        v18[1] |= 1u;
        v19 = 0;
      }
    }
    if ( v19 )
    {
      for ( j = 0; j != 3; ++j )
      {
        a2[0] = 0;
        if ( syscall10_flash_erase(j, a2) <= 1 )
        {
          v52 = a2[0];
          *(uint8_t *)(*v17 + j) = a2[0];
          *(uint8_t *)(*v17 + j + 3) = v52;
          *(uint8_t *)(*v17 + j + 6) = v52;
        }
      }
    }
    v22 = off_103780;
    v23 = dword_1037D4;
    v24 = 1;
    for ( k = 0; k != 3; ++k )
    {
      v26 = load_calib_data2(k, *v22 + 6 * k);
      if ( v26 != v23 )
      {
        v18[1] |= 1u;
        v24 = 0;
      }
    }
    if ( v24 )
    {
      v27 = 0;
      v28 = dword_1037D8;
      a2[0] = 0;
      v29 = 2;
      v30 = 4;
      do
      {
        v31 = (unsigned int)v28 * (uint64_t)(unsigned int)(2 * v27);
        v32 = v30 == HIDWORD(v31) >> 1;
        v30 = HIDWORD(v31) >> 1;
        if ( !v32 )
          v29 = syscall11_flash_write(HIDWORD(v31) >> 1, a2);
        if ( v29 <= 1 )
        {
          v33 = a2[0];
          *(uint8_t *)(*v22 + v27) = a2[0];
          v34 = *v22 + v27;
          *(uint8_t *)(v34 + 6) = v33;
          *(uint8_t *)(v34 + 12) = v33;
        }
        ++v27;
      }
      while ( v27 != 6 );
    }
    v35 = 31 - __clz(get_hw_info_1b());
    *v18 = v35;
  }
  else
  {
    memset(v82, 0, sizeof(v82));
    v55 = ioctl_cmd_2((int)v82);
    if ( v55 )
    {
      v18 = (char *)off_103994;
    }
    else
    {
      v73 = off_1039BC;
      printf_wrapper(aFlTxpwrOfst24g);
      v74 = v82;
      do
      {
        printf_wrapper("\r\n  [%d] =", v55);
        v75 = 3 * v55;
        v76 = (char *)v74;
        for ( m = 0; m != 3; ++m )
        {
          v78 = *v76++;
          *(uint8_t *)(*v73 + v75 + m) = v78;
          v79 = *(char *)(*v73 + v75 + m);
          printf_wrapper(" %d", v79);
        }
        ++v55;
        v74 = (uint32_t *)((char *)v74 + 3);
      }
      while ( v55 != 3 );
      v18 = (char *)off_103994;
      printf_wrapper((const char *)off_1039B4);
      v18[1] |= 1u;
    }
    memset(a2, 0, 20);
    if ( !ioctl_cmd_4((int)a2) )
    {
      v65 = off_1039A8;
      printf_wrapper(aFlTxpwrOfst5g);
      v66 = 0;
      v80 = v18;
      v67 = v65;
      v68 = a2;
      do
      {
        printf_wrapper("\r\n  [%d] =", v66);
        v69 = v68;
        for ( n = 0; n != 6; ++n )
        {
          v71 = *v69++;
          *(uint8_t *)(*v67 + n + 6 * v66) = v71;
          v72 = *v67 + n;
          printf_wrapper(" %d", *(char *)(v72 + 6 * v66));
        }
        ++v66;
        v68 += 6;
      }
      while ( v66 != 3 );
      v18 = v80;
      printf_wrapper((const char *)off_1039B4);
      v80[1] |= 1u;
    }
    if ( ioctl_cmd_0x80((int)v81) )
    {
      v35 = -1;
      *v18 = -1;
    }
    else
    {
      v56 = v81[0];
      *v18 = v81[0];
      v35 = v56;
    }
  }
  printf_wrapper("cal_ver=%d\n", v35);
  if ( *((uint8_t *)v9 + 372) )
  {
    if ( (*(uint32_t *)off_103770 & 0x2000000) != 0 )
    {
      if ( get_hw_info_bit18() )
      {
        v57 = get_hw_info_field0();
        v58 = (int *)off_103998;
        v59 = off_10399C;
        *(uint8_t *)off_10399C = *((uint8_t *)off_103998 + v57);
        v59[1] = *((uint8_t *)v58 + get_hw_info_field1());
        v59[2] = *((uint8_t *)v58 + get_hw_info_field2());
      }
    }
    else
    {
      *(uint32_t *)a2 = 0;
      if ( !ioctl_cmd_0x20((int)a2) )
      {
        v62 = off_10399C;
        v63 = *((uint8_t *)off_103998 + a2[1]);
        v64 = *((uint8_t *)off_103998 + a2[2]);
        *(uint8_t *)off_10399C = *((uint8_t *)off_103998 + a2[0]);
        v62[1] = v63;
        v62[2] = v64;
      }
    }
  }
  v36 = off_10378C;
  v37 = (int *)off_103790[0];
  *(uint32_t *)off_103788 &= 0xFFFFFFC7;
  memcpy(0, 0, 0x10u, v36);
  memcpy(0, 16, 0x10u, off_103794);
  memcpy(0, 32, 0x10u, v37[2]);
  memcpy(0, 48, 0x10u, v37[1]);
  memcpy(0, 64, 0x10u, *v37);
  memcpy(1, 0, 0x10u, *(uint32_t *)off_103798);
  memcpy(1, 16, 0x10u, ((uint32_t *)(uintptr_t)off_10379C)[0]);
  adc_read_ch1();
  hw_init(1);
  adc_read_ch0(0);
  hw_init(0);
  if ( (v9[98] & 4) != 0 )
  {
    v38 = (int *)off_1037A0;
    v39 = dword_1037A4;
    v40 = dword_1037A8;
    ((uint32_t *)(uintptr_t)off_1037A0)[13] = dword_1037A4;
    v38[14] = v40;
    --v39;
    v40 -= 10;
    v38[109] = v39;
    v38[110] = v40;
    v39 += 2;
    v40 -= 8;
    v41 = (int *)off_1037AC;
    v38[204] = v39;
    v38[205] = v40;
    v39 += 33;
    v40 += 41;
    v42 = dword_1037B0;
    v38[206] = v39;
    v38[15] = v40;
    v39 -= 7;
    v38[111] = v40;
    v38[207] = v40;
    v38[303] = v40;
    v38[399] = v40;
    v38[495] = v40;
    v40 -= 16;
    v38[302] = v40;
    v38[398] = v40;
    v38[494] = v40;
    v38[300] = v42;
    v38[396] = v42;
    v38[492] = v42;
    v38[301] = v39;
    v38[397] = v39;
    v38[493] = v39;
    v43 = v41 + 1896;
    do
    {
      v41[318] |= 0x8000u;
      v41 += 316;
    }
    while ( v41 != v43 );
  }
  v44 = off_1037B8;
  *(uint32_t *)off_1037B4 |= 0x8000000u;
  v45 = ke_event_handler();
  v46 = ((int)(((uint64_t)(dword_1037BC * (uint64_t)(4 * (v45 - 35))) >> 32) + 4 * (v45 - 35)) >> 2)
      - ((4 * (v45 - 35)) >> 31)
      + 120;
  *(uint16_t *)off_1037DC = v46;
  *v44 = v46;
  ke_event_schedule_1("Init T=%d C, ipa_target=%d\n", v45, v46);
  v47 = board_init((int)a2);
  printf_wrapper("cal_ipa_5g offset=%d, cgm=%d\n", v47, *(uint32_t *)a2);
  if ( (v18[1] & 1) != 0 && *v18 < 0 )
  {
    v48 = (unsigned int *)off_1037CC;
    *(uint32_t *)off_1037C8 = *(uint32_t *)off_1037C8 & 0xFFFFFF87 | 0x40;
    *v48 = *v48 & 0xFFF87FFF | 0x40000;
  }
  v49 = board_init_2();
  return printf_wrapper("cal_ipa_24g offset=%d\n", v49);
}
