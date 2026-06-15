// v23 annotated: sub_1372E0 @ 0x1372e0
// Original: 1372e0_sub_1372E0.c
// Primary struct: <unclustered>
//
// sub_1372E0 @ 0x1372e0, size 112 bytes
BOOL __fastcall sub_1372E0(unsigned __int8 *a1)
{
  int v1; // r8
  int v3; // r9
  int v4; // r7
  int v5; // r4
  int v6; // r5
  unsigned __int8 *v7; // r10
  int v8; // r2

  v1 = *((unsigned __int8 *)off_137350 + 3898);
  if ( *((_BYTE *)off_137350 + 3898) )
    return sub_1437AC(a1 + 1, dword_137354, 7) == 0;
  v3 = *(_DWORD *)off_137350;
  v4 = *(unsigned __int8 *)(*(_DWORD *)off_137350 + 368);
  if ( *(_BYTE *)(*(_DWORD *)off_137350 + 368) )
  {
    v5 = *(_DWORD *)off_137350;
    v6 = *((unsigned __int8 *)off_137350 + 3898);
    v7 = a1 + 1;
    while ( *(_BYTE *)(v5 + 252) )
    {
      v8 = *a1;
      if ( v8 == *(unsigned __int8 *)(v5 + 252) )
      {
        if ( !sub_1437AC(v5 + 253, v7, v8) )
          return 1;
        v4 = *(unsigned __int8 *)(v3 + 368);
      }
      ++v6;
      v5 += 33;
      if ( v4 <= v6 )
        return v1;
    }
  }
  return 1;
}

