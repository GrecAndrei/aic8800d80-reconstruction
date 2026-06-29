// fwstruct annotate: 10dafc_sub_10DAFC.c
// sub_10DAFC @ 0x10dafc, size 42 bytes
int __fastcall sub_10DAFC(int result)
{
  _DWORD *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DB28;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | v1[1];
    v1[1] = result;
  }
  return result;
}

