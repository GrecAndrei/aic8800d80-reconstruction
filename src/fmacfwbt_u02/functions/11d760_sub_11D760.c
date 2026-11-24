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


extern uint32_t dword_11DA60;
extern uint32_t dword_11DA68;
extern uint32_t dword_11DA78;
extern uint32_t dword_11DA7C;
extern uint32_t dword_11DA84;
extern uint32_t off_11DA70;
extern uint32_t off_11DA74;
extern uint32_t off_11DA90;
extern uint32_t off_11DA98;
extern uint32_t off_11DA9C;
extern uint32_t off_11DAA0;
extern uint32_t off_11DAA4;
extern uint32_t off_11DAA8;
extern uint32_t off_11DAAC;
extern uint32_t off_11DAB0;
extern uint32_t off_11DBCC;
extern uint32_t off_11DBD0;
extern uint32_t off_11DBD4;
extern uint32_t off_11DBD8;
extern uint32_t off_11DBDC;
extern uint32_t off_11DBE0;

// sub_11D760 @ 0x11d760, size 1128 bytes
BOOL  sub_11D760(int a1)
{
  uint16_t **v1; // r10
  int v2; // r8
  int v3; // r3
  uint32_t *v5; // r9
  uint16_t v6; // r11
  unsigned int v7; // r6
  int v8; // r5
  int v10; // r2
  unsigned int v11; // r7
  int v12; // r3
  volatile unsigned int v13; // r1
  unsigned int v14; // r3
  uint8_t *v15; // r5
  int v16; // r2
  int v17; // r3
  int v18; // r11
  int v19; // r2
  uint8_t *v20; // r7
  int v21; // r4
  uint64_t v22; // r0
  uint64_t v23; // r0
  unsigned int v24; // r2
  uint64_t v25; // r4
  uint64_t v26; // r0
  uint64_t v27; // r0
  uint64_t v28; // r0
  int v29; // r0
  uint8_t *v30; // r4
  uint32_t *v31; // r2
  int v32; // r8
  int *v33; // r11
  uint32_t *v34; // r7
  volatile unsigned int v35; // r9
  unsigned int v36; // r3
  uint32_t *v37; // r3
  volatile unsigned int v38; // r2
  uint32_t *v39; // r9
  volatile unsigned int v40; // r5
  unsigned int v41; // r1
  int v42; // r6
  int v43; // r5
  int v44; // r3
  int v45; // r2
  uint32_t *v46; // r6
  int v47; // r2
  unsigned int v48; // r3
  uint32_t *v49; // r6
  int v50; // r1
  unsigned int v51; // r3
  int a3; // [sp+4h] [bp-18h]
  int a3a; // [sp+4h] [bp-18h]
  int v54; // [sp+8h] [bp-14h]
  int v55; // [sp+Ch] [bp-10h]
  uint8_t *a4; // [sp+14h] [bp-8h] BYREF

  if ( *(uint16_t *)(a1 + 48) )
  {
    v1 = (uint16_t **)off_11DAAC;
    v2 = *(uint32_t *)(a1 + 28);
    v3 = **(uint16_t **)off_11DAAC;
    if ( v3 < 0 && !v2 )
    {
      v8 = 0;
      sub_12F630((int)aRhdFirstPbdPtr, (int)aRxlFrameHandle, 423);
      return v8;
    }
    v5 = *(uint32_t **)(v2 + 8);
    v6 = *(uint16_t *)v5;
    v7 = *(uint32_t *)(a1 + 84);
    if ( LOBYTE(((uint32_t *)(uintptr_t)off_11DA70)[102])
      && (*((uint32_t *)off_11DA74 + 1) & 0x40) != 0
      && (*(uint32_t *)(a1 + 84) & 0x600) == 0x200 )
    {
      if ( (v6 & 0xFC) == 0xC4 )
        ++*(uint32_t *)off_11DA90;
    }
    else
    {
      if ( (dword_11DA78 & ~v7) != 0 )
        return 0;
      *(uint32_t *)(a1 + 84) = v7 & 0xFEFFFFFF;
      if ( v3 < 0 )
      {
        v8 = (v7 >> 15) & 0x1F0;
        if ( !v8 )
        {
          sub_12F630((int)aKeyIdxHwMmSecD, (int)aRxlFrameHandle, 475);
          return v8;
        }
      }
      v10 = dword_11DA7C;
      v11 = (uint8_t)((v7 >> 15) - 16);
      v12 = dword_11DA7C + 696 * v11;
      v8 = *(uint8_t *)(v12 + 37);
      if ( !*(uint8_t *)(v12 + 37) )
      {
        *(uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
        return v8;
      }
      if ( v11 <= 0x23 )
      {
        v13 = (*(volatile uint32_t *)0x40501010u);
        *(uint32_t *)(v12 + 664) = v13;
      }
      v14 = v10 + 696 * v11;
      if ( *(uint16_t *)(v14 + 32) == 0xFFFF )
      {
        if ( (v6 & 0xFC) != 0x80 )
        {
          *(uint32_t *)(a1 + 84) = v7 & 0xFCFFFFFF;
          return 0;
        }
        a3 = *(uint32_t *)(v14 + 44);
        *(uint32_t *)(a1 + 84) = v7 & 0xFE007FFF | ((*(uint8_t *)(a3 + 35) + 16) << 15);
      }
      else
      {
        a3 = v10 + 696 * v11;
      }
      v54 = *(uint8_t *)(a3 + 34);
      v15 = (uint8_t *)(dword_11DA84 + 1320 * v54);
      v55 = 1320 * v54;
      sub_11D0B8(v5, v11, v15[107]);
      if ( !v15[108] )
        return 0;
      v16 = v15[106];
      v17 = dword_11DA84;
      if ( v15[106] )
      {
        if ( (v6 & 4) != 0 )
          goto LABEL_38;
        goto LABEL_36;
      }
      if ( (v6 & 0x300) != 0x200 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
          goto LABEL_19;
        goto LABEL_36;
      }
      v29 = sub_1437AC((unsigned int)(v5 + 4), v55 + 100 + dword_11DA84, 6u);
      v17 = dword_11DA84;
      if ( v29 )
      {
        v8 = v6 & 4;
        if ( (v6 & 4) != 0 )
        {
LABEL_37:
          v16 = *(uint8_t *)(v17 + 1320 * v54 + 106);
          if ( !*(uint8_t *)(v17 + 1320 * v54 + 106) )
          {
LABEL_19:
            v18 = v6 & 0xFC;
            v19 = v55 + v17;
            v20 = (uint8_t *)(v55 + v17);
            if ( v18 == 128 )
            {
              a4 = nullptr;
              v43 = sub_122830(a1 + 20, (int)v20, a3, &a4);
              sub_1291B0((unsigned int)a4, *(uint16_t *)(a1 + 48), (int)v20);
              sub_12057C((int)v20);
              if ( v43 )
                sub_12A568(v20, v2, a1 + 20);
              return v43 == 0;
            }
            if ( v18 == 80 )
            {
              v30 = off_11DA98;
              if ( *((uint8_t *)off_11DA98 + 29) == 7 )
              {
                v8 = *((uint8_t *)off_11DA98 + 36);
                if ( !*((uint8_t *)off_11DA98 + 36) )
                {
                  v31 = off_11DA9C;
                  v32 = *(uint32_t *)off_11DA9C & 0xF;
                  if ( v32 )
                  {
                    if ( (__get_CPSR() & 1) == 0 )
                    {
                      __disable_irq();
                      *(uint32_t *)off_11DAA0 = 1;
                    }
                    v33 = (int *)off_11DAB0;
                    v34 = off_11DA9C;
                    ++*(uint32_t *)off_11DAB0;
                    *v34 = 0;
                    v35 = (*(volatile uint32_t *)0x40501010u);
                    while ( *v34 << 28 )
                    {
                      v36 = (*(volatile uint32_t *)0x40501010u) - v35;
                      if ( v36 > 0x7530 )
                        sub_12EEF8(2, aIdleErr, 30000);
                    }
                    v37 = off_11DAA4;
                    v38 = (*(volatile uint32_t *)0x40501010u);
                    if ( (*(uint32_t *)off_11DAA8 & *(uint32_t *)off_11DAA4 & 4) == 0 )
                    {
                      a3a = v8;
                      v39 = off_11DAA8;
                      v40 = v38;
                      do
                      {
                        v41 = (*(volatile uint32_t *)0x40501010u) - v40;
                        v42 = *v37 & *v39;
                        if ( v41 > 0x7530 )
                        {
                          sub_12EEF8(2, aIdleIntErr);
                          v37 = off_11DBCC;
                        }
                      }
                      while ( (v42 & 4) == 0 );
                      v8 = a3a;
                    }
                    *(uint32_t *)off_11DBD0 = 4;
                    if ( *v33 )
                    {
                      v44 = *v33 - 1;
                      v45 = *(uint32_t *)off_11DBD4;
                      *v33 = v44;
                      if ( !v44 )
                      {
                        if ( v45 )
                          __enable_irq();
                      }
                    }
                    v46 = off_11DBD8;
                    v47 = **v1;
                    v48 = *((uint32_t *)off_11DBD8 + 1) & 0xFFFFFDFF;
                    *((uint32_t *)off_11DBD8 + 1) = v48;
                    if ( v47 < 0 && *(uint32_t *)off_11DBE0 << 28 )
                    {
                      sub_12F6C4((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v48 = v46[1];
                    }
                    *(uint32_t *)off_11DBDC = v48 | *v46;
                    *(uint32_t *)off_11DBE0 = 16 * v32;
                  }
                  else
                  {
                    v49 = off_11DBD8;
                    v50 = **v1;
                    v51 = *((uint32_t *)off_11DBD8 + 1) & 0xFFFFFDFF;
                    *((uint32_t *)off_11DBD8 + 1) = v51;
                    if ( v50 < 0 && *v31 << 28 )
                    {
                      sub_12F6C4((int)aNxmacCurrentSt, (int)aMmRxFilterSet, 472);
                      v51 = v49[1];
                    }
                    *(uint32_t *)off_11DBDC = v51 | *v49;
                  }
                  v30[36] = 1;
                  v30[29] = 0;
                  return v8;
                }
              }
            }
            else if ( v8 )
            {
              if ( v18 == 132 )
              {
                sub_12942C((int)v5, v7, v19);
                return 0;
              }
            }
            else
            {
              sub_12942C((int)v5, v7, v19);
              if ( *(uint8_t *)(dword_11DA84 + 1320 * v54 + 1224) && v18 == 208 )
              {
                sub_12A618((int)v20, *(uint8_t **)(v2 + 8), *(uint16_t *)(a1 + 48), *(uint32_t *)(a1 + 52));
                return v8;
              }
            }
            return 0;
          }
LABEL_38:
          if ( v16 == 2 && *(uint8_t *)(a3 + 35) <= 0x23u )
          {
            v21 = *(char *)(a1 + 65);
            sub_101968();
            if ( !*(uint8_t *)(a3 + 689) )
            {
              v8 = *(char *)(a3 + 689);
              *(uint8_t *)(a3 + 689) = v21;
              return v8;
            }
            v22 = sub_142A70(*(char *)(a3 + 689));
            v23 = sub_142B44(v22, *(uint64_t *)&dword_11DA60);
            v24 = v23;
            LODWORD(v23) = v21;
            v25 = __PAIR64__(HIDWORD(v23), v24);
            v26 = sub_142A70(v23);
            v27 = sub_142B44(v26, *(uint64_t *)&dword_11DA68);
            v28 = sub_1427D8(v25, v27);
            *(uint8_t *)(a3 + 689) = sub_143078(v28);
          }
          return 0;
        }
LABEL_36:
        sub_12B098(*(uint8_t *)(v17 + 1320 * v54 + 107), v11, 1);
        v17 = dword_11DA84;
        v8 = 0;
        goto LABEL_37;
      }
    }
  }
  return 1;
}
