// sub_121EF4 @ 0x121ef4, size 36 bytes
int __fastcall sub_121EF4(int result, int a2)
{
  int v2; // r4

  v2 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(_BYTE *)(result + 128) = 0;
  }
  else
  {
    sub_12EB90(1024, dword_121F18);
    return sub_121ED4(v2);
  }
  return result;
}

