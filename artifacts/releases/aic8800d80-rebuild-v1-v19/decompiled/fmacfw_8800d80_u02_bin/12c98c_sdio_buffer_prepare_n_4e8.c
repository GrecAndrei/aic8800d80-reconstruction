// sdio_buffer_prepare_n_4e8 @ 0x12c98c, size 106 bytes
// Doc: message_dispatch_n52 [ipc]: Dispatches short message after subtracting 0xc offset
// message_dispatch_n52 [ipc]: Dispatches short message after subtracting 0xc offset
int __fastcall sdio_buffer_prepare_n_4e8(int a1)
{
  __int16 v1; // r3
  unsigned __int16 *v4; // r0

  v1 = *(_WORD *)(a1 - 6);
  if ( **(__int16 **)off_12C9F8 >= 0 || (unsigned __int8)v1 <= 0xEu )
  {
    if ( (unsigned __int8)v1 <= 0xCu )
    {
      list_push_tail(dword_12C9FC);
      return irq_nesting_or_d104(0x4000000);
    }
  }
  else
  {
    sub_12F46C(dword_12CA04, message_dispatch_n74, 183);
  }
  msg_parse(message_dispatch_a08, *(unsigned __int16 *)(a1 - 8), *(unsigned __int16 *)(a1 - 4));
  v4 = (unsigned __int16 *)(a1 - 12);
  if ( *(_BYTE *)off_12CA0C )
    return sub_12CBC8(v4);
  else
    return j_state_check(v4);
}

