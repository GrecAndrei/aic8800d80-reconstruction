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


extern uint32_t dword_10DAF8;
extern uint32_t dword_10DB1C;
extern uint32_t dword_10DC14;
extern uint32_t off_10DAD4;
extern uint32_t off_10DAD8;
extern uint32_t off_10DADC;
extern uint32_t off_10DAE0;
extern uint32_t off_10DAE4;
extern uint32_t off_10DAE8;
extern uint32_t off_10DAEC;
extern uint32_t off_10DAF4;
extern uint32_t off_10DB08;
extern uint32_t off_10DB0C;
extern uint32_t off_10DB10;
extern uint32_t off_10DB14;
extern uint32_t off_10DB18;
extern uint32_t off_10DB2C;
extern uint32_t off_10DB30;
extern uint32_t off_10DB34;
extern uint32_t off_10DC04;
extern uint32_t off_10DC08;
extern uint32_t off_10DC0C;
extern uint32_t off_10DC10;
extern uint32_t off_10DC1C;
extern uint32_t off_10DC20;

// prepare_debug_buffer @ 0x10d808, size 1016 bytes
int  prepare_debug_buffer(uint8_t *a1, unsigned int *a2)
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
  int v22; // r3
  char *v23; // r8
  unsigned int v24; // r0
  uint8_t *v25; // r8
  uint8_t *v26; // r9
  char *v27; // r0
  uint32_t *v28; // r2
  int *v29; // r12
  int v30; // r1
  int v31; // t1
  uint16_t *v32; // r10
  int v33; // r11
  char *v34; // r0
  uint32_t *v35; // r2
  int *v36; // r5
  int v37; // r1
  int v38; // t1
  char **v39; // r3
  int v40; // r0
  char *v41; // r8
  int v42; // r3
  uint8_t *v43; // r1
  unsigned int v44; // r2
  uint16_t v45; // r0
  uint32_t *v46; // r5
  int v47; // r2
  int *v48; // r5
  int v49; // r0
  int v50; // r3
  int v51; // r2
  char *v52; // r0
  uint32_t *v53; // r2
  int *v54; // r4
  int v55; // r1
  int v56; // t1
  char *v57; // r0
  uint32_t *v58; // r2
  int *v59; // r4
  int v60; // r1
  int v61; // t1
  char *v62; // r0
  uint32_t *v63; // r2
  int *v64; // r12
  int v65; // r1
  int v66; // t1
  int v67; // r2
  uint64_t v68; // r0
  int ( *v69)(uint32_t); // r2
  int v70; // r0
  uint16_t *v71; // r2
  int v72; // r2
  uint16_t v73; // r5
  char *v74; // r1
  uint32_t *v75; // r2
  int *v76; // r0
  int v77; // t1
  int *v78; // [sp+Ch] [bp-108h]
  char a1a[260]; // [sp+10h] [bp-104h] BYREF

  CPSR = __get_CPSR();
  v4 = rf_cal_init(a1a, 256, 0, a1, a2);
  v5 = v4;
  if ( v4 <= 0 )
    return v5;
  v6 = v4;
  if ( *(uint32_t *)off_10DAD4 )
  {
    if ( CPSR )
      goto LABEL_5;
  }
  else
  {
    is_initialized();
    if ( CPSR )
      goto LABEL_5;
  }
  while ( !*(uint32_t *)off_10DAD8 )
    ;
