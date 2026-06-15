// sub_1327E8 @ 0x1327e8, size 40 bytes
int __fastcall sub_1327E8(int a1)
{
  int v1; // r2
  int result; // r0
  int v4; // r3
  char v5; // r1

  v1 = 14;
  result = 7;
  do
  {
    v4 = (a1 >> v1) & 3;
    v5 = result - 1;
    v1 -= 2;
    if ( v4 != 3 )
      break;
    result = (unsigned __int8)(result - 1);
  }
  while ( v5 );
  return result;
}

