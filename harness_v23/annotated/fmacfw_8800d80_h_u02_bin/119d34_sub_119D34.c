// v23 annotated: sub_119D34 @ 0x119d34
// Original: 119d34_sub_119D34.c
// Primary struct: <unclustered>
//
// sub_119D34 @ 0x119d34, size 72 bytes
int sub_119D34()
{
  int v0; // r4
  int *v1; // r7
  int v2; // r6
  int v3; // r9
  int result; // r0
  int v5; // t1
  int v6; // r5
  int v7; // r8

  v0 = dword_119D7C;
  v1 = (int *)dword_119D80;
  v2 = dword_119D84;
  v3 = dword_119D7C + 48;
  do
  {
    result = sub_12D100(v0);
    v5 = *v1++;
    if ( v5 > 0 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        result = sub_12D108(v0);
        ++v7;
        v6 += 360;
      }
      while ( v7 < *(v1 - 1) );
    }
    v0 += 8;
    v2 += 4;
  }
  while ( v0 != v3 );
  return result;
}

