// fwstruct annotate: 12c5c8_sub_12C5C8.c
// sub_12C5C8 @ 0x12c5c8, size 26 bytes
// Doc: message_dispatch_n_3c2 [ipc]: Dispatch message by computing count of leading zeros on index delta
// message_dispatch_n_3c2 [ipc]: Dispatch message by computing count of leading zeros on index delta
BOOL __fastcall sub_12C5C8(int a1, unsigned int a2)
{
  return *(unsigned __int16 *)(a1 + 4) == HIWORD(a2) && *(unsigned __int16 *)(a1 + 6) == (unsigned __int16)a2;
}

