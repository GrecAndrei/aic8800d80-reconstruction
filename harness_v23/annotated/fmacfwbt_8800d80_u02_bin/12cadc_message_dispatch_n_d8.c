// v23 annotated: message_dispatch_n_d8 @ 0x12cadc
// Original: 12cadc_message_dispatch_n_d8.c
// Primary struct: <unclustered>
//
// message_dispatch_n_d8 @ 0x12cadc, size 32 bytes
// Doc: message_dispatch_n_d8 [ipc]: Dispatches incoming message based on header field to handlers
// message_dispatch_n_d8 [ipc]: Dispatches incoming message based on header field to handlers
int __fastcall message_dispatch_n_d8(int a1, int a2)
{
  int **v2; // r3

  v2 = *((int ***)rf_level_apply_n21a + 5);
  if ( !v2 )
    return (int)v2;
  while ( *((unsigned __int16 *)v2 + 2) != a1 || *((unsigned __int16 *)v2 + 3) != a2 )
  {
    v2 = (int **)*v2;
    if ( !v2 )
      return (int)v2;
  }
  return 1;
}

