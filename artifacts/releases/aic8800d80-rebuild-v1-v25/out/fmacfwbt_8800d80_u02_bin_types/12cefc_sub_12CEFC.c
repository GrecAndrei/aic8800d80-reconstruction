// sub_12CEFC @ 0x12cefc, size 82 bytes
// Doc: message_dispatch_n38a [ipc]: Dispatch message slot 0x38a and tail-call handler
// message_dispatch_n38a [ipc]: Dispatch message slot 0x38a and tail-call handler
int  sub_12CEFC(int a1, int *a2, int a3)
{
  int v3; // r3
  int v5; // r2
  int v6; // r4
  int v7; // r6
  int v8; // r5
  int result; // r0

  if ( !a3 )
    return 0;
  v3 = a3 - 1;
  v5 = *a2;
  while ( 1 )
  {
    v6 = *(unsigned __int16 *)(v5 + 8 * v3);
    v7 = 8 * v3;
    v8 = v5 + 8 * v3--;
    if ( v6 == a1 )
      break;
    if ( v3 == -1 )
      return 0;
  }
  result = *(uint32_t *)(v8 + 4);
  if ( **(__int16 **)message_dispatch_n39c_cf50 < 0 && !result )
  {
    sub_12F694(ipc_msg_dispatch, dword_12CF54, 239);
    return *(uint32_t *)(v7 + *a2 + 4);
  }
  return result;
}

