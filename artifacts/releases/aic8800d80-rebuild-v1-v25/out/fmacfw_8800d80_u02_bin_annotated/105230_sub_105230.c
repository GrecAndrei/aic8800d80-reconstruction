// fwstruct annotate: 105230_sub_105230.c
// sub_105230 @ 0x105230, size 168 bytes
int __fastcall sub_105230(float a1, int a2, int a3)
{
  float v5; // r0
  int v6; // r0
  __int64 v7; // r0
  __int16 v8; // r0
  __int64 v9; // kr00_8
  __int64 v11; // kr08_8

  v5 = sub_12D520(a1 / 20.0);
  v6 = sub_1429F8((float)a2 * v5);
  v7 = sub_14261C(v6);
  v8 = sub_142FDC(v7, HIDWORD(v7));
  if ( v8 <= 232 )
  {
    if ( v8 > 31 )
    {
      *(_BYTE *)(a3 + 104) = v8;
    }
    else
    {
      v11 = *(_QWORD *)(a3 + 112);
      *(_BYTE *)(a3 + 104) = 32;
      if ( SHIDWORD(v11) < (int)v11 )
        sub_12EA88(dword_1052E0, HIDWORD(v11), v11);
    }
  }
  else
  {
    v9 = *(_QWORD *)(a3 + 112);
    *(_BYTE *)(a3 + 104) = -24;
    if ( SHIDWORD(v9) < (int)v9 )
      sub_12EA88(dword_1052E4, HIDWORD(v9), v9);
  }
  return sub_12ECD0(1, dword_1052DC);
}

