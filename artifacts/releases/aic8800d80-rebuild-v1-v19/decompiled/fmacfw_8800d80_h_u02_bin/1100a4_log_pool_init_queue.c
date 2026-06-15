// log_pool_init_queue @ 0x1100a4, size 52 bytes
// Doc: log_pool_init_queue [util]: Initialize the log message pool queue and metadata
// log_pool_init_queue [util]: Initialize the log message pool queue and metadata
int log_pool_init_queue()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_1100D8;
  result = sub_12D100(dword_1100DC);
  if ( *(_WORD *)(*(_DWORD *)v0 + 2) )
  {
    v2 = dword_1100E0;
    v3 = dword_1100DC;
    v4 = 0;
    do
    {
      sub_10F9E8(v2, 0xCu);
      result = sub_12D108(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 2) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

