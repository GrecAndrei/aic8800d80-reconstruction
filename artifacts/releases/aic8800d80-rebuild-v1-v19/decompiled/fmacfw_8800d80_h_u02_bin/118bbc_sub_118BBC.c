// sub_118BBC @ 0x118bbc, size 40 bytes
int __fastcall sub_118BBC(int result, int a2)
{
  int v2; // r4
  int (__fastcall *v4)(_DWORD, _DWORD); // r3

  v2 = result;
  if ( !*(_BYTE *)(result + 96) )
    result = sub_12D108(dword_118BE4);
  if ( a2 )
  {
    v4 = *(int (__fastcall **)(_DWORD, _DWORD))(v2 + 88);
    if ( v4 )
      return v4(*(_DWORD *)(v2 + 92), 0);
  }
  return result;
}

