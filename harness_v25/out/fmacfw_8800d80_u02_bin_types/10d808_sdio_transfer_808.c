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

extern uint32_t off_10DAD4;
extern uint32_t off_10DAD8;
extern uint32_t off_10DADC;
extern uint32_t off_10DAE0;
extern uint32_t off_10DAE4;
extern uint32_t off_10DAE8;
extern uint32_t off_10DAEC;
extern uint32_t off_10DAF4;
extern uint32_t dword_10DAF0;
extern uint32_t dword_10DAF8;
extern uint32_t dword_10DB24;
extern uint32_t dword_10DB20;
extern uint32_t dword_10DB28;
extern uint32_t off_10DB2C;
extern uint32_t dword_10DC00;
extern uint32_t off_10DC04;
extern uint32_t off_10DC1C;
extern uint32_t off_10DC20;
extern uint32_t off_10DC08;
extern uint32_t off_10DC0C;
extern uint32_t off_10DC10;
extern uint32_t off_10DB30;
extern uint32_t dword_10DAFC;
extern uint32_t dword_10DB00;
extern uint32_t off_10DB34;
extern uint32_t dword_10DB04;
extern uint32_t off_10DB08;
extern uint32_t dword_10DC14;
extern uint32_t off_10DB0C;
extern uint32_t off_10DB10;
extern uint32_t off_10DB14;
extern uint32_t off_10DB18;
extern uint32_t dword_10DB1C;
extern uint32_t dword_10DC18;

