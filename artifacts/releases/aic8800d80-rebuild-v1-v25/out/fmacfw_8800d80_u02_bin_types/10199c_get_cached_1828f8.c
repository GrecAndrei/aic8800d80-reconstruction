// get_cached_1828f8 @ 0x10199c, size 40 bytes
// Doc: get_cached_1828f8 [util]: Retrieve cached pointer/value from 0x1828f8
// get_cached_1828f8 [util]: Retrieve cached pointer/value from 0x1828f8
QWORD * get_cached_1828f8(QWORD *result, int a2)
{
  QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (QWORD *)msg_parse(dword_1019C8, dword_1019CC, a2);
    *v2 = *(QWORD *)((char *)off_1019C4 + 36);
  }
  else
  {
    *result = *(QWORD *)((char *)off_1019C4 + 36);
  }
  return result;
}

