// v23 annotated: sub_1428B8 @ 0x1428b8
// Original: 1428b8_sub_1428B8.c
// Primary struct: <unclustered>
//
// sub_1428B8 @ 0x1428b8, size 66 bytes
int __fastcall sub_1428B8(int a1, int a2, int a3, unsigned int a4)
{
  bool v4; // zf
  int v5; // r2
  int result; // r0

  v5 = 2 * a1;
  v4 = 2 * a1 == 0;
  result = a1 << 29;
  if ( v4 || (a4 = v5 & 0xFF000000, (v5 & 0xFF000000) == 0) || a4 == 0xFF000000 )
  {
    if ( (v5 & 0xFFFFFF) != 0 && a4 != 0xFF000000 )
      JUMPOUT(0x142734);
  }
  return result;
}

