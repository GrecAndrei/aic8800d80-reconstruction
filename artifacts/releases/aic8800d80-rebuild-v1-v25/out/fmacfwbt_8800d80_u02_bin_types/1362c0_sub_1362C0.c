// sub_1362C0 @ 0x1362c0, size 142 bytes
int  sub_1362C0(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  __int16 v6; // r2
  int v7; // r0
  int value; // r0
  uint32_t *v10; // r1
  uint32_t *v11; // r4
  int v12; // r6
  int v13; // r0
  unsigned int v14; // r3
  int *v15; // r3
  int v16; // r3

  sub_12ECB0(dword_136354, dword_136350);
  v6 = a3;
  v7 = dword_136358 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && !*(uint8_t *)(v7 + 108) )
  {
    value = msg_get_value(7u);
    v6 = a3;
    if ( !value )
    {
      sub_1287E0(*a2);
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_13635C = 1;
      }
      v10 = off_136360;
      v11 = off_136364;
      v12 = *(uint32_t *)off_136360;
      v13 = *(uint32_t *)off_136360 + 1;
      v14 = *((uint32_t *)off_136364 + 1) & 0xFFFFFFEF;
      *(uint32_t *)off_136360 = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (int *)off_13635C;
        *v10 = v12;
        v16 = *v15;
        if ( !v12 )
        {
          if ( v16 )
            __enable_irq();
        }
      }
    }
  }
  message_dispatch_n84(7175, a4, v6);
  return 0;
}

