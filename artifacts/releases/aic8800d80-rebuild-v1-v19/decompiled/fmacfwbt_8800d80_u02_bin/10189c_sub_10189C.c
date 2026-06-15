// sub_10189C @ 0x10189c, size 20 bytes
unsigned int __fastcall sub_10189C(int a1)
{
  unsigned int result; // r0

  result = (8 * a1) & 8 | *(_DWORD *)off_1018B0 & 0xFFFFFFF7;
  *(_DWORD *)off_1018B0 = result;
  return result;
}

