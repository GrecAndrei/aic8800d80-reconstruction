// fwstruct annotate: 11027c_sub_11027C.c
// sub_11027C @ 0x11027c, size 52 bytes
// Doc: log_free_dispatch_n286 [util]: Free log entry then dispatch to logging sink
// log_free_dispatch_n286 [util]: Free log entry then dispatch to logging sink
int sub_11027C()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = log_free_dispatch_n2a8;
  result = sub_12D240(log_free_dispatch_n2ac_02b4);
  if ( *(_WORD *)(*(_DWORD *)v0 + 4) )
  {
    v2 = dword_1102B8;
    v3 = log_free_dispatch_n2ac_02b4;
    v4 = 0;
    do
    {
      sub_10FB28(v2, 0x7Cu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 4) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

