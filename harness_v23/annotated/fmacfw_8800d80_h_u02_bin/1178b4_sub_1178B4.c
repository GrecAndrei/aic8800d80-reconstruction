// v23 annotated: sub_1178B4 @ 0x1178b4
// Original: 1178b4_sub_1178B4.c
// Primary struct: <unclustered>
//
// sub_1178B4 @ 0x1178b4, size 38 bytes
int sub_1178B4()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(_DWORD *)off_1178DC & 0xF00000;
  if ( v0 )
  {
    result = sub_11AB34((unsigned __int8)(11 - __clz(v0)));
    *(_DWORD *)off_1178E0 = v0;
  }
  else
  {
    *(_DWORD *)off_1178E0 = 0;
  }
  return result;
}

