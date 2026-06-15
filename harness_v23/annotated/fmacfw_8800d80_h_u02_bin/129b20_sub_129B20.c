// v23 annotated: sub_129B20 @ 0x129b20
// Original: 129b20_sub_129B20.c
// Primary struct: <unclustered>
//
// sub_129B20 @ 0x129b20, size 56 bytes
unsigned __int8 *__fastcall sub_129B20(unsigned __int8 *result)
{
  int v1; // r3
  unsigned __int8 *v2; // r4
  int v3; // r1

  v1 = result[114];
  v2 = result;
  if ( v1 == 1 )
  {
    result[114] = 0;
    return sub_1296C4(result);
  }
  else if ( v1 == 2 )
  {
    v3 = *((_DWORD *)result + 29);
    result[114] = 1;
    sub_124BFC((int)(result + 96), v3);
    return sub_1296C4(v2);
  }
  return result;
}

