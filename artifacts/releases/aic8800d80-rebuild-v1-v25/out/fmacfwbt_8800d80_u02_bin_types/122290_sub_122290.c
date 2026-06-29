// sub_122290 @ 0x122290, size 168 bytes
// Doc: sub_1222294 [unknown]: Unknown behavioral function in fmacfwbt
// sub_1222294 [unknown]: Unknown behavioral function in fmacfwbt
int  sub_122290(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  uint16_t *v5; // r3
  int result; // r0
  uint32_t *v7; // r3
  int v8; // r1
  uint8_t *v9; // r3
  char *v10; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    v7 = off_12234C;
    *(uint8_t *)(a1 + 128) = 0;
    v8 = v7[4];
    v9 = off_122344;
    v10 = (char *)off_122344 + 12;
    *((uint16_t *)off_122344 + 14) = 1793;
    v9[36] = 0;
    *((uint32_t *)v9 + 5) = a1;
    result = timestamp_update_4f60(v10, v8 + 10000);
    *(uint8_t *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (unsigned __int8)(*(uint8_t *)(a1 + 115) + 1);
    v4 = *(uint32_t *)off_122338;
    *(uint8_t *)(a1 + 115) = v3;
    if ( *(unsigned __int8 *)(v4 + 1) == v3 )
    {
      *(uint8_t *)(a1 + 115) = 0;
      feature_guard_sdio(1024, dword_122354);
      return mac_cmd_send_status_query(a1);
    }
    else if ( *(uint8_t *)(a1 + 108) )
    {
      return rf_table_lookup_n528(*(unsigned __int8 *)(a1 + 107), dword_122350, a1);
    }
    else
    {
      if ( *((uint8_t *)off_12233C + 2) )
        *(uint32_t *)off_122340 &= ~0x80000000;
      v5 = off_122344;
      if ( *((uint8_t *)off_122344 + 8) )
        --*((uint8_t *)off_122344 + 8);
      v5[14] = 1;
      result = timestamp_remove_058(dword_122348);
      *(uint32_t *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}

