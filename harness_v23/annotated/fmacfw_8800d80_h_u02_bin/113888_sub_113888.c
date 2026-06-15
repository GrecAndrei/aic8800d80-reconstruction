// v23 annotated: sub_113888 @ 0x113888
// Original: 113888_sub_113888.c
// Primary struct: <unclustered>
//
// sub_113888 @ 0x113888, size 52 bytes
int sub_113888()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_1138BC;
  result = sub_12D100(dword_1138C0);
  if ( *(_WORD *)(*(_DWORD *)v0 + 4) )
  {
    v2 = dword_1138C4;
    v3 = dword_1138C0;
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

