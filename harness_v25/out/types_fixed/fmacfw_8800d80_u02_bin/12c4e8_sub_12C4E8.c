// sub_12C4E8 @ 0x12c4e8, size 64 bytes
// Doc: message_dispatch_n_482 [ipc]: Dispatch incoming IPC/host message (variant n_482)
// message_dispatch_n_482 [ipc]: Dispatch incoming IPC/host message (variant n_482)
int __fastcall sub_12C4E8(int result, int a2)
{
  int v2; // r4
  int v3; // r0

  if ( *((_BYTE *)message_dispatch_n_464 + 197) )
  {
    v2 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 48);
    v3 = sub_101D58(
           (*(_DWORD *)(v2 + 20) >> 11) & 7,
           *(_DWORD *)(v2 + 20) & 0x7F,
           (unsigned __int8 *)(*(_DWORD *)(result + 72) + 4));
    result = v3 | (v3 << 8);
    *(_DWORD *)(v2 + 36) = result;
  }
  else if ( **(__int16 **)msg_dispatch_handler < 0 )
  {
    return sub_12F46C(dword_12C534, message_dispatch_n_45c, 92);
  }
  return result;
}

