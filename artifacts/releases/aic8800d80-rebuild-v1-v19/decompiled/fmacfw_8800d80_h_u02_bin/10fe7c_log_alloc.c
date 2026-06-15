// log_alloc @ 0x10fe7c, size 62 bytes
// Doc: log_alloc [util]: Allocate a log entry from the log pool if logging is enabled
// log_alloc [util]: Allocate a log entry from the log pool if logging is enabled
_DWORD *__fastcall log_alloc(char a1)
{
  _DWORD *v2; // r4

  if ( **(_BYTE **)off_10FEBC == 1 )
    v2 = (_DWORD *)sub_110340();
  else
    v2 = sub_10F9E8(dword_10FEC0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FDF4((unsigned int)v2) )
  {
    *((_BYTE *)v2 - 1) = a1;
    return v2;
  }
  sub_10DAE4(dword_10FEC4, v2);
  return v2;
}

