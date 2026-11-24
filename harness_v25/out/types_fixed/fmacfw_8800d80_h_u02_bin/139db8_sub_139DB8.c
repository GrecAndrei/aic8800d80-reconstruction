// sub_139DB8 @ 0x139db8, size 96 bytes
int __fastcall sub_139DB8(char *a1, char a2, int a3)
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
  result = sub_143630(&v6, &a1[(unsigned __int8)(v3 + 6)], 2);
  if ( v6 == 36488 )
    return sub_12E948(dword_139E18, 36488, a3);
  return result;
}

