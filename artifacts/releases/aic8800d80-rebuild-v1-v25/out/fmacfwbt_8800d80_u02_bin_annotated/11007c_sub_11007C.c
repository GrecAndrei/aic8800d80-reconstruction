// fwstruct annotate: 11007c_sub_11007C.c
// sub_11007C @ 0x11007c, size 72 bytes
// Doc: log_free_dispatch_n234 [util]: Dispatch and free log buffer entries
// log_free_dispatch_n234 [util]: Dispatch and free log buffer entries
int sub_11007C()
{
  void *v0; // r8
  int result; // r0
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_dispatch_n270;
  result = bt_xtal_init_check(log_free_dispatch_n264);
  if ( *(_WORD *)(*(_DWORD *)v0 + 8) )
  {
    v2 = log_free_dispatch_n268;
    v3 = log_free_dispatch_4;
    v4 = log_free_dispatch_n264;
    v5 = 0;
    do
    {
      log_pool_alloc2(v3, 0x6B8u);
      result = list_push_tail(v4);
      v6 = *(unsigned __int16 *)(*(_DWORD *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

