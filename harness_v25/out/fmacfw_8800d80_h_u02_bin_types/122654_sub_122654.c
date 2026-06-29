// sub_122654 @ 0x122654, size 214 bytes
char * sub_122654(char *result)
{
  int v1; // r4
  int v2; // r6
  int v3; // r5
  unsigned int v4; // r3
  int v5; // r2
  unsigned __int8 *v6; // r1
  unsigned int v7; // r2
  uint8_t *v8; // r3
  unsigned int v9; // r3

  if ( result[108] )
  {
    v1 = (int)result;
    if ( result[146] && result[148] )
    {
      v9 = (unsigned __int8)(result[146] - 1);
      result[146] = v9;
      if ( v9 <= 1 )
        return (char *)sub_1201D4((int)result);
      if ( v9 == 2 )
        sub_12249C(result[107], 0);
    }
    v2 = *(uint32_t *)(v1 + 36);
    v3 = *(uint32_t *)(dword_12272C + 696 * *(unsigned __int8 *)(v1 + 116) + 8) + v2;
    if ( v1 != *((uint32_t *)off_122730 + 8)
      || (v8 = off_122738, *(uint32_t *)(v1 + 36) = v3, !v8[189]) && **(uint8_t **)off_12273C != 2 )
    {
      sub_124BFC(v1 + 24, v3);
    }
    sub_1200F0(v1);
    sub_12A144(v1, *(uint32_t *)(v1 + 136) + v2);
    result = (char *)sub_127DFC(v1, v2, v3);
    if ( !result )
    {
      v4 = (unsigned __int8)(*(uint8_t *)(v1 + 128) + 1);
      v5 = *(uint32_t *)(v1 + 4) | 1;
      v6 = *(unsigned __int8 **)off_122734;
      *(uint8_t *)(v1 + 128) = v4;
      *(uint32_t *)(v1 + 4) = v5;
      v7 = *v6;
      if ( v4 > v7 )
      {
        return (char *)sub_118F4C(*(unsigned __int8 *)(v1 + 116), (int)off_122740, v1);
      }
      else if ( v4 == v7 )
      {
        return (char *)sub_128294(v1);
      }
    }
  }
  return result;
}

