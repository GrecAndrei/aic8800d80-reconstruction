// fwstruct annotate: 11013c_sub_11013C.c
// sub_11013C @ 0x11013c, size 52 bytes
int sub_11013C()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110170;
  result = sub_12D100(dword_110174);
  if ( *(_WORD *)(*(_DWORD *)v0 + 4) )
  {
    v2 = dword_110178;
    v3 = dword_110174;
    v4 = 0;
    do
    {
      sub_10F9E8(v2, 0x7Cu);
      result = sub_12D108(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 4) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

