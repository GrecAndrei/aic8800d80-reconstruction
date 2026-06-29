// fwstruct annotate: 127080_sub_127080.c
// sub_127080 @ 0x127080, size 44 bytes
int sub_127080()
{
  char v0; // r3
  int result; // r0

  if ( *((_BYTE *)off_1270AC + 89) )
  {
    v0 = *((_BYTE *)off_1270AC + 89) - 1;
    *((_BYTE *)off_1270AC + 89) = v0;
    if ( !v0 && *(_BYTE *)off_1270B0 == 1 )
    {
      *(_BYTE *)off_1270B0 = 0;
      sub_121AE4();
      return sub_127048();
    }
  }
  return result;
}

