// fwstruct annotate: 10ffbc_log_alloc.c
// log_alloc @ 0x10ffbc, size 62 bytes
// Doc: log_alloc [util]: Logs allocation event based on debug flag
// log_alloc [util]: Logs allocation event based on debug flag
_DWORD *__fastcall log_alloc(char a1)
{
  _DWORD *v2; // r4

  if ( **(_BYTE **)off_10FFFC == 1 )
    v2 = (_DWORD *)sub_110480();
  else
    v2 = sub_10FB28(log_free_pool_dispatch2_n320, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FF34((unsigned int)v2) )
  {
    *((_BYTE *)v2 - 1) = a1;
    return v2;
  }
  sub_10DC24(rf_fault_dump_n3cc, v2);
  return v2;
}

