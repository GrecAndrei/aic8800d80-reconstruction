// sub_13BE14 @ 0x13be14, size 120 bytes
// Doc: sub_123BE14 [unknown]: Unknown behavioral helper, likely init/state helper
// sub_123BE14 [unknown]: Unknown behavioral helper, likely init/state helper
int  sub_13BE14(int result)
{
  int v1; // r9
  int v2; // r6
  int v3; // r5
  int v4; // r7
  int v5; // r10
  int v6; // r8
  int i; // r4
  int v8; // t1

  v1 = dword_13BE98;
  v2 = dword_13BE8C;
  v3 = dword_13BE90;
  v4 = result;
  v5 = dword_13BE98 - 8;
  v6 = dword_13BE98 + 24;
  for ( i = 0; i != 32; ++i )
  {
    v8 = *(unsigned __int16 *)(v2 + 2);
    v2 += 2;
    if ( v8 && *(unsigned __int8 *)(v3 + 16) == v4 )
    {
      if ( i > 15 )
      {
        sub_12D2E8(v6, (uint32_t *)v3);
        list_push_tail(dword_13BE94, (uint32_t *)v3);
      }
      else
      {
        sub_12D2E8(v1, (uint32_t *)v3);
        list_push_tail(v5, (uint32_t *)v3);
      }
      sub_12CD34((unsigned __int16)((uint16_t)i << 8) | 8, 4);
      result = tx_build_frame_header(v4, (unsigned __int16)i);
    }
    v3 += 32;
  }
  return result;
}

