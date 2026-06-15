// v23 annotated: sub_12C92C @ 0x12c92c
// Original: 12c92c_sub_12C92C.c
// Primary struct: <unclustered>
//
// sub_12C92C @ 0x12c92c, size 82 bytes
// Doc: message_dispatch_n_56 [ipc]: Dispatch incoming message via fmac control path
// message_dispatch_n_56 [ipc]: Dispatch incoming message via fmac control path
int __fastcall sub_12C92C(__int16 a1, __int16 a2, __int16 a3, unsigned int a4)
{
  int v8; // r0
  int v9; // r4

  v8 = message_dispatch_n158(a4 + 12);
  v9 = v8;
  if ( **(__int16 **)off_12C980 < 0 && !v8 )
    sub_12F46C(dword_12C988, dword_12C984, 145);
  *(_WORD *)(v9 + 4) = a1;
  *(_WORD *)(v9 + 6) = a2;
  *(_WORD *)(v9 + 8) = a3;
  *(_WORD *)(v9 + 10) = a4;
  *(_DWORD *)v9 = 0;
  memset_thunk((int *)(v9 + 12), 0, a4);
  return v9 + 12;
}

