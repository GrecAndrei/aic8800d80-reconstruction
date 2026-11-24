// sub_11FA28 @ 0x11fa28, size 44 bytes
void sub_11FA28()
{
  _BYTE *v0; // r3
  unsigned int v1; // r2

  v0 = *((_BYTE **)off_11FA54 + 2);
  if ( !*(_DWORD *)(v0 + 0x1a8) && *(_DWORD *)(v0 + 0x1b0) && *(_DWORD *)(v0 + 0x1d4) )
  {
    v1 = (unsigned __int8)*(_DWORD *)(v0 + 0x1d8);
    if ( v1 <= 8 )
      *(_DWORD *)off_11FA58 = ((1 << v1) - 1) << 8;
  }
}

