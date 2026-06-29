// sub_12380C @ 0x12380c, size 106 bytes
int  sub_12380C(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  uint32_t *v5; // r5
  int v6; // r6
  uint64_t v7; // r0
  int v8; // r2
  int v9; // r0
  int v10; // r0
  int v11; // r3
  int v12; // r3
  int v13; // r0

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_123878 = 1;
  }
  v4 = (int *)off_12387C;
  v5 = off_123880;
  v6 = *(uint32_t *)off_123880;
  ++*(uint32_t *)off_12387C;
  v7 = sub_12B768();
  v9 = sub_101924(v7, SHIDWORD(v7), v8);
  v10 = sub_12C798(v9);
  sub_132088(v10);
  sub_117A7C();
  sub_1205E0();
  v11 = *v4;
  *v5 = v6;
  if ( v11 )
  {
    v12 = v11 - 1;
    v13 = *(uint32_t *)off_123878;
    *v4 = v12;
    if ( !v12 )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  sub_12C8D0(1, a4, a3);
  sub_12CBF4(0);
  return 0;
}

