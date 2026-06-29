// fwstruct annotate: 10199c_sub_10199C.c
// sub_10199C @ 0x10199c, size 40 bytes
_QWORD *__fastcall sub_10199C(_QWORD *result, int a2)
{
  _QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (_QWORD *)sub_12EA88(dword_1019C8, dword_1019CC, a2);
    *v2 = *(_QWORD *)((char *)off_1019C4 + 36);
  }
  else
  {
    *result = *(_QWORD *)((char *)off_1019C4 + 36);
  }
  return result;
}

