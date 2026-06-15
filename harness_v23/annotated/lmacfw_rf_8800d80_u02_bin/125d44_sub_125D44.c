// v23 annotated: sub_125D44 @ 0x125d44
// Original: 125d44_sub_125D44.c
// Primary struct: <unclustered>
//
// sub_125D44 @ 0x125d44, size 88 bytes
int __fastcall sub_125D44(int a1, int a2)
{
  unsigned __int16 v3; // r3
  unsigned __int8 *v4; // r0
  unsigned __int16 v5; // r4
  unsigned __int16 v6; // r5
  int v7; // r3
  int v9[2]; // [sp+4h] [bp-8h] BYREF

  v3 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
  v4 = *(unsigned __int8 **)(a2 + 8);
  v5 = v3;
  v6 = parse_int(v4, nullptr, 0x10u);
  sub_100200(v9, 0, 4u);
  LOWORD(v9[0]) = v5;
  v7 = *(_DWORD *)off_125D9C;
  HIWORD(v9[0]) = v6;
  if ( (v7 & 0x2000000) == 0 )
  {
    sub_11485C((int)v9);
    msg_parse(dword_125DA0, v5, v6);
  }
  return 0;
}

