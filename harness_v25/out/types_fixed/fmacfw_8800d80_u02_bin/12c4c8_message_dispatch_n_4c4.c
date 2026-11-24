// message_dispatch_n_4c4 @ 0x12c4c8, size 26 bytes
// Doc: rf_cmd_dispatch_n2aa [rf]: Dispatches RF command to lower RF layer
// rf_cmd_dispatch_n2aa [rf]: Dispatches RF command to lower RF layer
int __fastcall message_dispatch_n_4c4(int a1, _BYTE *a2, _BYTE *a3)
{
  int v3; // r3
  int result; // r0

  v3 = *(char *)(a1 + 109);
  if ( v3 == 127 )
    result = *(_DWORD *)off_12C4E4;
  else
    result = (unsigned __int8)v3;
  if ( v3 == 127 )
    result = (unsigned __int8)result;
  if ( a2 )
    *a2 = v3;
  if ( a3 )
    *a3 = result;
  return result;
}

