// sub_10199C @ 0x10199c, size 40 bytes
QWORD * sub_10199C(QWORD *result, int a2)
{
  QWORD *v2; // r4

  v2 = result;
  if ( a2 )
  {
    result = (QWORD *)sub_12EA88(dword_1019C8, dword_1019CC, a2);
    *v2 = *(QWORD *)((char *)off_1019C4 + 36);
  }
  else
  {
    *result = *(QWORD *)((char *)off_1019C4 + 36);
  }
  return result;
}

