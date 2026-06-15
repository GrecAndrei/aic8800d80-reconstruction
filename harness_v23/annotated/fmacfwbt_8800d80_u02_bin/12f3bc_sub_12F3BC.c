// v23 annotated: sub_12F3BC @ 0x12f3bc
// Original: 12f3bc_sub_12F3BC.c
// Primary struct: <unclustered>
//
// sub_12F3BC @ 0x12f3bc, size 448 bytes
int sub_12F3BC()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r10
  _DWORD *v2; // r6
  _DWORD *v3; // r7
  _DWORD *v4; // r8
  _DWORD *v5; // r9
  _DWORD *v6; // r5
  int v7; // r2
  unsigned int v8; // r0
  int v9; // r3
  _DWORD *v10; // r7
  int v11; // r6
  _DWORD *v12; // r5
  int v13; // r4
  bool v15; // nf
  _DWORD **v16; // r3

  v0 = off_12F584;
  v1 = off_12F620;
  v2 = off_12F588;
  v3 = off_12F58C;
  v4 = off_12F624;
  v5 = off_12F628;
  v6 = off_12F590;
  sub_12ECB0(dword_12F580, *(_DWORD *)off_12F57C & 0xF);
  sub_12ECB0(dword_12F598, *v0, *(_DWORD *)off_12F594);
  sub_12ECB0(dword_12F59C, *v1);
  sub_12ECB0(dword_12F5A0, *v2);
  sub_12ECB0(dword_12F5A4, *v3);
  sub_12ECB0(dword_12F5A8, *v4);
  sub_12ECB0(dword_12F5AC, *v5);
  sub_12ECB0(dword_12F5B0, *v6);
  sub_12ECB0(
    dword_12F5C4,
    *(_DWORD *)off_12F5B4,
    *(_DWORD *)off_12F5B8,
    *(_DWORD *)off_12F5BC,
    *(_DWORD *)off_12F5C0,
    *(_DWORD *)off_12F62C);
  sub_12ECB0(dword_12F5C8, *(_DWORD *)(*v2 + 60));
  sub_12ECB0(dword_12F5CC, *(_DWORD *)(*v3 + 60));
  sub_12ECB0(dword_12F5D0, *(_DWORD *)(*v4 + 60));
  sub_12ECB0(dword_12F5D4, *(_DWORD *)(*v5 + 60));
  sub_12ECB0(dword_12F5D8, *(_DWORD *)(*v6 + 60));
  v7 = *v0 << 6;
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (_DWORD *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(_DWORD **)off_12F618;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (_DWORD *)*v2;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (_DWORD *)*v3;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (_DWORD *)*v4;
  }
  else
  {
    v7 = *v0 << 14;
    if ( (*v0 & 0x20000) != 0 )
    {
      v0 = (_DWORD *)*v5;
    }
    else
    {
      v16 = (_DWORD **)(*v0 << 30);
      v15 = (*v0 & 2) != 0;
      if ( (*v0 & 2) != 0 )
        v16 = (_DWORD **)dword_12F61C;
      else
        v0 = (_DWORD *)*v1;
      if ( v15 )
        v0 = *v16;
    }
  }
  if ( v0 )
  {
    rf_mem_read_ed40((unsigned int)v0, 68, 1, 0);
    rf_mem_read_ed40(v0[9], 52, 1, 0);
    sub_12ECB0(dword_12F5DC, v0[6]);
    v8 = v0[4];
    if ( v8 )
    {
      rf_mem_read_ed40(v8, v0[5] + 1 - v8, 1, 0);
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    else
    {
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    rf_mem_read_ed40(*(_DWORD *)(v9 + 8), *(_DWORD *)(v9 + 12) + 1 - *(_DWORD *)(v9 + 8), 1, 0);
  }
LABEL_6:
  v10 = off_12F5E0;
  v11 = dword_12F5E4;
  v12 = off_12F5E8;
  LOBYTE(v13) = 8;
  do
  {
    sub_12ECB0(v11, *v10, v7);
    sub_12ECB0(dword_12F5EC, *v12);
    v13 = (unsigned __int8)(v13 - 1);
  }
  while ( v13 );
  sub_12ECB0(dword_12F5F4, *(_DWORD *)off_12F5F0);
  sub_12ECB0(dword_12F5FC, *(_DWORD *)off_12F5F8);
  sub_12ECB0(dword_12F604, *(_DWORD *)off_12F600);
  sub_12ECB0(dword_12F60C, *(_DWORD *)off_12F608);
  return sub_12ECB0(dword_12F614, *(_DWORD *)off_12F610);
}

