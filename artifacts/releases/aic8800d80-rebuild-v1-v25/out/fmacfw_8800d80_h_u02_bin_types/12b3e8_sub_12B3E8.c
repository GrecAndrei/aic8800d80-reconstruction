// sub_12B3E8 @ 0x12b3e8, size 20 bytes
int  sub_12B3E8(int a1)
{
  if ( (*(uint8_t *)(a1 + 3) & 5) != 0 )
    return *(uint32_t *)(*(uint32_t *)off_12B3FC + 20);
  else
    return sub_12AFD4((unsigned __int16 *)a1);
}

