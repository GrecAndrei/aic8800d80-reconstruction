// sub_10F458 @ 0x10f458, size 192 bytes
int sub_10F458()
{
  unsigned __int8 **v0; // r4
  int v1; // r3
  _DWORD *v2; // r3
  int v3; // r2
  __int64 v4; // r0
  int v5; // r3
  _DWORD *v6; // r3
  int v7; // r2
  _DWORD *v8; // r3
  void *v9; // r2
  int (__fastcall **v10)(int); // r4
  int v11; // r0
  int v12; // r2
  int (__fastcall **v13)(int); // r5
  int v14; // r0
  int v15; // r0
  int v16; // r0
  int (__fastcall **v17)(int); // r5
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r0

  v0 = (unsigned __int8 **)off_10F518;
  v1 = **(unsigned __int8 **)off_10F518;
  switch ( v1 )
  {
    case 1:
      v8 = off_10F51C;
      v9 = off_10F534;
      *((_DWORD *)off_10F51C + 2) = dword_10F530;
      v8[3] = v9;
      break;
    case 2:
      v2 = off_10F51C;
      v3 = dword_10F524;
      *((_DWORD *)off_10F51C + 6) = dword_10F520;
      v2[7] = v3;
      break;
    case 3:
      v6 = off_10F51C;
      v7 = dword_10F52C;
      *((_DWORD *)off_10F51C + 8) = dword_10F528;
      v6[9] = v7;
      break;
  }
  sub_10F37C();
  v4 = sub_10F3B0();
  v5 = **v0;
  if ( v5 == 1 )
  {
    v17 = (int (__fastcall **)(int))off_10F51C;
    *(_DWORD *)off_10F538 = dword_10F54C;
    v18 = sub_1101E4(v4, HIDWORD(v4));
    v19 = sub_110224(v18);
    v20 = sub_11027C(v19);
    sub_11018C(v20);
    v21 = v17[2](dword_10F540);
    LODWORD(v4) = v17[3](v21);
    v5 = **v0;
  }
  if ( v5 == 2 )
  {
    v12 = dword_10F548;
    *(_DWORD *)off_10F538 = dword_10F544;
    v13 = (int (__fastcall **)(int))off_10F51C;
    *(_WORD *)(v12 + 8244) = 0;
    v14 = sub_1139C8();
    sub_113814(v14);
    v15 = v13[6](dword_10F540);
    v16 = v13[7](v15);
    LODWORD(v4) = sub_114168(v16);
    v5 = **v0;
  }
  if ( v5 == 3 )
  {
    v10 = (int (__fastcall **)(int))off_10F51C;
    *(_DWORD *)off_10F538 = dword_10F53C;
    sub_114234();
    v11 = v10[8](dword_10F540);
    LODWORD(v4) = v10[9](v11);
  }
  return v4;
}

