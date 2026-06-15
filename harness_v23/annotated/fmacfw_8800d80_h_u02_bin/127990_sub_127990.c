// v23 annotated: sub_127990 @ 0x127990
// Original: 127990_sub_127990.c
// Primary struct: <unclustered>
//
// sub_127990 @ 0x127990, size 118 bytes
int __fastcall sub_127990(__int16 *a1, int a2, char a3)
{
  _BYTE *v3; // r4
  __int16 v7; // r3
  _BYTE *v8; // r2

  v3 = off_127A0C;
  if ( **(__int16 **)off_127A08 < 0 && *((unsigned __int8 *)off_127A0C + 108) != 255 )
    sub_12F32C(dword_127A18, dword_127A14, 2838);
  v3[108] = 3;
  *((_WORD *)v3 + 49) = 255;
  v3[88] = *((_BYTE *)a1 + 2);
  v7 = *a1;
  *((_WORD *)v3 + 46) = *a1;
  *((_WORD *)v3 + 45) = v7;
  v8 = off_127A10;
  v3[96] = *((_BYTE *)a1 + 4);
  LOBYTE(v7) = v8[88];
  v3[97] = *((_BYTE *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((_DWORD *)v3 + 26) = a2;
  v3[100] = 1;
  return sub_127204();
}

