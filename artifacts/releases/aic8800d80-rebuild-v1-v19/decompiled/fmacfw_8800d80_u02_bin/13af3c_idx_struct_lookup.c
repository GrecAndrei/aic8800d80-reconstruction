// idx_struct_lookup @ 0x13af3c, size 64 bytes
// Doc: idx_struct_lookup [util]: Looks up per-index struct entry (stride 0x2b8) and dereferences member
// idx_struct_lookup [util]: Looks up per-index struct entry (stride 0x2b8) and dereferences member
int *__fastcall idx_struct_lookup(int *result)
{
  int v1; // r5

  v1 = **(_DWORD **)(dword_13AF7C + 696 * *((unsigned __int8 *)result + 29) + 188);
  if ( v1 )
  {
    if ( *(_BYTE *)(v1 + 96) == 1 )
      return sub_116174(
               (int)result,
               v1 + 80,
               result[18] - *((unsigned __int8 *)result + 52) + 172,
               *((unsigned __int8 *)result + 52) + *((unsigned __int16 *)result + 24));
  }
  return result;
}

