// sub_114AB8 @ 0x114ab8, size 42 bytes
void sub_114AB8()
{
  int *v0; // r4

  v0 = (int *)off_114AE4;
  if ( !*(_DWORD *)off_114AE4 )
    *v0 = sub_114A78();
  if ( !*(_DWORD *)off_114AE8 )
    *(_DWORD *)off_114AE8 = *v0 + 67092480;
  *(_DWORD *)off_114AEC = 1;
}

