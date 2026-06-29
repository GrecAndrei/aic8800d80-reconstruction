// fwstruct annotate: 10db48_sub_10DB48.c
// sub_10DB48 @ 0x10db48, size 42 bytes
int __fastcall sub_10DB48(int result)
{
  _DWORD *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DB74;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

