// sub_117DC0 @ 0x117dc0, size 44 bytes
void sub_117DC0()
{
  _BYTE *v0; // r3
  unsigned int v1; // r2

  v0 = *((_BYTE **)off_117DEC + 2);
  if ( !*(_DWORD *)(v0 + 0x178) && *(_DWORD *)(v0 + 0x180) && *(_DWORD *)(v0 + 0x19c) )
  {
    v1 = (unsigned __int8)*(_DWORD *)(v0 + 0x1a0);
    if ( v1 <= 8 )
      *(_DWORD *)off_117DF0 = ((1 << v1) - 1) << 8;
  }
}

