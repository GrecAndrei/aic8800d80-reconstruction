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

extern uint32_t off_10D970;
extern uint32_t off_10D974;
extern uint32_t off_10D978;
extern uint32_t off_10D97C;
extern uint32_t off_10D980;
extern uint32_t off_10D988;
extern uint32_t dword_10D98C;
extern uint32_t dword_10D9B8;
extern uint32_t dword_10D9B4;
extern uint32_t dword_10D984;
extern uint32_t dword_10D9C8;
extern uint32_t off_10D990;
extern uint32_t dword_10D9BC;
extern uint32_t off_10D9D0;
extern uint32_t off_10D9C0;
extern uint32_t off_10D9C4;
extern uint32_t off_10D9CC;
extern uint32_t dword_10D994;
extern uint32_t dword_10D998;
extern uint32_t off_10DA68;
extern uint32_t dword_10D99C;
extern uint32_t dword_10DA54;
extern uint32_t off_10DA58;
extern uint32_t dword_10DA5C;
extern uint32_t off_10DA60;
extern uint32_t off_10DA64;
extern uint32_t off_10D9A0;
extern uint32_t off_10D9A4;
extern uint32_t off_10D9A8;
extern uint32_t off_10D9AC;
extern uint32_t dword_10D9B0;

// hci_cmd_init @ 0x10d6a8, size 940 bytes
int  hci_cmd_init(int a1, int a2)
{
  int v2; // r4
  int v3; // r0
  int v4; // r1
  int v5; // r6
  int v6; // r5
  int v7; // r3
  uint8_t *v8; // r4
  uint32_t *v9; // r1
  uint32_t *v10; // r0
  uint8_t *v11; // r5
  int v12; // r2
  int v13; // t1
  uint8_t **v15; // r7
  int v16; // r3
  uint8_t **v17; // r8
  int v18; // r0
  uint32_t *v19; // r2
  int *v20; // r4
  int v21; // r1
  int v22; // t1
  int v23; // r1
  uint8_t *v24; // r7
  int v25; // r8
  uint8_t *v26; // r0
  uint8_t *v27; // r7
  uint8_t *v28; // r8
  int v29; // r0
  uint32_t *v30; // r2
  int *v31; // r12
  int v32; // r1
  int v33; // t1
  uint16_t *v34; // r9
  int v35; // r10
  int v36; // r0
  uint32_t *v37; // r2
  int *v38; // r5
  int v39; // r1
  int v40; // t1
  int *v41; // r11
  int v42; // r0
  int v43; // r7
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
  int *v67; // r7
  int v68; // r1
  int v69; // t1
  int *v70; // r11
  uint64_t v71; // kr00_8
  int ( *v72)(uint32_t); // r3
  int v73; // r0
  uint16_t *v74; // r3
  int v75; // r3
  uint16_t v76; // r5
  int v77; // r1
  uint32_t *v78; // r2
  int *v79; // r0
  int v80; // t1
  uint8_t v81[260]; // [sp+8h] [bp-104h] BYREF

  v3 = sub_11EBB4(v81, 256, 0, a1, a2);
  v5 = v3;
  if ( v3 <= 0 )
    return v5;
  v6 = v3;
  if ( *(uint32_t *)off_10D970 )
  {
    v7 = *((uint16_t *)off_10D974 + 89) & 0x4000;
    if ( (*((uint16_t *)off_10D974 + 89) & 0x4000) == 0 )
      goto LABEL_4;
  }
  else
  {
    mac_tx_work();
    v7 = *((uint16_t *)off_10D974 + 89) & 0x4000;
    if ( (*((uint16_t *)off_10D974 + 89) & 0x4000) == 0 )
    {
LABEL_4:
      v8 = v81;
      v9 = off_10D978;
      v10 = off_10D97C;
      v11 = &v81[v6];
      do
      {
        v13 = *v8++;
        v12 = v13;
        if ( v13 == 10 && v7 != 13 )
        {
          while ( (*v9 & 0x80000) != 0 )
            ;
          *v10 = 13;
          v12 = *(v8 - 1);
        }
        while ( (*v9 & 0x80000) != 0 )
          ;
        *v10 = v12;
        v7 = *(v8 - 1);
      }
      while ( v8 != v11 );
      return v5;
    }
  }
  v15 = (uint8_t **)off_10D980;
  v16 = **(uint8_t **)off_10D980;
  if ( v16 == 1 )
  {
    if ( **(uint8_t **)off_10D988 != 3 )
    {
      if ( v6 >= 124 )
        LOWORD(v6) = 124;
      ke_alloc_node(19, v81, (uint16_t)v6);
    }
  }
  else
  {
    if ( v16 != 2 )
      return v5;
    v17 = (uint8_t **)off_10D988;
    if ( **(uint8_t **)off_10D988 == 3 )
      goto LABEL_12;
    if ( (unsigned int)list_count(dword_10D98C, v4) <= 4 )
    {
      if ( **v15 != 2 )
        return v5;
      if ( **v17 != 3 )
      {
        if ( (unsigned int)list_count(dword_10D98C, v23) > 4 )
        {
          v60 = dword_10D9B8;
          v61 = off_10D978;
          v62 = (int *)off_10D97C;
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
          v55 = dword_10D9B4;
          v56 = off_10D978;
          v57 = (int *)off_10D97C;
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
        return v5;
      }
LABEL_12:
      v18 = dword_10D984;
      v19 = off_10D978;
      v20 = (int *)off_10D97C;
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
      return v5;
    }
    v24 = v81;
    v25 = dword_10D9C8;
    while ( 1 )
    {
      v26 = v24++;
      if ( !memcpy(v26, v25, 20) )
        break;
      if ( &v81[v6] == v24 )
      {
        v27 = off_10D990;
        goto LABEL_30;
      }
    }
    v65 = dword_10D9BC;
    v66 = off_10D978;
    v67 = (int *)off_10D97C;
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
    v27 = off_10D990;
    v70 = (int *)off_10D9D0;
    v71 = *(uint64_t *)(*(uint32_t *)off_10D9C0 + 4);
    v72 = *(int ( **)(uint32_t))(HIDWORD(v71) + 16);
    *(uint8_t *)off_10D990 = 1;
    v73 = v72(v71);
    v74 = off_10D9C4;
    *v70 = v73;
    *v74 = 4;
LABEL_30:
    if ( *v27 )
    {
      v28 = off_10D9CC;
      if ( !memcpy(v81, dword_10D994, 5) )
      {
        v29 = dword_10D998;
        v30 = off_10D978;
        v31 = (int *)off_10D97C;
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
      v34 = (uint16_t *)off_10D9C4;
      v35 = *(uint16_t *)off_10D9C4;
      if ( v35 + v6 <= 1720 )
      {
        v41 = (int *)off_10DA68;
        memcpy_large(*(uint32_t *)off_10DA68 + v35, v81, v6);
        v75 = (uint8_t)*v28;
        v76 = v6 + *v34;
        v35 = v76;
        *v34 = v76;
        if ( !v75 )
          return v5;
      }
      else
      {
        v36 = dword_10D99C;
        v37 = off_10D978;
        v38 = (int *)off_10D97C;
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
        v41 = (int *)off_10D9D0;
      }
      v42 = dword_10D98C;
      *v27 = 0;
      *v28 = 0;
      v43 = *v41;
      *v34 = 4;
      *v41 = 0;
      v5 = v35;
      list_pop_front(v42);
    }
    else
    {
      v2 = list_pop_front(dword_10DA54);
      if ( v6 <= 122 )
        v43 = disable_interrupts();
      else
        v43 = (*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10DA58 + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10DA58 + 4));
      if ( !v43 )
      {
        v77 = dword_10DA5C;
        v78 = off_10DA60;
        v79 = (int *)off_10DA64;
        v5 = 110;
        do
        {
          while ( (*v78 & 0x80000) != 0 )
            ;
          *v79 = v5;
          v80 = *(uint8_t *)++v77;
          v5 = v80;
        }
        while ( v80 );
        return v5;
      }
      memcpy_large(v43 + 4, v81, v6);
      LOWORD(v35) = v6;
    }
    *(uint16_t *)v43 = v5 + 1;
    *(uint8_t *)(v43 + 2) = 19;
    v44 = 0;
    v45 = off_10D9A0;
    *(uint8_t *)(v43 + 3) = 0;
    *(uint8_t *)(v43 + v5 + 4) = 0;
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
    v48 = off_10D9A4;
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
    *(uint32_t *)(v2 + 8) = v5 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10D9A8 = 1;
    }
    v50 = (int *)off_10D9AC;
    v51 = dword_10D9B0;
    ++*(uint32_t *)off_10D9AC;
    v52 = check_kernel_state(v51);
    process_event(v52);
    if ( *v50 )
    {
      v53 = *v50 - 1;
      v54 = *(uint32_t *)off_10D9A8;
      *v50 = v53;
      if ( !v53 )
      {
        if ( v54 )
          __enable_irq();
      }
    }
  }
  return v5;
}

