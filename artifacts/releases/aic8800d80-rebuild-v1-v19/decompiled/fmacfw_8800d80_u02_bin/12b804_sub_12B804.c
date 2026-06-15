// sub_12B804 @ 0x12b804, size 120 bytes
// Doc: sub_122B804 [util]: Check global flag value and branch on sign
// sub_122B804 [util]: Check global flag value and branch on sign
int sub_12B804()
{
  _DWORD *v0; // r1
  int v1; // r6
  int *v2; // r4
  _DWORD *v3; // r2
  _DWORD *v4; // r5
  _DWORD *v5; // r7
  int v6; // r3
  int result; // r0
  _DWORD *v8; // r4
  int v9; // r3
  int *v10; // r3
  int v11; // r3

  if ( **(__int16 **)off_12B87C < 0 && !(*(_DWORD *)off_12B898 << 28) )
    return fmac_phy_op_handler(dword_12B8A4, dword_12B8A0, 213, *(_DWORD *)off_12B898);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12B880 = 1;
  }
  v0 = off_12B888;
  v1 = *(_DWORD *)off_12B888;
  v2 = (int *)off_12B88C;
  v3 = off_12B890;
  v4 = off_12B894;
  v5 = off_12B898;
  v6 = *(_DWORD *)off_12B884 + 25000;
  result = *(_DWORD *)off_12B888 + 1;
  *(_DWORD *)off_12B888 = result;
  *v2 = v6;
  v8 = off_12B89C;
  *v3 = 128;
  v9 = v8[1] | 4;
  *v4 |= 0x80u;
  v8[1] = v9;
  *v5 = 0;
  if ( result )
  {
    v10 = (int *)off_12B880;
    *v0 = v1;
    v11 = *v10;
    if ( !v1 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

