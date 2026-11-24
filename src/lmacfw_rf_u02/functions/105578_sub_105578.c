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


extern uint32_t off_105848;
extern uint32_t off_10584C;
extern uint32_t off_105850;
extern uint32_t off_105854;
extern uint32_t off_105858;
extern uint32_t off_10585C;
extern uint32_t off_105864;
extern uint32_t off_105868;
extern uint32_t off_10586C;
extern uint32_t off_105870;
extern uint32_t off_105874;
extern uint32_t off_105878;
extern uint32_t off_10587C;
extern uint32_t off_105880;
extern uint32_t off_105884;
extern uint32_t off_105888;
extern uint32_t off_105B9C;
extern uint32_t off_105BA0;
extern uint32_t off_105BA4;
extern uint32_t off_105BA8;
extern uint32_t off_105BAC;
extern uint32_t off_105BB4;
extern uint32_t off_105BB8;
extern uint32_t off_105BC0;
extern uint32_t off_105BC8;
extern uint32_t off_105BD0;
extern uint32_t off_105BD4;
extern uint32_t off_105BD8;
extern uint32_t off_105BDC;
extern uint32_t off_105BE0;
extern uint32_t off_105BE4;
extern uint32_t off_105BE8;
extern uint32_t off_105DC0;
extern uint32_t off_105DC4;
extern uint32_t off_105DC8;

