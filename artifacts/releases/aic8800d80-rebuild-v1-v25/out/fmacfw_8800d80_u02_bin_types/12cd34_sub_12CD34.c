// sub_12CD34 @ 0x12cd34, size 278 bytes
// Doc: message_dispatch_n4a2 [ipc]: Dispatch firmware message via handler table
// message_dispatch_n4a2 [ipc]: Dispatch firmware message via handler table
uint32_t * sub_12CD34(unsigned int a1, int a2)
{
  __int16 **v2; // r7
  unsigned int v5; // r9
  int v6; // r6
  uint16_t *v7; // r9
  uint32_t *result; // r0
  int ( *v9)(uint32_t *, int); // r8
  int v10; // r7
  int *v11; // r6
  int *v12; // r5
  int v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r6

  v2 = (__int16 **)off_12CE4C;
  v5 = a1 >> 8;
  v6 = (unsigned __int8)a1;
  if ( **(__int16 **)off_12CE4C >= 0 )
    goto message_dispatch_n3c2;
  if ( (unsigned __int8)a1 > 0xDu )
  {
    sub_12F46C(dword_12CE74, dword_12CE68, 173);
    if ( **v2 >= 0 )
    {
message_dispatch_n3c2:
      v7 = (uint16_t *)(*(uint32_t *)(dword_12CE50 + 16 * v6 + 8) + 2 * v5);
      goto message_dispatch_n3ce;
    }
    if ( v6 != 14 )
      sub_12F46C(dword_12CE7C, ipc_doorbell_handler_n3a, 183);
  }
  else if ( (unsigned __int8)a1 != 13 )
  {
    goto message_dispatch_n440;
  }
  sub_12F46C(dword_12CE80, dword_12CE68, 174);
  if ( **v2 >= 0 )
    goto message_dispatch_n3c2;
message_dispatch_n440:
  v16 = dword_12CE50 + 16 * v6;
  if ( *(unsigned __int16 *)(v16 + 14) > v5 )
  {
    v7 = (uint16_t *)(*(uint32_t *)(v16 + 8) + 2 * v5);
    if ( v7 )
      goto message_dispatch_n3ce;
    goto message_dispatch_n458;
  }
  sub_12F46C(dword_12CE70, dword_12CE68, 175);
  v7 = (uint16_t *)(*(uint32_t *)(v16 + 8) + 2 * v5);
  if ( **v2 < 0 && !v7 )
message_dispatch_n458:
    sub_12F46C(dword_12CE6C, dword_12CE68, 180);
message_dispatch_n3ce:
  result = (uint32_t *)msg_parse(dword_12CE54, a1, a2);
  if ( (unsigned __int16)*v7 != a2 )
  {
    v9 = (int ( *)(uint32_t *, int))message_dispatch_n4f9;
    v10 = message_dispatch_n4cc;
    v11 = (int *)message_dispatch_n4d0;
    *v7 = a2;
    while ( 1 )
    {
      result = list_find_remove_ca3c(v10, v9, a1);
      if ( !result )
        break;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *v11 = 1;
      }
      v12 = (int *)off_12CE60;
      v13 = dword_12CE64;
      ++*(uint32_t *)off_12CE60;
      list_push_tail(v13);
      v14 = *v12 - 1;
      if ( *v12 )
      {
        v15 = *v11;
        *v12 = v14;
        if ( !v14 )
        {
          if ( v15 )
            __enable_irq();
        }
      }
      irq_nesting_or_d104(0x4000000);
    }
  }
  return result;
}

