// v23 annotated: sub_12CCD4 @ 0x12ccd4
// Original: 12ccd4_sub_12CCD4.c
// Primary struct: <unclustered>
//
// sub_12CCD4 @ 0x12ccd4, size 82 bytes
// Doc: message_dispatch_tail_n390 [ipc]: Tail handler for message dispatch, returns status
// message_dispatch_tail_n390 [ipc]: Tail handler for message dispatch, returns status
int __fastcall sub_12CCD4(int a1, int *a2, int a3)
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
  result = *(_DWORD *)(v8 + 4);
  if ( **(__int16 **)message_dispatch_n39c < 0 && !result )
  {
    sub_12F46C(message_dispatch_n3a4, message_dispatch_n3a0, 239);
    return *(_DWORD *)(v7 + *a2 + 4);
  }
  return result;
}

