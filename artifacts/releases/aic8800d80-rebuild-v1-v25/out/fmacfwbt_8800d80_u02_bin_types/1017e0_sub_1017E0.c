// sub_1017E0 @ 0x1017e0, size 24 bytes
int  sub_1017E0(int result, int a2, int a3)
{
  if ( (*(uint32_t *)off_1017F8 & 8) != 0 )
  {
    result = mmio_reg_read_pair(result, a2, a3, *(uint32_t *)off_1017F8 << 28);
    *(uint32_t *)off_1017FC = 8;
  }
  return result;
}

