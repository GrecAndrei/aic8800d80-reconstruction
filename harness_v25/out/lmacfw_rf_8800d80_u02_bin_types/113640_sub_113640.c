// sub_113640 @ 0x113640, size 64 bytes
int sub_113640()
{
  int v0; // r0
  uint32_t *v1; // r4
  int result; // r0

  v0 = (*(int ( **)(uint32_t))(*((uint32_t *)off_113680 + 2) + 16))(*((uint32_t *)off_113680 + 1));
  if ( !v0 )
    return sub_10DA6C(dword_11368C);
  v1 = (uint32_t *)v0;
  result = sub_112C20(*(uint32_t *)off_113684 + v0, *(uint32_t *)off_113688);
  if ( result < 0 )
  {
    sub_10FEF8(v1);
    return sub_10DA6C(dword_113690);
  }
  return result;
}

