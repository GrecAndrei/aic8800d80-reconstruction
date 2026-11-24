// sub_122BC0 @ 0x122bc0, size 98 bytes
int __fastcall sub_122BC0(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r4
  _BYTE *v9; // r4

  v4 = dword_122C28;
  v6 = *a2;
  if ( **(__int16 **)off_122C24 < 0 && *(_BYTE *)(dword_122C28 + 1320 * v6 + 106) )
    sub_12F46C(dword_122C30, dword_122C2C, 3702);
  v9 = (_BYTE *)(v4 + 1320 * v6);
  *(_DWORD *)(v9 + 0x23c) = *(_DWORD *)(a2 + 0x4);
  *(_DWORD *)(v9 + 0x240) = *(_DWORD *)(a2 + 0x8);
  *(_DWORD *)(v9 + 0x244) = 0;
  sub_12CA10(134, a4, a3);
  return 0;
}

