// sub_12D190 @ 0x12d190, size 22 bytes
_DWORD *__fastcall sub_12D190(int a1)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r2

  v1 = *(_DWORD **)a1;
  if ( *(_DWORD *)a1 )
  {
    v2 = *(_DWORD **)(a1 + 4);
    *(_DWORD *)a1 = *v1;
    if ( v2 == v1 )
      *(_DWORD *)(a1 + 4) = 0;
  }
  return v1;
}

