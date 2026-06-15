// sub_11F704 @ 0x11f704, size 122 bytes
int __fastcall sub_11F704(int a1, int a2, int a3)
{
  int v3; // r10
  int v4; // r4
  int v8; // r9
  int v9; // r1
  int v10; // r0
  int v12; // [sp+4h] [bp-4h] BYREF

  v3 = *(_DWORD *)(a2 + 572);
  if ( !v3 )
    return 0;
  v4 = 0;
  v8 = a2 + 572;
  do
  {
    v12 = 0;
    if ( !bt_sub_121733C(a1) )
      break;
    if ( !sub_136C34(v3) )
      break;
    v10 = sub_136CFC(a1, a2, &v12);
    if ( v12 )
      break;
    if ( !v10 )
      v10 = sub_12D4F8(v8);
    v9 = *(unsigned __int8 *)(v10 + 27);
    *(_BYTE *)(v10 + 97) = 0;
    ++v4;
    cmd_dispatch_handler(v10, v9);
    if ( a3 )
    {
      if ( v4 == a3 )
        break;
    }
    v3 = *(_DWORD *)(a2 + 572);
  }
  while ( v3 );
  return v4;
}

