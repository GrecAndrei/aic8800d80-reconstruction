// sub_122268 @ 0x122268, size 36 bytes
int __fastcall sub_122268(int result, int a2)
{
  int v2; // r4

  v2 = result;
  if ( (a2 & 0x800000) != 0 )
  {
    *(_BYTE *)(result + 128) = 0;
  }
  else
  {
    feature_guard_sdio(1024, dword_12228C);
    return mac_cmd_send_status_query(v2);
  }
  return result;
}

