// fwstruct annotate: 12f8ec_sub_12F8EC.c
// sub_12F8EC @ 0x12f8ec, size 50 bytes
int __fastcall sub_12F8EC(int a1)
{
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = sub_143D00(a1);
  if ( v2 <= 2 )
    return 4;
  v3 = v2 + a1;
  if ( *(_BYTE *)(v3 - 2) != 46 )
    return 4;
  v5 = *(unsigned __int8 *)(v3 - 1);
  if ( v5 == 98 )
    return 1;
  if ( v5 == 104 )
    return 2;
  return -1;
}

