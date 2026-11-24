// scan_ie_parse_ef8 @ 0x139ef8, size 96 bytes
// Doc: scan_ie_parse_ef8 [scan]: Parses scan info-element with signed byte and 0x78-masked option flags
// scan_ie_parse_ef8 [scan]: Parses scan info-element with signed byte and 0x78-masked option flags
int __fastcall scan_ie_parse_ef8(char *a1, char a2, int a3)
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
  result = sub_143770(&v6, &a1[(unsigned __int8)(v3 + 6)], 2);
  if ( v6 == 36488 )
    return msg_parse(dword_139F58, 36488, a3);
  return result;
}

