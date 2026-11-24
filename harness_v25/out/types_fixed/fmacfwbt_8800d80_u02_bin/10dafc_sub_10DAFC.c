// sub_10DAFC @ 0x10dafc, size 42 bytes
int __fastcall sub_10DAFC(int result)
{
  _DWORD *v1; // r1

  if ( result <= 7 )
  {
    v1 = off_10DB28;
    dword_40504080[result] &= 0xFFFFFFF0;
    result = (1 << result) | *(_DWORD *)(v1 + 0x4);
    *(_DWORD *)(v1 + 0x4) = result;
  }
  return result;
}

