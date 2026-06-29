// fwstruct annotate: 11e188_sub_11E188.c
// sub_11E188 @ 0x11e188, size 810 bytes
int __fastcall sub_11E188(int a1, unsigned int a2, int a3, __int16 a4, int a5, int a6)
{
  int v6; // r8
  unsigned __int8 **v7; // r7
  int v8; // r12
  unsigned __int8 *v9; // r5
  int v11; // r3
  int v14; // r3
  _DWORD *v15; // r0
  int v16; // r3
  int *v18; // r5
  int v19; // r8
  unsigned __int8 v20; // r7
  _WORD *v21; // r5
  int *v22; // r9
  int v23; // r10
  bool v24; // cc
  int v25; // r0
  int v26; // r0
  int v27; // r1
  int v28; // r3
  int v29; // r0
  _BYTE *v30; // r1
  int v31; // r2
  char v32; // r10
  int v33; // r2
  int v34; // r3
  _BYTE *v35; // r5
  int v36; // r2
  int *v37; // r9
  int v38; // r0
  int v39; // r0
  int v40; // r1
  int v41; // r3
  int v42; // r2
  _DWORD *v43; // r0
  int v44; // r1
  int v45; // r2
  int v46; // r7
  int v47; // r2
  int v48; // r12
  int v49; // r2
  int v50; // r0
  unsigned int CPSR; // r3
  int *v52; // r4
  int v53; // r0
  int v54; // r2
  int v55; // r3
  int v56; // r0
  int v57; // [sp+Eh] [bp-Eh] BYREF
  int v58[2]; // [sp+14h] [bp-8h] BYREF

  v7 = (unsigned __int8 **)off_11E41C;
  v8 = *(_DWORD *)(a1 + 28);
  v9 = *(unsigned __int8 **)off_11E41C;
  v58[0] = v8;
  LOWORD(v57) = a4;
  v11 = *v9;
  if ( v11 != 2 )
    goto LABEL_2;
  v21 = off_11E42C;
  if ( *((_DWORD *)off_11E42C + 2057) )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_11E430 = 1;
    }
    v22 = (int *)off_11E450;
    v23 = dword_11E454;
    v24 = (unsigned __int16)v21[4122] > 0x186u;
    ++*(_DWORD *)off_11E450;
    v25 = dword_11E434;
    if ( v24 )
      v21[4122] = 0;
    v26 = sub_12D190(v25);
    v27 = *(_DWORD *)off_11E438;
    v28 = (unsigned __int16)v21[4122];
    v6 = v26;
    v29 = *(_DWORD *)off_11E438 + 8 * v28;
    *(_WORD *)(v6 + 12) = v28;
    *(_DWORD *)(v29 + 4) = a1 + 48;
    *(_DWORD *)(v27 + 8 * v28) = v23;
    v30 = off_11E43C;
    *(_DWORD *)(v6 + 4) = v29;
    v31 = *v22;
    v32 = *((_BYTE *)v21 + 3074) + 1;
    LOBYTE(v29) = v30[3] + 1;
    v21[4122] = v28 + 1;
    *((_BYTE *)v21 + 3074) = v32;
    v30[3] = v29;
    if ( v31 )
    {
      v33 = v31 - 1;
      v34 = *(_DWORD *)off_11E430;
      *v22 = v33;
      if ( !v33 )
      {
        if ( v34 )
          __enable_irq();
      }
    }
    v11 = **v7;
    if ( v11 == 2 )
    {
      sub_11DACC(v58, a2, &v57);
      v14 = **v7;
      if ( v14 != 2 )
        goto LABEL_5;
LABEL_25:
      v35 = off_11E43C;
      if ( !*((_BYTE *)off_11E43C + 2) )
        goto LABEL_6;
      v36 = *(_DWORD *)(v6 + 4);
      *(_DWORD *)(v6 + 8) = *(unsigned __int16 *)off_11E43C + 58;
      *(_BYTE *)(v36 + 3) &= 0x3Fu;
      *(_BYTE *)(v6 + 14) = v35[3];
      *(_DWORD *)v6 = 0;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(_DWORD *)off_11E430 = 1;
      }
      v37 = (int *)off_11E450;
      v38 = dword_11E440;
      ++*(_DWORD *)off_11E450;
      v39 = sub_12D108(v38);
      sub_113374(v39, v40);
      if ( *v37 )
      {
        v41 = *v37 - 1;
        v42 = *(_DWORD *)off_11E430;
        *v37 = v41;
        if ( !v41 )
        {
          if ( v42 )
            __enable_irq();
        }
      }
      *(_DWORD *)v35 = 0;
      *((_DWORD *)v35 + 1) = 0;
      v14 = **v7;
