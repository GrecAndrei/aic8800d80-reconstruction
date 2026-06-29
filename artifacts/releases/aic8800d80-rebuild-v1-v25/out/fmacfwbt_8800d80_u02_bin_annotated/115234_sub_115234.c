// fwstruct annotate: 115234_sub_115234.c
// sub_115234 @ 0x115234, size 42 bytes
void sub_115234()
{
  int *v0; // r4

  v0 = (int *)off_115260;
  if ( !*(_DWORD *)off_115260 )
    *v0 = sub_1151F4();
  if ( !*(_DWORD *)off_115264 )
    *(_DWORD *)off_115264 = *v0 + 67092480;
  *(_DWORD *)off_115268 = 1;
}

