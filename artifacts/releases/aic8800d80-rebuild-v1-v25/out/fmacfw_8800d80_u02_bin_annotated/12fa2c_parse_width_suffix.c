// fwstruct annotate: 12fa2c_parse_width_suffix.c
// parse_width_suffix @ 0x12fa2c, size 50 bytes
// Doc: parse_width_suffix [util]: Parse a printf-style width/length suffix character
// parse_width_suffix [util]: Parse a printf-style width/length suffix character
int __fastcall parse_width_suffix(int a1)
{
  int v2; // r0
  int v3; // r0
  int v5; // r3

  v2 = sub_143E40(a1);
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

