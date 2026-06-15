// sub_1132B0 @ 0x1132b0, size 164 bytes
int __fastcall sub_1132B0(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r5
  int v4; // r3
  _DWORD *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = off_113354;
  if ( *(_BYTE *)off_113354 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_113358;
  if ( *(_BYTE *)off_113358 )
  {
    sub_10DAE4(dword_11336C, dword_113368, *(unsigned __int8 *)off_113358);
    return -3;
  }
  else
  {
    v4 = *(char *)off_11335C;
    *(_BYTE *)off_113358 = 1;
    v5 = off_113360;
    if ( v4 )
    {
      *((_DWORD *)off_113360 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((_DWORD *)off_113360 + 713) |= 1u;
    }
    v6 = sub_111FDC(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DAE4(dword_113370, dword_113368, v6);
      return -1;
    }
    else
    {
      *(_BYTE *)off_113364 = 1;
      if ( *v2 )
      {
        sub_111C74(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

