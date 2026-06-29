// fwstruct annotate: 1266e4_sub_1266E4.c
// sub_1266E4 @ 0x1266e4, size 1096 bytes
int __fastcall sub_1266E4(int a1, int a2, unsigned int a3)
{
  int v3; // r7
  int v4; // r5
  int v5; // r8
  int v6; // r9
  int v7; // r11
  int v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int v14; // r6
  int result; // r0
  int v16; // r10
  int v17; // r8
  unsigned int v18; // r6
  int v19; // r6
  int v20; // r0
  int v21; // r0
  int v22; // r3
  int v23; // r11
  int v24; // r2
  int v25; // r9
  int v26; // r0
  int v27; // r6
  int v28; // r7
  char *v29; // r6
  int v30; // r10
  int v31; // r11
  unsigned int v32; // r11
  int v33; // r0
  unsigned int v34; // r3
  int v35; // r3
  unsigned __int8 *v36; // r1
  bool v37; // zf
  int v38; // r3
  unsigned __int8 *v39; // r6
  int v40; // r6
  int v41; // r7
  bool v42; // cf
  int v43; // r6
  int v44; // r8
  int v45; // r0
  int v46; // r6
  int v47; // r10
  int v48; // r1
  int v49; // r2
  char *v50; // r1
  int v51; // r6
  int v52; // [sp+4h] [bp-20h]
  int v53; // [sp+4h] [bp-20h]
  int v54; // [sp+4h] [bp-20h]
  int v55; // [sp+4h] [bp-20h]
  int v56; // [sp+4h] [bp-20h]
  int v57; // [sp+8h] [bp-1Ch]
  int v58; // [sp+8h] [bp-1Ch]
  int v59; // [sp+8h] [bp-1Ch]
  int v61; // [sp+10h] [bp-14h]
  int v62; // [sp+10h] [bp-14h]
  int v63; // [sp+14h] [bp-10h]
  int v64; // [sp+18h] [bp-Ch] BYREF
  int v65[2]; // [sp+1Ch] [bp-8h] BYREF

  v3 = dword_1269F8;
  v4 = *((_DWORD *)off_1269F4 + 4);
  v5 = *(_DWORD *)(a1 + 72);
  v6 = *(unsigned __int8 *)(v4 + 8);
  v7 = dword_1269F8 + 1320 * v6;
  v52 = *(_DWORD *)(v4 + 4) - 4000;
  v53 = v52 - a2 - sub_101944();
  if ( *(_DWORD *)(v7 + 72) != v5 )
  {
    v57 = *(_DWORD *)(v4 + 4);
    v10 = sub_101944();
    v11 = *(unsigned __int8 *)(v5 + 27);
    v61 = v10;
    v12 = v57 - 4000;
    v58 = v57 - 4000 - v10;
    if ( v11 == 255 )
    {
      v13 = *(unsigned __int8 *)(a1 + 86);
      v63 = v12;
      if ( v13 == 255 )
      {
        if ( a3 > (v53 + a3) >> 1 )
          goto LABEL_31;
        v14 = a2 - a3 + ((v53 + a3) >> 1);
LABEL_6:
        if ( a2 != v14 )
          return sub_1265D4(v14, *(_DWORD *)(v3 + 1320 * v6 + 72), v4);
LABEL_31:
        sub_1266A0();
        v14 = a2;
        return sub_1265D4(v14, *(_DWORD *)(v3 + 1320 * v6 + 72), v4);
      }
      v30 = v3 + 1320 * v13;
      v31 = sub_12A000(v30, &v64, v65);
      v14 = v64 - 4000 - sub_101944();
      v64 = v14;
      if ( !v31 )
      {
        if ( v14 + v61 - v63 >= 0 )
          v14 = v58;
        if ( v61 - v63 + v65[0] + 9000 + sub_101944() < 0 )
        {
          sub_1265D4(v14, *(_DWORD *)(v30 + 72), 0);
          v14 = v58;
          sub_1265D4(v65[0], v5, 0);
        }
        goto LABEL_6;
      }
      if ( v65[0] + 9000 + v61 - v63 + sub_101944() < 0 )
      {
        sub_1265D4(a2, *(_DWORD *)(v30 + 72), 0);
        sub_1265D4(v65[0], v5, 0);
        v14 = v64;
        if ( v64 + v61 - v63 >= 0 )
          v14 = v58;
        goto LABEL_6;
      }
LABEL_26:
      v14 = a2;
      goto LABEL_6;
    }
    v16 = v3 + 1320 * v11;
    v17 = *(_DWORD *)(v7 + 72);
    v54 = v12;
    if ( sub_12A000(v16, &v64, v65) )
    {
      v14 = v65[0];
      if ( v58 - v65[0] >= 0 )
      {
        if ( v64 - v54 + v61 >= 0 )
          goto LABEL_6;
        v18 = v64 - v65[0];
        if ( v18 > sub_101944() + 9000 )
        {
          sub_1265D4(v65[0], v17, 0);
          v19 = v64;
          v20 = v19 - 4000 - sub_101944();
          v14 = v58;
          sub_1265D4(v20, *(_DWORD *)(v16 + 72), 0);
          goto LABEL_6;
        }
      }
    }
    else
    {
      if ( v58 - v64 < 0 )
        goto LABEL_26;
      v32 = v64 - a2;
      if ( v32 > sub_101944() + 9000 )
      {
        sub_1265D4(a2, v17, 0);
        v44 = v64;
        v45 = sub_101944();
        sub_1265D4(v44 - 4000 - v45, *(_DWORD *)(v16 + 72), 0);
      }
      v14 = v65[0];
      if ( v58 - v65[0] >= 0 )
        goto LABEL_6;
    }
    v14 = v58;
    goto LABEL_6;
  }
  result = sub_101944();
  v55 = v53 - 4000 - result;
  if ( v55 <= 4999 )
    return result;
  v59 = *(_DWORD *)(v4 + 4);
  v21 = sub_101944();
  v62 = *(unsigned __int8 *)(v5 + 27);
  v22 = v59 - v21;
  v23 = v21;
  v24 = v55;
  v25 = v59 - v21 - 4000;
  if ( v62 == 255 )
  {
    v33 = *(unsigned __int8 *)(a1 + 86);
    v56 = v22;
    if ( v33 == 255 )
    {
      v34 = (v24 + a3) >> 1;
      if ( a3 > v34 )
      {
        v29 = (char *)off_1269FC;
        goto LABEL_39;
      }
      v29 = (char *)off_126B2C;
      v28 = a2 - a3 + v34;
    }
    else
    {
      sub_12A000(v3 + 1320 * v33, &v64, v65);
      v40 = v64;
      result = sub_101944();
      if ( v56 - v40 + result < 0 )
        return result;
      v41 = v64;
      v29 = (char *)off_1269FC;
      v28 = v41 - 4000 - sub_101944();
      v42 = v25 - v65[0] < 0;
      v25 &= (v25 - v65[0]) >> 31;
      if ( !v42 )
        v25 = v65[0];
    }
LABEL_51:
    if ( a2 != v28 )
    {
LABEL_40:
      v35 = *(unsigned __int8 *)(v5 + 24);
      if ( v35 == 2 )
      {
        if ( (unsigned __int8)v29[24] == 255 )
        {
          v38 = 1;
LABEL_44:
          v39 = (unsigned __int8 *)&v29[28 * v38];
          if ( v39[24] == 255 )
            v36 = nullptr;
          else
            v36 = v39;
          goto LABEL_47;
        }
        v36 = (unsigned __int8 *)off_126B2C;
      }
      else
      {
        v36 = (unsigned __int8 *)&v29[28 * v35 + 28];
        if ( v36[24] == 255 )
        {
          v37 = v35 == 1;
          v38 = v35 + 2;
          if ( v37 )
            v38 = 0;
          goto LABEL_44;
        }
      }
LABEL_47:
      sub_1265D4(v28, (int)v36, 0);
      return sub_1265D4(v25, v5, v4);
    }
LABEL_39:
    sub_1266A0();
    v28 = a2;
    goto LABEL_40;
  }
  if ( sub_12A000(v3 + 1320 * v62, &v64, v65) )
  {
    v43 = v64;
    v28 = v65[0];
    if ( v43 - v59 + v23 - sub_101944() < 0 )
    {
      v46 = v64;
      v25 = v46 - 4000 - sub_101944();
    }
    result = v25 - v28 - 9000 - sub_101944();
    if ( result >= 0 )
      goto LABEL_19;
    return result;
  }
  v26 = sub_101944();
  v27 = v64;
  if ( 5000 - v64 + a2 + 2 * (v26 + 4000) < 0 )
  {
    if ( v27 - v59 + v23 - sub_101944() < 0 )
    {
      v51 = v64;
      v47 = v51 - 4000 - sub_101944();
    }
    else
    {
      v47 = v25;
    }
    if ( v65[0] + 9000 - v25 + sub_101944() >= 0 )
    {
      v29 = (char *)off_126B2C;
      v25 = v47;
      goto LABEL_39;
    }
    v29 = (char *)off_126B2C;
    v48 = *(unsigned __int8 *)(*(_DWORD *)(v3 + 1320 * v62 + 72) + 24);
    v49 = v48 + 1;
    if ( v48 == 2 )
    {
      if ( *((unsigned __int8 *)off_126B2C + 24) != 255 )
      {
        v49 = 0;
        goto LABEL_77;
      }
      v49 = 1;
    }
    else
    {
      if ( *((unsigned __int8 *)off_126B2C + 28 * v49 + 24) != 255 )
        goto LABEL_77;
      v49 = v48 + 2;
      if ( v48 == 1 )
        v49 = 0;
    }
    if ( *((unsigned __int8 *)off_126B2C + 28 * v49 + 24) == 255 )
    {
      v50 = nullptr;
LABEL_70:
      sub_1265D4(a2, (int)v50, 0);
      sub_1265D4(v47, *(_DWORD *)(v3 + 1320 * v62 + 72), 0);
      v28 = v65[0];
      goto LABEL_51;
    }
LABEL_77:
    v50 = (char *)off_126B2C + 28 * v49;
    goto LABEL_70;
  }
  result = sub_101944();
  v28 = v65[0];
  if ( v65[0] + 9000 - v25 + result < 0 )
  {
LABEL_19:
    v29 = (char *)off_1269FC;
    goto LABEL_51;
  }
  return result;
}

