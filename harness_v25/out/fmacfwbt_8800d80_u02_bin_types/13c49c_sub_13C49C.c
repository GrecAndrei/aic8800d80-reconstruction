// sub_13C49C @ 0x13c49c, size 34 bytes
int  sub_13C49C(int a1)
{
  int v1; // r3
  int v2; // r1
  int result; // r0
  int v4; // t1

  if ( !*(uint8_t *)(a1 + 263) )
    return *(unsigned __int8 *)(a1 + 263);
  v1 = a1 + 5;
  v2 = *(unsigned __int8 *)(a1 + 263) + a1 + 5;
  result = 0;
  do
  {
    v4 = *(unsigned __int8 *)++v1;
    if ( v4 == 2 )
      result = (char)(result + 1);
  }
  while ( v1 != v2 );
  return result;
}

