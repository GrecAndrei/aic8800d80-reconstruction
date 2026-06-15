// v23 annotated: sub_11913C @ 0x11913c
// Original: 11913c_sub_11913C.c
// Primary struct: <unclustered>
//
// sub_11913C @ 0x11913c, size 40 bytes
int __fastcall sub_11913C(int result, int a2)
{
  int v2; // r4
  int (__fastcall *v4)(_DWORD, _DWORD); // r3

  v2 = result;
  if ( !*(_BYTE *)(result + 96) )
    result = list_push_tail(dword_119164);
  if ( a2 )
  {
    v4 = *(int (__fastcall **)(_DWORD, _DWORD))(v2 + 88);
    if ( v4 )
      return v4(*(_DWORD *)(v2 + 92), 0);
  }
  return result;
}

