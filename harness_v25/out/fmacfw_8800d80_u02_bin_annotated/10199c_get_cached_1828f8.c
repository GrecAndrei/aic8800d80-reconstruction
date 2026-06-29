// fwstruct annotate: 10199c_get_cached_1828f8.c
// get_cached_1828f8 @ 0x10199c, size 40 bytes
// Doc: get_cached_1828f8 [util]: Retrieve cached pointer/value from 0x1828f8
// get_cached_1828f8 [util]: Retrieve cached pointer/value from 0x1828f8
_QWORD *__fastcall get_cached_1828f8(_QWORD *result, int a2)
{
  _QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (_QWORD *)msg_parse(dword_1019C8, dword_1019CC, a2);
    *v2 = *(_QWORD *)((char *)off_1019C4 + 36);
  }
  else
  {
    *result = *(_QWORD *)((char *)off_1019C4 + 36);
  }
  return result;
}

