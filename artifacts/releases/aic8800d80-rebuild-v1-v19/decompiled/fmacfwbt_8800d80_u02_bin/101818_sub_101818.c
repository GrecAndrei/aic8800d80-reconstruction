// sub_101818 @ 0x101818, size 40 bytes
_QWORD *__fastcall sub_101818(_QWORD *result, int a2)
{
  _QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (_QWORD *)sub_12ECB0(dword_101844, dword_101848, a2);
    *v2 = *(_QWORD *)((char *)off_101840 + 36);
  }
  else
  {
    *result = *(_QWORD *)((char *)off_101840 + 36);
  }
  return result;
}

