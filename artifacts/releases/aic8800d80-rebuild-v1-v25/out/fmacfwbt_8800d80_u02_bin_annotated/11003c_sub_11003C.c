// fwstruct annotate: 11003c_sub_11003C.c
// sub_11003C @ 0x11003c, size 52 bytes
int sub_11003C()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110070;
  result = sub_12D468(dword_110074);
  if ( *(_WORD *)(*(_DWORD *)v0 + 2) )
  {
    v2 = dword_110078;
    v3 = dword_110074;
    v4 = 0;
    do
    {
      sub_10F980(v2, 0xCu);
      result = sub_12D470(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 2) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

