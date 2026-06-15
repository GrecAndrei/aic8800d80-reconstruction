// sub_129404 @ 0x129404, size 82 bytes
int __fastcall sub_129404(int a1, int a2)
{
  int v4; // r0
  int v5; // r3
  int v6; // r2
  __int64 v7; // kr00_8

  v4 = sub_12C7EC(85, 13, 0, 16);
  *(_BYTE *)v4 = *(_BYTE *)(a1 + 113);
  v5 = a1 + 48 * a2;
  *(_BYTE *)(v4 + 1) = a2;
  if ( *(_BYTE *)(v5 + 16) )
  {
    v6 = *(unsigned __int8 *)(v5 + 20);
    *(_BYTE *)(v4 + 3) = v6;
    if ( v6 )
    {
      *(_BYTE *)(v4 + 2) = *(_BYTE *)(v5 + 32);
      v7 = *(_QWORD *)(v5 + 24);
      *(_DWORD *)(v4 + 12) = *(_DWORD *)(v5 + 36);
      *(_QWORD *)(v4 + 4) = v7;
    }
  }
  else
  {
    *(_BYTE *)(v4 + 3) = 0;
  }
  return sub_12C84C(v4);
}

