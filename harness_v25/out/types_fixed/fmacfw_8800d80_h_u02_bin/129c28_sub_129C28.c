// sub_129C28 @ 0x129c28, size 32 bytes
int __fastcall sub_129C28(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r0
  unsigned __int8 v6; // r4

  v5 = sub_129B58(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  sub_124BFC(a1, v5);
  *(_BYTE *)(a1 + 16) = 1;
  return v6;
}

