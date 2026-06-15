// sub_12CC48 @ 0x12cc48, size 22 bytes
int __fastcall sub_12CC48(int a1, __int16 a2, __int16 a3, __int16 a4)
{
  *(_WORD *)(a1 - 8) = a2;
  *(_WORD *)(a1 - 6) = a3;
  *(_WORD *)(a1 - 4) = a4;
  return sub_12CBB4(a1);
}

