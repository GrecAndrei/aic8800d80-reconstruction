// v23 annotated: sub_114408 @ 0x114408
// Original: 114408_sub_114408.c
// Primary struct: <unclustered>
//
// sub_114408 @ 0x114408, size 110 bytes
// Doc: sub_1214408 [ipc]: Unidentified helper, possibly IPC/mailbox glue
// sub_1214408 [ipc]: Unidentified helper, possibly IPC/mailbox glue
int __fastcall sub_114408(int result)
{
  if ( !result )
  {
    if ( *(_DWORD *)off_114478
      && (result = *((_DWORD *)off_11447C + 4),
          *(_DWORD *)(*(_DWORD *)off_114478 + 12) - result - *((unsigned __int16 *)off_114480 + 92) - 2000 < 0) )
    {
      result = feature_guard_sdio(2, dword_114490);
    }
    else
    {
      if ( !*(_BYTE *)off_114484
        || (result = *((_DWORD *)off_11447C + 4),
            *((_DWORD *)off_114484 + 1)
          + *((_DWORD *)off_114484 + 2)
          - result
          - *((unsigned __int16 *)off_114480 + 92)
          - *(unsigned __int16 *)(*(_DWORD *)off_114488 + 52) >= 0) )
      {
        *(_DWORD *)off_11448C = 0x40000000;
        return result;
      }
      result = feature_guard_sdio(2, dword_114494);
    }
  }
  *(_DWORD *)off_11448C = 0x80000000;
  return result;
}

