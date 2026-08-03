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

extern uint32_t dword_11CF3C;
extern uint32_t dword_11CF40;
extern uint32_t off_11CF58;
extern uint32_t off_11CF4C;
extern uint32_t dword_11CF50;
extern uint32_t dword_11CF54;
extern uint32_t off_11D2BC;
extern uint32_t dword_11D2A4;
extern uint32_t dword_11D2B8;
extern uint32_t off_11D2AC;
extern uint32_t dword_11D2B0;
extern uint32_t dword_11D2B4;
extern uint32_t dword_11D2A8;
extern uint32_t dword_11CF48;
extern uint32_t dword_11CF44;
extern uint32_t dword_11D318;

// sub_11CC78 @ 0x11cc78, size 1694 bytes
uint16_t * sub_11CC78(uint16_t *result, int a2, int a3)
{
  int v3; // r8
  int16_t v5; // r10
  int v6; // r9
  int v7; // r6
  uint16_t *v8; // r5
  int v9; // r4
  int16_t v10; // r7
  int v11; // r7
  uint8_t *v12; // r5
  uint8_t v13; // r3
  int v14; // r9
  int v15; // r4
  unsigned int v16; // r2
  int v17; // r6
  int v18; // r2
  int v19; // r5
  int v20; // r9
  int v21; // r4
  unsigned int v22; // r3
  uint8_t *v23; // r0
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  int v27; // r9
  int v28; // r5
  int v29; // r4
  unsigned int v30; // r3
  uint8_t *v31; // r0
  int v32; // r1
  int *v33; // r10
  int v34; // r7
  int v35; // r2
  int v36; // r5
  int v37; // r4
  int v38; // r9
  unsigned int CPSR; // r3
  void *v40; // r2
  int v41; // r0
  int *v42; // r3
  int v43; // r3
  int v44; // r3
  uint8_t *v45; // r0
  int *v46; // r10
  int v47; // r1
  int v48; // r7
  int v49; // r3
  int v50; // r9
  int v51; // r4
  int v52; // r5
  int v53; // r0
  int v54; // r2
  uint32_t *v55; // r3
  int v56; // r2
  int v57; // r0
  uint16_t *v58; // r0
  void *v59; // r2
  uint32_t *v60; // r9
  int v61; // r7
  int v62; // r1
  int v63; // r10
  int v64; // r11
  int v65; // r6
  int v66; // r0
  int *v67; // r3
  int v68; // r3
  int v69; // r3
  int *v70; // r10
  int v71; // r7
  int v72; // r2
  int v73; // r1
  int v74; // r6
  int v75; // r5
  int v76; // r9
  int v77; // r0
  int *v78; // r3
  int v79; // r3
  int v80; // r3
  int v81; // r0
  int v82; // r2
  int v83; // r0
  uint8_t *v84; // r0
  int v85; // [sp+4h] [bp-10h]
  int v86; // [sp+8h] [bp-Ch]
  int v87; // [sp+8h] [bp-Ch]

  v3 = dword_11CF3C + 1320 * a3;
  if ( *(uint8_t *)(v3 + 106) == 2 )
  {
    v5 = *result;
    v6 = 696 * a2;
    v7 = dword_11CF40 + 696 * a2;
    v8 = result;
    v85 = *(uint8_t *)(v7 + 36);
    v9 = a2;
    if ( v85 != 1 )
    {
      if ( (v5 & 0x1404) != 0x1000 )
        return result;
      v16 = *(uint8_t *)(v7 + 35);
      *(uint8_t *)(v7 + 36) = 1;
      if ( v16 <= 0x1F )
      {
        v31 = (uint8_t *)sub_12C92C(73, 13, 0, 2);
        *v31 = v9;
        v31[1] = 1;
        sub_12C98C(v31);
        if ( !*(uint8_t *)(v7 + 36) && *(uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v32 = dword_11CF3C;
          v33 = (int *)off_11CF58;
          v34 = dword_11CF3C + 1320 * *(uint8_t *)(v7 + 34);
          v35 = dword_11CF40;
          v36 = dword_11CF3C + 8 * (165 * *(uint8_t *)(v7 + 34) + 159);
          v37 = dword_11CF40 + 8 * (87 * (int16_t)v9 + 78);
          v38 = dword_11CF40 + 664 + v6;
          do
          {
            if ( *(uint32_t *)(v7 + 584) )
            {
              CPSR = __get_CPSR();
              v40 = (void *)(CPSR << 31);
              if ( (CPSR & 1) == 0 )
              {
                __disable_irq();
                v40 = off_11CF4C;
                *(uint32_t *)off_11CF4C = 1;
              }
              v41 = dword_11CF50;
              ++*v33;
              sub_12EA88(v41, v32, v40);
              sub_12D430(v37 - 40, v36 - 40);
              *(uint64_t *)(v34 + 1232) = *(uint64_t *)(v7 + 584);
              sub_12D240(v37 - 40);
              v35 = *v33 - 1;
              if ( *v33 )
              {
                v42 = (int *)off_11CF4C;
                *v33 = v35;
                v43 = *v42;
                if ( !v35 )
                {
                  if ( v43 )
                    __enable_irq();
                }
              }
            }
            v44 = *(uint32_t *)(v7 + 624);
            v34 += 8;
            v7 += 8;
            if ( v44 )
            {
              sub_12EA88(dword_11CF54, v32, v35);
              sub_12D430(v36, v37);
              sub_12D240(v37);
            }
            v37 += 8;
            v36 += 8;
          }
          while ( v37 != v38 );
          sub_12D104(512);
        }
      }
      v17 = dword_11CF3C + 1320 * a3;
      v18 = *(uint8_t *)(v17 + 234);
      if ( !*(uint8_t *)(v17 + 234) )
      {
        v19 = (uint8_t)(a3 + 32);
        v20 = 696 * v19;
        v21 = dword_11CF40 + 696 * v19;
        if ( *(uint8_t *)(v21 + 36) != 1 )
        {
          v22 = *(uint8_t *)(v21 + 35);
          *(uint8_t *)(v21 + 36) = 1;
          if ( v22 <= 0x1F )
          {
            v23 = (uint8_t *)sub_12C92C(73, 13, v18, 2);
            *v23 = v19;
            v23[1] = 1;
            sub_12C98C(v23);
            if ( *(uint8_t *)(v21 + 36) || *(uint8_t *)(v21 + 35) > 0x1Fu )
            {
              LOBYTE(v18) = *(uint8_t *)(v17 + 234);
            }
            else
            {
              v70 = (int *)off_11D2BC;
              v71 = dword_11D2A4 + 1320 * *(uint8_t *)(v21 + 34);
              v72 = 87 * (uint8_t)(a3 + 32) + 78;
              v73 = dword_11D2B8 - 664;
              v74 = dword_11D2A4 + 8 * (165 * *(uint8_t *)(v21 + 34) + 159);
              v75 = dword_11D2B8 - 664 + 8 * v72;
              v76 = dword_11D2B8 + v20;
              do
              {
                if ( *(uint32_t *)(v21 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    v72 = (int)off_11D2AC;
                    *(uint32_t *)off_11D2AC = 1;
                  }
                  v77 = dword_11D2B0;
                  ++*v70;
                  sub_12EA88(v77, v73, v72);
                  sub_12D430(v75 - 40, v74 - 40);
                  *(uint64_t *)(v71 + 1232) = *(uint64_t *)(v21 + 584);
                  sub_12D240(v75 - 40);
                  v72 = *v70 - 1;
                  if ( *v70 )
                  {
                    v78 = (int *)off_11D2AC;
                    *v70 = v72;
                    v79 = *v78;
                    if ( !v72 )
                    {
                      if ( v79 )
                        __enable_irq();
                    }
                  }
                }
                v80 = *(uint32_t *)(v21 + 624);
                v71 += 8;
                v21 += 8;
                if ( v80 )
                {
                  sub_12EA88(dword_11D2B4, v73, v72);
                  sub_12D430(v74, v75);
                  sub_12D240(v75);
                }
                v75 += 8;
                v74 += 8;
              }
              while ( v75 != v76 );
              sub_12D104(512);
              LOBYTE(v18) = *(uint8_t *)(dword_11D2A4 + 1320 * a3 + 234);
            }
          }
        }
      }
      v24 = v3;
      *(uint8_t *)(dword_11CF3C + 1320 * a3 + 234) = v18 + 1;
      return (uint16_t *)sub_12A5D0(v24);
    }
    if ( (*result & 0x1404) == 0 )
    {
      v25 = *(uint8_t *)(v7 + 35);
      *(uint8_t *)(v7 + 36) = 0;
      if ( v25 <= 0x1F )
      {
        v45 = (uint8_t *)sub_12C92C(73, 13, 0, 2);
        *v45 = v9;
        v45[1] = 0;
        sub_12C98C(v45);
        if ( !*(uint8_t *)(v7 + 36) && *(uint8_t *)(v7 + 35) <= 0x1Fu )
        {
          v46 = (int *)off_11D2BC;
          v86 = v9;
          v47 = dword_11D2A8;
          v48 = dword_11D2A4 + 8 * (165 * *(uint8_t *)(v7 + 34) + 159);
          v49 = dword_11D2A8 + 664 + v6;
          v50 = dword_11D2A4 + 1320 * *(uint8_t *)(v7 + 34);
          v51 = dword_11D2A8 + 8 * (87 * (int16_t)v9 + 78);
          v52 = v49;
          do
          {
            if ( *(uint32_t *)(v7 + 584) )
            {
              if ( (__get_CPSR() & 1) == 0 )
              {
                __disable_irq();
                *(uint32_t *)off_11D2AC = 1;
              }
              v53 = dword_11D2B0;
              v54 = *v46 + 1;
              *v46 = v54;
              sub_12EA88(v53, v47, v54);
              sub_12D430(v51 - 40, v48 - 40);
              *(uint64_t *)(v50 + 1232) = *(uint64_t *)(v7 + 584);
              sub_12D240(v51 - 40);
              v47 = *v46 - 1;
              if ( *v46 )
              {
                v55 = off_11D2AC;
                *v46 = v47;
                if ( !v47 )
                {
                  if ( *v55 )
                    __enable_irq();
                }
              }
            }
            v56 = *(uint32_t *)(v7 + 624);
            v50 += 8;
            v7 += 8;
            if ( v56 )
            {
              sub_12EA88(dword_11D2B4, v47, v56);
              sub_12D430(v48, v51);
              sub_12D240(v51);
            }
            v51 += 8;
            v48 += 8;
          }
          while ( v51 != v52 );
          v9 = v86;
          sub_12D104(512);
        }
      }
      sub_136D14(v3, v9);
      v26 = dword_11CF3C + 1320 * a3;
      v27 = (uint8_t)(*(uint8_t *)(v26 + 234) - 1);
      *(uint8_t *)(v26 + 234) = v27;
      if ( !v27 )
      {
        v28 = (uint8_t)(a3 + 32);
        v29 = dword_11CF40 + 696 * v28;
        if ( *(uint8_t *)(v29 + 36) )
        {
          v30 = *(uint8_t *)(v29 + 35);
          *(uint8_t *)(v29 + 36) = 0;
          if ( v30 <= 0x1F )
          {
            v58 = (uint16_t *)sub_12C92C(73, 13, 0, 2);
            *v58 = (uint8_t)v28;
            sub_12C98C(v58);
            if ( !*(uint8_t *)(v29 + 36) && *(uint8_t *)(v29 + 35) <= 0x1Fu )
            {
              v59 = (void *)dword_11D2B8;
              v60 = off_11D2BC;
              v87 = (uint8_t)(a3 + 32);
              v61 = dword_11D2A4 + 1320 * *(uint8_t *)(v29 + 34);
              v62 = dword_11D2B8 - 664;
              v63 = dword_11D2A4 + 8 * (165 * *(uint8_t *)(v29 + 34) + 159);
              v64 = dword_11D2B8 - 664 + 8 * (87 * v87 + 78);
              v65 = dword_11D2B8 + 696 * v28;
              do
              {
                if ( *(uint32_t *)(v29 + 584) )
                {
                  if ( (__get_CPSR() & 1) == 0 )
                  {
                    __disable_irq();
                    v59 = off_11D2AC;
                    *(uint32_t *)off_11D2AC = 1;
                  }
                  v66 = dword_11D2B0;
                  ++*v60;
                  sub_12EA88(v66, v62, v59);
                  sub_12D430(v64 - 40, v63 - 40);
                  *(uint64_t *)(v61 + 1232) = *(uint64_t *)(v29 + 584);
                  sub_12D240(v64 - 40);
                  v59 = (void *)(*v60 - 1);
                  if ( *v60 )
                  {
                    v67 = (int *)off_11D2AC;
                    *v60 = v59;
                    v68 = *v67;
                    if ( !v59 )
                    {
                      if ( v68 )
                        __enable_irq();
                    }
                  }
                }
                v69 = *(uint32_t *)(v29 + 624);
                v61 += 8;
                v29 += 8;
                if ( v69 )
                {
                  sub_12EA88(dword_11D2B4, v62, v59);
                  sub_12D430(v63, v64);
                  sub_12D240(v64);
                }
                v64 += 8;
                v63 += 8;
              }
              while ( v65 != v64 );
              v28 = v87;
              sub_12D104(512);
            }
          }
        }
        sub_136D14(v3, v28);
      }
      v24 = v3;
      return (uint16_t *)sub_12A5D0(v24);
    }
    if ( (v5 & 0xFC) == 0xA4 )
    {
      if ( (*(uint8_t *)(v7 + 53) & 2) != 0 )
      {
        *(uint8_t *)(v7 + 54) |= 1u;
        result = (uint16_t *)sub_11F3CC(v3, v7, 1);
        *(uint8_t *)(v7 + 54) &= ~1u;
      }
      else
      {
        result = (uint16_t *)sub_11F448(v3, dword_11CF40 + 696 * a2, 1);
        if ( !result )
        {
          v57 = sub_12C92C(74, 13, 0, 4);
          *(uint8_t *)v57 = v9;
          *(uint16_t *)(v57 + 1) = (uint8_t)v85;
          result = (uint16_t *)sub_12C98C(v57);
        }
      }
    }
    if ( (v5 & 0x8C) == 0x88 )
    {
      v10 = (v5 & 0x300) == 0x300 ? v8[15] : v8[12];
      v11 = v10 & 7;
      v12 = (uint8_t *)(dword_11CF40 + 696 * v9);
      if ( (*(uint8_t *)(dword_11CF48 + *(uint8_t *)(dword_11CF44 + v11)) & v12[310]) != 0 )
      {
        v13 = v12[53];
        if ( (v13 & 0xC) != 0 )
        {
          if ( (v12[54] & 6) == 0 )
          {
            v14 = v12[311];
            if ( (v12[53] & 8) != 0 )
            {
              v82 = v12[311];
              v12[54] = 2;
              v83 = sub_11F3CC(v3, v7, v82);
              if ( v14 )
              {
                v14 -= v83;
                if ( v14 <= 0 )
                  goto LABEL_16;
              }
              v13 = v12[53];
            }
            if ( (v13 & 4) != 0 )
            {
              *(uint8_t *)(dword_11D318 + 696 * v9 + 54) = 4;
              v84 = (uint8_t *)sub_12C92C(74, 13, 0, 4);
              *v84 = v9;
              v84[1] = v14;
              v84[2] = 1;
              return (uint16_t *)sub_12C98C(v84);
            }
LABEL_16:
            v15 = dword_11CF40 + 696 * v9;
            result = (uint16_t *)sub_118F48(*(uint8_t *)(v15 + 35), v11 | 0x10, 0, 0);
            *(uint8_t *)(v15 + 54) = 0;
          }
        }
        else if ( (v12[54] & 6) == 0 )
        {
          v81 = v12[35];
          v12[54] = 2;
          result = (uint16_t *)sub_118F48(v81, v11 | 0x10, 0, 0);
          v12[54] = 0;
        }
      }
    }
  }
  return result;
}

