// sub_11CD50 @ 0x11cd50, size 20 bytes
int  sub_11CD50(int a1)
{
  if ( (*(uint8_t *)(a1 + 3) & 5) != 0 )
    return *(uint32_t *)(*(uint32_t *)off_11CD64 + 20);
  else
    return fw_signature_check((unsigned __int16 *)a1);
}

