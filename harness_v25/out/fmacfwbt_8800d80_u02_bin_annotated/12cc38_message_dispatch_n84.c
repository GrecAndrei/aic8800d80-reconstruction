// fwstruct annotate: 12cc38_message_dispatch_n84.c
// message_dispatch_n84 @ 0x12cc38, size 16 bytes
// Doc: message_dispatch_n86_cc3a [ipc]: Dispatch IPC message storing two halfword params at negative offset
// message_dispatch_n86_cc3a [ipc]: Dispatch IPC message storing two halfword params at negative offset
int __fastcall message_dispatch_n84(__int16 a1, __int16 a2, __int16 a3)
{
  int v3; // r0

  v3 = rf_bus_setup_n3a8(a1, a2, a3, 0);
  return sub_12CBB4(v3);
}

