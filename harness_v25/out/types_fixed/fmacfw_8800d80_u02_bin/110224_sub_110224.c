// sub_110224 @ 0x110224, size 72 bytes
// Doc: log_free_dispatch_n23e [util]: Dispatch free log entries to consumers
// log_free_dispatch_n23e [util]: Dispatch free log entries to consumers
int sub_110224()
{
  void *v0; // r8
  int result; // r0
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_dispatch_n270_0278;
  result = sub_12D240(log_free_dispatch_n264);
  if ( *(_WORD *)(*(_DWORD *)v0 + 8) )
  {
    v2 = log_free_dispatch_n268_0270;
    v3 = log_free_dispatch_n26c;
    v4 = log_free_dispatch_n264;
    v5 = 0;
    do
    {
      sub_10FB28(v3, 0x6B8u);
      result = list_push_tail(v4);
      v6 = *(unsigned __int16 *)(*(_DWORD *)v0 + 8);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

