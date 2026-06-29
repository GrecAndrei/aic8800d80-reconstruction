// fwstruct annotate: 10d26c_sub_10D26C.c
// sub_10D26C @ 0x10d26c, size 378 bytes
// Doc: sub_120D26C [unknown]: General handler loading signed state from globals, processes 3-arg call
// sub_120D26C [unknown]: General handler loading signed state from globals, processes 3-arg call
int __fastcall sub_10D26C(int a1, int a2, int a3)
{
  int *v6; // r1
  int result; // r0
  int v8; // r12
  int v9; // lr
  int v10; // r9
  int v11; // r3
  int *v12; // r3
  int v13; // r3

  if ( **(__int16 **)off_10D3E8 < 0 && a3 > 13 )
    sub_12F694(dword_10D3F8, dword_10D3F4, 69);
  *(_DWORD *)(a2 + 32) = 0;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10D3EC = 1;
  }
  v6 = (int *)off_10D3F0;
  result = *(_DWORD *)off_10D3F0;
  v8 = *(_DWORD *)off_10D3F0 + 1;
  dword_40021000[16 * a3] |= 1u;
  *v6 = v8;
  while ( (dword_40021000[16 * a3] & 0x10000) == 0 )
    ;
  v9 = dword_10D3FC;
  v10 = *(_DWORD *)(dword_10D3FC + 4 * a3);
  if ( v10 && (dword_40021000[16 * a3 + 3] & 0x800) == 0 )
  {
    if ( (dword_40021000[16 * a3 + 6] & 0x80000) != 0 )
    {
      dword_40021000[16 * a3 + 6] &= ~0x80000u;
      dword_40021000[16 * a3 + 12] = a1;
    }
    *(_DWORD *)(v10 + 8) &= ~0x80000u;
    *(_DWORD *)(v10 + 32) = a1;
  }
  else
  {
    dword_40021000[16 * a3 + 2] = dword_10D400;
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
    *(_DWORD *)(a2 + 8) |= 0x80000u;
    dword_40021000[16 * a3 + 2] |= 1u;
    dword_40021000[16 * a3 + 1] |= 1u;
  }
  v11 = dword_40021000[16 * a3];
  *(_DWORD *)(v9 + 4 * a3) = a2;
  dword_40021000[16 * a3] = v11 & 0xFFFFFFFE;
  if ( v8 )
  {
    v12 = (int *)off_10D3EC;
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

