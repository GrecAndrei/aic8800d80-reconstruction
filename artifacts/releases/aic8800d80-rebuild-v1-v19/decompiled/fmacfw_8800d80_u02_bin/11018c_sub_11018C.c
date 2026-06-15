// sub_11018C @ 0x11018c, size 72 bytes
int sub_11018C()
{
  void *v0; // r8
  int result; // r0
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = off_1101E0;
  result = sub_12D240(dword_1101D4);
  if ( *(_WORD *)(*(_DWORD *)v0 + 6) )
  {
    v2 = off_1101D8;
    v3 = dword_1101DC;
    v4 = dword_1101D4;
    v5 = 0;
    do
    {
      sub_10FB28(v3, 0x63Cu);
      result = sub_12D248(v4);
      v6 = *(unsigned __int16 *)(*(_DWORD *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

