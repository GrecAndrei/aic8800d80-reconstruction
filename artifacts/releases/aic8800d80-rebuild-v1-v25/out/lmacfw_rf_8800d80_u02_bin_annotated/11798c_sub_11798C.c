// fwstruct annotate: 11798c_sub_11798C.c
// sub_11798C @ 0x11798c, size 52 bytes
unsigned int sub_11798C()
{
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((_DWORD *)off_1179C0 + 2);
  if ( v0 == *(_DWORD *)off_1179C4 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((_DWORD *)off_1179C0 + 1) - (v0 & 0x7FFFFFFFu) <= 0x9B )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(_DWORD *)off_1179C0 )
      v2 += 0x80000000;
    v3 = v2 | *(_DWORD *)off_1179C0;
    *((_DWORD *)off_1179C0 + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}

