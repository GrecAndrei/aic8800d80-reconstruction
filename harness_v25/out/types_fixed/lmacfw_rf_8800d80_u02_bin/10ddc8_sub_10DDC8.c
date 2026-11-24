// sub_10DDC8 @ 0x10ddc8, size 162 bytes
int __fastcall sub_10DDC8(int result, int a2)
{
  _DWORD *v2; // r4
  _DWORD *v3; // r3
  int v4; // r2
  int v5; // r3
  __int64 v6; // r8
  __int64 v7; // r6
  int *v8; // r5
  int *v9; // r10
  __int64 v10; // r0
  __int64 v11; // r0
  __int64 v12; // r0
  int v13; // r0

  v2 = off_10DE88;
  v3 = off_10DE8C;
  v4 = dword_10DE90;
  *(_DWORD *)off_10DE88 = 0;
  *(_DWORD *)(v3 + 0x38) = 296;
  v5 = dword_10DE94;
  *(_DWORD *)(v2 + 0x8) = *(_DWORD *)(v2 + 0x8) & 0xF000FFFF | 0x2000000;
  *(_DWORD *)(v2 + 0xc) = v4 & *(_DWORD *)(v2 + 0xc) | 0xA06A000;
  *(_DWORD *)(v2 + 0xc) = v5 & *(_DWORD *)(v2 + 0xc) | 0x100230;
  if ( a2 > 0 )
  {
    v6 = *(_QWORD *)&dword_10DE70;
    v7 = *(_QWORD *)&dword_10DE78;
    v8 = (int *)result;
    v9 = (int *)(result + 4 * a2);
    do
    {
      *(_DWORD *)(v2 + 0x4) = 1;
      while ( *(_DWORD *)(v2 + 0x1c) != 1 )
        ;
      *(_DWORD *)(v2 + 0x1c) = 1;
      v10 = sub_12752C(*(_DWORD *)(v2 + 0x10));
      v11 = sub_127620(v10, HIDWORD(v10), v6, HIDWORD(v6));
      v12 = sub_127874(v11, HIDWORD(v11), v7, HIDWORD(v7));
      v13 = sub_1272B0(v12, HIDWORD(v12), dword_10DE80, dword_10DE84);
      result = sub_127BE4(v13);
      *v8++ = result;
    }
    while ( v8 != v9 );
  }
  return result;
}