// sdio_transfer_808 @ 0x10d808, size 1016 bytes
// Doc: sdio_transfer_808 [mac]: SDIO data transfer handler with 256-byte buffer
// sdio_transfer_808 [mac]: SDIO data transfer handler with 256-byte buffer
int  sdio_transfer_808(int a1, int a2)
{
  int v2; // r4
  unsigned int CPSR; // r6
  int v4; // r0
  int v5; // r1
  int v6; // r7
  int v7; // r5
  int v8; // r3
  uint8_t *v9; // r4
  uint32_t *v10; // r1
  uint32_t *v11; // r0
  uint8_t *v12; // r5
  int v13; // r2
  int v14; // t1
  int v16; // r3
  uint8_t **v17; // r8
  int v18; // r0
  uint32_t *v19; // r2
  int *v20; // r4
  int v21; // r1
  int v22; // t1
  int v23; // r1
  uint8_t *v24; // r8
  int v25; // r9
  uint8_t *v26; // r0
  uint8_t *v27; // r8
  uint8_t *v28; // r9
  int v29; // r0
  uint32_t *v30; // r2
  int *v31; // r12
  int v32; // r1
  int v33; // t1
  uint16_t *v34; // r10
  int v35; // r11
  int v36; // r0
  uint32_t *v37; // r2
  int *v38; // r5
  int v39; // r1
  int v40; // t1
  int *v41; // r3
  int v42; // r0
  int v43; // r8
  int v44; // r3
  uint8_t *v45; // r1
  unsigned int v46; // r2
  int16_t v47; // r0
  uint32_t *v48; // r5
  int v49; // r2
  int *v50; // r5
  int v51; // r0
  int v52; // r0
  int v53; // r3
  int v54; // r2
  int v55; // r0
  uint32_t *v56; // r2
  int *v57; // r4
  int v58; // r1
  int v59; // t1
  int v60; // r0
  uint32_t *v61; // r2
  int *v62; // r4
  int v63; // r1
  int v64; // t1
  int v65; // r0
  uint32_t *v66; // r2
  int *v67; // r12
  int v68; // r1
  int v69; // t1
  int v70; // r2
  uint64_t v71; // r0
  int ( *v72)(uint32_t); // r2
  int v73; // r0
  uint16_t *v74; // r2
  int v75; // r2
  uint16_t v76; // r5
  int v77; // r1
  uint32_t *v78; // r2
  int *v79; // r0
  int v80; // t1
  int *v81; // [sp+Ch] [bp-108h]
  uint8_t v82[260]; // [sp+10h] [bp-104h] BYREF

  CPSR = __get_CPSR();
  v4 = sub_12E11C(v82, 256, 0, a1, a2);
  v6 = v4;
  if ( v4 <= 0 )
    return v6;
  v7 = v4;
  if ( *(uint32_t *)off_10DAD4 )
  {
    if ( CPSR )
      goto LABEL_5;
  }
  else
  {
    log_hw_init_d648();
    if ( CPSR )
      goto LABEL_5;
  }
  while ( !*(uint32_t *)off_10DAD8 )
    ;
LABEL_5:
  if ( !*(uint32_t *)off_10DADC )
  {
    do
      v5 = *(uint32_t *)off_10DAE0 << 12;
    while ( (*(uint32_t *)off_10DAE0 & 0x80000) != 0 );
    *(uint32_t *)off_10DAE4 = 95;
  }
  v8 = *((uint16_t *)off_10DAE8 + 89) & 0x4000;
  if ( (*((uint16_t *)off_10DAE8 + 89) & 0x4000) == 0 )
  {
    v9 = v82;
    v10 = off_10DAE0;
    v11 = off_10DAE4;
    v12 = &v82[v7];
    do
    {
      v14 = *v9++;
      v13 = v14;
      if ( v14 == 10 && v8 != 13 )
      {
        while ( (*v10 & 0x80000) != 0 )
          ;
        *v11 = 13;
        v13 = *(v9 - 1);
      }
      while ( (*v10 & 0x80000) != 0 )
        ;
      *v11 = v13;
      v8 = *(v9 - 1);
    }
    while ( v9 != v12 );
    goto LABEL_13;
  }
  v16 = **(uint8_t **)off_10DAEC;
  if ( v16 == 1 )
  {
    if ( **(uint8_t **)off_10DAF4 != 3 )
    {
      if ( v7 >= 124 )
        LOWORD(v7) = 124;
      log_enqueue(19, v82, (uint16_t)v7);
    }
    goto LABEL_13;
  }
  if ( v16 != 2 )
    goto LABEL_13;
  v17 = (uint8_t **)off_10DAF4;
  if ( **(uint8_t **)off_10DAF4 == 3 )
  {
LABEL_19:
    v18 = dword_10DAF0;
    v19 = off_10DAE0;
    v20 = (int *)off_10DAE4;
    v21 = 110;
    do
    {
      while ( (*v19 & 0x80000) != 0 )
        ;
      *v20 = v21;
      v22 = *(uint8_t *)++v18;
      v21 = v22;
    }
    while ( v22 );
    goto LABEL_13;
  }
  if ( (unsigned int)list_count(dword_10DAF8, v5) <= 4 )
  {
    if ( **(uint8_t **)off_10DAEC == 2 )
    {
      if ( **v17 != 3 )
      {
        if ( (unsigned int)list_count(dword_10DAF8, v23) > 4 )
        {
          v60 = dword_10DB24;
          v61 = off_10DAE0;
          v62 = (int *)off_10DAE4;
          v63 = 111;
          do
          {
            while ( (*v61 & 0x80000) != 0 )
              ;
            *v62 = v63;
            v64 = *(uint8_t *)++v60;
            v63 = v64;
          }
          while ( v64 );
        }
        else
        {
          v55 = dword_10DB20;
          v56 = off_10DAE0;
          v57 = (int *)off_10DAE4;
          v58 = 102;
          do
          {
            while ( (*v56 & 0x80000) != 0 )
              ;
            *v57 = v58;
            v59 = *(uint8_t *)++v55;
            v58 = v59;
          }
          while ( v59 );
        }
        goto LABEL_13;
      }
      goto LABEL_19;
    }
LABEL_13:
    if ( !CPSR )
      *(uint32_t *)off_10DAD8 = 1;
    return v6;
  }
  v24 = v82;
  v25 = dword_10DB28;
  while ( 1 )
  {
    v26 = v24++;
    if ( !sub_143710(v26, v25, 20) )
      break;
    if ( &v82[v7] == v24 )
    {
      v27 = off_10DB2C;
      goto LABEL_37;
    }
  }
  v65 = dword_10DC00;
  v66 = off_10DC04;
  v67 = (int *)off_10DC1C;
  v68 = 70;
  do
  {
    while ( (*v66 & 0x80000) != 0 )
      ;
    *v67 = v68;
    v69 = *(uint8_t *)++v65;
    v68 = v69;
  }
  while ( v69 );
  v27 = off_10DC20;
  v70 = *(uint32_t *)off_10DC08;
  v81 = (int *)off_10DC0C;
  v71 = *(uint64_t *)(v70 + 4);
  v72 = *(int ( **)(uint32_t))(HIDWORD(v71) + 16);
  *(uint8_t *)off_10DC20 = 1;
  v73 = v72(v71);
  v74 = off_10DC10;
  *v81 = v73;
  *v74 = 4;
LABEL_37:
  if ( *v27 )
  {
    v28 = off_10DB30;
    if ( !sub_143710(v82, dword_10DAFC, 5) )
    {
      v29 = dword_10DB00;
      v30 = off_10DAE0;
      v31 = (int *)off_10DAE4;
      *v28 = 1;
      v32 = 80;
      do
      {
        while ( (*v30 & 0x80000) != 0 )
          ;
        *v31 = v32;
        v33 = *(uint8_t *)++v29;
        v32 = v33;
      }
      while ( v33 );
    }
    v34 = (uint16_t *)off_10DB34;
    v35 = *(uint16_t *)off_10DB34;
    if ( v35 + v7 <= 1720 )
    {
      v81 = (int *)off_10DC0C;
      sub_143770(*(uint32_t *)off_10DC0C + v35, v82, v7);
      v75 = (uint8_t)*v28;
      v41 = v81;
      v76 = v7 + *v34;
      v35 = v76;
      *v34 = v76;
      if ( !v75 )
        return v6;
    }
    else
    {
      v36 = dword_10DB04;
      v37 = off_10DAE0;
      v38 = (int *)off_10DAE4;
      v39 = 66;
      do
      {
        while ( (*v37 & 0x80000) != 0 )
          ;
        *v38 = v39;
        v40 = *(uint8_t *)++v36;
        v39 = v40;
      }
      while ( v40 );
      v41 = (int *)off_10DB08;
    }
    v42 = dword_10DAF8;
    *v27 = 0;
    *v28 = 0;
    v43 = *v41;
    *v34 = 4;
    *v41 = 0;
    v6 = v35;
    rf_bus_mark_n100_d2d0(v42);
    goto LABEL_48;
  }
  v2 = rf_bus_mark_n100_d2d0(dword_10DC14);
  if ( v7 <= 122 )
    v43 = sub_113A08();
  else
    v43 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10DC08 + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10DC08
                                                                                                  + 4));
  if ( v43 )
  {
    sub_143770(v43 + 4, v82, v7);
    LOWORD(v35) = v7;
LABEL_48:
    *(uint16_t *)v43 = v6 + 1;
    *(uint8_t *)(v43 + 2) = 19;
    v44 = 0;
    v45 = off_10DB0C;
    *(uint8_t *)(v43 + 3) = 0;
    *(uint8_t *)(v43 + v6 + 4) = 0;
    v46 = *((uint16_t *)v45 + 4122);
    if ( v46 > 0x186 )
    {
      LOWORD(v46) = 0;
      v47 = 1;
    }
    else
    {
      v47 = v46 + 1;
      v44 = 8 * v46;
    }
    v48 = off_10DB10;
    *(uint16_t *)(v2 + 12) = v46;
    v49 = *v48 + v44;
    *(uint32_t *)(v49 + 4) = v43;
    *(uint16_t *)v49 = v35 + 5;
    *(uint8_t *)(v49 + 3) = *(uint8_t *)(v49 + 3) & 0x31 | 4;
    LOBYTE(v48) = v45[3074] + 1;
    *((uint16_t *)v45 + 4122) = v47;
    v45[3074] = (uint8_t)v48;
    *(uint32_t *)(v2 + 4) = v49;
    *(uint8_t *)(v2 + 14) = 1;
    *(uint32_t *)v2 = 0;
    *(uint32_t *)(v2 + 8) = v6 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10DB14 = 1;
    }
    v50 = (int *)off_10DB18;
    v51 = dword_10DB1C;
    ++*(uint32_t *)off_10DB18;
    v52 = list_push_tail(v51);
    rf_cmd_queue_next_4b4(v52);
    if ( *v50 )
    {
      v53 = *v50 - 1;
      v54 = *(uint32_t *)off_10DB14;
      *v50 = v53;
      if ( !v53 )
      {
        if ( v54 )
          __enable_irq();
      }
    }
    goto LABEL_13;
  }
  v77 = dword_10DC18;
  v78 = off_10DC04;
  v79 = (int *)off_10DC1C;
  v6 = 110;
  do
  {
    while ( (*v78 & 0x80000) != 0 )
      ;
    *v79 = v6;
    v80 = *(uint8_t *)++v77;
    v6 = v80;
  }
  while ( v80 );
  return v6;
}

