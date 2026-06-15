// v23 annotated: sub_127AD0 @ 0x127ad0
// Original: 127ad0_sub_127AD0.c
// Primary struct: <unclustered>
//
// sub_127AD0 @ 0x127ad0, size 118 bytes
int __fastcall sub_127AD0(__int16 *a1, int a2, char a3)
{
  _BYTE *v3; // r4
  __int16 v7; // r3
  _BYTE *v8; // r2

  v3 = off_127B4C;
  if ( **(__int16 **)off_127B48 < 0 && *((unsigned __int8 *)off_127B4C + 108) != 255 )
    sub_12F46C(dword_127B58, dword_127B54, 2838);
  v3[108] = 3;
  *((_WORD *)v3 + 49) = 255;
  v3[88] = *((_BYTE *)a1 + 2);
  v7 = *a1;
  *((_WORD *)v3 + 46) = *a1;
  *((_WORD *)v3 + 45) = v7;
  v8 = off_127B50;
  v3[96] = *((_BYTE *)a1 + 4);
  LOBYTE(v7) = v8[88];
  v3[97] = *((_BYTE *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((_DWORD *)v3 + 26) = a2;
  v3[100] = 1;
  return sub_127344();
}

