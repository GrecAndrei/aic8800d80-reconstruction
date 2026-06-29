// fwstruct annotate: 122bc0_sub_122BC0.c
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
  v9[143] = a2[1];
  v9[144] = a2[2];
  v9[145] = 0;
  sub_12CA10(134, a4, a3);
  return 0;
}

