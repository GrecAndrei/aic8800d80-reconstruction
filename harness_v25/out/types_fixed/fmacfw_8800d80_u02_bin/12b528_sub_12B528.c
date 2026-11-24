// sub_12B528 @ 0x12b528, size 20 bytes
int __fastcall sub_12B528(int a1)
{
  if ( (*(_BYTE *)(a1 + 3) & 5) != 0 )
    return *(_DWORD *)(*(_DWORD *)off_12B53C + 20);
  else
    return mac_check_msg_id_0x96c((unsigned __int16 *)a1);
}

