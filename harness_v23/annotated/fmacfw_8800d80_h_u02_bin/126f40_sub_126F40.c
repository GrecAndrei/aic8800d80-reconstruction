// v23 annotated: sub_126F40 @ 0x126f40
// Original: 126f40_sub_126F40.c
// Primary struct: <unclustered>
//
// sub_126F40 @ 0x126f40, size 44 bytes
int sub_126F40()
{
  char v0; // r3
  int result; // r0

  if ( *((_BYTE *)off_126F6C + 89) )
  {
    v0 = *((_BYTE *)off_126F6C + 89) - 1;
    *((_BYTE *)off_126F6C + 89) = v0;
    if ( !v0 && *(_BYTE *)off_126F70 == 1 )
    {
      *(_BYTE *)off_126F70 = 0;
      sub_1219A4();
      return sub_126F08();
    }
  }
  return result;
}

