// sub_114024 @ 0x114024, size 82 bytes
int  sub_114024(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5; // r2

  if ( a1 == *(uint32_t *)off_114078 )
  {
    v5 = 0;
  }
  else
  {
    if ( a1 != *((uint32_t *)off_114078 + 1) )
    {
      result = sub_12ECB0(dword_11407C, a1, *(uint32_t *)off_114078);
      goto LABEL_4;
    }
    v5 = 1;
  }
  result = sub_12ECB0(dword_11408C, dword_114088, *(uint32_t *)(dword_114084 + 4 * v5));
LABEL_4:
  if ( *((uint8_t *)off_114080 + 353) )
    return rf_level_apply_80c(1068, 1, 1000 * *((unsigned __int8 *)off_114080 + 354), a4);
  return result;
}

