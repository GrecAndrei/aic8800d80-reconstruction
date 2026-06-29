// sub_126034 @ 0x126034, size 94 bytes
// Doc: sub_1226034 [mmio]: Indexed entry lookup by per-instance id from mmio table
// sub_1226034 [mmio]: Indexed entry lookup by per-instance id from mmio table
int  sub_126034(int result)
{
  int v1; // r6
  int v2; // r4
  int v3; // r3
  int v4; // r5
  int v5; // r4
  int *v6; // r3
  int v7; // r1

  v1 = dword_126094;
  v2 = *(unsigned __int8 *)(result + 1225);
  v3 = dword_126094 + 140 * v2;
  v4 = result;
  if ( !*(uint8_t *)(v3 + 32) && *(uint8_t *)(v3 + 16) )
    result = ((int (*)(void))bt_link_state_get_n2c4)();
  v5 = v1 + 140 * v2;
  if ( !*(uint8_t *)(v5 + 80) && *(uint8_t *)(v5 + 64) )
    result = bt_link_state_get_n2c4(v4, 1);
  v6 = *((int **)off_126098 + 2);
  if ( v6 )
  {
    v7 = *(unsigned __int8 *)(v4 + 107);
    result = 255;
    do
    {
      if ( *((unsigned __int8 *)v6 + 86) == v7 )
        *((uint8_t *)v6 + 86) = -1;
      v6 = (int *)*v6;
    }
    while ( v6 );
  }
  return result;
}

