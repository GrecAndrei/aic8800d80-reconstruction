// sub_11DEEC @ 0x11deec, size 86 bytes
_DWORD *__fastcall sub_11DEEC(int a1, int (__fastcall *a2)(_DWORD *, int), int a3)
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

