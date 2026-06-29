// sub_121F44 @ 0x121f44, size 212 bytes
// Doc: rf_cmd_dispatch_fc0 [rf]: Dispatch incoming RF commands to handlers
// rf_cmd_dispatch_fc0 [rf]: Dispatch incoming RF commands to handlers
int  sub_121F44(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int cb_efa4; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = parse_int(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = rf_cmd_dispatch_n_34(*(uint32_t *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    sub_10DA6C(dword_122028, v5);
    return -1;
  }
  v9 = parse_int(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
  v5 = rf_cmd_dispatch_n_34(*(uint32_t *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      cb_efa4 = rf_reg_read_cb_efa4();
      sub_10DA6C(dword_122018, v4 & 0xFFFFFFFC, cb_efa4);
      return 0;
    }
    else if ( v5 == 4 )
    {
      sub_10DA6C(dword_12201C, v4, *(uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      sub_10DA6C(dword_122020, v4, *(unsigned __int16 *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        sub_10DA6C(dword_122024, v4, *(unsigned __int8 *)v4);
      return 0;
    }
  }
  v7 = **(uint8_t **)a2 == 82 && v4 < 0x40000000;
  rf_mem_read_f594(v4, v9, (unsigned __int8)v5, v7);
  return 0;
}

