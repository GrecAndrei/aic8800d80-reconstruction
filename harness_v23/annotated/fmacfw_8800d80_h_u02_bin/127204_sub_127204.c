// v23 annotated: sub_127204 @ 0x127204
// Original: 127204_sub_127204.c
// Primary struct: <unclustered>
//
// sub_127204 @ 0x127204, size 48 bytes
int sub_127204()
{
  void *v0; // r2
  int v1; // r0
  int result; // r0

  v0 = off_127234;
  if ( (*((_BYTE *)off_127234 + 88) & 0x10) == 0 )
  {
    v1 = *((unsigned __int8 *)off_127234 + 90);
    *((_BYTE *)off_127234 + 88) |= 0x10u;
    if ( v1 )
      return sub_124BFC((int)v0 + 48, *((_DWORD *)off_127238 + 4) + 30000);
    else
      return sub_127160();
  }
  return result;
}

