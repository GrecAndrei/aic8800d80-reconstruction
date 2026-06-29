// fwstruct annotate: 116628_sub_116628.c
// sub_116628 @ 0x116628, size 40 bytes
int __fastcall sub_116628(int result, int a2)
{
  int v2; // r4
  int (__fastcall *v4)(_DWORD, _DWORD); // r3

  v2 = result;
  if ( !*(_BYTE *)(result + 52) )
    result = list_push_tail(dword_116650);
  if ( a2 )
  {
    v4 = *(int (__fastcall **)(_DWORD, _DWORD))(v2 + 44);
    if ( v4 )
      return v4(*(_DWORD *)(v2 + 48), 0);
  }
  return result;
}

