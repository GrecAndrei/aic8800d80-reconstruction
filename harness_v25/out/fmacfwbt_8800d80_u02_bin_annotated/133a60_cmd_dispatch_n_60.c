// fwstruct annotate: 133a60_cmd_dispatch_n_60.c
// cmd_dispatch_n_60 @ 0x133a60, size 54 bytes
// Doc: cmd_dispatch_n_60 [util]: Dispatch command 6 to handler
// cmd_dispatch_n_60 [util]: Dispatch command 6 to handler
int __fastcall cmd_dispatch_n_60(int a1, int a2, __int16 a3, __int16 a4)
{
  int value; // r0
  __int16 v6; // r1
  __int16 v7; // r2
  __int16 v10; // [sp+0h] [bp-8h]
  __int16 v12; // [sp+4h] [bp-4h]

  value = msg_get_value(6u);
  v6 = a4;
  v7 = a3;
  if ( value == 6 )
  {
    v10 = a3;
    v12 = v6;
    sub_135B4C(*(unsigned __int16 *)(a2 + 2));
    v7 = v10;
    v6 = v12;
  }
  message_dispatch_n84(6156, v6, v7);
  return 0;
}

