// fwstruct annotate: 114090_sub_114090.c
// sub_114090 @ 0x114090, size 72 bytes
int sub_114090()
{
  _DWORD *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_1140D8;
  v1 = off_1140DC;
  sub_12D468(*(_DWORD *)off_1140D8 + 564);
  result = sub_12D468(*v0 + 572);
  if ( *(_WORD *)(*(_DWORD *)v1 + 8) )
  {
    v3 = dword_1140E0;
    v4 = 0;
    do
    {
      sub_10F980(v3, 0x6B8u);
      result = sub_12D470(*v0 + 564);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v1 + 8) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

