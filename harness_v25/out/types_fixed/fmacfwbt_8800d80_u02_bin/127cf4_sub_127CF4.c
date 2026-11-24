// sub_127CF4 @ 0x127cf4, size 118 bytes
int __fastcall sub_127CF4(__int16 *a1, int a2, char a3)
{
  _BYTE *v3; // r4
  __int16 v7; // r3
  _BYTE *v8; // r2

  v3 = off_127D70;
  if ( **(__int16 **)off_127D6C < 0 && *((unsigned __int8 *)off_127D70 + 108) != 255 )
    sub_12F694(dword_127D7C, dword_127D78, 2838);
  *(_DWORD *)(v3 + 0x1b0) = 3;
  *((_WORD *)v3 + 49) = 255;
  *(_DWORD *)(v3 + 0x160) = *((_BYTE *)a1 + 2);
  v7 = *a1;
  *((_WORD *)v3 + 46) = *a1;
  *((_WORD *)v3 + 45) = v7;
  v8 = off_127D74;
  *(_DWORD *)(v3 + 0x180) = *((_BYTE *)a1 + 4);
  LOBYTE(v7) = *(_DWORD *)(v8 + 0x160);
  *(_DWORD *)(v3 + 0x184) = *((_BYTE *)a1 + 3);
  *(_DWORD *)(v8 + 0x160) = v7 | 2;
  *(_DWORD *)(v3 + 0x1b8) = a3;
  *((_DWORD *)v3 + 26) = a2;
  *(_DWORD *)(v3 + 0x190) = 1;
  return sub_127568();
}

