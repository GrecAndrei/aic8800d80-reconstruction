// v23 annotated: sub_133AA4 @ 0x133aa4
// Original: 133aa4_sub_133AA4.c
// Primary struct: <unclustered>
//
// sub_133AA4 @ 0x133aa4, size 66 bytes
int __fastcall sub_133AA4(int a1, unsigned __int8 *a2)
{
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  sub_12EB90(256, dword_133AE8);
  result = sub_12CD48(6u);
  if ( result )
    return 2;
  v4 = dword_133AEC + 1320 * v2;
  v5 = *(unsigned __int8 *)(v4 + 106);
  if ( !*(_BYTE *)(v4 + 106) )
  {
    result = *(unsigned __int8 *)(v4 + 108);
    if ( *(_BYTE *)(v4 + 108) )
    {
      sub_134C4C(v4, 1, *(unsigned __int8 *)(v4 + 106));
      return v5;
    }
  }
  return result;
}

