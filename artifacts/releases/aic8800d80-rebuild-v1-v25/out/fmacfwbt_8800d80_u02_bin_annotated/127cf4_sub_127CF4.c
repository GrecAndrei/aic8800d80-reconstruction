// fwstruct annotate: 127cf4_sub_127CF4.c
// sub_127CF4 @ 0x127cf4, size 118 bytes
int __fastcall sub_127CF4(__int16 *a1, int a2, char a3)
{
  _BYTE *v3; // r4
  __int16 v7; // r3
  _BYTE *v8; // r2

  v3 = off_127D70;
  if ( **(__int16 **)off_127D6C < 0 && *((unsigned __int8 *)off_127D70 + 108) != 255 )
    sub_12F694(dword_127D7C, dword_127D78, 2838);
  v3[108] = 3;
  *((_WORD *)v3 + 49) = 255;
  v3[88] = *((_BYTE *)a1 + 2);
  v7 = *a1;
  *((_WORD *)v3 + 46) = *a1;
  *((_WORD *)v3 + 45) = v7;
  v8 = off_127D74;
  v3[96] = *((_BYTE *)a1 + 4);
  LOBYTE(v7) = v8[88];
  v3[97] = *((_BYTE *)a1 + 3);
  v8[88] = v7 | 2;
  v3[110] = a3;
  *((_DWORD *)v3 + 26) = a2;
  v3[100] = 1;
  return sub_127568();
}

