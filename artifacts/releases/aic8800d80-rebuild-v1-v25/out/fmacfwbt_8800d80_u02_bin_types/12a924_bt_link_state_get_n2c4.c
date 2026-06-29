// bt_link_state_get_n2c4 @ 0x12a924, size 218 bytes
// Doc: bt_link_state_get_n2c4 [bt]: Looks up Bluetooth link state entry indexed by connection slot
// bt_link_state_get_n2c4 [bt]: Looks up Bluetooth link state entry indexed by connection slot
int  bt_link_state_get_n2c4(int a1, unsigned int a2, int a3)
{
  int v3; // r6
  int v4; // r5
  int result; // r0
  int v7; // r3
  unsigned int v8; // r8
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3

  v3 = *(unsigned __int8 *)(a1 + 1225);
  v4 = dword_12AA00;
  result = *(unsigned __int8 *)(dword_12AA00 + 140 * v3 + 112);
  if ( result != 1 )
    return 1;
  if ( a2 <= 1 )
  {
    v7 = 140 * v3 + 48 * a2 + dword_12AA00;
    if ( *(uint8_t *)(v7 + 16) )
    {
      if ( !a3 || *(uint8_t *)(v7 + 32) )
      {
        timestamp_remove_058(48 * a2 + 140 * v3 + dword_12AA00);
        v8 = 140 * v3 + 48 * a2 + v4;
        *(uint8_t *)(v8 + 16) = 0;
        sub_1297BC(v4 + 140 * v3);
        sub_129A28((unsigned __int8 *)(v4 + 140 * v3));
        v9 = v4 + 140 * v3;
        v10 = *(unsigned __int8 *)(v8 + 32);
        v11 = (unsigned __int8)(*(uint8_t *)(v9 + 121) - 1);
        *(uint8_t *)(v9 + 121) = v11;
        if ( v10 == 1 )
          --*(uint8_t *)(v9 + 122);
        v12 = v4 + 140 * v3;
        if ( *(uint8_t *)(v12 + 115) || v11 )
          sub_125EFC(*(unsigned __int8 *)(v4 + 140 * v3 + 113), 3);
        else
          sub_125EFC(*(unsigned __int8 *)(v12 + 113), 2);
        sub_129768(v4 + 140 * v3, a2);
        return 0;
      }
    }
  }
  return result;
}

