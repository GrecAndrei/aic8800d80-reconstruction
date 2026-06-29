// fwstruct annotate: 117ffc_sub_117FFC.c
// sub_117FFC @ 0x117ffc, size 2000 bytes
int __fastcall sub_117FFC(int a1)
{
  int v1; // s16
  int v2; // r4
  int result; // r0
  int v4; // r4
  int *v5; // r7
  int v6; // r8
  int v7; // r6
  int v8; // r10
  int v9; // r11
  unsigned int v10; // r5
  int v11; // r9
  int v12; // r10
  int v13; // r3
  int v14; // r2
  _BYTE **v15; // r11
  int v16; // r9
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v19; // r2
  _DWORD *v20; // r0
  _BYTE *v21; // r3
  int v22; // r3
  int v23; // r2
  int v24; // r5
  int v25; // r2
  int v26; // r9
  int v27; // r3
  int v28; // r2
  __int16 v29; // r1
  unsigned int v30; // r3
  unsigned int v31; // r2
  int v32; // r5
  int v33; // r3
  int v34; // r3
  int v35; // r11
  unsigned int v36; // r3
  int v37; // r2
  _WORD *v38; // r2
  unsigned int v39; // r3
  unsigned int v40; // r1
  int v41; // r3
  int v42; // r10
  int v43; // r3
  int v44; // r3
  int v45; // r11
  unsigned int v46; // r3
  int v47; // r2
  int v48; // r1
  __int16 v49; // r2
  int v50; // r2
  int v51; // r2
  __int16 v52; // r1
  int v53; // r2
  int v54; // r2
  int v55; // r6
  __int16 v56; // r6
  int v57; // r1
  int v58; // r2
  int v59; // [sp+4h] [bp-28h]
  int v61; // [sp+Ch] [bp-20h]
  int v62; // [sp+10h] [bp-1Ch]
  int v63; // [sp+10h] [bp-1Ch]
  int v64; // [sp+14h] [bp-18h]
  int v65; // [sp+14h] [bp-18h]
  int v66; // [sp+18h] [bp-14h]
  int v67; // [sp+1Ch] [bp-10h]
  _BYTE v68[12]; // [sp+20h] [bp-Ch] BYREF

  v1 = dword_1182F4 + 8 * a1;
  v2 = *(_DWORD *)(dword_1182F8 + 4 * a1);
  if ( **(__int16 **)off_1182F0 < 0 && (v2 & *(_DWORD *)off_1187DC) == 0 )
    sub_12F32C(dword_1187E4, dword_1187E0, 612);
  sub_12D00C(v2);
  result = sub_12D100(v68);
  v4 = *(_DWORD *)(dword_1182F4 + 8 * a1);
  if ( v4 )
  {
    v5 = (int *)off_1182FC;
    v61 = 0;
    v66 = 0;
    v59 = 0;
    v6 = 0;
    do
    {
      v7 = *(_DWORD *)(v4 + 76);
      v8 = *(_DWORD *)(v4 + 68);
      v9 = *(unsigned __int8 *)(v4 + 29);
      if ( *((_BYTE *)off_118300 + 512) == 1 )
      {
        *((_BYTE *)off_118300 + 512) = 0;
        result = sub_12CFC4(512);
        if ( !v8 )
        {
LABEL_39:
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(_DWORD *)off_118304 = 1;
          }
          ++*v5;
          sub_12D190(v1);
          if ( *v5 )
          {
            v22 = *v5 - 1;
            v23 = *(_DWORD *)off_118304;
            *v5 = v22;
            if ( !v22 )
            {
              if ( v23 )
                __enable_irq();
            }
          }
          v24 = *(unsigned __int8 *)(v4 + 28);
          v25 = *(_DWORD *)(v7 + 4);
          v63 = v25;
          if ( *(_BYTE *)(dword_11830C + 696 * v9 + 36) != 1 || (v25 & 0x810000) != 0x10000 )
            sub_13E9A0(v4);
          v26 = dword_118318;
          v27 = dword_118318 + 1320 * v24;
          v28 = *(unsigned __int8 *)(v27 + 1224);
          if ( *(_BYTE *)(v27 + 1224) )
            v8 = dword_118310 + 140 * *(unsigned __int8 *)(v27 + 1225);
          if ( *(unsigned __int8 *)(v4 + 29) > 0x1Fu
            || (v29 = *(_WORD *)(v4 + 30), (v29 & 8) != 0)
            || (v63 & 0x810000) != 0x10000
            || !*(_BYTE *)(dword_118318 + 1320 * v24 + 108) )
          {
LABEL_53:
            if ( *(int *)(*(_DWORD *)(v4 + 44) + 60) >= 0 || (v63 & 0x800000) == 0 )
              goto LABEL_54;
            v42 = *(_DWORD *)(v4 + 76);
            if ( **(__int16 **)off_1185B4 >= 0 )
            {
              v43 = *(_DWORD *)(v42 + 28);
              if ( !v43 )
                goto LABEL_94;
LABEL_96:
              if ( (*(_WORD *)v43 & 0x8000) != 0 && (*(_WORD *)v43 & 0xC) == 8 && (*(_DWORD *)(v43 + 26) & 0x3F) == 7 )
                *(_DWORD *)(*(_DWORD *)(v4 + 44) + 60) &= ~0x80000000;
LABEL_54:
              if ( sub_13AE40(v4, 0) )
              {
                v48 = *(_DWORD *)(v4 + 76);
                v49 = *(_WORD *)(v4 + 30) | 1;
                *(_DWORD *)(v4 + 68) = 0;
                *(_DWORD *)(v48 + 72) = 0;
                *(_DWORD *)(v48 + 4) = 0;
                *(_WORD *)(v4 + 30) = v49;
                *(_WORD *)(v4 + 82) = 0;
                v50 = dword_1185CC;
                *(_DWORD *)(v4 + 44) = 0;
                *(_DWORD *)(v4 + 36) = 0;
                sub_12D240(v26 + 8 * (165 * (__int16)v24 + a1 + 159), v4, v50);
                result = sub_12CFC4(512);
              }
              else
              {
                if ( *(unsigned __int16 *)(v4 + 24) == 36488 && (*(_DWORD *)(v7 + 4) & 0xF) == 9 )
                {
                  v45 = dword_1185B8 + 696 * v9;
                  v46 = *(unsigned __int8 *)(v45 + 669);
                  if ( v46 <= 1 )
                  {
                    v47 = *(_DWORD *)(*(_DWORD *)(v4 + 76) + 36);
                    if ( v47 != *(unsigned __int16 *)(v45 + 670) )
                    {
                      *(_BYTE *)(v45 + 669) = v46 + 1;
                      *(_WORD *)(v45 + 670) = v47;
                    }
                  }
                }
                v30 = *(unsigned __int8 *)(v4 + 29);
                if ( v30 <= 0x1F )
                {
                  v31 = *(unsigned __int8 *)(v4 + 27);
                  if ( v31 <= 8 )
                    *(_DWORD *)(dword_118308 + 4 * (9 * v30 + v31 + 2062)) -= *(unsigned __int16 *)(v4 + 4);
                }
                sub_116D10(v4);
                sub_117BF0(v4, (_DWORD *)(v7 + 4));
                if ( (*(_WORD *)(v4 + 30) & 1) != 0 )
                  sub_12CFC4(512);
                result = sub_12F4B4((unsigned __int8)a1, v4);
              }
              goto LABEL_36;
            }
            if ( *(_DWORD *)(v4 + 72) )
            {
              v43 = *(_DWORD *)(v42 + 28);
              if ( v43 )
                goto LABEL_96;
              goto LABEL_125;
            }
            sub_12F32C(dword_1187F8, dword_1187D4, 518);
            v43 = *(_DWORD *)(v42 + 28);
            if ( v43 )
              goto LABEL_96;
            if ( **(__int16 **)off_1187FC < 0 )
            {
LABEL_125:
              v44 = *(_DWORD *)(v42 + 24);
              if ( !v44 )
              {
                sub_12F32C(dword_1187D8, dword_1187D4, 525);
                goto LABEL_94;
              }
            }
            else
            {
LABEL_94:
              v44 = *(_DWORD *)(v42 + 24);
            }
            v43 = *(_DWORD *)(v44 + 8);
            goto LABEL_96;
          }
          if ( *(_BYTE *)(dword_1187E8 + 696 * v9 + 36) != 1 )
          {
            if ( (v29 & 2) == 0 )
              goto LABEL_132;
            v65 = dword_118318 + 1320 * v24;
            if ( sub_13B7BC(*(unsigned __int16 *)(v4 + 64)) )
            {
              v28 = *(unsigned __int8 *)(v65 + 1224);
LABEL_132:
              if ( !v28 || *(_BYTE *)(v8 + 112) != 1 || *(_BYTE *)(v8 + 133) )
                goto LABEL_53;
            }
          }
          sub_12E948(dword_1187EC, v63, a1);
          v56 = *(_WORD *)(v4 + 30);
          v57 = *(_DWORD *)(v4 + 76);
          v58 = dword_1187CC;
          *(_WORD *)(v4 + 64) = *((_WORD *)off_1187F4 + 22) + (*((_DWORD *)off_1187F0 + 4) >> 10);
          *(_DWORD *)(v4 + 68) = 0;
          *(_DWORD *)(v57 + 72) = 0;
          *(_DWORD *)(v57 + 4) = 0;
          *(_WORD *)(v4 + 82) = 0;
          *(_DWORD *)(v4 + 44) = 0;
          *(_DWORD *)(v4 + 36) = 0;
          *(_WORD *)(v4 + 30) = v56 | 1;
          sub_12D240(v26 + 8 * (165 * (__int16)v24 + a1 + 159), v4, v58);
          result = sub_12CFC4(512);
          goto LABEL_36;
        }
      }
      else if ( !v8 )
      {
        goto LABEL_39;
      }
      if ( (*(_BYTE *)(v8 + 8) & 0x10) == 0 )
        return result;
      v10 = *(_DWORD *)(v7 + 4) & 0xFF7FFFFF;
      v11 = *(_BYTE *)(v8 + 8) & 0x40;
      ++v59;
      *(_DWORD *)(v7 + 4) = v10;
      if ( v11 )
      {
        v38 = *(_WORD **)(v8 + 224);
        if ( !v38
          || (v39 = (*(_WORD *)(v4 + 32) - (*v38 >> 4)) & 0xFFF, v39 <= 0x7FE)
          && ((*v38 & 0xF) != 4 ? (v40 = 3) : (v40 = 15),
              v40 >= v39 >> 4 && (((int)(unsigned __int16)v38[(v39 >> 4) + 1] >> (v39 & 0xF)) & 1) != 0) )
        {
          ++v61;
          v41 = 8650752;
        }
        else
        {
          v41 = 0x40000;
        }
        v10 |= v41;
        *(_DWORD *)(v7 + 4) = v10;
      }
      v62 = sub_13AE40(v4, 0);
      if ( (*(_DWORD *)(v4 + 36) & 0x380000) == 0x280000 )
        v6 = v4;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_118304 = 1;
      }
      ++*v5;
      result = sub_12D190(v1);
      if ( (*(_DWORD *)(v4 + 36) & 0x380000) == 0x380000 )
      {
        if ( **(__int16 **)off_1185B4 < 0 && !v6 )
          sub_12F32C(dword_1185C8, dword_1185C4, 706);
        if ( *(_BYTE *)(dword_1185B8 + 696 * v9 + 36) != 1 || v11 )
          sub_13E9CC(v6, v59, v61, v8);
        v61 = 0;
        result = sub_11A190(v8);
        v59 = 0;
        v12 = 1;
      }
      else
      {
        v12 = 0;
      }
      if ( *v5 )
      {
        v13 = *v5 - 1;
        v14 = *(_DWORD *)off_118304;
        *v5 = v13;
        if ( !v13 )
        {
          if ( v14 )
            __enable_irq();
        }
      }
      if ( *(unsigned __int16 *)(v4 + 24) == 36488 && (*(_DWORD *)(v7 + 4) & 0xF) == 9 )
      {
        v35 = dword_1185B8 + 696 * v9;
        v36 = *(unsigned __int8 *)(v35 + 669);
        if ( v36 <= 1 )
        {
          v37 = *(_DWORD *)(*(_DWORD *)(v4 + 76) + 36);
          if ( v37 != *(unsigned __int16 *)(v35 + 670) )
          {
            *(_BYTE *)(v35 + 669) = v36 + 1;
            *(_WORD *)(v35 + 670) = v37;
          }
        }
      }
      if ( *(int *)(*(_DWORD *)(v4 + 44) + 60) < 0 )
      {
        if ( (v10 & 0x800000) != 0 )
        {
          v32 = *(_DWORD *)(v4 + 76);
          if ( **(__int16 **)off_1185B4 >= 0 )
          {
            v33 = *(_DWORD *)(v32 + 28);
            if ( !v33 )
              goto LABEL_65;
LABEL_67:
            if ( (*(_WORD *)v33 & 0x8000) != 0 && (*(_WORD *)v33 & 0xC) == 8 && (*(_DWORD *)(v33 + 26) & 0x3F) == 7 )
              *(_DWORD *)(*(_DWORD *)(v4 + 44) + 60) &= ~0x80000000;
            v15 = (_BYTE **)off_1185D8;
            if ( !**(_BYTE **)off_1185D8 )
              goto LABEL_34;
            v16 = dword_1185DC;
            v64 = *(unsigned __int8 *)(v4 + 28);
            v67 = dword_1185DC + 1320 * v64;
            goto LABEL_24;
          }
          if ( *(_DWORD *)(v4 + 72) )
          {
            v33 = *(_DWORD *)(v32 + 28);
            if ( v33 )
              goto LABEL_67;
            goto LABEL_111;
          }
          result = sub_12F32C(dword_1187F8, dword_1187D4, 518);
          v33 = *(_DWORD *)(v32 + 28);
          if ( v33 )
            goto LABEL_67;
          if ( **(__int16 **)off_1187FC < 0 )
          {
LABEL_111:
            v34 = *(_DWORD *)(v32 + 24);
            if ( !v34 )
            {
              result = sub_12F32C(dword_1185D4, dword_1185D0, 525);
              goto LABEL_65;
            }
          }
          else
          {
LABEL_65:
            v34 = *(_DWORD *)(v32 + 24);
          }
          v33 = *(_DWORD *)(v34 + 8);
          goto LABEL_67;
        }
        v15 = (_BYTE **)off_1185D8;
        if ( !**(_BYTE **)off_1185D8 )
          goto LABEL_34;
        v16 = dword_1185DC;
        v64 = *(unsigned __int8 *)(v4 + 28);
        v67 = dword_1185DC + 1320 * v64;
      }
      else
      {
        v15 = (_BYTE **)off_118314;
        if ( !**(_BYTE **)off_118314 )
          goto LABEL_34;
        v16 = dword_118318;
        v64 = *(unsigned __int8 *)(v4 + 28);
        v67 = dword_118318 + 1320 * v64;
        if ( (v10 & 0x800000) != 0 )
          goto LABEL_24;
      }
      if ( v62 && *(_BYTE *)(v16 + 1320 * v64 + 108) )
      {
        v51 = *(_DWORD *)(v4 + 76);
        v52 = *(_WORD *)(v4 + 30) | 1;
        *(_DWORD *)(v4 + 68) = 0;
        *(_DWORD *)(v51 + 72) = 0;
        *(_DWORD *)(v51 + 4) = 0;
        *(_WORD *)(v4 + 30) = v52;
        v53 = dword_1187CC;
        *(_WORD *)(v4 + 82) = 0;
        *(_DWORD *)(v4 + 44) = 0;
        *(_DWORD *)(v4 + 36) = 0;
        result = sub_12D240(v16 + 8 * (a1 + 159 + 165 * v64), v4, v53);
        if ( v12 )
          goto LABEL_117;
        v66 = 1;
        goto LABEL_36;
      }
LABEL_24:
      v17 = *(unsigned __int8 *)(v4 + 29);
      if ( v17 <= 0x1F )
      {
        v18 = *(unsigned __int8 *)(v4 + 27);
        if ( v18 <= 8 )
          *(_DWORD *)(dword_118308 + 4 * (9 * v17 + v18 + 2062)) -= *(unsigned __int16 *)(v4 + 4);
      }
      sub_117BF0(v4, (_DWORD *)(v7 + 4));
      v19 = *(unsigned __int16 *)(v4 + 30);
      if ( (v19 & 1) != 0 )
      {
        sub_12CFC4(512);
        v20 = *(_DWORD **)(v4 + 72);
        if ( !v20 )
        {
LABEL_101:
          sub_12E948(dword_1185C0, dword_1185BC, v19);
          goto LABEL_31;
        }
      }
      else
      {
        v20 = *(_DWORD **)(v4 + 72);
        if ( !v20 )
          goto LABEL_101;
      }
      sub_10FEC8(v20);
      v21 = *v15;
      *(_DWORD *)(v4 + 72) = 0;
      if ( *v21 == 1 )
        sub_117F1C();
LABEL_31:
      result = sub_12F4B4((unsigned __int8)a1, v4);
      if ( v12 )
      {
        if ( v66 )
        {
LABEL_117:
          if ( sub_116DBC(v67) && !*((_BYTE *)off_1187D0 + 511) )
          {
            do
            {
              v55 = *(_DWORD *)(v16 + 8 * (165 * v64 + a1 + 159));
              if ( !v55 )
                break;
              sub_12D190(v16 + 8 * (a1 + 159 + 165 * v64));
              sub_13AA68(v55, (unsigned __int8)a1, v54);
            }
            while ( !*((_BYTE *)off_1187D0 + 511) );
          }
        }
        result = sub_12CFC4(512);
        v66 = 0;
LABEL_34:
        if ( v12 )
          v6 = 0;
      }
LABEL_36:
      v4 = *(_DWORD *)(dword_1182F4 + 8 * a1);
    }
    while ( v4 );
  }
  return result;
}

