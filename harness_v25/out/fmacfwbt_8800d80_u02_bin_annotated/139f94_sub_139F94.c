// fwstruct annotate: 139f94_sub_139F94.c
// sub_139F94 @ 0x139f94, size 96 bytes
// Doc: sub_1239F94 [util]: Parses a signed byte string with bitmask extraction (mask 0x78)
// sub_1239F94 [util]: Parses a signed byte string with bitmask extraction (mask 0x78)
int __fastcall sub_139F94(char *a1, char a2, int a3)
{
  char v3; // r3
  int result; // r0
  unsigned __int16 v6; // [sp+6h] [bp-2h] BYREF

  if ( *a1 >= 0 )
    v3 = 24;
  else
    v3 = 26;
  v6 = 0;
  if ( (a2 & 0x78) == 8 )
  {
    v3 += 8;
  }
  else if ( (a2 & 0x7C) == 4 )
  {
    v3 += 4;
  }
  result = sub_14380C(&v6, &a1[(unsigned __int8)(v3 + 6)], 2);
  if ( v6 == 36488 )
    return sub_12ECB0(dword_139FF4, 36488, a3);
  return result;
}

