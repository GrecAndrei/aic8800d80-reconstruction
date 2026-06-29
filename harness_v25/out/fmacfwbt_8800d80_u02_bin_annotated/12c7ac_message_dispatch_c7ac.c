// fwstruct annotate: 12c7ac_message_dispatch_c7ac.c
// message_dispatch_c7ac @ 0x12c7ac, size 44 bytes
// Doc: message_dispatch_n_3fc [ipc]: Message dispatch comparator clamping against 0x7f boundary
// message_dispatch_n_3fc [ipc]: Message dispatch comparator clamping against 0x7f boundary
int __fastcall message_dispatch_c7ac(int result)
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
    return sub_12876C(result);
  return result;
}

