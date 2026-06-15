// v23 annotated: sub_113FD4 @ 0x113fd4
// Original: 113fd4_sub_113FD4.c
// Primary struct: <unclustered>
//
// sub_113FD4 @ 0x113fd4, size 64 bytes
int sub_113FD4()
{
  int v0; // r0
  _DWORD *v1; // r4
  int result; // r0

  v0 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_114014 + 2) + 16))(*((_DWORD *)off_114014 + 1));
  if ( !v0 )
    return sub_10DAE4(dword_114020);
  v1 = (_DWORD *)v0;
  result = sub_113210(*(_DWORD *)off_114018 + v0, *(_DWORD *)off_11401C);
  if ( result < 0 )
  {
    sub_10FEC8(v1);
    return sub_10DAE4(dword_114024);
  }
  return result;
}

