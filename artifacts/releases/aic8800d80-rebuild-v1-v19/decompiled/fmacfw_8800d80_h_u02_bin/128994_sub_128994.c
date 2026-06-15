// sub_128994 @ 0x128994, size 80 bytes
int __fastcall sub_128994(int a1)
{
  unsigned __int8 *v1; // r6
  int v2; // r4
  _BYTE *v4; // r0

  v1 = (unsigned __int8 *)off_1289E4;
  v2 = dword_1289E8 + 1320 * *((unsigned __int8 *)off_1289E4 + 16);
  if ( *(_DWORD *)(v2 + 72) )
  {
    sub_12847C(*((unsigned __int8 *)off_1289E4 + 16));
  }
  else
  {
    v4 = (_BYTE *)sub_12C7EC(5143, 5, 5, 2);
    *v4 = 1;
    v4[1] = *(_BYTE *)(v2 + 107);
    sub_12C84C(v4);
  }
  return sub_128748(v1[16], a1);
}

