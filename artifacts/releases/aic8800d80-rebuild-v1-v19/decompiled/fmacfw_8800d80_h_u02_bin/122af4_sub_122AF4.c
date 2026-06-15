// sub_122AF4 @ 0x122af4, size 92 bytes
int __fastcall sub_122AF4(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r5
  int v9; // r0

  v4 = dword_122B54;
  v6 = *a2;
  if ( **(__int16 **)off_122B50 < 0 && *(_BYTE *)(dword_122B54 + 1320 * v6 + 106) )
    sub_12F32C(dword_122B5C, dword_122B58, 2639);
  v9 = v4 + 1320 * v6;
  *(_WORD *)(v9 + 112) = *((_WORD *)a2 + 1);
  *(_BYTE *)(v9 + 114) = a2[4];
  sub_12C8D0(76, a4, a3);
  return 0;
}

