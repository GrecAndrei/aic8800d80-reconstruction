// v23 annotated: message_dispatch_408 @ 0x12c584
// Original: 12c584_message_dispatch_408.c
// Primary struct: ke_dispatch_ctx (cluster 17, 4 funcs)
// Fields: msg_id=0x4, task_id=0x6, param=0x8, status=0x6d
//
// message_dispatch_408 @ 0x12c584, size 44 bytes
// Doc: message_dispatch_n_3f2 [ipc]: Message dispatch stub (returns immediately)
// message_dispatch_n_3f2 [ipc]: Message dispatch stub (returns immediately)
int __fastcall message_dispatch_408(int result)
{
  int *i; // r3
  int v2; // r2
  int v3; // r3

  v2 = *(char *)(result + 110);
  v3 = (char)(*(_BYTE *)(result + 420) - *(_BYTE *)(result + 464));
  if ( v2 == 127 )
  {
    *(_BYTE *)(result + 109) = 127;
    if ( v3 == 127 )
      return result;
  }
  else if ( v3 >= v2 )
  {
    LOBYTE(v3) = *(_BYTE *)(result + 110);
  }
  *(_BYTE *)(result + 109) = v3;
  for ( i = *(int **)(result + 240); i; i = (int *)*i )
    *((_BYTE *)i + 350) |= 0x10u;
  result = *(_DWORD *)(result + 72);
  if ( result )
    return sub_128548(result);
  return result;
}

