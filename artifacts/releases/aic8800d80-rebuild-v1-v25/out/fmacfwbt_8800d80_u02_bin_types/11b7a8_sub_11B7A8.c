// sub_11B7A8 @ 0x11b7a8, size 74 bytes
int  sub_11B7A8(int result)
{
  uint32_t *v1; // r6
  char *v2; // r3
  int v3; // r2
  int v4; // r4
  int v5; // r5
  int v6; // r3

  v1 = off_11B7F4;
  v2 = (char *)off_11B7F4 + 28 * result;
  if ( v2[46] )
  {
    v3 = *((uint32_t *)off_11B7F4 + 52);
    v2[46] = 0;
    v4 = result;
    v5 = 8 * result;
    if ( (v3 & 1) == 0 || *((unsigned __int8 *)v1 + 190) != result )
    {
      v6 = (int)&v1[7 * result];
      result = *(uint32_t *)(v6 + 36);
      if ( result )
        result = bt_chan_dispatch_n_6f0(result, v4, v3, v6);
      v1[v5 - v4 + 9] = 0;
    }
  }
  return result;
}

