// fwstruct annotate: 101954_sub_101954.c
// sub_101954 @ 0x101954, size 36 bytes
int sub_101954()
{
  char *v0; // r2
  int v1; // r1

  v0 = (char *)off_101978;
  v1 = *(_DWORD *)off_101978;
  *(_DWORD *)off_10197C = *(_DWORD *)off_101978;
  if ( (v1 & 0x1000) == 0 )
    return sub_12EA88(dword_101980, v1, v0);
  *(_DWORD *)&v0[-8] &= ~0x1000u;
  return sub_12D104(16);
}

