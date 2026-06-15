// v23 annotated: sub_129F8C @ 0x129f8c
// Original: 129f8c_sub_129F8C.c
// Primary struct: <unclustered>
//
// sub_129F8C @ 0x129f8c, size 32 bytes
int __fastcall sub_129F8C(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r0
  unsigned __int8 v6; // r4

  v5 = sub_129EBC(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  sub_124F60(a1, v5);
  *(_BYTE *)(a1 + 16) = 1;
  return v6;
}

