// v23 annotated: sub_126588 @ 0x126588
// Original: 126588_sub_126588.c
// Primary struct: <unclustered>
//
// sub_126588 @ 0x126588, size 418 bytes
int sub_126588()
{
  int v0; // r3
  _BYTE *v1; // r5
  _BYTE *v2; // r6
  char *v3; // r4
  int v4; // r7
  char *v5; // r3
  int v6; // r7
  int v7; // r10
  float v8; // r3
  float v9; // r9
  __int64 v10; // r0
  __int64 v11; // r0
  unsigned int v12; // r2
  unsigned __int64 v13; // r8
  __int64 v14; // r0
  __int64 v15; // r2
  unsigned __int64 v16; // r0
  __int64 v17; // r8
  char *v18; // r4
  char v19; // r0
  int v20; // r2
  int v21; // r3
  int v22; // r0
  int *v23; // r0
  int *v24; // r1
  _DWORD *v25; // r2
  int v26; // r3
  _BYTE *v27; // r4
  int v28; // r6
  __int64 v29; // r0
  unsigned int v30; // r2
  unsigned __int64 v31; // r6
  __int64 v32; // r0
  int v33; // r0
  float v34; // r0
  __int64 v35; // r0
  __int64 v36; // r0
  char v37; // r3
  int v38; // r0
  __int64 v40; // r8
  __int64 v41; // r0
  int v42; // r0
  int v43; // r0
  _DWORD *v44; // r3

  v0 = *(unsigned __int8 *)off_12672C;
  v1 = off_126734;
  *(_WORD *)off_126730 = 0;
  if ( v0 )
  {
    if ( *v1 == 2 )
    {
      v27 = off_12673C;
      v28 = *(unsigned __int16 *)off_12673C;
      if ( *(_WORD *)off_12673C )
      {
        v29 = sub_12754C(*(_DWORD *)off_126758);
        v30 = v29;
        LODWORD(v29) = v28;
        v31 = __PAIR64__(HIDWORD(v29), v30);
        v32 = sub_12754C(v29);
        v33 = sub_127874(v31, HIDWORD(v31), v32, HIDWORD(v32));
        v34 = sub_127BE4(v33);
        v35 = sub_127570(LODWORD(v34));
      }
      else
      {
        v35 = 0;
      }
      v36 = math_round(v35, HIDWORD(v35));
      v37 = sub_127B54(v36, HIDWORD(v36));
      v38 = dword_126748;
      v27[5] = v37;
      *v1 = 3;
      msg_parse(v38);
      return irq_nesting_or(0x2000);
    }
    else
    {
      return rf_init_n_dc();
    }
  }
  else if ( *v1 )
  {
    v2 = off_126738;
    v3 = (char *)off_12673C;
    v4 = *(unsigned __int8 *)off_126738 - 1;
    v5 = (char *)off_12673C + 8 * v4;
    v6 = 8 * v4;
    v7 = (unsigned __int8)v5[2];
    if ( v5[2] )
    {
      v40 = sub_12754C(*(_DWORD *)off_126758);
      v41 = sub_12754C(v7);
      v42 = sub_127874(v40, HIDWORD(v40), v41, HIDWORD(v41));
      v9 = sub_127BE4(v42);
      v8 = *(float *)off_126740 / (float)v7;
      *(float *)off_126740 = v8;
    }
    else
    {
      v8 = *(float *)off_126740;
      v9 = 0.0;
    }
    v10 = sub_127570(LODWORD(v8));
    v11 = math_round(v10, HIDWORD(v10));
    v12 = v11;
    *(float *)&v11 = v9;
    v13 = __PAIR64__(HIDWORD(v11), v12);
    v14 = sub_127570(v11);
    v15 = math_round(v14, HIDWORD(v14));
    v16 = v13;
    v17 = v15;
    v18 = &v3[v6];
    v18[4] = sub_127B54(v16, HIDWORD(v16));
    v19 = sub_127B54(v17, HIDWORD(v17));
    v20 = (unsigned __int8)*v2;
    v21 = *(unsigned __int8 *)off_126744;
    v18[3] = v19;
    v22 = dword_126748;
    if ( v20 == v21 )
    {
      *v1 = 4;
      msg_parse(v22);
    }
    else
    {
      *v1 = 2;
      msg_parse(v22);
      v23 = (int *)off_12674C;
      v24 = (int *)off_126750;
      v25 = off_126754;
      ++*v2;
      v26 = *v23;
      *v24 = *v23;
      *v25 = v26 + 1000000;
    }
    return irq_nesting_or(0x2000);
  }
  else
  {
    msg_parse(dword_12675C);
    v43 = dword_126748;
    *v1 = 1;
    msg_parse(v43);
    v44 = off_126760;
    *(_DWORD *)off_126760 |= 0x100u;
    *v44 |= 0x200u;
    *v44 |= 0x400u;
    return irq_nesting_or(0x2000);
  }
}

