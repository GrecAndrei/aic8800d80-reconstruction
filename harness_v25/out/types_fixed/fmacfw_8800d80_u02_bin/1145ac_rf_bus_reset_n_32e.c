// rf_bus_reset_n_32e @ 0x1145ac, size 110 bytes
// Doc: rf_fault_dump_n_17c [rf]: Dumps RF fault state from 0x182b64
// rf_fault_dump_n_17c [rf]: Dumps RF fault state from 0x182b64
int __fastcall rf_bus_reset_n_32e(int result)
{
  if ( !result )
  {
    if ( *(_DWORD *)rf_fault_dump_n_12c
      && (result = *((_DWORD *)rf_fault_dump_n_128 + 4),
          *(_DWORD *)(*(_DWORD *)rf_fault_dump_n_12c + 12) - result - *((unsigned __int16 *)off_114624 + 92) - 2000 < 0) )
    {
      result = feature_guard_check(2, rf_fault_dump_n_114);
    }
    else
    {
      if ( !*(_BYTE *)rf_fault_dump_628
        || (result = *((_DWORD *)rf_fault_dump_n_128 + 4),
            *((_DWORD *)rf_fault_dump_628 + 1)
          + *((_DWORD *)rf_fault_dump_628 + 2)
          - result
          - *((unsigned __int16 *)off_114624 + 92)
          - *(unsigned __int16 *)(*(_DWORD *)off_11462C + 52) >= 0) )
      {
        *(_DWORD *)off_114630 = 0x40000000;
        return result;
      }
      result = feature_guard_check(2, rf_fault_dump_n_110);
    }
  }
  *(_DWORD *)off_114630 = 0x80000000;
  return result;
}

