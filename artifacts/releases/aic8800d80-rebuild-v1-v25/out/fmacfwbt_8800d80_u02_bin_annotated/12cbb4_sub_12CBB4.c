// fwstruct annotate: 12cbb4_sub_12CBB4.c
// sub_12CBB4 @ 0x12cbb4, size 106 bytes
// Doc: message_dispatch_n52_cc06 [ipc]: Dispatches an incoming IPC message by ID
// message_dispatch_n52_cc06 [ipc]: Dispatches an incoming IPC message by ID
int __fastcall sub_12CBB4(int a1)
{
  __int16 v1; // r3
  unsigned __int16 *v4; // r0

  v1 = *(_WORD *)(a1 - 6);
  if ( **(__int16 **)message_dispatch_c20 >= 0 || (unsigned __int8)v1 <= 0xEu )
  {
    if ( (unsigned __int8)v1 <= 0xCu )
    {
      list_push_tail(message_dispatch_n70);
      return irq_nesting_or(0x4000000);
    }
  }
  else
  {
    sub_12F694(message_dispatch2_cc2c, message_dispatch_n74, 183);
  }
  sub_12ECB0(message_dispatch_n7c, *(unsigned __int16 *)(a1 - 8), *(unsigned __int16 *)(a1 - 4));
  v4 = (unsigned __int16 *)(a1 - 12);
  if ( *(_BYTE *)message_dispatch_n80 )
    return buffer_pool_get(v4);
  else
    return j_rf_state_check_n36a(v4);
}

