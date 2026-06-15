// v23 annotated: sub_13208C @ 0x13208c
// Original: 13208c_sub_13208C.c
// Primary struct: <unclustered>
//
// sub_13208C @ 0x13208c, size 62 bytes
int __fastcall sub_13208C(int a1, unsigned __int8 *a2)
{
  int v2; // r6
  int v4; // r0

  v2 = dword_1320CC;
  timestamp_remove(696 * *a2 + 672 + dword_1320CC);
  v4 = *a2;
  if ( *(_BYTE *)(v2 + 696 * v4 + 37) )
    sub_132324(v4);
  else
    sub_12CA10(5130, 13, 5);
  return 0;
}

