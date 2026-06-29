// fwstruct annotate: 117ac8_sub_117AC8.c
// sub_117AC8 @ 0x117ac8, size 48 bytes
// Doc: sub_1217AC8 [unknown]: Unknown internal function (lmacfw)
// sub_1217AC8 [unknown]: Unknown internal function (lmacfw)
int *__fastcall sub_117AC8(int a1)
{
  int v2; // r5
  int v3; // r0
  int *result; // r0

  v2 = a1 + 48;
  while ( *(_DWORD *)(a1 + 48) )
  {
    v3 = sub_11E7AC(v2);
    sub_116628(v3, 1);
  }
  result = sub_100200((int *)a1, 0, 0x98u);
  *(_BYTE *)(a1 + 32) = -1;
  return result;
}

