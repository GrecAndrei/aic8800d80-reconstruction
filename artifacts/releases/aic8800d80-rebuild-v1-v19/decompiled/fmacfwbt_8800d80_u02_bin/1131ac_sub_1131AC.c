// sub_1131AC @ 0x1131ac, size 130 bytes
int __fastcall sub_1131AC(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r6
  _DWORD *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = off_113230;
  if ( *(_BYTE *)off_113230 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_113234;
  if ( *(_BYTE *)off_113234 )
  {
    sub_10DA7C(dword_113244, dword_113240, *(unsigned __int8 *)off_113234);
    return -3;
  }
  else
  {
    v4 = off_113238;
    *(_BYTE *)off_113234 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = sub_111EA4(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      sub_10DA7C(dword_113248, dword_113240, v5);
      return -1;
    }
    else
    {
      *(_BYTE *)off_11323C = 1;
      if ( *v2 )
      {
        sub_111C10(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