LABEL_5:
  if ( !*(uint32_t *)off_10DADC )
  {
    while ( (*(uint32_t *)off_10DAE0 & 0x80000) != 0 )
      ;
    *(uint32_t *)off_10DAE4 = 95;
  }
  v7 = HIWORD(((uint32_t *)(uintptr_t)off_10DAE8)[44]) & 0x4000;
  if ( (((uint32_t *)(uintptr_t)off_10DAE8)[44] & 0x40000000) == 0 )
  {
    v8 = a1a;
    v9 = off_10DAE0;
    v10 = off_10DAE4;
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
  v15 = **(uint8_t **)off_10DAEC;
  if ( v15 == 1 )
  {
    v22 = **(uint8_t **)off_10DAF4;
    if ( v22 != 3 )
    {
      if ( v6 >= 124 )
        LOWORD(v6) = 124;
      mutex_lock(19, a1a, (uint16_t)v6, v22);
    }
    goto LABEL_13;
  }
  if ( v15 != 2 )
    goto LABEL_13;
  v16 = (uint8_t **)off_10DAF4;
  if ( **(uint8_t **)off_10DAF4 == 3 )
  {
LABEL_19:
    v17 = aNoActive;
    v18 = off_10DAE0;
    v19 = (int *)off_10DAE4;
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
  if ( (unsigned int)read_u32((uint32_t **)dword_10DAF8) <= 4 )
  {
    if ( **(uint8_t **)off_10DAEC == 2 )
    {
      if ( **v16 != 3 )
      {
        if ( (unsigned int)read_u32((uint32_t **)dword_10DAF8) > 4 )
        {
          v57 = aOtherErr;
          v58 = off_10DAE0;
          v59 = (int *)off_10DAE4;
          v60 = 111;
          do
          {
            while ( (*v58 & 0x80000) != 0 )
              ;
            *v59 = v60;
            v61 = (uint8_t)*++v57;
            v60 = v61;
          }
          while ( v61 );
        }
        else
        {
          v52 = aFree5;
          v53 = off_10DAE0;
          v54 = (int *)off_10DAE4;
          v55 = 102;
          do
          {
            while ( (*v53 & 0x80000) != 0 )
              ;
            *v54 = v55;
            v56 = (uint8_t)*++v52;
            v55 = v56;
          }
          while ( v56 );
        }
        goto LABEL_13;
      }
      goto LABEL_19;
    }
LABEL_13:
    if ( !CPSR )
      *(uint32_t *)off_10DAD8 = 1;
    return v5;
  }
  v23 = a1a;
  while ( 1 )
  {
    v24 = (unsigned int)v23++;
    if ( !memcmp(v24, (unsigned int)aCm4FaultHandle, 0x14u) )
      break;
    if ( &a1a[v6] == v23 )
    {
      v25 = off_10DB2C;
      goto LABEL_37;
    }
  }
  v62 = aFoundPanic;
  v63 = off_10DC04;
  v64 = (int *)off_10DC1C;
  v65 = 70;
  do
  {
    while ( (*v63 & 0x80000) != 0 )
      ;
    *v64 = v65;
    v66 = (uint8_t)*++v62;
    v65 = v66;
  }
  while ( v66 );
  v25 = off_10DC20;
  v67 = *(uint32_t *)off_10DC08;
  v78 = (int *)off_10DC0C;
  v68 = *(uint64_t *)(v67 + 4);
  v69 = *(int ( **)(uint32_t))(HIDWORD(v68) + 16);
  *(uint8_t *)off_10DC20 = 1;
  v70 = v69(v68);
  v71 = off_10DC10;
  *v78 = v70;
  *v71 = 4;
LABEL_37:
  if ( *v25 )
  {
    v26 = off_10DB30;
    if ( !memcmp((unsigned int)a1a, (unsigned int)aPanic, 5u) )
    {
      v27 = aPanicEnd;
      v28 = off_10DAE0;
      v29 = (int *)off_10DAE4;
      *v26 = 1;
      v30 = 80;
      do
      {
        while ( (*v28 & 0x80000) != 0 )
          ;
        *v29 = v30;
        v31 = (uint8_t)*++v27;
        v30 = v31;
      }
      while ( v31 );
    }
    v32 = (uint16_t *)off_10DB34;
    v33 = *(uint16_t *)off_10DB34;
    if ( v33 + v6 <= 1720 )
    {
      v78 = (int *)off_10DC0C;
      memcpy((char *)(*(uint32_t *)off_10DC0C + v33), a1a, v6);
      v72 = (uint8_t)*v26;
      v39 = (char **)v78;
      v73 = v6 + *v32;
      v33 = v73;
      *v32 = v73;
      if ( !v72 )
        return v5;
    }
    else
    {
      v34 = aBufFull;
      v35 = off_10DAE0;
      v36 = (int *)off_10DAE4;
      v37 = 66;
      do
      {
        while ( (*v35 & 0x80000) != 0 )
          ;
        *v36 = v37;
        v38 = (uint8_t)*++v34;
        v37 = v38;
      }
      while ( v38 );
      v39 = (char **)off_10DB08;
    }
    v40 = dword_10DAF8;
    *v25 = 0;
    *v26 = 0;
    v41 = *v39;
    *v32 = 4;
    *v39 = nullptr;
    v5 = v33;
    mem_word_load(v40);
    goto LABEL_48;
  }
  v2 = mem_word_load(dword_10DC14);
  if ( v6 <= 122 )
    v41 = (char *)error_trap();
  else
    v41 = (char *)(*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10DC08 + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10DC08 + 4));
  if ( v41 )
  {
    memcpy(v41 + 4, a1a, v6);
    LOWORD(v33) = v6;
LABEL_48:
    *(uint16_t *)v41 = v5 + 1;
    v41[2] = 19;
    v42 = 0;
    v43 = off_10DB0C;
    v41[3] = 0;
    v41[v5 + 4] = 0;
    v44 = *((uint16_t *)v43 + 4122);
    if ( v44 > 0x186 )
    {
      LOWORD(v44) = 0;
      v45 = 1;
    }
    else
    {
      v45 = v44 + 1;
      v42 = 8 * v44;
    }
    v46 = off_10DB10;
    *((uint16_t *)v2 + 6) = v44;
    v47 = *v46 + v42;
    *(uint32_t *)(v47 + 4) = v41;
    *(uint16_t *)v47 = v33 + 5;
    *(uint8_t *)(v47 + 3) = *(uint8_t *)(v47 + 3) & 0x31 | 4;
    LOBYTE(v46) = v43[3074] + 1;
    *((uint16_t *)v43 + 4122) = v45;
    v43[3074] = (uint8_t)v46;
    v2[1] = v47;
    *((uint8_t *)v2 + 14) = 1;
    *v2 = 0;
    v2[2] = v5 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10DB14 = 1;
    }
    v48 = (int *)off_10DB18;
    v49 = dword_10DB1C;
    ++*(uint32_t *)off_10DB18;
    cmd_handler_a(v49, v2);
    check_init_flag();
    if ( *v48 )
    {
      v50 = *v48 - 1;
      v51 = *(uint32_t *)off_10DB14;
      *v48 = v50;
      if ( !v50 )
      {
        if ( v51 )
          __enable_irq();
      }
    }
    goto LABEL_13;
  }
  v74 = aNoTxBuffer;
  v75 = off_10DC04;
  v76 = (int *)off_10DC1C;
  v5 = 110;
  do
  {
    while ( (*v75 & 0x80000) != 0 )
      ;
    *v76 = v5;
    v77 = (uint8_t)*++v74;
    v5 = v77;
  }
  while ( v77 );
  return v5;
}
