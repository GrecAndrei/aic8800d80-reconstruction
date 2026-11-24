// log_pool_init_queue @ 0x1101e4, size 52 bytes
// Doc: log_free_dispatch_n1f4 [util]: Free log entry and dispatch next pending log
// log_free_dispatch_n1f4 [util]: Free log entry and dispatch next pending log
int log_pool_init_queue()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = log_free_dispatch_n210_0218;
  result = sub_12D240(log_free_dispatch_n215);
  if ( *(_WORD *)(*(_DWORD *)v0 + 2) )
  {
    v2 = log_free_dispatch_n218_0;
    v3 = log_free_dispatch_n215;
    v4 = 0;
    do
    {
      sub_10FB28(v2, 0xCu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 2) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

