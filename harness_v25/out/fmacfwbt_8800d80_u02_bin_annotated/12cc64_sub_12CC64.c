// fwstruct annotate: 12cc64_sub_12CC64.c
// sub_12CC64 @ 0x12cc64, size 86 bytes
// Doc: message_dispatch_nee [ipc]: Helper tail of message dispatch that stores a field
// message_dispatch_nee [ipc]: Helper tail of message dispatch that stores a field
_DWORD *__fastcall sub_12CC64(int a1, int (__fastcall *a2)(_DWORD *, int), int a3)
{
  _DWORD *v3; // r4
  _DWORD *v7; // r8
  int i; // r0
  int v9; // r3

  v3 = *(_DWORD **)a1;
  if ( !*(_DWORD *)a1 )
    return nullptr;
  v7 = nullptr;
  for ( i = a2(v3, a3); ; i = a2(v3, a3) )
  {
    v9 = *v3;
    if ( i )
      break;
    v7 = v3;
    if ( !v9 )
      return nullptr;
    v3 = (_DWORD *)*v3;
  }
  if ( v7 )
  {
    *v7 = v9;
    if ( *v3 )
    {
LABEL_8:
      *v3 = 0;
      return v3;
    }
  }
  else
  {
    *(_DWORD *)a1 = v9;
    if ( v9 )
      goto LABEL_8;
  }
  *(_DWORD *)(a1 + 4) = v7;
  return v3;
}

