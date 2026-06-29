// fwstruct annotate: 114114_sub_114114.c
// sub_114114 @ 0x114114, size 64 bytes
int sub_114114()
{
  int v0; // r0
  _DWORD *v1; // r4
  int result; // r0

  v0 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_114154 + 2) + 16))(*((_DWORD *)off_114154 + 1));
  if ( !v0 )
    return sub_10DC24(dword_114160);
  v1 = (_DWORD *)v0;
  result = sub_113350(*(_DWORD *)off_114158 + v0, *(_DWORD *)off_11415C);
  if ( result < 0 )
  {
    sub_110008(v1);
    return sub_10DC24(dword_114164);
  }
  return result;
}

