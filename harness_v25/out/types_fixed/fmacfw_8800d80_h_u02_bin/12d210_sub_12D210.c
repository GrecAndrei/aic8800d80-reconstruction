// sub_12D210 @ 0x12d210, size 26 bytes
BOOL __fastcall sub_12D210(_DWORD **a1, _DWORD *a2)
{
  _DWORD *v2; // r3

  v2 = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( v2 )
  {
    v2 = (_DWORD *)*v2;
    if ( a2 == v2 )
      return 1;
  }
  return a2 == nullptr;
}

