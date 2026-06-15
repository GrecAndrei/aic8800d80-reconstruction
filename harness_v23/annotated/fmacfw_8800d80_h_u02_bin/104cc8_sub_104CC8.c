// v23 annotated: sub_104CC8 @ 0x104cc8
// Original: 104cc8_sub_104CC8.c
// Primary struct: <unclustered>
//
// sub_104CC8 @ 0x104cc8, size 710 bytes
int __fastcall sub_104CC8(int *a1, int a2, int a3, int a4, __int64 *a5)
{
  int v6; // r0
  int v8; // r2
  int v9; // r0
  float v10; // r0
  int *v11; // r11
  int v12; // r2
  __int64 v13; // d9
  __int64 v14; // r0
  __int64 v15; // d13
  __int64 v16; // r0
  int v17; // r0
  __int64 v18; // r4
  int v19; // r8
  __int64 v20; // r0
  int v21; // r0
  __int64 v22; // d8
  __int64 v23; // r0
  __int64 v24; // r0
  int v25; // r6
  __int64 v26; // r0
  int v27; // r0
  int *v28; // r10
  __int64 v29; // d11
  __int64 v30; // r6
  __int64 v31; // r0
  __int64 v32; // r8
  __int64 v33; // r6
  __int64 v34; // r0
  __int64 v35; // d10
  __int64 v36; // r6
  __int64 v37; // r0
  __int64 v38; // r6
  __int64 v39; // r0
  __int64 v40; // r6
  __int64 v41; // r0
  __int64 v42; // d12
  __int64 v43; // r6
  __int64 v44; // r0
  __int64 v45; // r6
  __int64 v46; // r0
  __int64 v47; // r0
  __int64 v48; // r8
  __int64 v49; // r0
  __int64 v50; // r6
  __int64 v51; // r0
  __int64 v52; // r6
  __int64 v53; // r0
  __int64 v54; // r0
  __int64 v55; // r2
  __int64 v56; // r0
  int v57; // r0
  int result; // r0
  int v59; // t1
  __int64 v60; // r8
  __int64 v61; // [sp+0h] [bp-1Ch]
  __int64 v62; // [sp+8h] [bp-14h]
  __int64 v63; // [sp+10h] [bp-Ch]

  v6 = sub_142E9C(a3, a4);
  v9 = sub_12E948(dword_104F90, v6, v8);
  v10 = sub_10DE08(v9);
  v11 = a1;
  sub_12E948(dword_104F98, (int)(float)(v10 * flt_104F94), v12);
  v13 = a5[2];
  v14 = sub_142968(*((_DWORD *)a5 + 4), *((_DWORD *)a5 + 5), 0, dword_104F9C);
  sub_142E9C(v14, HIDWORD(v14));
  v15 = a5[1];
  v16 = sub_142968(*((_DWORD *)a5 + 2), *((_DWORD *)a5 + 3), 0, dword_104F9C);
  v17 = sub_142E9C(v16, HIDWORD(v16));
  v18 = *a5;
  v19 = v17;
  v20 = sub_142968(*(_DWORD *)a5, *((_DWORD *)a5 + 1), 0, dword_104F9C);
  v21 = sub_142E9C(v20, HIDWORD(v20));
  v22 = a5[5];
  v63 = a5[4];
  v62 = a5[3];
  sub_12E948(dword_104FA0, v21, v19);
  v23 = sub_142968(v22, HIDWORD(v22), 0, dword_104F9C);
  sub_142E9C(v23, HIDWORD(v23));
  v24 = sub_142968(v63, HIDWORD(v63), 0, dword_104F9C);
  v25 = sub_142E9C(v24, HIDWORD(v24));
  v26 = sub_142968(v62, HIDWORD(v62), 0, dword_104F9C);
  v27 = sub_142E9C(v26, HIDWORD(v26));
  sub_12E948(dword_104FA4, v27, v25);
  v28 = v11 + 32;
  do
  {
    v59 = *v11++;
    v60 = sub_1428B8(v59);
    if ( sub_142E74(v18, HIDWORD(v18), v60, HIDWORD(v60)) )
    {
      v55 = v62;
    }
    else if ( sub_142E38(v15, HIDWORD(v15), v60, HIDWORD(v60)) )
    {
      v55 = v63;
    }
    else if ( sub_142E60(v13, HIDWORD(v13), v60, HIDWORD(v60)) )
    {
      v55 = v22;
    }
    else
    {
      v29 = sub_1425F8(v60, HIDWORD(v60), v15, HIDWORD(v15));
      v30 = sub_1425F8(v60, HIDWORD(v60), v13, HIDWORD(v13));
      v31 = sub_1425F8(v60, HIDWORD(v60), v18, HIDWORD(v18));
      v32 = v30;
      v33 = v31;
      v34 = sub_142968(v62, HIDWORD(v62), v29, HIDWORD(v29));
      v35 = v33;
      v36 = sub_142968(v34, HIDWORD(v34), v32, HIDWORD(v32));
      v37 = sub_1425F8(v18, HIDWORD(v18), v15, HIDWORD(v15));
      v38 = sub_142BBC(v36, HIDWORD(v36), v37, HIDWORD(v37));
      v39 = sub_1425F8(v18, HIDWORD(v18), v13, HIDWORD(v13));
      v40 = sub_142BBC(v38, HIDWORD(v38), v39, HIDWORD(v39));
      v41 = sub_142968(v63, HIDWORD(v63), v35, HIDWORD(v35));
      v42 = v40;
      v43 = sub_142968(v41, HIDWORD(v41), v32, HIDWORD(v32));
      v44 = sub_1425F8(v15, HIDWORD(v15), v18, HIDWORD(v18));
      v45 = sub_142BBC(v43, HIDWORD(v43), v44, HIDWORD(v44));
      v46 = sub_1425F8(v15, HIDWORD(v15), v13, HIDWORD(v13));
      v47 = sub_142BBC(v45, HIDWORD(v45), v46, HIDWORD(v46));
      v48 = sub_1425FC(v42, HIDWORD(v42), v47, HIDWORD(v47));
      v49 = sub_142968(v22, HIDWORD(v22), v35, HIDWORD(v35));
      v50 = sub_142968(v49, HIDWORD(v49), v29, HIDWORD(v29));
      v51 = sub_1425F8(v13, HIDWORD(v13), v18, HIDWORD(v18));
      v52 = sub_142BBC(v50, HIDWORD(v50), v51, HIDWORD(v51));
      v53 = sub_1425F8(v13, HIDWORD(v13), v15, HIDWORD(v15));
      v54 = sub_142BBC(v52, HIDWORD(v52), v53, HIDWORD(v53));
      v55 = sub_1425FC(v48, HIDWORD(v48), v54, HIDWORD(v54));
    }
    v61 = v55;
    v56 = sub_1428B8(v11[63]);
    v57 = sub_142968(v56, HIDWORD(v56), v61, HIDWORD(v61));
    result = sub_142F2C(v57);
    v11[31] = result;
  }
  while ( v11 != v28 );
  return result;
}

