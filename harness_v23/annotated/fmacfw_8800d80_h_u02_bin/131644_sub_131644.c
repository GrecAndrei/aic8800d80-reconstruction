// v23 annotated: sub_131644 @ 0x131644
// Original: 131644_sub_131644.c
// Primary struct: <unclustered>
//
// sub_131644 @ 0x131644, size 142 bytes
int __fastcall sub_131644(int a1, unsigned __int8 *a2)
{
  int v3; // r5
  int v4; // r6
  char v5; // r3
  char v7; // r3

  v3 = *(_DWORD *)(dword_1316D8 + 696 * *a2 + 340);
  if ( **(__int16 **)off_1316D4 < 0 && !v3 )
    sub_12F32C(dword_1316E0, dword_1316DC, 1031);
  v4 = *((unsigned __int16 *)a2 + 1);
  if ( v4 == 0xFFFF )
  {
    v5 = *(_BYTE *)(v3 + 166);
    *(_WORD *)(v3 + 190) = -1;
    v5 &= 0xCFu;
    *(_BYTE *)(v3 + 166) = v5;
    if ( (v5 & 0x80) == 0 )
      return 0;
    sub_13EF7C(*a2);
    *(_BYTE *)(v3 + 166) &= ~0x80u;
    return 0;
  }
  else
  {
    if ( !sub_13F2A4(v3, *((unsigned __int16 *)a2 + 1)) )
      return 0;
    v7 = *(_BYTE *)(v3 + 166);
    *(_WORD *)(v3 + 190) = v4;
    *(_BYTE *)(v3 + 166) = v7 & 0xCF | 0x10;
    return 0;
  }
}

