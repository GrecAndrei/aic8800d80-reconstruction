// message_dispatch_c8b4 @ 0x12c8b4, size 32 bytes
// Doc: message_dispatch_n_c6 [ipc]: Message dispatch helper returning 1; sets r0 from r3
// message_dispatch_n_c6 [ipc]: Message dispatch helper returning 1; sets r0 from r3
int __fastcall message_dispatch_c8b4(int a1, int a2)
{
  int **v2; // r3

  v2 = *((int ***)off_12C8D4 + 5);
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

