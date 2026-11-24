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


extern uint32_t dword_10D98C;
extern uint32_t dword_10D9B0;
extern uint32_t dword_10DA54;
extern uint32_t off_10D970;
extern uint32_t off_10D974;
extern uint32_t off_10D978;
extern uint32_t off_10D97C;
extern uint32_t off_10D980;
extern uint32_t off_10D988;
extern uint32_t off_10D990;
extern uint32_t off_10D9A0;
extern uint32_t off_10D9A4;
extern uint32_t off_10D9A8;
extern uint32_t off_10D9AC;
extern uint32_t off_10D9C0;
extern uint32_t off_10D9C4;
extern uint32_t off_10D9CC;
extern uint32_t off_10D9D0;
extern uint32_t off_10DA58;
extern uint32_t off_10DA60;
extern uint32_t off_10DA64;
extern uint32_t off_10DA68;

// hci_cmd_init @ 0x10d6a8, size 940 bytes
int  hci_cmd_init(uint8_t *a1, unsigned int *a2)
{
  uint32_t *v2; // r4
  signed int v3; // r0
  int v4; // r6
  signed int v5; // r5
  int v6; // r3
  char *v7; // r4
  uint32_t *v8; // r1
  uint32_t *v9; // r0
  char *v10; // r5
  int v11; // r2
  int v12; // t1
  uint8_t **v14; // r7
  int v15; // r3
  uint8_t **v16; // r8
  char *v17; // r0
  uint32_t *v18; // r2
  int *v19; // r4
  int v20; // r1
  int v21; // t1
  int v22; // r3
  char *v23; // r7
  unsigned int v24; // r0
  uint8_t *v25; // r7
  uint8_t *v26; // r8
  char *v27; // r0
  uint32_t *v28; // r2
  int *v29; // r12
  int v30; // r1
  int v31; // t1
  uint16_t *v32; // r9
  int v33; // r10
  char *v34; // r0
  uint32_t *v35; // r2
  int *v36; // r5
  int v37; // r1
  int v38; // t1
  char **v39; // r11
  int v40; // r0
  char *v41; // r7
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
  int *v64; // r7
  int v65; // r1
  int v66; // t1
  int *v67; // r11
  uint64_t v68; // kr00_8
  int ( *v69)(uint32_t); // r3
  int v70; // r0
  uint16_t *v71; // r3
  int v72; // r3
  uint16_t v73; // r5
  char *v74; // r1
  uint32_t *v75; // r2
  int *v76; // r0
  int v77; // t1
  char a1a[260]; // [sp+8h] [bp-104h] BYREF

  v3 = rf_parse_cal_cmd(a1a, 256, 0, a1, a2);
  v4 = v3;
  if ( v3 <= 0 )
    return v4;
  v5 = v3;
  if ( *(uint32_t *)off_10D970 )
  {
    v6 = *((uint16_t *)off_10D974 + 89) & 0x4000;
    if ( (*((uint16_t *)off_10D974 + 89) & 0x4000) == 0 )
      goto LABEL_4;
  }
  else
  {
    mac_tx_work();
    v6 = *((uint16_t *)off_10D974 + 89) & 0x4000;
    if ( (*((uint16_t *)off_10D974 + 89) & 0x4000) == 0 )
    {
LABEL_4:
      v7 = a1a;
      v8 = off_10D978;
      v9 = off_10D97C;
      v10 = &a1a[v5];
      do
      {
        v12 = (uint8_t)*v7++;
        v11 = v12;
        if ( v12 == 10 && v6 != 13 )
        {
          while ( (*v8 & 0x80000) != 0 )
            ;
          *v9 = 13;
          v11 = (uint8_t)*(v7 - 1);
        }
        while ( (*v8 & 0x80000) != 0 )
          ;
        *v9 = v11;
        v6 = (uint8_t)*(v7 - 1);
      }
      while ( v7 != v10 );
      return v4;
    }
  }
  v14 = (uint8_t **)off_10D980;
  v15 = **(uint8_t **)off_10D980;
  if ( v15 == 1 )
  {
    v22 = **(uint8_t **)off_10D988;
    if ( v22 != 3 )
    {
      if ( v5 >= 124 )
        LOWORD(v5) = 124;
      ke_alloc_node(19, a1a, (uint16_t)v5, v22);
    }
  }
  else
  {
    if ( v15 != 2 )
      return v4;
    v16 = (uint8_t **)off_10D988;
    if ( **(uint8_t **)off_10D988 == 3 )
      goto LABEL_12;
    if ( (unsigned int)list_count((uint32_t **)dword_10D98C) <= 4 )
    {
      if ( **v14 != 2 )
        return v4;
      if ( **v16 != 3 )
      {
        if ( (unsigned int)list_count((uint32_t **)dword_10D98C) > 4 )
        {
          v57 = aOtherErr;
          v58 = off_10D978;
          v59 = (int *)off_10D97C;
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
          v53 = off_10D978;
          v54 = (int *)off_10D97C;
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
        return v4;
      }
LABEL_12:
      v17 = aNoActive;
      v18 = off_10D978;
      v19 = (int *)off_10D97C;
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
      return v4;
    }
    v23 = a1a;
    while ( 1 )
    {
      v24 = (unsigned int)v23++;
      if ( !memcpy(v24, (unsigned int)aCm4FaultHandle, 0x14u) )
        break;
      if ( &a1a[v5] == v23 )
      {
        v25 = off_10D990;
        goto LABEL_30;
      }
    }
    v62 = aFoundPanic;
    v63 = off_10D978;
    v64 = (int *)off_10D97C;
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
    v25 = off_10D990;
    v67 = (int *)off_10D9D0;
    v68 = *(uint64_t *)(*(uint32_t *)off_10D9C0 + 4);
    v69 = *(int ( **)(uint32_t))(HIDWORD(v68) + 16);
    *(uint8_t *)off_10D990 = 1;
    v70 = v69(v68);
    v71 = (uint16_t *)off_10D9C4;
    *v67 = v70;
    *v71 = 4;
LABEL_30:
    if ( *v25 )
    {
      v26 = off_10D9CC;
      if ( !memcpy((unsigned int)a1a, (unsigned int)aPanic, 5u) )
      {
        v27 = aPanicEnd;
        v28 = off_10D978;
        v29 = (int *)off_10D97C;
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
      v32 = (uint16_t *)off_10D9C4;
      v33 = *(uint16_t *)off_10D9C4;
      if ( v33 + v5 <= 1720 )
      {
        v39 = (char **)off_10DA68;
        memcpy_large((char *)(*(uint32_t *)off_10DA68 + v33), a1a, v5);
        v72 = (uint8_t)*v26;
        v73 = v5 + *v32;
        v33 = v73;
        *v32 = v73;
        if ( !v72 )
          return v4;
      }
      else
      {
        v34 = aBufFull;
        v35 = off_10D978;
        v36 = (int *)off_10D97C;
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
        v39 = (char **)off_10D9D0;
      }
      v40 = dword_10D98C;
      *v25 = 0;
      *v26 = 0;
      v41 = *v39;
      *v32 = 4;
      *v39 = nullptr;
      v4 = v33;
      list_pop_front(v40);
    }
    else
    {
      v2 = list_pop_front(dword_10DA54);
      if ( v5 <= 122 )
        v41 = (char *)disable_interrupts();
      else
        v41 = (char *)(*(int ( **)(uint32_t))(*(uint32_t *)(*(uint32_t *)off_10DA58 + 8) + 16))(*(uint32_t *)(*(uint32_t *)off_10DA58 + 4));
      if ( !v41 )
      {
        v74 = aNoTxBuffer;
        v75 = off_10DA60;
        v76 = (int *)off_10DA64;
        v4 = 110;
        do
        {
          while ( (*v75 & 0x80000) != 0 )
            ;
          *v76 = v4;
          v77 = (uint8_t)*++v74;
          v4 = v77;
        }
        while ( v77 );
        return v4;
      }
      memcpy_large(v41 + 4, a1a, v5);
      LOWORD(v33) = v5;
    }
    *(uint16_t *)v41 = v4 + 1;
    v41[2] = 19;
    v42 = 0;
    v43 = off_10D9A0;
    v41[3] = 0;
    v41[v4 + 4] = 0;
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
    v46 = off_10D9A4;
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
    v2[2] = v4 + 5;
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(uint32_t *)off_10D9A8 = 1;
    }
    v48 = (int *)off_10D9AC;
    v49 = dword_10D9B0;
    ++*(uint32_t *)off_10D9AC;
    check_kernel_state(v49, v2);
    process_event();
    if ( *v48 )
    {
      v50 = *v48 - 1;
      v51 = *(uint32_t *)off_10D9A8;
      *v48 = v50;
      if ( !v50 )
      {
        if ( v51 )
          __enable_irq();
      }
    }
  }
  return v4;
}
