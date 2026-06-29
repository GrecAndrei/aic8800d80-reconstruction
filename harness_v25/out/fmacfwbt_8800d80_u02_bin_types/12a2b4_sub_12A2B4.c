// sub_12A2B4 @ 0x12a2b4, size 152 bytes
unsigned __int8 * sub_12A2B4(unsigned __int8 *result, int a2)
{
  int v2; // r5
  int v3; // r7
  unsigned __int8 *v4; // r8
  int v5; // r9
  int v6; // r4
  unsigned __int8 *v7; // r5
  int v8; // r3

  if ( result[1224] && !(result[106] | a2) )
  {
    v2 = result[1225];
    v3 = dword_12A34C;
    v4 = (unsigned __int8 *)(dword_12A34C + 140 * v2);
    v5 = 140 * v2;
    if ( v4[16] )
    {
      timestamp_remove_058(dword_12A34C + 140 * v2);
      v4[16] = 0;
    }
    v6 = v3 + 140 * v2;
    if ( *(uint8_t *)(v6 + 64) )
    {
      timestamp_remove_058(v5 + 48 + v3);
      *(uint8_t *)(v6 + 64) = 0;
    }
    v7 = (unsigned __int8 *)(v3 + 140 * v2);
    v8 = v7[114];
    v7[115] = 0;
    v7[120] = 0;
    v7[132] = 0;
    if ( v8 )
    {
      timestamp_remove_058(v5 + 96 + v3);
      v7[114] = 0;
    }
    return sub_129A28(v4);
  }
  return result;
}

