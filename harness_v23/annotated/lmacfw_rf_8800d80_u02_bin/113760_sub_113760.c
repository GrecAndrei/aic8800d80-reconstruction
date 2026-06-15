// v23 annotated: sub_113760 @ 0x113760
// Original: 113760_sub_113760.c
// Primary struct: <unclustered>
//
// sub_113760 @ 0x113760, size 72 bytes
int sub_113760()
{
  _DWORD *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_1137A8;
  v1 = off_1137AC;
  sub_11E71C(*(_DWORD *)off_1137A8 + 580);
  result = sub_11E71C(*v0 + 588);
  if ( *(_WORD *)(*(_DWORD *)v1 + 8) )
  {
    v3 = dword_1137B0;
    v4 = 0;
    do
    {
      log_pool_alloc2_a18(v3, 0x6B8u);
      result = list_push_tail(*v0 + 580);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v1 + 8) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

