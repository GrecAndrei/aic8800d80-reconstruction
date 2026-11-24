// message_dispatch_n94_cc48 @ 0x12cc48, size 22 bytes
// Doc: message_dispatch_n96 [ipc]: Secondary message dispatch trampoline
// message_dispatch_n96 [ipc]: Secondary message dispatch trampoline
int __fastcall message_dispatch_n94_cc48(int a1, __int16 a2, __int16 a3, __int16 a4)
{
  *(_WORD *)(a1 - 8) = a2;
  *(_WORD *)(a1 - 6) = a3;
  *(_WORD *)(a1 - 4) = a4;
  return sub_12CBB4(a1);
}

