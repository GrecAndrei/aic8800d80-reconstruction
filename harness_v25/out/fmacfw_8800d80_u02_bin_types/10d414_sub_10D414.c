// sub_10D414 @ 0x10d414, size 378 bytes
// Doc: sub_120D414 [ipc]: Reads global state flag and dispatches by value
// sub_120D414 [ipc]: Reads global state flag and dispatches by value
int  sub_10D414(int a1, int a2, int a3)
{
  int *v6; // r1
  int result; // r0
  int v8; // r12
  int v9; // lr
  int v10; // r9
  int v11; // r3
  int *v12; // r3
  int v13; // r3

  if ( **(__int16 **)off_10D590 < 0 && a3 > 13 )
    sub_12F46C(dword_10D5A0, dword_10D59C, 69);
  *(uint32_t *)(a2 + 32) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_10D594 = 1;
  }
  v6 = (int *)off_10D598;
  result = *(uint32_t *)off_10D598;
  v8 = *(uint32_t *)off_10D598 + 1;
  dword_40021000[16 * a3] |= 1u;
  *v6 = v8;
  while ( (dword_40021000[16 * a3] & 0x10000) == 0 )
    ;
  v9 = dword_10D5A4;
  v10 = *(uint32_t *)(dword_10D5A4 + 4 * a3);
  if ( v10 && (dword_40021000[16 * a3 + 3] & 0x800) == 0 )
  {
    if ( (dword_40021000[16 * a3 + 6] & 0x80000) != 0 )
    {
      dword_40021000[16 * a3 + 6] &= ~0x80000u;
      dword_40021000[16 * a3 + 12] = a1;
    }
    *(uint32_t *)(v10 + 8) &= ~0x80000u;
    *(uint32_t *)(v10 + 32) = a1;
  }
  else
  {
    dword_40021000[16 * a3 + 2] = dword_10D5A8;
    dword_40021000[16 * a3 + 3] = 20;
    dword_40021000[16 * a3 + 4] = 0;
    dword_40021000[16 * a3 + 5] = 0;
    dword_40021000[16 * a3 + 6] = 0;
    dword_40021000[16 * a3 + 7] = 0;
    dword_40021000[16 * a3 + 8] = 0;
    dword_40021000[16 * a3 + 9] = 0;
    dword_40021000[16 * a3 + 10] = 0;
    dword_40021000[16 * a3 + 11] = 0;
    dword_40021000[16 * a3 + 13] = 0;
    dword_40021000[16 * a3 + 14] = 0;
    dword_40021000[16 * a3 + 15] = 0;
    dword_40021000[16 * a3 + 12] = a1;
    *(uint32_t *)(a2 + 8) |= 0x80000u;
    dword_40021000[16 * a3 + 2] |= 1u;
    dword_40021000[16 * a3 + 1] |= 1u;
  }
  v11 = dword_40021000[16 * a3];
  *(uint32_t *)(v9 + 4 * a3) = a2;
  dword_40021000[16 * a3] = v11 & 0xFFFFFFFE;
  if ( v8 )
  {
    v12 = (int *)off_10D594;
    *v6 = result;
    v13 = *v12;
    if ( !result )
    {
      if ( v13 )
        __enable_irq();
    }
  }
  return result;
}

