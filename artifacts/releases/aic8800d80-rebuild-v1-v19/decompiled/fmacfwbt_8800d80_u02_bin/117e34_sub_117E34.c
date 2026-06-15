// sub_117E34 @ 0x117e34, size 38 bytes
int sub_117E34()
{
  unsigned int v0; // r4
  int result; // r0

  v0 = *(_DWORD *)off_117E5C & 0xF00000;
  if ( v0 )
  {
    result = sub_11B0B4((unsigned __int8)(11 - __clz(v0)));
    *(_DWORD *)off_117E60 = v0;
  }
  else
  {
    *(_DWORD *)off_117E60 = 0;
  }
  return result;
}

