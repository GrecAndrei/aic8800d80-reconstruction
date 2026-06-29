// fwstruct annotate: 129140_queue_check.c
// queue_check @ 0x129140, size 50 bytes
// Doc: queue_check [ke]: Check queue flag state
// queue_check [ke]: Check queue flag state
int queue_check()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r3

  v0 = off_129174;
  if ( !*(_BYTE *)off_129174 && !sub_12A690() )
    return 0;
  if ( v0[1] )
    return 0;
  v1 = *((_DWORD **)off_129178 + 2);
  if ( v1 )
  {
    while ( !v1[1] )
    {
      v1 = (_DWORD *)*v1;
      if ( !v1 )
        return 1;
    }
    return 0;
  }
  return 1;
}

