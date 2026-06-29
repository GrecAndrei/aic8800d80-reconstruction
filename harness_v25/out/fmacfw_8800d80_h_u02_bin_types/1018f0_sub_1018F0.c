// sub_1018F0 @ 0x1018f0, size 40 bytes
QWORD * sub_1018F0(QWORD *result, int a2)
{
  QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (QWORD *)sub_12E948(dword_10191C, dword_101920, a2);
    *v2 = *(QWORD *)((char *)off_101918 + 36);
  }
  else
  {
    *result = *(QWORD *)((char *)off_101918 + 36);
  }
  return result;
}

