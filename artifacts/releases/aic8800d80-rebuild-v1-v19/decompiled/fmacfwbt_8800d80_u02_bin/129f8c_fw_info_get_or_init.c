// fw_info_get_or_init @ 0x129f8c, size 32 bytes
// Doc: fw_info_get_or_init [util]: Fetch/initialize firmware info block via helper call
// fw_info_get_or_init [util]: Fetch/initialize firmware info block via helper call
int __fastcall fw_info_get_or_init(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r0
  unsigned __int8 v6; // r4

  v5 = sub_129EBC(a1, a2, a3, a4);
  v6 = v5;
  if ( !v5 )
    return 0;
  timestamp_update_4f60(a1, v5);
  *(_BYTE *)(a1 + 16) = 1;
  return v6;
}