// prcm_stop @ 0x105578, size 2120 bytes
unsigned int * prcm_stop(int a1, int a2, int a3, unsigned int a4, uint8_t a5, int a6)
{
  uint32_t *v6; // lr
  unsigned int *v7; // r4
  unsigned int *v8; // r5
  unsigned int *v9; // r12
  unsigned int *v10; // r7
  unsigned int *v11; // r9
  unsigned int *v12; // r0
  unsigned int v13; // r11
  unsigned int v14; // r10
  unsigned int v15; // r8
  unsigned int v16; // lr
  uint32_t *v19; // r2
  uint32_t *v20; // r0
  unsigned int *v21; // r11
  unsigned int *v22; // r9
  int *v23; // r8
  uint32_t *v24; // r1
  unsigned int v25; // r10
  unsigned int v26; // r6
  unsigned int v27; // r5
  unsigned int v28; // r11
  unsigned int v29; // lr
  unsigned int v30; // r4
  unsigned int v31; // r9
  unsigned int v32; // r12
  int v33; // r10
  void *v34; // r3
  void *v35; // r3
  void *v36; // r3
  void *v37; // r3
  void *v38; // r3
  char *v39; // r2
  uint32_t *v40; // r4
  unsigned int *v41; // r1
  unsigned int *v42; // r0
  int v43; // r8
  int v44; // r2
  unsigned int v45; // r9
  int v46; // r8
  int v47; // r4
  unsigned int *v48; // r6
  unsigned int *v49; // r5
  unsigned int *v50; // r11
  unsigned int *v51; // r4
  unsigned int *v52; // r7
  unsigned int *v53; // r9
  unsigned int *v54; // r8
  uint32_t *v55; // r2
  unsigned int *v56; // r2
  unsigned int *v57; // r12
  unsigned int *v58; // r1
  unsigned int *v59; // r3
  unsigned int *v60; // lr
  unsigned int *result; // r0
  unsigned int *v62; // r10
  uint32_t *v63; // r6
  unsigned int *v64; // r2
  int v65; // [sp+8h] [bp-8Ch]
  int v66; // [sp+Ch] [bp-88h]
  unsigned int v67; // [sp+10h] [bp-84h]
  int v68; // [sp+10h] [bp-84h]
  int v69; // [sp+14h] [bp-80h]
  int v70; // [sp+18h] [bp-7Ch]
  unsigned int v71; // [sp+1Ch] [bp-78h]
  int v72; // [sp+1Ch] [bp-78h]
  unsigned int v73; // [sp+20h] [bp-74h]
  int v74; // [sp+20h] [bp-74h]
  unsigned int v75; // [sp+24h] [bp-70h]
  int v76; // [sp+24h] [bp-70h]
  unsigned int v77; // [sp+28h] [bp-6Ch]
  int v78; // [sp+28h] [bp-6Ch]
  unsigned int v79; // [sp+2Ch] [bp-68h]
  int v80; // [sp+2Ch] [bp-68h]
  unsigned int v81; // [sp+30h] [bp-64h]
  int v82; // [sp+30h] [bp-64h]
  unsigned int v83; // [sp+34h] [bp-60h]
  int v84; // [sp+34h] [bp-60h]
  int v85; // [sp+38h] [bp-5Ch]
  unsigned int v86; // [sp+3Ch] [bp-58h]
  int v87; // [sp+3Ch] [bp-58h]
  unsigned int v88; // [sp+40h] [bp-54h]
  int v89; // [sp+40h] [bp-54h]
  unsigned int v90; // [sp+44h] [bp-50h]
  int v91; // [sp+44h] [bp-50h]
  unsigned int v92; // [sp+48h] [bp-4Ch]
  int v93; // [sp+48h] [bp-4Ch]
  unsigned int v94; // [sp+4Ch] [bp-48h]
  int v95; // [sp+4Ch] [bp-48h]
  unsigned int v96; // [sp+50h] [bp-44h]
  int v97; // [sp+50h] [bp-44h]
  int v98; // [sp+54h] [bp-40h]
  unsigned int v99; // [sp+58h] [bp-3Ch]
  int v100; // [sp+58h] [bp-3Ch]
  int v101; // [sp+5Ch] [bp-38h]
  int v102; // [sp+5Ch] [bp-38h]
  unsigned int v103; // [sp+60h] [bp-34h]
  int v104; // [sp+60h] [bp-34h]
  unsigned int v105; // [sp+64h] [bp-30h]
  int v106; // [sp+64h] [bp-30h]
  int v107; // [sp+68h] [bp-2Ch]
  int v108; // [sp+6Ch] [bp-28h]
  int v109; // [sp+70h] [bp-24h]
  int v110; // [sp+74h] [bp-20h]
  int v111; // [sp+78h] [bp-1Ch]
  int v112; // [sp+7Ch] [bp-18h]
  int v113; // [sp+80h] [bp-14h]
  int v114; // [sp+84h] [bp-10h]
  int v115; // [sp+88h] [bp-Ch]

  v6 = off_105874;
  v7 = (unsigned int *)off_105848;
  v8 = (unsigned int *)off_10584C;
  v9 = (unsigned int *)off_10585C;
  v10 = (unsigned int *)off_105850;
  v11 = (unsigned int *)off_105868;
  *(uint32_t *)off_105874 |= 0x400u;
  v12 = (unsigned int *)off_105854;
  *v6 &= ~0x400u;
  v13 = *v8;
  v14 = *v9;
  v67 = *v7;
  v15 = *v7;
  v16 = *v10;
  v71 = *v12;
  v73 = *v12;
  v75 = *v12;
  v77 = *v12;
  v79 = *v8;
  v83 = *(uint32_t *)off_105858;
  v81 = *(uint32_t *)off_105858;
  *v8 |= 0x20u;
  *v9 = *v9 & 0xF8FFFFFF | 0x2000000;
  *v7 |= 0x100000u;
  *v7 |= 0x200000u;
  *v10 = *v10 & 0xFFFFFF0F | 0xC0;
  *v11 = *v11 & 0xFFFFFFC7 | 0x20;
  v65 = (v13 >> 5) & 1;
  v66 = HIBYTE(v14) & 7;
  v68 = (v67 >> 21) & 1;
  v69 = (v15 >> 20) & 1;
  v70 = (uint8_t)v16 >> 4;
  v72 = (v71 >> 7) & 1;
  v74 = (v73 >> 4) & 7;
  v76 = (v75 >> 10) & 1;
  v78 = (v77 >> 8) & 3;
  v80 = (v79 >> 2) & 7;
  v112 = (v83 >> 22) & 1;
  v111 = (v81 >> 21) & 1;
  *v12 |= 0x400u;
  if ( a4 <= 8 )
  {
    *v12 = *v12 & 0xFFFFFCFF | 0x100;
    *v8 &= 0xFFFFFFE3;
    goto LABEL_3;
  }
  if ( a4 == 9 )
  {
    if ( a5 )
    {
      *v12 &= 0xFFFFFCFF;
      *v8 &= 0xFFFFFFE3;
      goto LABEL_3;
    }
    goto LABEL_26;
  }
  if ( a4 <= 0xB )
  {
LABEL_26:
    v64 = (unsigned int *)off_105DC8;
    *(uint32_t *)off_105DC4 &= 0xFFFFFCFF;
    *v64 = *v64 & 0xFFFFFFE3 | 8;
    goto LABEL_3;
  }
  if ( a5 )
  {
    *v11 = *v11 & 0xFFFFFFC7 | 0x20;
    *v8 = *v8 & 0xFFFFFFE3 | 8;
    *v12 &= 0xFFFFFCFF;
    if ( a4 == 15 && a5 == 1 )
    {
      *v11 &= 0xFFFFFFC7;
      *v12 &= 0xFFFFFCFF;
      *v8 |= 0x1Cu;
    }
  }
  else
  {
    *v11 = *v11 & 0xFFFFFFC7 | 0x10;
    *v8 |= 0x1Cu;
    *v12 &= 0xFFFFFCFF;
  }
LABEL_3:
  v19 = off_105858;
  v20 = off_10585C;
  v21 = (unsigned int *)off_105878;
  v22 = (unsigned int *)off_10587C;
  v23 = (int *)off_105880;
  *(uint32_t *)off_105858 = *(uint32_t *)off_105858 & 0xFFFE00FF | 0x100;
  *v19 |= 0x20000u;
  *v19 |= 0x40000u;
  check_interrupt_flag(1, "tia_aux_gbit_use=%d\n", (*v20 >> 21) & 7);
  v34 = off_105864;
  v24 = off_10586C;
  v25 = *(uint32_t *)off_105868;
  v26 = *(uint32_t *)off_10586C;
  v27 = *(uint32_t *)off_105864;
  v86 = *(uint32_t *)off_105864;
  v88 = *(uint32_t *)off_105864;
  v90 = *(uint32_t *)off_105848;
  v92 = *(uint32_t *)off_105848;
  v94 = *(uint32_t *)off_105848;
  v96 = *(uint32_t *)off_105848;
  v28 = *v21;
  v99 = *(uint32_t *)off_105870;
  v101 = *(uint32_t *)off_105850;
  v103 = *v22;
  v105 = *(uint32_t *)off_105850;
  v115 = *v23;
  v114 = *(uint32_t *)off_105884;
  v29 = *(uint32_t *)off_105848;
  v30 = *(uint32_t *)off_105848;
  v31 = *(uint32_t *)off_105848;
  v32 = *(uint32_t *)off_105888;
  *(uint32_t *)off_105868 |= 0x40u;
  *v24 &= 0xFFFF8FFF;
  *(uint32_t *)v34 |= 0x800000u;
  v82 = (v26 >> 12) & 7;
  v84 = (v27 >> 23) & 1;
  v85 = (v27 >> 22) & 1;
  v87 = (v86 >> 20) & 1;
  v89 = (v88 >> 21) & 1;
  v91 = (v90 >> 17) & 1;
  v93 = HIWORD(v92) & 1;
  v95 = (v94 >> 15) & 1;
  v97 = (v96 >> 14) & 1;
  v98 = (v28 >> 18) & 1;
  v100 = (v99 >> 12) & 3;
  v102 = v101 & 3;
  v104 = (v103 >> 18) & 7;
  v106 = (v105 >> 2) & 1;
  v107 = (v29 >> 23) & 1;
  v108 = (v29 >> 22) & 1;
  v109 = (v30 >> 19) & 1;
  v110 = (v31 >> 18) & 1;
  v113 = (v32 >> 8) & 1;
  v33 = (v25 >> 6) & 1;
  *(uint32_t *)v34 |= 0x400000u;
  LOBYTE(v34) = 90;
  do
    v34 = (void *)(uint8_t)((uint8_t)v34 - 1);
  while ( v34 );
  v35 = off_105864;
  *(uint32_t *)off_105864 &= ~0x100000u;
  *(uint32_t *)v35 |= 0x200000u;
  LOBYTE(v35) = 60;
  do
    v35 = (void *)(uint8_t)((uint8_t)v35 - 1);
  while ( v35 );
  v36 = off_105848;
  *(uint32_t *)off_105864 |= 0x100000u;
  *(uint32_t *)v36 |= 0x20000u;
  *(uint32_t *)v36 |= 0x10000u;
  LOBYTE(v36) = 90;
  do
    v36 = (void *)(uint8_t)((uint8_t)v36 - 1);
  while ( v36 );
  v37 = off_105B9C;
  *(uint32_t *)off_105B9C &= ~0x40000u;
  *(uint32_t *)v37 |= 0x80000u;
  LOBYTE(v37) = 60;
  do
    v37 = (void *)(uint8_t)((uint8_t)v37 - 1);
  while ( v37 );
  v38 = off_105B9C;
  *(uint32_t *)off_105B9C |= 0x40000u;
  *(uint32_t *)v38 |= 0x8000u;
  *(uint32_t *)v38 |= 0x4000u;
  LOBYTE(v38) = 90;
  do
    v38 = (void *)(uint8_t)((uint8_t)v38 - 1);
  while ( v38 );
  v39 = (char *)off_105BA0;
  v40 = off_105BA4;
  v41 = (unsigned int *)off_105BA8;
  v42 = (unsigned int *)off_105BAC;
  *(uint32_t *)off_105BA0 |= 0x40000u;
  *v40 |= 0x3000u;
  *v41 = *v41 & 0xFFFFFFFC | 1;
  *v42 = *v42 & 0xFFE3FFFF | 0xC0000;
  *v41 |= 4u;
  *(uint32_t *)&v39[-28] |= 0x800000u;
  v40 -= 465770;
  *(uint32_t *)&v39[-28] |= 0x400000u;
  *v40 &= ~0x100u;
  disable_bb_timer_irq();
  check_interrupt_flag(1, aStDpdDump);
  rf_reg_init((int)off_105BB4[158 * a5 + 2], (int)off_105BB4[158 * a5 + 146]);
  *v40 &= ~0x200u;
  *v40 |= 0x200u;
  *v40 &= ~0x200u;
  if ( a5 )
  {
    v43 = a3 == 1;
    if ( a4 == 7 )
    {
      v44 = 8 * v43 + 5;
      v46 = v43 << 12;
      v47 = v44;
      v45 = 83886080;
    }
    else
    {
      v44 = 15 - a4 + 8 * v43;
      v45 = (15 - a4) << 24;
      v46 = v43 << 12;
      v47 = v44;
    }
  }
  else if ( a4 == 4 )
  {
    v44 = 1;
    v46 = 0;
    v47 = 1;
    v45 = 0x1000000;
  }
  else if ( a4 == 7 )
  {
    v44 = 0;
    v45 = 0;
    v46 = 0;
    v47 = 0;
  }
  else
  {
    v44 = 15 - a4;
    v46 = 0;
    v47 = 15 - a4;
    v45 = (15 - a4) << 24;
  }
  v48 = (unsigned int *)off_105BB8;
  v49 = (unsigned int *)off_105BC0;
  v50 = (unsigned int *)off_105BA0;
  check_interrupt_flag(1, "dpd use %d table\n", v44);
  configure_bb_winsize(a2, v47, a6);
  v51 = (unsigned int *)off_105BC8;
  check_interrupt_flag(1, "tx_gain_map_ini=%x\n", *v48);
  *v48 = v45 | v46 | (a4 << 8) | 0x3F4080;
  bb_hw_init();
  v52 = (unsigned int *)off_105BD0;
  v53 = (unsigned int *)off_105BA4;
  v54 = (unsigned int *)off_105BAC;
  check_interrupt_flag(1, "tx_gain_map_ini00=%x\n", *v48);
  v55 = off_105BD4;
  *v49 &= ~0x200u;
  *v49 |= 0x200u;
  *v49 &= ~0x200u;
  *v55 |= 0x10000000u;
  write_timer_reg(6500);
  load_patch_data();
  *v51 = *v51 & 0xFFBFFFFF | (v112 << 22);
  *v51 = *v51 & 0xFFDFFFFF | (v111 << 21);
  disable_rx_path();
  v56 = (unsigned int *)off_105BD8;
  v57 = (unsigned int *)off_105BE0;
  v58 = (unsigned int *)off_105BDC;
  v59 = (unsigned int *)off_105B9C;
  v60 = (unsigned int *)off_105BE4;
  *v52 = *v52 & 0xF8FFFFFF | (v66 << 24);
  result = (unsigned int *)off_105BA8;
  *v56 = *v56 & 0xFFFFFFBF | (v33 << 6);
  v62 = (unsigned int *)off_105BE8;
  *v57 = *v57 & 0xFFFF8FFF | (v82 << 12);
  *v58 = *v58 & 0xFF7FFFFF | (v84 << 23);
  *v58 = *v58 & 0xFFBFFFFF | (v85 << 22);
  *v58 = *v58 & 0xFFEFFFFF | (v87 << 20);
  *v58 = *v58 & 0xFFDFFFFF | (v89 << 21);
  *v59 = *v59 & 0xFFFBFFFF | (v110 << 18);
  *v59 = *v59 & 0xFFF7FFFF | (v109 << 19);
  *v59 = *v59 & 0xFFFDFFFF | (v91 << 17);
  *v59 = *v59 & 0xFFFEFFFF | (v93 << 16);
  *v59 = *v59 & 0xFFFF7FFF | (v95 << 15);
  *v59 = *v59 & 0xFFFFBFFF | (v97 << 14);
  *v50 = *v50 & 0xFFFBFFFF | (v98 << 18);
  *v53 = *v53 & 0xFFFFCFFF | (v100 << 12);
  *result = *result & 0xFFFFFFFC | v102;
  *v54 = *v54 & 0xFFE3FFFF | (v104 << 18);
  *result = *result & 0xFFFFFFFB | (4 * v106);
  *v59 = *v59 & 0xFF7FFFFF | (v107 << 23);
  *v59 = *v59 & 0xFFBFFFFF | (v108 << 22);
  *v62 = *v62 & 0xFFFFFFDF | (32 * v65);
  *v59 = *v59 & 0xFFDFFFFF | (v68 << 21);
  *v59 = *v59 & 0xFFEFFFFF | (v69 << 20);
  v63 = off_105DC0;
  *result = *result & 0xFFFFFF0F | (16 * v70);
  v56[20] = v56[20] & 0xFFFFFF7F | (v72 << 7);
  v56[20] = v56[20] & 0xFFFFFF8F | (16 * v74);
  v56[20] = v56[20] & 0xFFFFFBFF | (v76 << 10);
  v56[20] = v56[20] & 0xFFFFFCFF | (v78 << 8);
  *v62 = *v62 & 0xFFFFFFE3 | (4 * v80);
  *v51 &= 0xFFFE00FF;
  *v51 &= ~0x20000u;
  *v51 |= 0x40000u;
  *v60 = *v60 & 0x7FFFFFFF | v115 & 0x80000000;
  *v63 = v114;
  v57 -= 8848;
  *v49 = *v49 & 0xFFFFFEFF | (v113 << 8);
  *v57 |= 0x400u;
  *v57 &= ~0x400u;
  return result;
}
