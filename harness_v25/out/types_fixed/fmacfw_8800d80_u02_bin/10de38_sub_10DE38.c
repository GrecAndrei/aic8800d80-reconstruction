// sub_10DE38 @ 0x10de38, size 78 bytes
int __fastcall sub_10DE38(int a1)
{
  int v1; // r4
  int result; // r0
  BOOL v3; // r4
  int v4; // r5

  v1 = BYTE2(a1);
  result = sub_10DC24(dword_10DE88, BYTE2(a1));
  if ( v1 == 3 )
  {
    v3 = sub_10DD2C(3);
    if ( v3 )
    {
      v4 = 1;
    }
    else
    {
      if ( *((_BYTE *)off_10DE8C + 369) )
        sub_10DD00(2);
      else
        sub_10DD14(2);
      v4 = 2;
    }
    sub_10DC24(dword_10DE90, v3);
    return sub_10D3AC(v4);
  }
  return result;
}

