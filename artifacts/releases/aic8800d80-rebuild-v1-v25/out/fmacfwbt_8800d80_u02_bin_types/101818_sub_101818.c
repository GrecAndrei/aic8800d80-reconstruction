// sub_101818 @ 0x101818, size 40 bytes
QWORD * sub_101818(QWORD *result, int a2)
{
  QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (QWORD *)sub_12ECB0(dword_101844, dword_101848, a2);
    *v2 = *(QWORD *)((char *)off_101840 + 36);
  }
  else
  {
    *result = *(QWORD *)((char *)off_101840 + 36);
  }
  return result;
}

