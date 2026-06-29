// fwstruct annotate: 12c6f0_message_dispatch_n_4c4.c
// message_dispatch_n_4c4 @ 0x12c6f0, size 26 bytes
// Doc: message_dispatch_n_4c4 [ipc]: Dispatch IPC message handling 0x7f opcode sentinel
// message_dispatch_n_4c4 [ipc]: Dispatch IPC message handling 0x7f opcode sentinel
int __fastcall message_dispatch_n_4c4(int a1, _BYTE *a2, _BYTE *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(_DWORD *)message_dispatch_n_4a7;
  else
    result = (unsigned __int8)v3;
  if ( v3 == 127 )
    result = (unsigned __int8)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}

