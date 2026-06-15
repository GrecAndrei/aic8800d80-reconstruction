// v23 annotated: sub_128E5C @ 0x128e5c
// Original: 128e5c_sub_128E5C.c
// Primary struct: <unclustered>
//
// sub_128E5C @ 0x128e5c, size 76 bytes
int __fastcall sub_128E5C(int a1, int a2)
{
  int result; // r0
  _BYTE *v4; // r3
  int v5; // r2
  int v6; // r2
  int v7; // r1
  int v8; // r0

  result = sub_128D50(a1, a2, (int)off_128EA8);
  if ( result )
  {
    v4 = off_128EB0;
    v5 = *((unsigned __int8 *)off_128EAC + 2);
    *((_BYTE *)off_128EB0 + 28) = 1;
    if ( v5 )
      *(_DWORD *)off_128EB4 &= ~0x80000000;
    if ( v4[8] )
      --v4[8];
    v6 = *((_DWORD *)off_128EBC + 4);
    v7 = *(unsigned __int16 *)(*(_DWORD *)off_128EB8 + 54);
    v8 = dword_128EC0;
    *((_DWORD *)v4 + 5) = a1;
    v4[29] = 4;
    result = timestamp_update_4f60(v8, v7 + v6);
    *(_DWORD *)(a1 + 4) |= 0x200u;
  }
  return result;
}

