// fwstruct annotate: 13709c_sub_13709C.c
// sub_13709C @ 0x13709c, size 112 bytes
BOOL __fastcall sub_13709C(unsigned __int8 *a1)
{
  int v1; // r8
  int v3; // r9
  int v4; // r7
  int v5; // r4
  int v6; // r5
  unsigned __int8 *v7; // r10
  int v8; // r2

  v1 = *((unsigned __int8 *)off_13710C + 3898);
  if ( *((_BYTE *)off_13710C + 3898) )
    return sub_1435D0(a1 + 1, dword_137110, 7) == 0;
  v3 = *(_DWORD *)off_13710C;
  v4 = *(unsigned __int8 *)(*(_DWORD *)off_13710C + 368);
  if ( *(_BYTE *)(*(_DWORD *)off_13710C + 368) )
  {
    v5 = *(_DWORD *)off_13710C;
    v6 = *((unsigned __int8 *)off_13710C + 3898);
    v7 = a1 + 1;
    while ( *(_BYTE *)(v5 + 252) )
    {
      v8 = *a1;
      if ( v8 == *(unsigned __int8 *)(v5 + 252) )
      {
        if ( !sub_1435D0(v5 + 253, v7, v8) )
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

