// sub_1019EC @ 0x1019ec, size 40 bytes
QWORD * sub_1019EC(QWORD *result, int a2)
{
  QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (QWORD *)sub_11F504(dword_101A18, dword_101A1C);
    *v2 = *(QWORD *)((char *)off_101A14 + 36);
  }
  else
  {
    *result = *(QWORD *)((char *)off_101A14 + 36);
  }
  return result;
}

