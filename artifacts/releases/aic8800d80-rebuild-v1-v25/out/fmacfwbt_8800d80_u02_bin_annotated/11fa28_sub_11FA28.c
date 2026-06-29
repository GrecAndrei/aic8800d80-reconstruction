// fwstruct annotate: 11fa28_sub_11FA28.c
// sub_11FA28 @ 0x11fa28, size 44 bytes
void sub_11FA28()
{
  _BYTE *v0; // r3
  unsigned int v1; // r2

  v0 = *((_BYTE **)off_11FA54 + 2);
  if ( !v0[106] && v0[108] && v0[117] )
  {
    v1 = (unsigned __int8)v0[118];
    if ( v1 <= 8 )
      *(_DWORD *)off_11FA58 = ((1 << v1) - 1) << 8;
  }
}

