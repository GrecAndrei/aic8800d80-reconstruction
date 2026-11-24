// sub_119AF4 @ 0x119af4, size 54 bytes
int __fastcall sub_119AF4(int a1, _BYTE *a2, int a3, int a4)
{
  char v7; // r0
  char v9; // r6
  _BYTE *v10; // r0

  v7 = sub_11BBA4(a2, a4);
  if ( a4 )
  {
    v9 = v7;
    v10 = (_BYTE *)sub_11DDF0(71, a4, a3, 3);
    *v10 = *a2;
    *(_DWORD *)(v10 + 0x4) = v9;
    *(_DWORD *)(v10 + 0x8) = 4;
    sub_11DE50(v10);
  }
  return 0;
}

