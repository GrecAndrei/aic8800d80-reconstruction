// msg_dispatch_unk @ 0x121cbc, size 26 bytes
// Doc: msg_dispatch_unk [ipc]: unknown message dispatch
// msg_dispatch_unk [ipc]: unknown message dispatch
int msg_dispatch_unk()
{
  int result; // r0

  result = msg_get_value(0);
  if ( result == 4 )
    return sub_12CD34(0);
  return result;
}

