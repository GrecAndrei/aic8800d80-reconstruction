// v23 annotated: sub_1179F4 @ 0x1179f4
// Original: 1179f4_sub_1179F4.c
// Primary struct: <unclustered>
//
// sub_1179F4 @ 0x1179f4, size 38 bytes
// Doc: sub_12179F4 [patch]: Checks upper-nibble mask and dispatches handler
// sub_12179F4 [patch]: Checks upper-nibble mask and dispatches handler
int sub_1179F4()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(_DWORD *)off_117A1C & 0xF00000;
  if ( v0 )
  {
    result = sub_11AC74((unsigned __int8)(11 - __clz(v0)));
    *(_DWORD *)off_117A20 = v0;
  }
  else
  {
    *(_DWORD *)off_117A20 = 0;
  }
  return result;
}

