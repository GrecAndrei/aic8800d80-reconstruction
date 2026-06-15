// v23 annotated: rf_msg_handler_n22e @ 0x124f7c
// Original: 124f7c_rf_msg_handler_n22e.c
// Primary struct: <unclustered>
//
// rf_msg_handler_n22e @ 0x124f7c, size 30 bytes
// Doc: rf_msg_handler_n22e [rf]: Dispatch RF message to sub-handlers based on opcode 0x30/0x29/0x2a
// rf_msg_handler_n22e [rf]: Dispatch RF message to sub-handlers based on opcode 0x30/0x29/0x2a
int __fastcall rf_msg_handler_n22e(_DWORD *a1)
{
  _DWORD *v1; // r3

  v1 = *(_DWORD **)off_124F9C;
  if ( !*(_DWORD *)off_124F9C )
    return (int)v1;
  if ( v1 != a1 )
  {
    while ( 1 )
    {
      v1 = (_DWORD *)*v1;
      if ( !v1 )
        break;
      if ( a1 == v1 )
        return 1;
    }
    return (int)v1;
  }
  return 1;
}

