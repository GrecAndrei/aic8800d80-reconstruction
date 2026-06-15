// v23 annotated: sub_114790 @ 0x114790
// Original: 114790_sub_114790.c
// Primary struct: <unclustered>
//
// sub_114790 @ 0x114790, size 42 bytes
int __fastcall sub_114790(unsigned __int8 *a1)
{
  int v1; // r3

  v1 = *a1;
  switch ( v1 )
  {
    case 1:
      return a1[3] + 4;
    case 2:
      return *(unsigned __int16 *)(a1 + 3) + 5;
    case 3:
      return a1[3] + 4;
    case 4:
      return a1[2] + 3;
  }
  return -1;
}

