// sub_11469C @ 0x11469c, size 44 bytes
int  sub_11469C(uint32_t *a1)
{
  int result; // r0
  int v2; // r2

  if ( *(uint32_t *)off_1146C8 )
    return list_push_tail(off_1146C8);
  result = sub_114E60(a1 + 1, *a1);
  if ( result )
  {
    sub_12ECB0(dword_1146CC, result, v2);
    return list_push_tail(off_1146C8);
  }
  return result;
}

