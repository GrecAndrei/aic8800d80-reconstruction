// sub_114790 @ 0x114790, size 42 bytes
int __fastcall sub_114790(unsigned __int8 *a1)
{
  int v1; // r3

  v1 = *a1;
  switch ( v1 )
  {
    case 1:
      return *(_DWORD *)(a1 + 0xc) + 4;
    case 2:
      return *(unsigned __int16 *)(a1 + 3) + 5;
    case 3:
      return *(_DWORD *)(a1 + 0xc) + 4;
    case 4:
      return *(_DWORD *)(a1 + 0x8) + 3;
  }
  return -1;
}

