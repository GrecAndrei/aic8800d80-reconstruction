// crypto_hw_enable @ 0x102b00, size 96 bytes
// Doc: crypto_hw_enable [util]: Enable hardware crypto engine
// crypto_hw_enable [util]: Enable hardware crypto engine
int * crypto_hw_enable(int a1)
{
  int v1; // r4
  int v2; // r1
  bool v3; // zf
  int v4; // r2
  int v5; // r2
  int v6; // r3
  int *result; // r0
  int v8; // r2
  int v9; // r3

  v2 = (int)off_102B60;
  v3 = a1 == 0;
  if ( a1 )
    v4 = -2;
  else
    v4 = -17;
  v5 = v4 & *(uint32_t *)off_102B60;
  if ( !a1 )
    a1 = -33;
  *(uint32_t *)off_102B60 = v5;
  if ( v3 )
    v2 = 64;
  else
    a1 = -3;
  if ( v3 )
    v1 = 16;
  else
    v2 = 4;
  if ( !v3 )
    v1 = 1;
  LOBYTE(v6) = 50;
  do
    v6 = (unsigned __int8)(v6 - 1);
  while ( v6 );
  v9 = v5 & a1;
  result = (int *)off_102B60;
  v8 = v9 | v2;
  *(uint32_t *)off_102B60 = v9;
  LOBYTE(v9) = 50;
  *result = v8;
  do
    v9 = (unsigned __int8)(v9 - 1);
  while ( v9 );
  *(uint32_t *)off_102B60 = v8 | v1;
  return result;
}

