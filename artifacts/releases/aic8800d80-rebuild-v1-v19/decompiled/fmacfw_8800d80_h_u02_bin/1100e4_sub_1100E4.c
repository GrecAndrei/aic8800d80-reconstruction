// sub_1100E4 @ 0x1100e4, size 72 bytes
int sub_1100E4()
{
  void *v0; // r8
  int result; // r0
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = off_110138;
  result = sub_12D100(dword_11012C);
  if ( *(_WORD *)(*(_DWORD *)v0 + 8) )
  {
    v2 = off_110130;
    v3 = dword_110134;
    v4 = dword_11012C;
    v5 = 0;
    do
    {
      sub_10F9E8(v3, 0x6B8u);
      result = sub_12D108(v4);
      v6 = *(unsigned __int16 *)(*(_DWORD *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

