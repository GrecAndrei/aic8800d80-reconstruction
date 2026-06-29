// sub_12B74C @ 0x12b74c, size 20 bytes
int  sub_12B74C(int a1)
{
  if ( (*(uint8_t *)(a1 + 3) & 5) != 0 )
    return *(uint32_t *)(*(uint32_t *)off_12B760 + 20);
  else
    return sub_12B338((unsigned __int16 *)a1);
}

