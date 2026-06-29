// get_cached_1828f8 @ 0x1019ec, size 40 bytes
// Doc: get_cached_1828f8 [util]: Retrieve cached pointer/value from table
// get_cached_1828f8 [util]: Retrieve cached pointer/value from table
QWORD * get_cached_1828f8(QWORD *result, int a2)
{
  QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (QWORD *)msg_parse(dword_101A18, dword_101A1C);
    *v2 = *(QWORD *)((char *)off_101A14 + 36);
  }
  else
  {
    *result = *(QWORD *)((char *)off_101A14 + 36);
  }
  return result;
}

