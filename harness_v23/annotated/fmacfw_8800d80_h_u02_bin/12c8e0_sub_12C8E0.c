// v23 annotated: sub_12C8E0 @ 0x12c8e0
// Original: 12c8e0_sub_12C8E0.c
// Primary struct: <unclustered>
//
// sub_12C8E0 @ 0x12c8e0, size 22 bytes
int __fastcall sub_12C8E0(int a1, __int16 a2, __int16 a3, __int16 a4)
{
  *(_WORD *)(a1 - 8) = a2;
  *(_WORD *)(a1 - 6) = a3;
  *(_WORD *)(a1 - 4) = a4;
  return sub_12C84C(a1);
}

