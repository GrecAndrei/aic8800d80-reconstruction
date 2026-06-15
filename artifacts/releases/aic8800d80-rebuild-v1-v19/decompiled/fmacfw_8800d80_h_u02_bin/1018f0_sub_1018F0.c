// sub_1018F0 @ 0x1018f0, size 40 bytes
_QWORD *__fastcall sub_1018F0(_QWORD *result, int a2)
{
  _QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (_QWORD *)sub_12E948(dword_10191C, dword_101920, a2);
    *v2 = *(_QWORD *)((char *)off_101918 + 36);
  }
  else
  {
    *result = *(_QWORD *)((char *)off_101918 + 36);
  }
  return result;
}

