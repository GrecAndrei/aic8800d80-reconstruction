// sub_114088 @ 0x114088, size 82 bytes
int  sub_114088(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r2

  if ( a1 == *(uint32_t *)off_1140DC )
  {
    v5 = 0;
  }
  else
  {
    if ( a1 != *((uint32_t *)off_1140DC + 1) )
    {
      result = sub_12E948(dword_1140E0, a1, *(uint32_t *)off_1140DC);
      goto LABEL_4;
    }
    v5 = 1;
  }
  result = sub_12E948(dword_1140F0, dword_1140EC, *(uint32_t *)(dword_1140E8 + 4 * v5));
LABEL_4:
  if ( *((uint8_t *)off_1140E4 + 353) )
    return sub_12C4A4(1068, 1, 1000 * *((unsigned __int8 *)off_1140E4 + 354), a4);
  return result;
}

