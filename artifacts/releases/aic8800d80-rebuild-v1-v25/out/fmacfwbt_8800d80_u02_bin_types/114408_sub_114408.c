// sub_114408 @ 0x114408, size 110 bytes
// Doc: sub_1214408 [ipc]: Unidentified helper, possibly IPC/mailbox glue
// sub_1214408 [ipc]: Unidentified helper, possibly IPC/mailbox glue
int  sub_114408(int result)
{
  if ( !result )
  {
    if ( *(uint32_t *)off_114478
      && (result = *((uint32_t *)off_11447C + 4),
          *(uint32_t *)(*(uint32_t *)off_114478 + 12) - result - *((unsigned __int16 *)off_114480 + 92) - 2000 < 0) )
    {
      result = feature_guard_sdio(2, dword_114490);
    }
    else
    {
      if ( !*(uint8_t *)off_114484
        || (result = *((uint32_t *)off_11447C + 4),
            *((uint32_t *)off_114484 + 1)
          + *((uint32_t *)off_114484 + 2)
          - result
          - *((unsigned __int16 *)off_114480 + 92)
          - *(unsigned __int16 *)(*(uint32_t *)off_114488 + 52) >= 0) )
      {
        *(uint32_t *)off_11448C = 0x40000000;
        return result;
      }
      result = feature_guard_sdio(2, dword_114494);
    }
  }
  *(uint32_t *)off_11448C = 0x80000000;
  return result;
}

