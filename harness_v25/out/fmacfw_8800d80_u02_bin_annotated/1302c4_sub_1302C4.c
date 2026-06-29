// fwstruct annotate: 1302c4_sub_1302C4.c
// sub_1302C4 @ 0x1302c4, size 44 bytes
unsigned int sub_1302C4()
{
  unsigned __int8 *v0; // r4
  unsigned int result; // r0
  unsigned int v2; // r3
  unsigned __int8 v3; // r0

  v0 = (unsigned __int8 *)off_1302F0;
  result = *((unsigned __int8 *)off_1302F0 + 6);
  v2 = *((unsigned __int8 *)off_1302F0 + 5);
  if ( result != v2 )
  {
    if ( result >= v2 )
      v3 = result - 1;
    else
      v3 = result + 1;
    *((_BYTE *)off_1302F0 + 6) = v3;
    sub_10EF38(v3);
    return sub_12EA88(dword_1302F4, v0[5], v0[6]);
  }
  return result;
}

