// message_dispatch_n_4a3 @ 0x12c710, size 64 bytes
// Doc: message_dispatch_n_47e [ipc]: Extract message ID bits and dispatch to handler
// message_dispatch_n_47e [ipc]: Extract message ID bits and dispatch to handler
int __fastcall message_dispatch_n_4a3(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((_BYTE *)message_dispatch_n_464 + 197) )
  {
    v2 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 48);
    v3 = scan_chan_parse_n1bd4(
           (*(_DWORD *)(v2 + 20) >> 11) & 7,
           *(_DWORD *)(v2 + 20) & 0x7F,
           (unsigned __int8 *)(*(_DWORD *)(result + 72) + 4));
    result = v3 | (v3 << 8);
    *(_DWORD *)(v2 + 36) = result;
  }
  else if ( **(__int16 **)off_12C754 < 0 )
  {
    return sub_12F694(dword_12C75C, message_dispatch_n_45c, 92);
  }
  return result;
}

