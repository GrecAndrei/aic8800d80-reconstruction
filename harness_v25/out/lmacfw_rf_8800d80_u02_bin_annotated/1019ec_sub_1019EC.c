// fwstruct annotate: 1019ec_sub_1019EC.c
// sub_1019EC @ 0x1019ec, size 40 bytes
_QWORD *__fastcall sub_1019EC(_QWORD *result, int a2)
{
  _QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (_QWORD *)sub_11F504(dword_101A18, dword_101A1C);
    *v2 = *(_QWORD *)((char *)off_101A14 + 36);
  }
  else
  {
    *result = *(_QWORD *)((char *)off_101A14 + 36);
  }
  return result;
}

