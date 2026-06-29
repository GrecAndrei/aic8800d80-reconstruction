// fwstruct annotate: 128af8_sub_128AF8.c
// sub_128AF8 @ 0x128af8, size 76 bytes
int __fastcall sub_128AF8(int a1, int a2)
{
  int result; // r0
  _BYTE *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = sub_1289EC(a1, a2, dword_128B44);
  if ( result )
  {
    v4 = off_128B4C;
    v5 = *((unsigned __int8 *)off_128B48 + 2);
    *((_BYTE *)off_128B4C + 28) = 1;
    if ( v5 )
      *(_DWORD *)off_128B50 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((_DWORD *)off_128B58 + 4);
    v7 = *(unsigned __int16 *)(*(_DWORD *)off_128B54 + 54);
    v8 = dword_128B5C;
    *((_DWORD *)v4 + 5) = a1;
    v4[29] = 4;
    result = sub_124BFC(v8, v7 + v6);
    *(_DWORD *)(a1 + 4) |= 0x200u;
  }
  return result;
}

