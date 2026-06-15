// sub_11DE50 @ 0x11de50, size 110 bytes
int __fastcall sub_11DE50(int a1)
{
  __int16 v1; // r5
  unsigned __int16 *v4; // r0

  v1 = *(_WORD *)(a1 - 6);
  if ( **(__int16 **)off_11DEC0 < 0 && (unsigned __int8)v1 > 5u )
    rf_cmd_send_n264(dword_11DED4, dword_11DED0, 183);
  if ( (v1 & 0xFC) != 0 )
  {
    msg_parse(dword_11DEC8, *(unsigned __int16 *)(a1 - 8));
    v4 = (unsigned __int16 *)(a1 - 12);
    if ( *(_BYTE *)off_11DECC )
      return sub_11E078(v4);
    else
      return rf_cmd_dispatch_n_4e8(v4);
  }
  else
  {
    list_push_tail(dword_11DEC4);
    return irq_nesting_or(0x4000000);
  }
}

