// process_event_loop @ 0x119e74, size 72 bytes
int process_event_loop()
{
  int v0; // r4
  int *v1; // r7
  int v2; // r6
  int v3; // r9
  int result; // r0
  int v5; // t1
  int v6; // r5
  int v7; // r8

  v0 = dword_119EBC;
  v1 = (int *)dword_119EC0;
  v2 = dword_119EC4;
  v3 = dword_119EBC + 48;
  do
  {
    result = zero_8_bytes(v0);
    v5 = *v1++;
    if ( v5 > 0 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        result = cmd_handler_a(v0);
        ++v7;
        v6 += 360;
      }
      while ( v7 < *(v1 - 1) );
    }
    v0 += 8;
    v2 += 4;
  }
  while ( v0 != v3 );
  return result;
}

