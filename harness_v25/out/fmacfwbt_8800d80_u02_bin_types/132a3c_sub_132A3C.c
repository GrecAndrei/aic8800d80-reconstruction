// sub_132A3C @ 0x132a3c, size 64 bytes
int  sub_132A3C(int a1, int a2)
{
  int v2; // r4
  int v3; // r7
  unsigned int v4; // r3
  int v5; // r2
  unsigned int v6; // r5
  unsigned int v7; // r3

  v2 = 0;
  v3 = 0;
  do
  {
    v4 = (a1 >> v2) & 3;
    v5 = v3 & ~(3 << v2);
    v6 = (a2 >> v2) & 3;
    if ( v4 == 3 || v6 == 3 )
      break;
    if ( v4 >= v6 )
      v4 = (a2 >> v2) & 3;
    v7 = v4 << v2;
    v2 += 2;
    v3 = (unsigned __int16)(v5 | v7);
  }
  while ( v2 != 16 );
  return v3;
}

