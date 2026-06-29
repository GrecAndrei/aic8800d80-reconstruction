// sub_126064 @ 0x126064, size 152 bytes
int  sub_126064(int a1, unsigned __int8 **a2)
{
  unsigned __int16 v3; // r6
  unsigned __int16 v4; // r7
  unsigned __int16 v5; // r8
  unsigned __int16 v6; // r3
  unsigned __int8 *v7; // r0
  unsigned __int16 v8; // r4
  unsigned __int8 v9; // r5
  int v10; // r3
  int v12; // [sp+Ch] [bp-Ch] BYREF
  unsigned __int16 v13; // [sp+10h] [bp-8h]
  unsigned __int16 v14; // [sp+12h] [bp-6h]
  unsigned __int8 v15; // [sp+14h] [bp-4h]

  v3 = parse_int(a2[1], nullptr, 0x10u);
  v4 = parse_int(a2[2], nullptr, 0x10u);
  v5 = parse_int(a2[3], nullptr, 0x10u);
  v6 = parse_int(a2[4], nullptr, 0x10u);
  v7 = a2[5];
  v8 = v6;
  v9 = parse_int(v7, nullptr, 0x10u);
  sub_100200(&v12, 0, 0xAu);
  v15 = v9;
  v10 = *(uint32_t *)off_1260FC;
  LOWORD(v12) = v3;
  HIWORD(v12) = v4;
  v13 = v5;
  v14 = v8;
  if ( (v10 & 0x2000000) == 0 )
  {
    sub_11488C((int)&v12);
    msg_parse(dword_126100, v3, v4, v5, v8, v9);
  }
  return 0;
}

