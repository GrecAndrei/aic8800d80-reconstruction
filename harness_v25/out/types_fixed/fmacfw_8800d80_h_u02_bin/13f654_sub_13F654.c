// sub_13F654 @ 0x13f654, size 142 bytes
int __fastcall sub_13F654(int a1)
{
  int v1; // r4
  int v2; // r3
  int result; // r0
  char v4; // r3

  v1 = *(_DWORD *)(dword_13F6E8 + 696 * a1 + 340);
  if ( **(__int16 **)off_13F6E4 < 0 && !v1 )
    sub_12F32C(dword_13F6F0, dword_13F6EC, 2194);
  sub_13E1E8(v1);
  v2 = *(unsigned __int16 *)(v1 + 184);
  *(_WORD *)(v1 + 136) = (v2 - 1) & ~(unsigned __int16)((v2 - 1) >> 31);
  *(_WORD *)(v1 + 138) = (v2 - 2) & ~(unsigned __int16)((v2 - 2) >> 31);
  *(_WORD *)(v1 + 140) = (v2 - 3) & ~(unsigned __int16)((v2 - 3) >> 31);
  *(_DWORD *)(v1 + 148) = 0x10000;
  *(_WORD *)(v1 + 190) = -1;
  *(_WORD *)(v1 + 142) = 0;
  *(_BYTE *)(v1 + 166) = 0;
  result = sub_13F490(v1, 1);
  v4 = *(_BYTE *)(v1 + 184);
  *(_BYTE *)(v1 + 154) = 0;
  *(_BYTE *)(v1 + 164) = v4 - 4;
  *(_WORD *)(v1 + 152) = 5;
  return result;
}

