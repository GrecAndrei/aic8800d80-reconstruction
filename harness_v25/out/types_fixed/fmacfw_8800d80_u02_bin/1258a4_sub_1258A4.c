// sub_1258A4 @ 0x1258a4, size 22 bytes
int __fastcall sub_1258A4(unsigned __int16 *a1)
{
  if ( *((_DWORD *)off_1258BC + 1) )
    return list_push_tail((char *)off_1258BC + 12);
  else
    return rf_parse_descriptor_n3f8(a1);
}

