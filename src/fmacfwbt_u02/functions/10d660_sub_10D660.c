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


extern uint32_t dword_10D950;
extern uint32_t dword_10D974;
extern uint32_t dword_10DA6C;
extern uint32_t off_10D92C;
extern uint32_t off_10D930;
extern uint32_t off_10D934;
extern uint32_t off_10D938;
extern uint32_t off_10D93C;
extern uint32_t off_10D940;
extern uint32_t off_10D944;
extern uint32_t off_10D94C;
extern uint32_t off_10D960;
extern uint32_t off_10D964;
extern uint32_t off_10D968;
extern uint32_t off_10D96C;
extern uint32_t off_10D970;
extern uint32_t off_10D984;
extern uint32_t off_10D988;
extern uint32_t off_10D98C;
extern uint32_t off_10DA5C;
extern uint32_t off_10DA60;
extern uint32_t off_10DA64;
extern uint32_t off_10DA68;
extern uint32_t off_10DA74;
extern uint32_t off_10DA78;

// debug_printf @ 0x10d660, size 1016 bytes
int  debug_printf(uint8_t *a1, unsigned int *a2)
{
  uint32_t *v2; // r4
  unsigned int CPSR; // r6
  signed int v4; // r0
  int v5; // r7
  signed int v6; // r5
  int v7; // r3
  char *v8; // r4
  uint32_t *v9; // r1
  uint32_t *v10; // r0
  char *v11; // r5
  int v12; // r2
  int v13; // t1
  int v15; // r3
  uint8_t **v16; // r8
  char *v17; // r0
  uint32_t *v18; // r2
  int *v19; // r4
  int v20; // r1
  int v21; // t1
  char *v22; // r8
  unsigned int v23; // r0
  uint8_t *v24; // r8
  uint8_t *v25; // r9
  char *v26; // r0
  uint32_t *v27; // r2
  int *v28; // r12
  int v29; // r1
  int v30; // t1
  uint16_t *v31; // r10
  int v32; // r11
  char *v33; // r0
  uint32_t *v34; // r2
  int *v35; // r5
  int v36; // r1
  int v37; // t1
  char **v38; // r3
  int v39; // r0
  char *v40; // r8
  int v41; // r3
  uint8_t *v42; // r1
  unsigned int v43; // r2
  uint16_t v44; // r0
  uint32_t *v45; // r5
  int v46; // r2
  int *v47; // r5
  int v48; // r0
  int v49; // r3
  int v50; // r2
  char *v51; // r0
  uint32_t *v52; // r2
  int *v53; // r4
  int v54; // r1
  int v55; // t1
  char *v56; // r0
  uint32_t *v57; // r2
  int *v58; // r4
  int v59; // r1
  int v60; // t1
  char *v61; // r0
  uint32_t *v62; // r2
  int *v63; // r12
  int v64; // r1
  int v65; // t1
  int v66; // r2
  uint64_t v67; // r0
  int ( *v68)(uint32_t); // r2
  int v69; // r0
  uint16_t *v70; // r2
  int v71; // r2
  uint16_t v72; // r5
  char *v73; // r1
  uint32_t *v74; // r2
  int *v75; // r0
  int v76; // t1
  int *v77; // [sp+Ch] [bp-108h]
  char a1a[260]; // [sp+10h] [bp-104h] BYREF

  CPSR = __get_CPSR();
  v4 = main_loop_dispatch(a1a, 256, 0, a1, a2);
  v5 = v4;
  if ( v4 <= 0 )
    return v5;
  v6 = v4;
  if ( *(uint32_t *)off_10D92C )
  {
    if ( CPSR )
      goto LABEL_5;
  }
  else
  {
    event_loop();
    if ( CPSR )
      goto LABEL_5;
  }
  while ( !*(uint32_t *)off_10D930 )
    ;
LABEL_5:
  if ( !*(uint32_t *)off_10D934 )
  {
    while ( (*(uint32_t *)off_10D938 & 0x80000) != 0 )
      ;
    *(uint32_t *)off_10D93C = 95;
  }
  v7 = HIWORD(((uint32_t *)(uintptr_t)off_10D940)[44]) & 0x4000;
  if ( (((uint32_t *)(uintptr_t)off_10D940)[44] & 0x40000000) == 0 )
  {
    v8 = a1a;
    v9 = off_10D938;
    v10 = off_10D93C;
    v11 = &a1a[v6];
    do
    {
      v13 = (uint8_t)*v8++;
      v12 = v13;
      if ( v13 == 10 && v7 != 13 )
      {
        while ( (*v9 & 0x80000) != 0 )
          ;
        *v10 = 13;
        v12 = (uint8_t)*(v8 - 1);
      }
      while ( (*v9 & 0x80000) != 0 )
        ;
      *v10 = v12;
      v7 = (uint8_t)*(v8 - 1);
    }
    while ( v8 != v11 );
    goto LABEL_13;
  }
  v15 = **(uint8_t **)off_10D944;
  if ( v15 == 1 )
  {
    if ( **(uint8_t **)off_10D94C != 3 )
    {
      if ( v6 >= 124 )
        LOWORD(v6) = 124;
      ke_mem_alloc(19, a1a, (uint16_t)v6);
    }
    goto LABEL_13;
  }
  if ( v15 != 2 )
    goto LABEL_13;
  v16 = (uint8_t **)off_10D94C;
  if ( **(uint8_t **)off_10D94C == 3 )
  {
LABEL_19:
    v17 = aNoActive;
    v18 = off_10D938;
    v19 = (int *)off_10D93C;
    v20 = 110;
    do
    {
      while ( (*v18 & 0x80000) != 0 )
        ;
      *v19 = v20;
      v21 = (uint8_t)*++v17;
      v20 = v21;
    }
    while ( v21 );
    goto LABEL_13;
  }
  if ( (unsigned int)list_length((uint32_t **)dword_10D950) <= 4 )
  {
    if ( **(uint8_t **)off_10D944 == 2 )
    {
      if ( **v16 != 3 )
      {
        if ( (unsigned int)list_length((uint32_t **)dword_10D950) > 4 )
        {
          v56 = aOtherErr;
          v57 = off_10D938;
          v58 = (int *)off_10D93C;
          v59 = 111;
          do
          {
            while ( (*v57 & 0x80000) != 0 )
              ;
            *v58 = v59;
            v60 = (uint8_t)*++v56;
            v59 = v60;
          }
          while ( v60 );
        }
        else
        {
          v51 = aFree5;
          v52 = off_10D938;
          v53 = (int *)off_10D93C;
          v54 = 102;
          do
          {
            while ( (*v52 & 0x80000) != 0 )
              ;
            *v53 = v54;
            v55 = (uint8_t)*++v51;
            v54 = v55;
          }
          while ( v55 );
        }
        goto LABEL_13;
      }
      goto LABEL_19;
    }
LABEL_13:
    if ( !CPSR )
      *(uint32_t *)off_10D930 = 1;
    return v5;
  }
  v22 = a1a;
  while ( 1 )
  {
    v23 = (unsigned int)v22++;
    if ( !memcpy_1(v23, (unsigned int)aCm4FaultHandle, 0x14u) )
      break;
    if ( &a1a[v6] == v22 )
    {
      v24 = off_10D984;
      goto LABEL_37;
    }
  }
  v61 = aFoundPanic;
  v62 = off_10DA5C;
  v63 = (int *)off_10DA74;
  v64 = 70;
  do
  {
    while ( (*v62 & 0x80000) != 0 )
      ;
    *v63 = v64;
    v65 = (uint8_t)*++v61;
    v64 = v65;
  }
  while ( v65 );
  v24 = off_10DA78;
  v66 = *(uint32_t *)off_10DA60;
  v77 = (int *)off_10DA64;
  v67 = *(uint64_t *)(v66 + 4);
  v68 = *(int ( **)(uint32_t))(HIDWORD(v67) + 16);
  *(uint8_t *)off_10DA78 = 1;
  v69 = v68(v67);
  v70 = off_10DA68;
  *v77 = v69;
  *v70 = 4;
LABEL_37:
  if ( *v24 )
  {
    v25 = off_10D988;
    if ( !memcpy_1((unsigned int)a1a, (unsigned int)aPanic, 5u) )
    {
      v26 = aPanicEnd;
      v27 = off_10D938;
      v28 = (int *)off_10D93C;
      *v25 = 1;
      v29 = 80;
      do
      {
        while ( (*v27 & 0x80000) != 0 )
          ;
        *v28 = v29;
        v30 = (uint8_t)*++v26;
        v29 = v30;
      }
      while ( v30 );
    }
    v31 = (uint16_t *)off_10D98C;
    v32 = *(uint16_t *)off_10D98C;
    if ( v32 + v6 <= 1720 )
    {
      v77 = (int *)off_10DA64;
      memcpy_aligned((char *)(*(uint32_t *)off_10DA64 + v32), a1a, v6);
      v71 = (uint8_t)*v25;
      v38 = (char **)v77;
      v72 = v6 + *v31;
      v32 = v72;
      *v31 = v72;
      if ( !v71 )
        return v5;
    }
    else
    {
      v33 = aBufFull;
      v34 = off_10D938;
      v35 = (int *)off_10D93C;
      v36 = 66;
      do
      {
        while ( (*v34 & 0x80000) != 0 )
          ;
        *v35 = v36;
        v37 = (uint8_t)*++v33;
        v36 = v37;
      }
      while ( v37 );
      v38 = (char **)off_10D960;
    }
    v39 = dword_10D950;
    *v24 = 0;
    *v25 = 0;
    v40 = *v38;
    *v31 = 4;
    *v38 = nullptr;
    v5 = v32;
    list_pop_front(v39);
    goto LABEL_48;
  }
  v2 = list_pop_front(dword_10DA6C);
  if ( v6 <= 122 )
    v40 = (char *)int_disable_set_flag();
  else
    v40 = (char *)(*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10DA60 + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10DA60 + 4));
  if ( v40 )
  {
    memcpy_aligned(v40 + 4, a1a, v6);
    LOWORD(v32) = v6;
LABEL_48:
    *(uint16_t *)v40 = v5 + 1;
    v40[2] = 19;
    v41 = 0;
    v42 = off_10D964;
    v40[3] = 0;
    v40[v5 + 4] = 0;
    v43 = *((uint16_t *)v42 + 4122);
    if ( v43 > 0x186 )
    {
      LOWORD(v43) = 0;
      v44 = 1;
    }
    else
    {
      v44 = v43 + 1;
      v41 = 8 * v43;
    }
    v45 = off_10D968;
    *((uint16_t *)v2 + 6) = v43;
    v46 = *v45 + v41;
    *(uint32_t *)(v46 + 4) = v40;
    *(uint16_t *)v46 = v32 + 5;
    *(uint8_t *)(v46 + 3) = *(uint8_t *)(v46 + 3) & 0x31 | 4;
    LOBYTE(v45) = v42[3074] + 1;
    *((uint16_t *)v42 + 4122) = v44;
    v42[3074] = (uint8_t)v45;
    v2[1] = v46;
    *((uint8_t *)v2 + 14) = 1;
    *v2 = 0;
    v2[2] = v5 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10D96C = 1;
    }
    v47 = (int *)off_10D970;
    v48 = dword_10D974;
    ++*(uint32_t *)off_10D970;
    check_abort_flag(v48, v2);
    rf_calib_init();
    if ( *v47 )
    {
      v49 = *v47 - 1;
      v50 = *(uint32_t *)off_10D96C;
      *v47 = v49;
      if ( !v49 )
      {
        if ( v50 )
          __enable_irq();
      }
    }
    goto LABEL_13;
  }
  v73 = aNoTxBuffer;
  v74 = off_10DA5C;
  v75 = (int *)off_10DA74;
  v5 = 110;
  do
  {
    while ( (*v74 & 0x80000) != 0 )
      ;
    *v75 = v5;
    v76 = (uint8_t)*++v73;
    v5 = v76;
  }
  while ( v76 );
  return v5;
}
