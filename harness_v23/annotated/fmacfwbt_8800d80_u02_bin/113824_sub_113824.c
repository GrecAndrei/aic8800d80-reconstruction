// v23 annotated: sub_113824 @ 0x113824
// Original: 113824_sub_113824.c
// Primary struct: <unclustered>
//
// sub_113824 @ 0x113824, size 52 bytes
int sub_113824()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_113858;
  result = sub_12D468(dword_11385C);
  if ( *(_WORD *)(*(_DWORD *)v0 + 4) )
  {
    v2 = dword_113860;
    v3 = dword_11385C;
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

