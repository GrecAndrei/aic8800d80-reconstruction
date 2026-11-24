// sub_1225C4 @ 0x1225c4, size 44 bytes
int __fastcall sub_1225C4(int a1, int a2)
{
  float v3; // r0
  int v4; // r0

  if ( a1 <= 1 )
  {
    v3 = COERCE_FLOAT(sub_10DD20());
    v4 = msg_parse(dword_1225F0, (int)v3);
    rf_level_dump(v4);
  }
  else
  {
    sub_122508(a1, a2);
  }
  return 0;
}

