// sub_13C400 @ 0x13c400, size 34 bytes
int __fastcall sub_13C400(int a1)
{
  int v1; // r3
  int v2; // r1
  int result; // r0
  int v4; // t1

  if ( !*(_BYTE *)(a1 + 263) )
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

