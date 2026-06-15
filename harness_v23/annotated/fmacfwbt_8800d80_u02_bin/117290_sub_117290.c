// v23 annotated: sub_117290 @ 0x117290
// Original: 117290_sub_117290.c
// Primary struct: <unclustered>
//
// sub_117290 @ 0x117290, size 30 bytes
int __fastcall sub_117290(int result)
{
  int v1; // r4

  if ( *(_WORD *)(result + 4) )
  {
    v1 = result;
    result = *(_DWORD *)(result + 72);
    if ( result )
    {
      if ( (*(_DWORD *)(v1 + 36) & 0x200000) == 0 )
      {
        result = log_free_dispatch_2((_DWORD *)result);
        *(_DWORD *)(v1 + 72) = 0;
      }
    }
  }
  return result;
}

