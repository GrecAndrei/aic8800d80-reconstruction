// sub_1327D0 @ 0x1327d0, size 22 bytes
int  sub_1327D0(char a1)
{
  int v1; // r0

  v1 = a1 & 3;
  if ( v1 == 1 )
    return 9;
  if ( v1 == 2 )
    return 11;
  return 7;
}

