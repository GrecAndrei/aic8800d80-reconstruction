// fwstruct annotate: 126da4_sub_126DA4.c
// sub_126DA4 @ 0x126da4, size 44 bytes
unsigned int sub_126DA4()
{
  unsigned __int8 *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  unsigned __int8 v3; // r0

  v0 = (unsigned __int8 *)off_126DD0;
  result = *((unsigned __int8 *)off_126DD0 + 6);
  v2 = *((unsigned __int8 *)off_126DD0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((_BYTE *)off_126DD0 + 6) = v3;
    sub_10F170(v3);
    return sub_11F504(dword_126DD4, v0[5], v0[6]);
  }
  return result;
}

