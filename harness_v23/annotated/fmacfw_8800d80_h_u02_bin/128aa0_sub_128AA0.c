// v23 annotated: sub_128AA0 @ 0x128aa0
// Original: 128aa0_sub_128AA0.c
// Primary struct: <unclustered>
//
// sub_128AA0 @ 0x128aa0, size 66 bytes
int __fastcall sub_128AA0(int a1, int a2)
{
  int result; // r0
  _BYTE *v4; // r5
  int v5; // r3

  result = sub_1289EC(a1, a2, (int)off_128AE4);
  if ( result )
  {
    v4 = off_128AEC;
    v5 = *((unsigned __int8 *)off_128AE8 + 2);
    *((_BYTE *)off_128AEC + 28) = 0;
    if ( v5 )
      *(_DWORD *)off_128AF0 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = sub_124CF4(dword_128AF4);
    v4[29] = 0;
    *(_DWORD *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}

