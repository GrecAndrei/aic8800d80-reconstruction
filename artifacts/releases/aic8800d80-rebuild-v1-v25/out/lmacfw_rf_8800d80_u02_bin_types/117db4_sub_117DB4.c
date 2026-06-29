// sub_117DB4 @ 0x117db4, size 10 bytes
int  sub_117DB4(int result)
{
  if ( *(uint32_t *)(result + 72) )
    return rf_bus_reset2_c158();
  return result;
}

