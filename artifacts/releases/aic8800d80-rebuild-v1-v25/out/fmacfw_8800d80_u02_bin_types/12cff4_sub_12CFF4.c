// sub_12CFF4 @ 0x12cff4, size 222 bytes
int sub_12CFF4()
{
  int *v0; // r5
  int v1; // r0
  int result; // r0
  unsigned __int16 *v3; // r4
  int v4; // r3
  int v5; // r2
  int ( *v6)(uint32_t, unsigned __int16 *, uint32_t, uint32_t); // r6
  int v7; // r2
  int v8; // r3
  int v9; // r3
  int v10; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12D0D4 = 1;
  }
  v0 = (int *)off_12D0D8;
  v1 = dword_12D0DC;
  ++*(uint32_t *)off_12D0D8;
  result = rf_bus_mark_n100_d2d0(v1);
  v3 = (unsigned __int16 *)result;
  if ( *v0 )
  {
    v4 = *v0 - 1;
    v5 = *(uint32_t *)off_12D0D4;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  if ( result )
  {
    v6 = (int ( *)(uint32_t, unsigned __int16 *, uint32_t, uint32_t))sub_12CF2C(
                                                                           *(unsigned __int16 *)(result + 4),
                                                                           *(unsigned __int16 *)(result + 6));
    msg_parse(dword_12D0E0, v3[2], v3[4]);
    if ( v6 )
    {
      result = v6(v3[2], v3 + 6, v3[3], v3[4]);
      if ( result == 1 )
        goto LABEL_12;
      if ( result == 2 )
      {
        result = list_push_tail(dword_12D0F0);
        goto LABEL_12;
      }
      if ( result )
      {
        if ( **(__int16 **)off_12D0E4 < 0 )
          result = sub_12F46C(dword_12D0F8, dword_12D0F4, 360);
        goto LABEL_12;
      }
    }
    else
    {
      msg_parse(dword_12D0EC, v3[2], v3[4]);
    }
    result = sub_12CA38((int)v3);
  }
LABEL_12:
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_12D0D4 = 1;
  }
  v7 = *((uint32_t *)off_12D0E8 + 1);
  v8 = *v0 + 1;
  *v0 = v8;
  if ( !v7 )
  {
    result = clear_flags(0x4000000);
    v8 = *v0;
  }
  if ( v8 )
  {
    v9 = v8 - 1;
    v10 = *(uint32_t *)off_12D0D4;
    *v0 = v9;
    if ( !v9 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  return result;
}

