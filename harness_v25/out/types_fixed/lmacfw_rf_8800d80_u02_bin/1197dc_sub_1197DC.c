// sub_1197DC @ 0x1197dc, size 186 bytes
int __fastcall sub_1197DC(int a1, _BYTE *a2, int a3, int a4)
{
  int v5; // r1
  _BYTE *v6; // r5
  char v7; // r2
  _BYTE *v8; // r6
  int v9; // r1
  _BYTE *(_DWORD *)(v11 + 0x14); // [sp+7h] [bp-5h] BYREF

  *(_DWORD *)(v11 + 0x0) = 0;
  v6 = (_BYTE *)sub_11DDF0(124, a4, a3, 2);
  if ( *a2 )
  {
    sub_11F504(dword_119898, v5);
    **(_BYTE **)off_11989C = 0;
  }
  else
  {
    sub_11F504(dword_1198A8, v5);
    **(_BYTE **)off_11989C = 3;
  }
  sub_11416C(v11);
  v7 = *(_DWORD *)(v11 + 0x0);
  *(_DWORD *)(v6 + 0x4) = *(_DWORD *)(v11 + 0x0);
  v8 = off_1198A0;
  if ( *(_DWORD *)(a2 + 0x4) )
    *((_BYTE *)off_1198A0 + 188) = (v7 & 0x20) != 0;
  else
    *((_BYTE *)off_1198A0 + 188) = (*(_DWORD *)(a2 + 0x8) & 0x20) != 0;
  if ( sub_1141F8() )
  {
    *(_DWORD *)(v8 + 0x2f0) = 0;
    v9 = 0;
  }
  else
  {
    v9 = (unsigned __int8)*(_DWORD *)(v8 + 0x2f0);
  }
  if ( *a2 )
  {
    if ( *(_DWORD *)(a2 + 0xc) )
      *((_WORD *)v8 + 89) |= 0x4000u;
    sub_11F504(dword_1198A4, v9);
    LOBYTE(v9) = *(_DWORD *)(v8 + 0x2f0);
  }
  *v6 = v9;
  sub_11DE50(v6);
  return 0;
}

