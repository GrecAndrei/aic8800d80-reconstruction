// sub_112094 @ 0x112094, size 66 bytes
int sub_112094()
{
  _BYTE *v0; // r4
  int v1; // r0
  int (__fastcall *v3)(_DWORD); // r3

  v0 = off_1120D8;
  v1 = *((unsigned __int16 *)off_1120D8 + 7);
  *(_WORD *)off_1120DC = v1;
  if ( v1 )
  {
    v3 = *((int (__fastcall **)(_DWORD))off_1120E4 + 5);
    if ( v3 && v3((unsigned __int8)v1) )
    {
      *(_BYTE *)off_1120E0 = 4;
      *v0 = 7;
      if ( !sub_11394C() )
        sub_114028(0);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    *(_BYTE *)off_1120E0 = 3;
    return 1;
  }
}

