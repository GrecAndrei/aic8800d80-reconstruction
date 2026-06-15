// v23 annotated: sub_10FFE4 @ 0x10ffe4
// Original: 10ffe4_sub_10FFE4.c
// Primary struct: <unclustered>
//
// sub_10FFE4 @ 0x10ffe4, size 72 bytes
// Doc: log_free_dispatch_n1bc [util]: Frees log entry and dispatches next log buffer
// log_free_dispatch_n1bc [util]: Frees log entry and dispatches next log buffer
int sub_10FFE4()
{
  void *v0; // r8
  int result; // r0
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_dispatch_n1d8;
  result = bt_xtal_init_check(log_free_dispatch_n1cc);
  if ( *(_WORD *)(*(_DWORD *)v0 + 6) )
  {
    v2 = patch_apply_n_32;
    v3 = log_free_dispatch_n1d4;
    v4 = log_free_dispatch_n1cc;
    v5 = 0;
    do
    {
      log_pool_alloc2(v3, 0x63Cu);
      result = list_push_tail(v4);
      v6 = *(unsigned __int16 *)(*(_DWORD *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

