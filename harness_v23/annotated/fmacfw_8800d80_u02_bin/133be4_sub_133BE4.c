// v23 annotated: sub_133BE4 @ 0x133be4
// Original: 133be4_sub_133BE4.c
// Primary struct: <unclustered>
//
// sub_133BE4 @ 0x133be4, size 66 bytes
int __fastcall sub_133BE4(int a1, unsigned __int8 *a2)
{
  int v2; // r4
  int result; // r0
  int v4; // r3
  int v5; // r4

  v2 = *a2;
  sub_12ECD0(256, dword_133C28);
  result = sub_12CE88(6u);
  if ( result )
    return 2;
  v4 = dword_133C2C + 1320 * v2;
  v5 = *(unsigned __int8 *)(v4 + 106);
  if ( !*(_BYTE *)(v4 + 106) )
  {
    result = *(unsigned __int8 *)(v4 + 108);
    if ( *(_BYTE *)(v4 + 108) )
    {
      sub_134D8C(v4, 1, *(unsigned __int8 *)(v4 + 106));
      return v5;
    }
  }
  return result;
}