LABEL_5:
      if ( v14 == 1 )
      {
        v18 = (int *)off_11E424;
        if ( *((_BYTE *)off_11E424 + 32) )
        {
          v43 = (_DWORD *)sub_11017C();
          v46 = (int)v43;
          if ( v43 )
          {
            if ( *((_BYTE *)v18 + 32) )
            {
              v47 = *v18;
              v48 = v18[1] + 1;
              v43[2] = (v48 << 24) & 0x7F000000 | v43[2] & 0x80FFFFFF;
              v18[1] = v48;
              sub_110FFC(v43, a1 + 48, v47, 0x3Au, 0);
              v49 = *((unsigned __int8 *)off_11E448 + 192);
              v18[3] += 58;
              if ( v49 )
                sub_11E130(v46);
              else
                sub_110EDC(v46, v18[1], v18[2]);
              *(_BYTE *)off_11E44C |= 1u;
              v18[1] = 0;
              v18[3] = 0;
              *v18 = 0;
              v18[2] = 0;
              *((_BYTE *)v18 + 32) = 0;
              goto LABEL_6;
            }
          }
          else
          {
            v56 = dword_11E4C0;
            *(_BYTE *)(a1 + 16) |= 1u;
            sub_12E948(v56, v44, v45);
            *((_BYTE *)v18 + 32) = 0;
          }
        }
        sub_12EB90(1024, dword_11E428);
        v19 = *v18;
        *(_BYTE *)(a1 + 16) |= 1u;
        if ( v19 && v18[1] )
        {
          v20 = 0;
          do
          {
            v19 = *(_DWORD *)(v19 + 4);
            sub_1101BC();
            ++v20;
          }
          while ( v20 < (unsigned int)v18[1] );
        }
        v18[1] = 0;
        v18[3] = 0;
        *v18 = 0;
        v18[2] = 0;
      }
LABEL_6:
      sub_11DE3C(a1, v58[0]);
      v15 = off_11E420;
      *(_DWORD *)(a1 + 4) = a5;
      v16 = v15[14];
      *(_DWORD *)(a1 + 8) = a6;
      if ( v16 )
        return sub_12D108(v15 + 14);
      else
        return sub_12D108(dword_11E444);
    }
LABEL_2:
    if ( v11 == 1 )
      sub_11DC04(v58, a2, &v57);
    else
      sub_11DD24(v58, a2, a3, &v57, 0);
    v14 = **v7;
    if ( v14 != 2 )
      goto LABEL_5;
    goto LABEL_25;
  }
  *(_BYTE *)(a1 + 16) |= 1u;
  v50 = sub_11DE3C(a1, v8);
  CPSR = __get_CPSR();
  if ( (CPSR & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11E4B4 = 1;
  }
  v52 = (int *)off_11E4B8;
  ++*(_DWORD *)off_11E4B8;
  v53 = sub_113374(v50, CPSR << 31);
  if ( *v52 )
  {
    v55 = *v52 - 1;
    v54 = *(_DWORD *)off_11E4B4;
    *v52 = v55;
    if ( !v55 )
    {
      if ( v54 )
        __enable_irq();
    }
  }
  return sub_10DAE4(dword_11E4BC, v53, v54);
}

