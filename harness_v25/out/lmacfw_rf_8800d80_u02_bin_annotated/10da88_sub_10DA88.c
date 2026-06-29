// fwstruct annotate: 10da88_sub_10DA88.c
// sub_10DA88 @ 0x10da88, size 74 bytes
int __fastcall sub_10DA88(int result)
{
  int v1; // r2

  v1 = 1 << result;
  if ( result <= 1 || (unsigned int)(result - 8) <= 1 )
  {
    result = 4 * result + 1079001088;
    *(_DWORD *)result = *(_DWORD *)result & 0xFFFFFFF0 | 1;
  }
  else if ( result <= 15 )
  {
    result = 4 * result + 1079001088;
    *(_DWORD *)result &= 0xFFFFFFF0;
  }
  *((_DWORD *)off_10DAD4 + 1) |= v1;
  return result;
}

