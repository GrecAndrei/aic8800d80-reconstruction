// v23 annotated: sub_1121D4 @ 0x1121d4
// Original: 1121d4_sub_1121D4.c
// Primary struct: <unclustered>
//
// sub_1121D4 @ 0x1121d4, size 66 bytes
int sub_1121D4()
{
  _BYTE *v0; // r4
  int v1; // r0
  int (__fastcall *v3)(_DWORD); // r3

  v0 = off_112218;
  v1 = *((unsigned __int16 *)off_112218 + 7);
  *(_WORD *)off_11221C = v1;
  if ( v1 )
  {
    v3 = *((int (__fastcall **)(_DWORD))off_112224 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(_BYTE *)off_112220 = 4;
      *v0 = 7;
      if ( !sub_113A8C() )
        sub_114168(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_BYTE *)off_112220 = 3;
    return 1;
  }
}

