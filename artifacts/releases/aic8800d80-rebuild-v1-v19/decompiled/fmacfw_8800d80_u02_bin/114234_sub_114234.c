// sub_114234 @ 0x114234, size 72 bytes
// Doc: rf_fault_dump_n_500 [rf]: Dump RF fault information
// rf_fault_dump_n_500 [rf]: Dump RF fault information
int sub_114234()
{
  _DWORD *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_11427C;
  v1 = off_114280;
  sub_12D240(*(_DWORD *)off_11427C + 628);
  result = sub_12D240(*v0 + 636);
  if ( *(_WORD *)(*(_DWORD *)v1 + 8) )
  {
    v3 = dword_114284;
    v4 = 0;
    do
    {
      sub_10FB28(v3, 0x6B8u);
      result = list_push_tail(*v0 + 628);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v1 + 8) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

