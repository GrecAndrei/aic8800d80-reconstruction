// sub_135250 @ 0x135250, size 418 bytes
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_135250(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r4
  int v14; // r6
  int v15; // r8
  int v16; // r9
  int v17; // r11
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  int v22; // r4
  _BYTE *v23; // r7
  int v24; // r10
  int v25; // r5
  __int16 v26; // r3
  _WORD *v27; // r2
  int v28; // r1
  int v29; // r11
  int v30; // t1
  int v31; // lr
  __int16 v32; // r3
  int v33; // r6
  __int16 v34; // r12
  _WORD *v35; // r7
  int v36; // r3
  int v37; // r0
  _DWORD *v38; // r1
  int v39; // r2
  bool v40; // cc
  int v41; // r2
  int v42; // r0
  int v43; // r3
  int v44; // r0
  _BYTE *v45; // r4
  int v46; // [sp-24h] [bp-24h]
  int v47; // [sp-20h] [bp-20h]
  int v48; // [sp-1Ch] [bp-1Ch]
  int v49; // [sp-18h] [bp-18h]
  int v50; // [sp-14h] [bp-14h]
  int v51; // [sp-10h] [bp-10h]
  int v52; // [sp-10h] [bp-10h]
  unsigned int v53; // [sp-10h] [bp-10h]
  int v54; // [sp-Ch] [bp-Ch] BYREF
  int v55[2]; // [sp-8h] [bp-8h] BYREF

  if ( *(_BYTE *)(v13 + 1224) )
  {
    v22 = sub_118B04(1, 512);
    if ( v22 )
      goto LABEL_5;
  }
  else
  {
    v18 = *(unsigned __int8 *)(v13 + 412);
    if ( *(_BYTE *)(v13 + 412) )
      v18 = 1;
    v22 = sub_118B04(v18, 512);
    if ( v22 )
    {
LABEL_5:
      v23 = off_1353F4;
      v52 = 1320 * v14;
      v24 = *((_DWORD *)off_1353F4 + 5);
      sub_12C3A8(v15 + 1320 * v14, v22);
      v25 = *(_DWORD *)(v22 + 72);
      v26 = (unsigned __int8)v23[33];
      if ( v23[33] )
      {
        v27 = (_WORD *)dword_135410;
        v26 = 32;
      }
      else
      {
        v27 = nullptr;
      }
      v28 = dword_135400;
      *(_WORD *)(v25 + 108) = v26;
      v29 = v28 + 696 * v17;
      v30 = *(_DWORD *)(v29 + 38);
      v29 += 38;
      v31 = *(_DWORD *)v29;
      v32 = *((_WORD *)off_135404 + 254);
      *(_DWORD *)(v25 + 112) = v30;
      v33 = v15 + 1320 * v14;
      *(_WORD *)(v25 + 116) = *(_WORD *)(v29 + 4);
      v34 = *(_WORD *)(v29 + 4);
      *(_DWORD *)(v25 + 118) = *(_DWORD *)(v33 + 100);
      *(_WORD *)(v25 + 122) = *(_WORD *)(v33 + 104);
      ++v32;
      v35 = off_135404;
      *(_DWORD *)(v25 + 124) = v31;
      *(_WORD *)(v25 + 128) = v34;
      *(_BYTE *)(v25 + 110) = 0;
      *(_BYTE *)(v25 + 111) = 0;
      LOWORD(v31) = 16 * v32;
      v35[254] = v32;
      v36 = *(unsigned __int8 *)(v33 + 107);
      *(_WORD *)(v25 + 130) = v31;
      v37 = sub_130700(v25 + 132, v52 + 248 + v15, v27, v36, v55, (_WORD *)&v54 + 1, v16);
      *(_BYTE *)(v22 + 28) = *(_BYTE *)(v33 + 107);
      v38 = *(_DWORD **)(v22 + 76);
      *(_BYTE *)(v22 + 29) = *(_BYTE *)(v33 + 116);
      v39 = HIWORD(v54);
      v40 = HIWORD(v54) > 0x320u;
      v38[8] = v38[7] + 23 + v37;
      v38[9] = v37 + 28;
      if ( v40 )
      {
        if ( **(__int16 **)off_135414 < 0 )
          sub_12F35C(dword_13541C, dword_135418, 1115);
        *(_WORD *)(v24 + 14) = 0;
      }
      else
      {
        if ( v39 )
        {
          v41 = v39 + v24 + 19;
          v42 = v55[0] - 19 - v24;
          v43 = v24 + 19;
          do
          {
            *(_BYTE *)(v43 + 1) = *(_BYTE *)(v42 + v43);
            ++v43;
          }
          while ( v43 != v41 );
          LOWORD(v39) = HIWORD(v54);
        }
        *(_WORD *)(v24 + 14) = v39;
      }
      v44 = v22;
      v53 = *(_DWORD *)(*(_DWORD *)off_135408 + 8);
      *(_DWORD *)(v22 + 88) = dword_13540C;
      *(_DWORD *)(v22 + 92) = v22;
      v45 = off_1353F4;
      sub_118B34(v44, 5);
      v45[34] = 1;
      sub_12C4A4(6154, 6, v53);
      sub_12CBF4(6u, 8);
      __asm { POP.W           {R4-R11,PC} }
    }
  }
  sub_134CC4(1, v19, v20, v21, v46, v47, v48, v49, v50, v51, v54, v55[0], v55[1]);
  __asm { POP.W           {R4-R11,PC} }
}

