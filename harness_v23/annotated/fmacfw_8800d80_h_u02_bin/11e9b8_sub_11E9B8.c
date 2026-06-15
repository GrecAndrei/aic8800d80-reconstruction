// v23 annotated: sub_11E9B8 @ 0x11e9b8
// Original: 11e9b8_sub_11E9B8.c
// Primary struct: <unclustered>
//
// sub_11E9B8 @ 0x11e9b8, size 52 bytes
unsigned int sub_11E9B8()
{
  int v0; // r3
  unsigned int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  v0 = *((_DWORD *)off_11E9EC + 2);
  if ( v0 == *(_DWORD *)off_11E9F0 )
    return 0;
  result = v0 & 0x7FFFFFFF;
  if ( *((_DWORD *)off_11E9EC + 1) - (v0 & 0x7FFFFFFFu) <= 0x9F )
  {
    v2 = v0 & 0x80000000;
    if ( result > *(_DWORD *)off_11E9EC )
      v2 += 0x80000000;
    v3 = v2 | *(_DWORD *)off_11E9EC;
    *((_DWORD *)off_11E9EC + 2) = v3;
    return v3 & 0x7FFFFFFF;
  }
  return result;
}

