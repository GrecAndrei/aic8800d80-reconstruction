// fwstruct annotate: 118cfc_sub_118CFC.c
// sub_118CFC @ 0x118cfc, size 40 bytes
// Doc: sub_1218CFC [unknown]: Unknown helper at 0x1218cfc in fmacfw
// sub_1218CFC [unknown]: Unknown helper at 0x1218cfc in fmacfw
int __fastcall sub_118CFC(int result, int a2)
{
  int v2; // r4
  int (__fastcall *v4)(_DWORD, _DWORD); // r3

  v2 = result;
  if ( !*(_BYTE *)(result + 96) )
    result = list_push_tail(dword_118D24);
  if ( a2 )
  {
    v4 = *(int (__fastcall **)(_DWORD, _DWORD))(v2 + 88);
    if ( v4 )
      return v4(*(_DWORD *)(v2 + 92), 0);
  }
  return result;
}

