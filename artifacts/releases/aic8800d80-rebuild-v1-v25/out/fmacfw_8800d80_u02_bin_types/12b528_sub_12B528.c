// sub_12B528 @ 0x12b528, size 20 bytes
int  sub_12B528(int a1)
{
  if ( (*(uint8_t *)(a1 + 3) & 5) != 0 )
    return *(uint32_t *)(*(uint32_t *)off_12B53C + 20);
  else
    return mac_check_msg_id_0x96c((unsigned __int16 *)a1);
}

