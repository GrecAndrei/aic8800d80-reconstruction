// sub_128C84 @ 0x128c84, size 186 bytes
void __fastcall sub_128C84(int a1)
{
  _BYTE *v1; // r5
  __int64 v3; // r2
  BOOL v4; // r0
  _DWORD *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r0

  v1 = off_128D44;
  LODWORD(v3) = *((_DWORD *)off_128D48 + 126);
  HIDWORD(v3) = *((_DWORD *)off_128D44 + 1) & 0x20;
  if ( **(_BYTE **)off_128D40 == 1 )
  {
    if ( v3 )
      v4 = 0;
    else
      v4 = sub_1111B4() != 0;
  }
  else
  {
    v4 = v3 == 0;
  }
  if ( *(_BYTE *)(a1 + 149) )
  {
    if ( !**(_BYTE **)off_128D4C || !*(_BYTE *)(a1 + 108) )
    {
LABEL_6:
      v1[29] = 0;
      *(_DWORD *)(a1 + 4) = 0;
      return;
    }
LABEL_18:
    v5 = off_128D58;
    v6 = *(_DWORD *)off_128D54;
    *((_DWORD *)v1 + 5) = a1;
    v7 = *(unsigned __int16 *)(v6 + 54);
    v8 = dword_128D5C;
    v1[29] = 1;
    sub_124BFC(v8, v7 + v5[4]);
    return;
  }
  if ( !**(_BYTE **)off_128D4C || !*(_BYTE *)(a1 + 108) )
    goto LABEL_6;
  if ( !v4 || (*(_DWORD *)off_128D50 & 0x2000000) == 0 && !v1[36] )
    goto LABEL_18;
  if ( v1[29] == 5 )
  {
    *(_DWORD *)(a1 + 4) &= ~2u;
    v1[29] = 0;
  }
  if ( v1[28] )
    sub_128C24();
  else
    v1[29] = 0;
}

