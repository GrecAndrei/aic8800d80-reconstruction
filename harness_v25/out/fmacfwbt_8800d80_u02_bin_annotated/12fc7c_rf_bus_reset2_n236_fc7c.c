// fwstruct annotate: 12fc7c_rf_bus_reset2_n236_fc7c.c
// rf_bus_reset2_n236_fc7c @ 0x12fc7c, size 212 bytes
// Doc: rf_bus_reset2_n236_fc7c [rf]: RF bus reset variant: check 0x20000 bit mask and continue reset sequence
// rf_bus_reset2_n236_fc7c [rf]: RF bus reset variant: check 0x20000 bit mask and continue reset sequence
int __fastcall rf_bus_reset2_n236_fc7c(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int v8; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = sub_12FB74(*(unsigned __int8 **)(a2 + 4), nullptr, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = bt_hci_cmd_dispatch_fc48(*(_DWORD *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    log_printf(dword_12FD60, v5);
    return -1;
  }
  v9 = sub_12FB74(*(unsigned __int8 **)(a2 + 8), nullptr, 0);
  v5 = bt_hci_cmd_dispatch_fc48(*(_DWORD *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      v8 = sub_10EBC4();
      log_printf(dword_12FD50, v4 & 0xFFFFFFFC, v8);
      return 0;
    }
    else if ( v5 == 4 )
    {
      log_printf(dword_12FD54, v4, *(_DWORD *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      log_printf(dword_12FD58, v4, *(unsigned __int16 *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        log_printf(dword_12FD5C, v4, *(unsigned __int8 *)v4);
      return 0;
    }
  }
  v7 = **(_BYTE **)a2 == 82 && v4 < 0x40000000;
  rf_mem_read_ed40(v4, v9, (unsigned __int8)v5, v7);
  return 0;
}

