// fwstruct annotate: 1100d4_sub_1100D4.c
// sub_1100D4 @ 0x1100d4, size 52 bytes
int sub_1100D4()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110108;
  result = sub_12D468(dword_11010C);
  if ( *(_WORD *)(*(_DWORD *)v0 + 4) )
  {
    v2 = dword_110110;
    v3 = dword_11010C;
    v4 = 0;
    do
    {
      sub_10F980(v2, 0x7Cu);
      result = sub_12D470(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 4) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

